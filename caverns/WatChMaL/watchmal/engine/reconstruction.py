"""
Class for training a fully supervised classifier
"""

# generic imports
import numpy as np
from datetime import timedelta
from datetime import datetime
from abc import ABC, abstractmethod

import wandb
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
        self.dump_path = dump_path # already contains the last '/'
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
        self.best_training_loss   = 1.0e10

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
            
            # get_world_size() returns the number of processes in the group. Not all the gpu availables
            self.n_gpus = torch.distributed.get_world_size()
        
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
        #self.train_log = CSVLog(self.dump_path + f"log_train_{self.rank}.csv")
        #self.val_log = CSVLog(self.dump_path + f"log_val_{self.rank}.csv")

        # if self.rank == 0:
        #     self.val_log = CSVLog(self.dump_path + "log_val.csv") # Only rank 0 will save its performances at validation in a .csv file


    @abstractmethod
    def forward(self, forward_type):
        pass 

    @abstractmethod
    def to_disk_data_reformat(self):
        pass

    @abstractmethod
    def make_plots(self):
        pass


    def configure_loss(self, loss_config):
        self.criterion = instantiate(loss_config)

    def configure_optimizers(self, optimizer_config):
        """Instantiate an optimizer from a hydra config."""
        self.optimizer = instantiate(optimizer_config, params=self.module.parameters())

    def configure_scheduler(self, scheduler_config):
        """Instantiate a scheduler from a hydra config."""
        self.scheduler = instantiate(scheduler_config, optimizer=self.optimizer)

    
    def set_dataset(self, dataset, dataset_config):
        
        if self.dataset is not None:
            print(f'Error : Dataset is already set in the engine of the process : {self.rank}')
            raise ValueError

        self.dataset = dataset
        self.split_path = dataset_config.split_path
        self.target_names = list(dataset_config.target_names)

        # Get the feat_norm and target_norm values for later (used when displaying data)
        for trf in dataset.transform.transforms: # dataset.transform is a T.Compose() object, to access the list of transform calling .transforms is needed
            if trf.__class__.__name__ == 'Normalize':
                ft_norm, target_norm = trf.feat_norm, trf.target_norm
                break
            
        self.feat_norm, self.target_norm = ft_norm, target_norm



    def configure_data_loaders(self, loaders_config):
        """
        Set up data loaders from loaders hydra configs for the data config, and a list of data loader configs.

        Parameters
        ==========
        loaders_config
            Dictionnary specifying a list of dataloader configurations.
        """

        for name, loader_config in loaders_config.items():
           
            self.data_loaders[name] = get_data_loader_v2(
                dataset=self.dataset,
                split_path=self.split_path,
                device=self.device,
                is_distributed=self.is_distributed,
                **loader_config
            )

        # Additional variables for plots and torch compatibility
        

    
        # Instead, note the self.datatets
        # for name, loader_config in loaders_config.items():
        #    self.data_loaders[name] = get_data_loader(self.datasets, **loader_config, is_distributed=is_distributed, seed=seed)


    def get_reduced(self, outputs, rank, n_gpus, op=torch.distributed.ReduceOp.SUM):
        """
        Gathers metrics from multiple processes using pytorch 
        distributed operations for DistributedDataParallel

        Note :  Only modifies rank O's outputs dictionnary
                Tensors are kept. (Nothing is converted via .item())
        Parameters
        ==========
        outputs : dict
            Dictionary containing values that are tensor outputs of a single process.

        Returns
        =======
        global_metric_dict : dict
            Dictionary containing mean of tensor values gathered from all processes
        """
        new_outputs = {}
        
        for name, tensor in outputs.items():
            
            # Reduce must be called from all the processes
            # note that only the tensor on rank 0 is modified
            # the others remain the same.
            torch.distributed.reduce(tensor, 0, op=torch.distributed.ReduceOp.SUM) 

            if self.rank == 0:
                # The reduce operation being a sum over all the processes, 
                # we need to divide by n_gpus to get the average value 
                new_outputs[name] = tensor / self.n_gpus 

            # new_outputs[name] = tensor.item() # to detach and convert the tensor for each of the processes.
            # decision to do this after. get_reduce should only reduce, not detach (as the name suggest)
        
        return new_outputs

    def get_gathered(self, inputs):
        """
        Gathers metrics from multiple processes using pytorch 
        distributed operations for DistributedDataParallel

        Note :  Only modifies rank O's outputs dictionnary
                Tensors are kept. (Nothing is converted via .item())
        Parameters
        ==========
        outputs : dict
            Dictionary containing values that are tensor outputs of a single process.

        Returns
        =======
        global_metric_dict : dict
            Dictionary containing mean of tensor values gathered from all processes
        """
        output_dict = {}
        for name, tensor in inputs.items():
            
            # Gather must be called from all the processes
            # note that only the rank 0 needs a tensor_list to receive the "new_tensor"
            if self.rank == 0:
                tensor_list = [torch.zeros_like(tensor, device=self.device) for _ in range(self.n_gpus)]
                torch.distributed.gather(tensor, gather_list=tensor_list, dst=0)
            else :
                torch.distributed.gather(tensor, dst=0) 

            output_dict[name] = tensor
        
        return output_dict
        

    def sub_train(self, loader, val_interval):
        """
        Each process performs its own sub_train. Outputs are gathered in the main train() loop.
        """
        self.model.train() # Set model to training mode
        
        # Global logs dictionnary. Everything in it will be log by wandb
        # Note : 'loss' key mandatory in Reg and Class engine.
        metrics_epoch_history = {'loss': 0} 
        
        for step, train_data in enumerate(loader):
            
            # Mount the batch of data to the device
            self.data = train_data['data'].to(self.device)
            self.target = train_data[self.truth_key].to(self.device)                
            
            # Call forward: make a prediction & measure the average error using data = self.data
            outputs, metrics  = self.forward(forward_type='train')
            
            # Call backward: back-propagate error and update weights using loss = self.loss
            self.loss = metrics['loss']
            self.backward()

            # Run scheduler
            if self.scheduler is not None:
                self.scheduler.step()
            
            # If not detaching now ( with .item() ) all the data of the epoch will be load into GPU memory
            # v.item() converts torch.tensors to python floats (and detachs + moves to cpu)
            metrics = {k: v.item() for k, v in metrics.items()} 
            outputs = {k: v.item() for k, v in outputs.items()}

            # For now we only monitor rank 0
            if self.rank == 0:

                # --- Logs in wandb --- #
                if self.wandb_run is not None:
                    self.wandb_run.log(
                        {'train_batch_' + k: v for k, v in outputs.items()} | 
                        {'train_batch_' + k: v for k, v in metrics.items()}
                    )

                # --- Keep track of metrics --- #
                for k in metrics.keys():
                    if not k in metrics_epoch_history.keys():
                        metrics_epoch_history[k] = 0.
                    metrics_epoch_history[k] += metrics[k]

            # --- Display --- #
            if ( step  % val_interval == 0 ):
                #log.info(f"GPU : {self.device} | Steps : {step + 1}/{len(loader)} | Iteration : {self.iteration + step} | Batch Size : {loader.batch_size}")
                
                if ( self.rank == 0 ) :
                    log.info(f"GPU : {self.device} | Steps : {step + 1}/{len(loader)} | Iteration : {self.iteration + step} | Batch Size : {loader.batch_size}")
                    #log.info(f" Iteration {self.iteration + step}, train loss : {metrics['loss']:.5f}")
                    log.info(f"Batch metrics {', '.join(f'{k}: {v:.5g}' for k, v in metrics.items())}")
                    
        
        self.iteration += ( step + 1 )

        if self.rank == 0:
            # Mean over the epoch for each metric
            for k in metrics_epoch_history.keys():
                metrics_epoch_history[k] /= (step + 1)

        return metrics_epoch_history

    def sub_validate(self, loader, forward_type='val'):
        """
        loader: Loader on which to perform the validation.
        forward_type: forward_type argument to pass to the forward method.
            If set to 'test' the output will be two dictionnaries :
            One containing the metrics, one containing the raw preds + targets
            Otherwise it just return the metrics dictionnary and raw_preds and 
            targets are not stored.
        """

        metrics_epoch_history = {'loss': 0}  # loss is mandatory for Class and Reg engine
        to_disk_epoch_history = {'preds': [], 'targets': []} # Will be saved in numpy arrays
        wandb_prefix = ""
            
        self.model.eval()                
        with torch.no_grad():
            
            for step, val_batch in enumerate(loader):
        
                # Mount the batch of data to the device
                self.data = val_batch['data'].to(self.device)
                self.target = val_batch[self.truth_key].to(self.device)
                
                # evaluate the network
                outputs, metrics = self.forward(forward_type=forward_type) # output is a dictionnary with torch.tensors
                
                # In case of ddp we reduce outputs to get the global performance
                # Note : It is currently done at each step to optimize gpu memory usage
                # But this could also be perform at the end of the validation epoch
                
                if forward_type == 'test':
                    preds = {'pred': outputs.pop('pred')}

                if self.is_distributed:
                    metrics = self.get_reduced(metrics)
                    outputs = self.get_reduced(outputs)

                    if forward_type == 'test':
                        self.target = self.get_gathered(self.target)
                        preds   = self.get_gathered(preds)
                
                # Detaching outputs tensors ( with .item() )
                # otherwise all the data of the epoch will be load into GPU memory
                # v.item() converts torch.tensors to python floats (and detachs + moves to cpu)
                metrics = {k: v.item() for k, v in metrics.items()} 
                outputs = {k: v.item() for k, v in outputs.items()} 

                if forward_type == 'test':
                    self.target = self.target.detach().cpu().numpy() # we store them for roc curve etc..
                    preds   = {k: v.detach().cpu().numpy() for k, v in preds.items()}
                
                if self.rank == 0: 

                    # --- Storing for saving --- # 
                    if forward_type == 'test':
                        to_disk_epoch_history['targets'].append(self.target)
                        to_disk_epoch_history['preds'].append(preds['pred']) 

                    # --- Storing gobal performances --- #
                    for k in metrics.keys():
                        if not k in metrics_epoch_history.keys():
                            metrics_epoch_history[k] = 0.
                        metrics_epoch_history[k] += metrics[k]

                    # --- Logs --- #
                    if self.wandb_run is not None:

                        # Pourquoi ne pas juste faire 
                        # log_dict = outputs | metrics puis {.. in log_dict.items()} ?
                        
                        self.wandb_run.log(
                            {wandb_prefix + 'val_batch_' + k: v for k, v in outputs.items()} | 
                            {wandb_prefix + 'val_batch_' + k: v for k, v in metrics.items()}
                        )

            # Take the mean over the epoch 
            if self.rank == 0:
                for k in metrics_epoch_history.keys():
                    metrics_epoch_history[k] /= (step + 1)
        
        if forward_type == 'test':
            return metrics_epoch_history, to_disk_epoch_history
        
        return metrics_epoch_history


    def backward(self):
        """Backward pass using the loss computed for a mini-batch"""

        self.optimizer.zero_grad()  # reset gradients
        self.loss.backward()        # compute the new gradients for this iteration
        self.optimizer.step()       # perform gradient descent on all the parameters of the model
        
    def train(self, epochs=0, val_interval=20, checkpointing=False, save_interval=None):
        """
        Train the model on the training set. The best state is always saved during training.

        Parameters
        ==========
        epochs: int
            Number of epochs to train, default 1
        val_interval: int
            Number of iterations between each validation, default 20
        num_val_batches: int
            Number of mini-batches in each validation, default 4
        checkpointing: bool
            Whether to save state every validation, default False
        save_interval: int
            Number of epochs between each state save, by default don't save
        """
        
        start_run_time = datetime.now()

        log.info(f"Engine : {self.rank} | Dataloaders : {self.data_loaders}")
        if self.rank == 0:
            print("\n")
            log.info( f"\033[1;96m********** 🚀 Starting training for {epochs} epochs 🚀 **********\033[0m")
        

        # initialize epoch and iteration counters
        #epoch               = 0 # (used by nick)  counter of epoch
        self.iteration       = 1 # (used by erwan) counter of the steps of all epochs
        self.step            = 0 # (used by nick)  counter of the steps of one epoch
        
        self.best_training_loss   = np.inf
        self.best_validation_loss = np.inf
        

        train_loader = self.data_loaders["train"]
        val_loader   = self.data_loaders["validation"]

        # Watching 
        if self.wandb_run is not None:
            self.wandb_run.watch(self.module, log='all', log_freq=val_interval * 2)
            self.wandb_run.log({'max_datapoints_seen': epochs * len(train_loader) * train_loader.batch_size})

        # global loop for multiple epochs        
        for epoch in range(epochs):
            
            # variables that will be used outside the train function
            self.epoch = epoch

            # ---- Starting the training epoch ---- #
            epoch_start_time = datetime.now()
            if ( self.rank == 0 ):
                log.info(f"\n\nTraining epoch {self.epoch + 1}/{epochs} starting at {epoch_start_time}")
            

            # update seeding for distributed samplers
            if self.is_distributed:
                train_loader.sampler.set_epoch(self.epoch)
          
            metrics_epoch_history = self.sub_train(train_loader, val_interval) # one train epoch.

            epoch_end_time = datetime.now()

            # --- Display global info about the train epoch --- #
            if self.rank == 0:
                log.info(f"(Train) Epoch : {epoch + 1} completed in {(epoch_end_time - epoch_start_time)} | Iteration : {self.iteration} ")
                log.info(f"Total time since the beginning of the run : {epoch_end_time - start_run_time}")
                log.info(f"Metrics over the (train) epoch {', '.join(f'{k}: {v:.5g}' for k, v in metrics_epoch_history.items())}")

                # --- Wandb logs --- #
                if self.wandb_run is not None:
                    self.wandb_run.log(
                        {'train_epoch_' + k: v for k, v in metrics_epoch_history.items()}
                    )

                    if metrics_epoch_history['loss'] < self.best_training_loss:
                        self.best_training_loss = metrics_epoch_history['loss']
                        self.wandb_run.log({'best_train_epoch_loss': self.best_training_loss})

            
            # ---- Starting the validation epoch ---- #
            epoch_start_time = datetime.now()
            if ( self.rank == 0 ):
                log.info("")
                log.info(f" -- Validation epoch starting at {epoch_start_time}")

            # if self.is_distributed:
            #     val_loader.sampler.set_epoch(self.epoch) # Previously +1, why?
                       
            metrics_epoch_history = self.sub_validate(val_loader, forward_type='val') # also store preds for roc etc. ?

            epoch_end_time = datetime.now()

            # --- Display global info about the validation epoch --- #
            if self.rank == 0:
                log.info(f" -- Validation epoch completed in {epoch_end_time - epoch_start_time} | Iteration : {self.iteration}")
                log.info(f" -- Total time since the beginning of the run : {epoch_end_time - start_run_time}")
                log.info(f" -- Metrics over the (val) epoch {', '.join(f'{k}: {v:.5g}' for k, v in metrics_epoch_history.items())}")
                            
                # --- Wandb --- #
                if self.wandb_run is not None:
                    self.wandb_run.log(
                        {'val_epoch_' + k: v for k, v in metrics_epoch_history.items()}
                    )

                # Save if this is the best model so far
                if metrics_epoch_history["loss"] < self.best_validation_loss:
                    log.info(" ... Best validation loss so far!")
                    self.best_validation_loss = metrics_epoch_history["loss"]

                    self.save_state(suffix="_BEST")
                elif checkpointing:
                    # if checkpointing = True the model is saved at the end of each validation epoch
                    self.save_state()
 
    def validate(self, data_loader_name, forward_type, label_names, prefix_plot_name):

        val_loader = self.data_loaders[data_loader_name]
        start_time = datetime.now()

        if self.rank == 0:
            log.info(f"\n\n Validation starting")


        metrics_epoch_history = self.sub_validate(val_loader, forward_type=forward_type, from_train=False)
        
        if forward_type == 'test':
            metrics_epoch_history, to_disk_epoch_history = metrics_epoch_history

            if self.rank == 0:

                self.make_plots(
                    prefix_plot_name,
                    targets=to_disk_epoch_history['targets'], 
                    preds=to_disk_epoch_history['preds'], # This is litteraly of the size n_event, [] (whole dataset)...
                )



        end_time = datetime.now()
        if self.rank == 0:
            log.info(f"Validation completed in {end_time - start_time} | Iteration check : {self.iteration}")
            log.info(f"Total time since the beginning of the validation : {end_time - start_time}")
            log.info(f"Metrics over the (val) epoch {', '.join(f'{k}: {v:.5g}' for k, v in metrics_epoch_history.items())}")
    
    def evaluate(self, prefix_for_plot_names, report_interval=20, batch_log=False):
        """Evaluate the performance of the trained model on the test set."""
        
        if self.rank == 0:
            log.info(f"\n\nTest epoch starting.\nOutput directory: {self.dump_path}")

        # Iterate over the validation set to calculate val_loss and val_acc
        with torch.no_grad():
            
            # Set the model to evaluation mode
            self.model.eval()
            metrics_epoch_history = {'loss': 0.}
            to_disk_epoch_history = {'preds': [], 'indices': [], 'targets': []} # Will be saved in numpy arrays. List seems the esiset way to this. Most efficient would be to init them as npy array the wanted size.
    
            # evaluation loop
            start_time = datetime.now()

            loader = self.data_loaders['test']            
            for step, eval_data in enumerate(loader):
                
                self.data   = eval_data['data'].to(self.device)
                self.target = eval_data[self.truth_key].to(self.device)
                indices     = {'indices': eval_data['indice'].to(self.device)} # Not optimal. It uses gpu memory for nothing if running on single gpu.

                outputs, metrics = self.forward(forward_type='test') # will ouput loss + accuracy + softmax of the preds (for classification)
                
                # In case of ddp we reduce outputs to get the global performance
                # Note : It is currently done at each step to optimize gpu memory usage
                # But this could also be perform at the end of the test epoch
                # We remove pred from the output dict so we can call reduce on all
                # the other outputs related var and call gather only on the real preds
                preds = {'pred': outputs.pop('pred')}
                if self.is_distributed:
                    metrics = self.get_reduced(metrics)
                    #outputs = self.get_reduced(outputs) We only wandb monitor the outputs of rank 0
                    preds   = self.get_gathered(preds)
                    indices = self.get_gathered(indices)
                    self.target = self.get_gathered(self.target)

                # metrics : Detach the tensors (loss + ..) from computational graph + put them on cpu 
                # so they become native python types (not tensors anymore)
                metrics = {k: v.item() for k, v in metrics.items()}
                outputs = {k: v.item() for k, v in outputs.items()} # OUTPUTS DOES NOT CONTAINS RAW_OUPUTS (it is PREDS, see the .pop above)

                # preds : item() cannot be call on multi-dim tensors, so we .detach() and put on cpu by ourselves  
                # we also convert to numpy array because no need to keep this data as tensors for after
                preds   = {k: v.detach().cpu().numpy() for k, v in preds.items()}
                indices = indices['indices'].detach().cpu().numpy()
                self.target = self.target.detach().cpu().numpy() # we store them for roc curve etc..


                if self.rank == 0: 

                    # --- Wandb --- #
                    if ( self.wandb_run is not None ) and batch_log:
                        self.wandb_run.log(
                            {'test_batch_' + k: v for k, v in metrics.items()} |
                            {'test_batch_' + k: v for k, v in outputs.items()}
                        )

                    # --- Storing performances --- #
                    for k in metrics.keys():
                        if not k in metrics_epoch_history.keys():
                            metrics_epoch_history[k] = 0.
                        metrics_epoch_history[k] += metrics[k]

                    # --- Concatenating indices and softmax to prepare saving --- # 
                    to_disk_epoch_history['preds'].append(preds['pred']) 
                    to_disk_epoch_history['indices'].append(indices)
                    to_disk_epoch_history['targets'].append(self.target)
                    
                    # --- Display --- #
                    if ( step % report_interval == 0 ):
                        log.info(
                            f"  Step {step + 1}/{len(loader)}"
                            f"  Evaluation {', '.join(f'{k}: {v:.5g}' for k, v in metrics.items())},"
                        )
            # end of the loader loop             
        end_time = datetime.now()
        
        if self.rank == 0:

            #
            # -- Regarding metrics_output_history --- #
            #
            # Compute the mean over the test epoch of each metric
            for k in metrics_epoch_history.keys():
                metrics_epoch_history[k] /= step + 1

            # --- Logs --- #
            log.info(f"Evaluation total time {end_time - start_time}")
            log.info(f"Metrics over the test epoch {', '.join(f'{k}: {v:.5g}' for k, v in metrics_epoch_history.items())}")

            # --- Wandb --- #
            if self.wandb_run is not None:
                self.wandb_run.log(
                    {'test_epoch_' + k: v for k, v in metrics_epoch_history.items()}
                )

            #
            # --- Regarding to_disk_epoch_history --- #
            #
            to_disk_epoch_history = self.to_disk_data_reformat(**to_disk_epoch_history)

            log.info(f"Starting to compute plots")
            self.make_plots(
                prefix_plot_name=prefix_for_plot_names,
                targets=to_disk_epoch_history['targets'],
                preds=to_disk_epoch_history['preds'],
            )     
                
            # --- Saving softmax + indices in .npy arrays --- #
            log.info("Saving the data...")
            for k, v in to_disk_epoch_history.items():
                save_path = self.dump_path + k + ".npy"
                np.save(save_path, v)

                if self.wandb_run is not None:
                    wandb.save(save_path)

            log.info("Done")


    def save_state(self, suffix="", name=None):
        """
        Save model weights and other training state information to a file.

        Parameters
        ==========
        suffix : string
            The suffix for the filename. Should be "_BEST" for saving the best validation state.
        name : string
            The name for the filename. By default, use the engine class name followed by model class name.

        Returns
        =======
        filename : string
            Filename where the saved state is saved.
        """
        if name is None:
            name = f"{self.__class__.__name__}_{self.module.__class__.__name__}"
       
        filename = f"{self.dump_path}{name}{suffix}.pth" # for model + optimizer state
        
        # Save model state dict in appropriate from depending on number of gpus
        model_dict = self.module.state_dict()
        optimizer_dict = self.optimizer.state_dict()
        
        # Save parameters
        # 0) iteration counter
        # 1) optimizer state => 0+1 in case we want to "continue training" later
        # 2) network weight
        
        torch.save({
            'global_step': self.iteration,
            'optimizer': optimizer_dict,
            'state_dict': model_dict
        }, filename)
        
        # Wandb Artifact to monitor models
        if self.wandb_run is not None:
            artifact = wandb.Artifact(name=f"model-and-opti-checkpoints-{self.wandb_run.id}", type="model-and-opti")
            artifact.add_file(filename)

            aliases = ['ite_' + str(self.iteration)]
            if suffix:
                artifact.description = f"Validation loss : {self.best_validation_loss:.4g}"
                
                aliases.append(suffix)
                self.wandb_run.log({'best_val_epoch_loss': self.best_validation_loss})

            self.wandb_run.log_artifact(artifact, aliases=aliases)

            log.info("Save state on wandb")

        log.info(f"Saved state as: {filename}")
        
        return filename

    def restore_state(self, weight_file):
        """Restore model and training state from a given filename."""
        
        # Open a file in read-binary mode
        with open(weight_file, 'rb') as f:
            log.info("\n\n")
            log.info(f"Restoring state from {weight_file}\n")
           
            # prevent loading while DDP operations are happening
            if self.is_distributed:
                torch.distributed.barrier()
            
            # torch interprets the file, then we can access using string keys
            checkpoint = torch.load(f, map_location=self.device)
            
            # load network weights
            self.module.load_state_dict(checkpoint['state_dict'])
        
            # if optim is provided, load the state of the optim
            if self.optimizer is not None:
                self.optimizer.load_state_dict(checkpoint['optimizer'])
            
            # load iteration count
            self.iteration = checkpoint['global_step']

    def restore_best_state(self, name=None, complete_path=False):
        """Restore model using best model found in current directory."""

        if name is None:
            name = f"{self.__class__.__name__}_{self.module.__class__.__name__}"
            
        full_path = f"{self.dump_path}{name}_BEST.pth"
        self.restore_state(full_path)

