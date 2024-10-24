"""
Class for training a fully supervised classifier
"""

# generic imports
import numpy as np
from datetime import timedelta
from datetime import datetime
from abc import ABC, abstractmethod

# hydra imports
from hydra.utils import instantiate

# torch imports
import torch
from torch.nn.parallel import DistributedDataParallel

# WatChMaL imports
from watchmal.dataset.data_utils import get_data_loader, get_data_loader_v2, get_dataset
from watchmal.utils.logging_utils import CSVLog, setup_logging

log = setup_logging(__name__)


class ReconstructionEngine(ABC):
    def __init__(
            self, 
            truth_key, 
            model, 
            rank, 
            device, 
            dump_path,
            wandb_run=None,
            dataset=None
        ):
        """
        Parameters
        ==========
        truth_key : string
            Name of the key for the target values in the dictionary returned by the dataloader
        model
            `nn.module` object that contains the full network that the engine will use in training or evaluation.
        rank : int
            The rank of process among all spawned processes (in multiprocessing mode).
        gpu : int
            The gpu that this process is running on.
        dump_path : string
            The path to store outputs in.
        """
        # create the directory for saving the log and dump files
        self.dump_path = dump_path
        self.wandb_run= wandb_run

        # variables for the model
        self.rank = rank
        self.device = torch.device(device) 
        self.model = model

        # variables to monitor training pipelines
        self.epoch = 0
        self.step = 0
        self.iteration = 0
        self.best_validation_loss = 1.0e10

        # variables for the dataset
        self.dataset      = dataset if dataset is not None else None
        self.split_path   = ""
        self.truth_key    = truth_key

        # Variables for the dataloaders
        self.data_loaders = {}

        # Set up the parameters to save given the model type
        if isinstance(self.model, DistributedDataParallel): # 25/05/2024 - Erwan : Best way to check ddp mode ?
            self.is_distributed = True

            self.module = self.model.module
            self.n_gpus = torch.distributed.get_world_size() # Returns the number of processes in the group. Not all the gpu availables
        else:
            self.is_distributed = False
            self.module = self.model

        # define the placeholder attributes
        self.data   = None
        self.target = None
        self.loss   = None
        self.outputs_epoch_history = []  

        self.criterion = None
        self.optimizer = None
        self.scheduler = None

        # logging attributes
        self.train_log = CSVLog(self.dump_path + f"log_train_{self.rank}.csv")
        #self.val_log = CSVLog(self.dump_path + f"log_val_{self.rank}.csv")

        if self.rank == 0:
            self.val_log = CSVLog(self.dump_path + "log_val.csv") # Only rank 0 will save its performances at validation in a .csv file


    def configure_loss(self, loss_config):
        self.criterion = instantiate(loss_config)

    def configure_optimizers(self, optimizer_config):
        """Instantiate an optimizer from a hydra config."""
        self.optimizer = instantiate(optimizer_config, params=self.module.parameters())

    def configure_scheduler(self, scheduler_config):
        """Instantiate a scheduler from a hydra config."""
        self.scheduler = instantiate(scheduler_config, optimizer=self.optimizer)   


    def configure_data_loaders(self, data_config, loaders_config):
        """
        Set up data loaders from loaders hydra configs for the data config, and a list of data loader configs.

        Parameters
        ==========
        data_config
            Hydra config specifying dataset.
        loaders_config
            Hydra config specifying a list of dataloaders.
        is_distributed : bool
            Whether running in multiprocessing mode.
        seed : int
            Random seed to use to initialize dataloaders.
        """

        for name, loader_config in loaders_config.items():
            self.data_loaders[name] = get_data_loader(
                **data_config.h5_dataset, 
                **loader_config, 
                is_distributed=self.is_distributed, 
                device=self.device
            )

    
    def get_synchronized_outputs(self, output_dict):
        """
        Gathers results from multiple processes using pytorch distributed operations for DistributedDataParallel

        Parameters
        ==========
        output_dict : dict of torch.Tensor
            Dictionary containing values that are tensor outputs of a single process.

        Returns
        =======
        global_output_dict : dict of torch.Tensor
            Dictionary containing concatenated tensor values gathered from all processes
        """
        global_output_dict = {}
        for name, tensor in output_dict.items():
            if self.is_distributed:
                if self.rank == 0:
                    tensor_list = [torch.zeros_like(tensor, device=self.device) for _ in range(self.n_gpus)]
                    torch.distributed.gather(tensor, tensor_list)
                    global_output_dict[name] = torch.cat(tensor_list).detach().cpu().numpy()
                else:
                    torch.distributed.gather(tensor, dst=0)
            else:
                global_output_dict[name] = tensor.detach().cpu().numpy()
        return global_output_dict

    def get_synchronized_metrics(self, metric_dict):
        """
        Gathers metrics from multiple processes using pytorch 
        distributed operations for DistributedDataParallel

        Parameters
        ==========
        metric_dict : dict of torch.Tensor
            Dictionary containing values that are tensor outputs of a single process.

        Returns
        =======
        global_metric_dict : dict
            Dictionary containing mean of tensor values gathered from all processes
        """
        global_metric_dict = {}
        
        for name, tensor in zip(metric_dict.keys(), metric_dict.values()): # .items() ?
            if self.is_distributed:

                # Aggregate the tensors from all the processes (of the group created by init_process_group(..))
                torch.distributed.reduce(tensor, 0) # default operation is adding all the 
                
                if self.rank == 0:
                    global_metric_dict[name] = tensor.item() / self.n_gpus
           
            else:
                global_metric_dict[name] = tensor.item()
        
        return global_metric_dict
         


    def validate(self, val_iter, num_val_batches, checkpointing):
        """
        Perform validation with the current state, on a number of batches of the validation set.

        Parameters
        ----------
        val_iter : iter
            Iterator of the validation dataset.
        num_val_batches : int
            Number of validation batches to iterate over.
        checkpointing : bool
            Whether to save the current state to disk.
        """
        # set model to eval mode
        self.model.eval()
        val_metrics = None

        for val_batch in range(num_val_batches): # num_val_batches is defined in grant_gnn_train et pas basé sur le val_dataset ??
            
            # get validation data mini-batch
            try:
                val_data = next(val_iter)
            
            except StopIteration:
                del val_iter
                if self.is_distributed:
                    self.data_loaders["validation"].sampler.set_epoch(self.data_loaders["validation"].sampler.epoch+1)
                
                val_iter = iter(self.data_loaders["validation"])
                val_data = next(val_iter)
            
            # extract the event data and target from the input data dict
            self.data = val_data['data'].to(self.device)
            self.target = val_data[self.truth_key].to(self.device)
            
            # evaluate the network
            outputs, metrics = self.forward(False)
            if val_metrics is None:
                val_metrics = metrics
            else:
                for k, v in metrics.items():
                    val_metrics[k] += v

        # record the validation stats to the csv
        val_metrics = {k: v/num_val_batches for k, v in val_metrics.items()}
        val_metrics = self.get_synchronized_metrics(val_metrics)

        if self.rank == 0:
            log_entries = {"iteration": self.iteration, "epoch": self.epoch, **val_metrics, "saved_best": False}
            
            # Save if this is the best model so far
            print(f"  Validation {', '.join(f'{k}: {v:.5g}' for k, v in val_metrics.items())}", end="\n")
            
            if val_metrics["loss"] < self.best_validation_loss:
                print(" ... Best validation loss so far!\n")
                self.best_validation_loss = val_metrics["loss"]
                self.save_state(suffix="_BEST")
                log_entries["saved_best"] = True
            else:
                print("")
           
            # Save the latest model if checkpointing
            if checkpointing:
                self.save_state()
            
            self.val_log.log(log_entries)


    def evaluate(self, report_interval=20):
        """Evaluate the performance of the trained model on the test set."""
        
        if self.rank == 0:
            log.info(f"\n\nEnd of the run. Test epoch starting.\nOutput directory: {self.dump_path}")

        # Iterate over the validation set to calculate val_loss and val_acc
        with torch.no_grad():
            
            # Set the model to evaluation mode
            self.model.eval()
            
            # evaluation loop
            start_time = datetime.now()
            step_time = start_time
            steps_per_epoch = len(self.data_loaders["test"])
            
            for self.step, eval_data in enumerate(self.data_loaders["test"]):
                
                self.data = eval_data['data'].to(self.device)
                self.target = eval_data[self.truth_key].to(self.device)

                metrics = self.forward(forward_type='test') # will ouput loss + accuracy + softmax of the preds
                outputs = {'softmax': metrics.pop('softmax')} 

                # Add the local result to the final result
                if self.step == 0:
                    indices = eval_data['indices']
                    targets = self.target
                    eval_outputs = outputs
                    eval_metrics = metrics
                else:
                    indices = torch.cat((indices, eval_data['indices']))
                    targets = torch.cat((targets, self.target))
                    
                    for k in eval_outputs.keys():
                        eval_outputs[k] = torch.cat((eval_outputs[k], outputs[k]))

                    for k in eval_metrics.keys():
                        eval_metrics[k] += metrics[k]
               
                # print the metrics at given intervals
                if self.rank == 0 and self.step % report_interval == 0:
                    previous_step_time = step_time
                    step_time = datetime.now()
                    average_step_time = (step_time - previous_step_time)/report_interval
                    print(f"Step {self.step}/{steps_per_epoch}"
                          f" Evaluation {', '.join(f'{k}: {v:.5g}' for k, v in metrics.items())},"
                          f" Step time {average_step_time},"
                          f" Total time {step_time-start_time}")
       
        for k in eval_metrics.keys():
            eval_metrics[k] /= self.step+1

        eval_outputs["indices"] = indices.to(self.device)
        eval_outputs[self.truth_key] = targets
       
        # Gather results from all processes
        eval_metrics = self.get_synchronized_metrics(eval_metrics)
        eval_outputs = self.get_synchronized_outputs(eval_outputs)
        
        if self.rank == 0:
            # Save overall evaluation results
            log.info("Saving Data...")
            for k, v in eval_outputs.items():
                np.save(self.dump_path + k + ".npy", v)
            # Compute overall evaluation metrics
            
            for k, v in eval_metrics.items(): # loss + accuracy
                log.info(f"Average evaluation {k}: {v:.4f}")

                # --- Wandb --- #
                if self.wandb_run is not None:
                    name = 'test_' + k
                    self.wandb_run.log({name: v})
