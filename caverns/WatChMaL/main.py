"""
Main file used for running the code
"""

# hydra imports
import hydra
from hydra.utils import instantiate, get_original_cwd, to_absolute_path
from hydra.core.hydra_config import HydraConfig
from hydra.core.utils import configure_log

from omegaconf import OmegaConf, open_dict, DictConfig

# torch imports
import torch
import torch.multiprocessing as mp

from torch.distributed import init_process_group, destroy_process_group
from torch.nn.parallel import DistributedDataParallel as DDP

import wandb

# generic imports
import logging
import os
import pprint
import yaml

# Watchmal import
from watchmal.utils.logging_utils import setup_logging
from watchmal.utils.build_utils import build_dataset, build_model, merge_config


#log = logging.getLogger(__name__)
log = setup_logging(__name__)

from hydra.utils import get_original_cwd



# A decorator changes the way a function work
@hydra.main(config_path='config/', config_name='resnet_train', version_base="1.1")
def hydra_main(config):
    """
    Run model using given config, spawn worker subprocesses as necessary

    Args:
        config  ... hydra config specified in the @hydra.main annotation
    """

    # Get the current and Hydra output directories for the run
    original_cwd = get_original_cwd()
    hydra_output_dir = os.getcwd()

    # Display folders for the run
    log.info(f"Original working directory: {original_cwd}")
    log.info(f"Hydra output directory: {hydra_output_dir}")
    #log.info(f"Global output directory for this run : {config.dump_path}")
    log.info(f"Specific output directory (the one use by the engine to save & load ) for this run :\n\n     {hydra_output_dir}\n")

    # Get the global config
    global_hydra_config = HydraConfig.get()

    # Lauch the run
    main(hydra_config=config, global_hydra_config=global_hydra_config)


def main(hydra_config, global_hydra_config):

    gpu_list = hydra_config.gpu_list

    # Initialize a wandb Run if asked
    if ( hydra_config.launch_wandb ) or ( 'WANDB_SWEEP_ID' in os.environ ):
        wandb_config_from_hydra = hydra_config.wandb
        wandb_config_from_hydra = OmegaConf.to_container(wandb_config_from_hydra, resolve=True)

        wandb_run    = wandb.init(**wandb_config_from_hydra)
        wandb_config = wandb.config # get the config from the agent (if any)
        hydra_config = merge_config(hydra_config, wandb_config)

    else :
        wandb_run =  None
    

    # Display the config(s) of the run 
    # (after wandb.init() so it's stored in wandb logs)
    y = OmegaConf.to_yaml(hydra_config)
    log.info(f"Hydra config: \n{y}\n")

    # Log top informations in wandb
    if wandb_run is not None :

        try:
            wandb_run.log({'SLURM_JOB_ID': int(os.getenv('SLURM_JOB_ID'))})
        except:
            log.info('No slurm job id')
        log.info(f"Wandb config : \n{wandb_config}\n")
        
        # Save hydra final dictionnary as a yaml file to store 
        # it in wandb.
        log_config_path = os.getcwd() + '/hydra_final_config.yaml'
        with open(log_config_path, 'w') as yaml_file:
            hydra_config_as_dict = OmegaConf.to_container(hydra_config, resolve=True)
            yaml.dump(hydra_config_as_dict, yaml_file, default_flow_style=False)        

        wandb.save(log_config_path)
        

    # Create or get the dataset (only for gnn, for cnn see run(..))
    # It's only when the dataset has to be processed that 
    # this part needs to be outside the run(..) function.
    # In the end we will need to make .root -> graph.pt outside of watchmal
    if hydra_config.kind == 'gnn':
        dataset = build_dataset(hydra_config)        
    else : # When using kind='cnn'
        dataset = None
    
    # Parse gpu argument to set the type of run (cpu/gpu/gpus)
    if len(gpu_list) == 0:
        log.info("The gpu list is empty. Run will be done on cpu.\n")
        run(rank=0, gpu_list=gpu_list, dataset=dataset, wandb_run=wandb_run, hydra_config=hydra_config, global_hydra_config=global_hydra_config)
    
    elif len(gpu_list) == 1:
        log.info("One gpu in the gpu list.\n")
        run(rank=0, gpu_list=gpu_list, dataset=dataset, wandb_run=wandb_run, hydra_config=hydra_config, global_hydra_config=global_hydra_config)

    else: 
        devids = [f"cuda:{x}" for x in gpu_list]
        log.info(f"Multiple gpus in the gpu_list. Running on distributed mode")
        log.info(f"List of accessible devices : {devids}\n")

        # Lauch a run on each gpu
        mp.spawn(
            run, 
            nprocs=len(gpu_list), # In our case we always consider n_processes=n_gpus=len(gpu_list)
            args=(gpu_list, dataset, wandb_run, hydra_config, global_hydra_config)
        )


def run(rank, gpu_list, dataset, wandb_run, hydra_config, global_hydra_config):

    # Initialize the group and configure the log in case of distributed training
    if len(gpu_list) > 1:
        ddp_setup(rank, world_size=len(gpu_list), master_port=str(hydra_config.master_port)) # Keep len(gpu_list here). After can call get_world_size()
        configure_log(global_hydra_config.job_logging, global_hydra_config.verbose)

    device = 'cpu' if len(gpu_list) == 0 else rank    
    wandb_run = wandb_run if rank == 0 else None
    log.info(f"Running worker {rank} on device : {device} with wandb_run : {wandb_run}")
    

    # Instantiate the model (for each process if many) 
    torch.manual_seed(0)
    model, nb_params = build_model(
        model_config=hydra_config.model, 
        device=device, 
        use_ddp=(len(gpu_list) > 1)
    )
    if wandb_run is not None:
        wandb_run.log({'nb_params': nb_params})

    # Instantiate the engine (for each process if many) --- Let's do the model in the engine ?
    hydra_output_dir = os.getcwd()
    engine = instantiate(
        config=hydra_config.engine,
        dump_path=hydra_output_dir + "/",
        model=model, 
        rank=rank, 
        device=device,
        wandb_run=wandb_run
    )

    if hydra_config.kind == 'gnn':
        engine.set_dataset(dataset, hydra_config.data.dataset)

    # keys to update in each dataloaders confic dictionnary           
    for task, task_config in hydra_config.tasks.items():

        with open_dict(task_config):

            # Configure data loaders
            if 'data_loaders' in task_config:
                match hydra_config.kind:
                    case 'cnn':
                        engine.configure_data_loaders(
                            hydra_config.data, 
                            task_config.pop("data_loaders"),
                        )
                    case 'gnn':                                                   
                        engine.configure_data_loaders(
                            task_config.pop("data_loaders"), 
                        )
                    case _:
                        print(f"The kind parameter {hydra_config.kind} is unknown. Set it to 'cnn' or 'gnn'")
                        raise ValueError                    

            # Configure optimizers
            if 'optimizers' in task_config:
                engine.configure_optimizers(task_config.pop("optimizers"))
            
            # Configure scheduler
            if 'scheduler' in task_config:
                engine.configure_scheduler(task_config.pop("scheduler"))
            
            # Configure loss
            if 'loss' in task_config:
                engine.configure_loss(task_config.pop("loss"))

    # Perform tasks - not very user-friendly, to be removed in the futur
    for task, task_config in hydra_config.tasks.items():

        # if 'train' in task:
        #     task = 'train'
        # elif 'validation' in task:
        #     task = 'validate'
        # elif 'test' in task:
        #     task= 'evaluate'
        
        getattr(engine, task)(**task_config)

    if wandb_run is not None:
        wandb_run.finish()

    if len(gpu_list) > 1:
        destroy_process_group()

    
    


def ddp_setup(rank, world_size, master_port: str):
    """
    Args:
        rank: Unique identifier of each process
        world_size: Total number of processes
    """
    os.environ["MASTER_ADDR"] = "localhost"
    os.environ["MASTER_PORT"] = master_port

    init_process_group(
        backend="nccl", init_method='env://', rank=rank, world_size=world_size
    )


if __name__ == '__main__':
    hydra_main()



