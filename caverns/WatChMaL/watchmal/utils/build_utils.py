"""
Functions to build / configure classes
that need to be done (any reason below)
- outside the engine
- outside the run(..) function in case of mulitprocessing
"""
# Import for doc
from omegaconf import DictConfig

# torch import
import torch
from torch.nn.parallel import DistributedDataParallel as DDP

# hydra imports 
from hydra.utils import instantiate

# watchmal impport
from watchmal.dataset.data_utils import get_dataset
from watchmal.utils.logging_utils import setup_logging

log = setup_logging(__name__)


def build_dataset(config: DictConfig):
    log.info(f"Loading the dataset..")

    dataset_config   = config.data # data contains .dataset and .transforms

    dataset = get_dataset(
        dataset_config.dataset.dataset_parameters, 
        dataset_config.transforms
    )

    log.info('Finished loading')
    log.info(f"Length of the dataset : {len(dataset)}")
    log.info(f"First graph of the dataset : {dataset[0]}")

    if not dataset_config.dataset.fully_processed:
        dataset.compute_edges(
            **dataset_config.dataset.compute_edges_parameters
        )
        log.info(f"Called compute_edges. First graph is now : {dataset[0]}\n")

    return dataset


def build_model(model_config, device, use_ddp=False):
    """
    Build the model and wrap it with SynBatchNorm and  config if using torch DDP
    """
    model = instantiate(model_config)
    nb_parameters = sum(p.numel() for p in model.parameters() if p.requires_grad)

    if ( device == 'cpu') or ( str(device) in ['0', 'cuda:0'] ):
        print()
        log.info(f"Number of parameters in the model : {nb_parameters}\n")

    model.to(device)

    if use_ddp:
        # Convert model batch norms to synchbatchnorm (if the model contains BatchNorm layers)
        model = torch.nn.SyncBatchNorm.convert_sync_batchnorm(model)

        # Wrap the model with DistributedDataParallel mode
        model = DDP(model, device_ids=[device])

    return model, nb_parameters


def merge_config(hydra_config, wandb_config):
    """
    Update Hydra configuration with values from W&B configuration if the keys match.
    
    Args:
    - hydra_config (omegaconf.DictConfig): The Hydra configuration object.
    - wandb_config (dict): The dictionary containing W&B configuration.
    
    Returns:
    - hydra_config (omegaconf.DictConfig): The updated Hydra configuration object.
    """
    print("\n") # For display purpose
    


    modified_keys, not_found_keys =[], []
    for key, value in wandb_config.items():
		
        # list_of_keys = ['data', 'dataset', 'root_file_path'] par ex.
        list_of_keys = key.split("-") 

        # key_name = ['root_file_path'] par ex.
        key_name = list_of_keys[-1] 

        # define the intial location 
        location = hydra_config 

        # Update the location based on the directory structure
        try:
            if len(list_of_keys) == 1:
                i = list_of_keys[0]
                location = location[i]
            else:
                for i in list_of_keys[0:-1]:
                    location = location[i]
            
        except:
            print(f"{list_of_keys} not found")
            not_found_keys.append(key)

        else:
            location[key_name] = value
            modified_keys.append(key)
    
        
	# On sort de la boucle for sur wandb_config
    print("Clés modifiées :", modified_keys)
    print("Clés non modifiées :", not_found_keys, end="\n")

    return hydra_config