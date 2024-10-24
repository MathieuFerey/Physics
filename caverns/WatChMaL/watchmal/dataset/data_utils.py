"""
Utils for handling creation of dataloaders
"""

# generic imports
import numpy as np
import random

# hydra imports
from hydra.utils import instantiate

# torch imports
import torch
from torch.utils.data import DataLoader

# pyg imports
import torch_geometric.transforms as T
from torch_geometric.loader import DataLoader as PyGDataLoader

# WatChMaL imports
from watchmal.dataset.samplers.samplers import DistributedSamplerWrapper
from watchmal.utils.logging_utils import setup_logging

log = setup_logging(__name__)



def get_dataset(dataset_config, transforms_config=None):
    """
    Instantiate a GraphCompose class with all the transformations passed in transforms_config
    Then instantiate a torch_geometric Dataset
    """
    transform_compose = None

    if 'transforms' in transforms_config.keys():
        transform_list = []

        for _, trf_config in transforms_config['transforms'].items():
            transform = instantiate(trf_config)
            transform_list.append(transform)
        
        transform_compose = T.Compose(transform_list)

    dataset = instantiate(
        dataset_config, 
        transform=transform_compose
    )
    
    return dataset

    # Combine transforms specified in data loader with transforms specified in dataset
    # print(f"\nTransform config : {transforms_config}\n")
    # print(f"\nDataset config : {dataset_config}\n")

    # print(f"\nPre Transforms_config: {transforms_config['pre_transforms']}\n")
    # print(f"\nTransforms_config: {transforms_config['transforms']}\n")

    #transforms = dataset["transforms"] if (("transforms" in dataset) and (dataset["transforms"] is not None)) else []
    #transforms = (pre_transforms or []) + transforms + (post_transforms or [])
    #dataset = instantiate(dataset, transforms=(transforms or None))

def get_data_loader_v2(
        dataset,
        device,
        split_path,  
        split_key,
        sampler_config=None,
        seed=None, 
        is_distributed=False,
        batch_size=2,
        is_graph=False, 
        num_workers=0,    
        **kwargs
):    
    
    # Define the sampler according to sampler_config
    if not seed: 
        split_indices = np.load(split_path, allow_pickle=True)[split_key]
        sampler=instantiate(sampler_config, indices=split_indices)

    else : # if a seed is provided we consider randomness is asked.
        
        generator = torch.Generator(device=device)
        generator.manual_seed(seed)

        split_indices = np.load(split_path, allow_pickle=True)[split_key]
        sampler = instantiate(sampler_config, indices=split_indices, generator=generator, device=device)

    # Ensure we have at least 1 step
    if split_indices.shape[0] < batch_size:
        batch_size = split_indices.shape[0]


    # Wrappe the sampler is case of distributed training
    if is_distributed:
        ngpus = torch.distributed.get_world_size()
        batch_size = max(int(batch_size / ngpus), 1)
        sampler = DistributedSamplerWrapper(sampler=sampler, seed=seed)


    persistent_workers = num_workers > 0    # Better way to do this ? 
    if is_graph: 
        return PyGDataLoader(
            dataset, 
            sampler=sampler,
            num_workers=num_workers,
            persistent_workers=persistent_workers,
            batch_size=batch_size,
            **kwargs
            )
    else:
        return DataLoader(
            dataset, 
            sampler=sampler, 
            persistent_workers=persistent_workers, 
            batch_size=batch_size,
            **kwargs
            )

def get_data_loader(dataset, 
                    batch_size, 
                    sampler_config, 
                    seed,
                    num_workers, 
                    device, 
                    is_distributed,  
                    is_graph=False,
                    pin_memory=False,
                    split_path=None, split_key=None, pre_transforms=None, post_transforms=None, drop_last=False):
    """
    Creates a dataloader given the dataset and sampler configs. The dataset and sampler are instantiated using their
    corresponding configs. If using DistributedDataParallel, the sampler is wrapped using DistributedSamplerWrapper.
    A dataloader is returned after being instantiated using this dataset and sampler.


    Parameters
    ----------
    dataset
        Hydra config specifying dataset object.
    batch_size : int
        Size of the batches that the data loader should return.
    sampler
        Hydra config specifying sampler object.
    num_workers : int
        Number of data loader worker processes to use.
    is_distributed : bool
        Whether running in multiprocessing mode (i.e. DistributedDataParallel)
    seed : int
        Random number used to coordinate samplers in distributed mode.
    is_graph : bool
        A boolean indicating whether the dataset is graph or not, to use PyTorch Geometric data loader if it is graph. False by default.
    split_path
        Path to an npz file containing an array of indices to use as a subset of the full dataset.
    split_key : string
        Name of the array to use in the file specified by split_path.
    pre_transforms : list of string
        List of transforms to apply to the dataset before any transforms specified by the dataset config.
    post_transforms : list of string
        List of transforms to apply to the dataset after any transforms specified by the dataset config.
    
    Returns
    -------
    If is_graph=False in config/task/ 
    torch.utils.data.DataLoader
        dataloader created with instantiated dataset and (possibly wrapped) sampler
     
    If is_graph=True in config/task/
    torch_geometric.loader.DataLoader
        
    """
    # combine transforms specified in data loader with transforms specified in dataset
    transforms = dataset["transforms"] if (("transforms" in dataset) and (dataset["transforms"] is not None)) else []
    transforms = (pre_transforms or []) + transforms + (post_transforms or [])
    dataset = instantiate(dataset, transforms=(transforms or None))


    # Define the sampler according to sampler_config
    if not seed: 
        split_indices = np.load(split_path, allow_pickle=True)[split_key]
        sampler=instantiate(sampler_config, indices=split_indices)

        print('Sequential mode')
    else : # We are in train or validation mode. There is randomness 
        
        generator = torch.Generator(device=device)
        generator.manual_seed(seed)

        split_indices = np.load(split_path, allow_pickle=True)[split_key]
        sampler = instantiate(sampler_config, indices=split_indices, generator=generator, device=device)
        print('Random mode')
    
    # Handle distributed training in case of multi_processing
    # ngpus est déjà connu mais recalculé ici..
    if is_distributed:
        ngpus = torch.distributed.get_world_size()
        batch_size = max(int(batch_size / ngpus), 1)
        sampler = DistributedSamplerWrapper(sampler=sampler, seed=seed)

    # Erwan 25/01 : Add drop_last parameters
    persistent_workers = num_workers > 0
    if is_graph: 
        return PyGDataLoader(
            dataset, 
            sampler=sampler, 
            batch_size=batch_size, 
            num_workers=num_workers, drop_last=drop_last)
    else:
        return DataLoader(
            dataset, 
            sampler=sampler, 
            batch_size=batch_size, 
            num_workers=num_workers, persistent_workers=persistent_workers, pin_memory=pin_memory, drop_last=drop_last)


def get_transformations(transformations, transform_names):
    """
    Returns a list of transformation functions from an object and a list of names of the desired transformations, where
    the object has functions with the given names.

    Parameters
    ----------
    transformations : object containing the transformation functions
    transform_names : list of strings

    Returns
    -------

    """
    if transform_names is not None:
        for transform_name in transform_names:
            assert hasattr(transformations, transform_name), f"Error: There is no defined transform named {transform_name}"
        transform_funcs = [getattr(transformations, transform_name) for transform_name in transform_names]
        return transform_funcs
    else:
        return None

def apply_random_transformations(transforms, data, segmented_labels=None):
    """
    Randomly chooses a set of transformations to apply, from a given list of transformations, then applies those that
    were randomly chosen to the data and returns the transformed data.

    Parameters
    ----------
    transforms : list of callable
        List of transformation functions to apply to the data.
    data : array_like
        Data to transform
    segmented_labels
        Truth data in the same format as data, to also apply the same transformation.

    Returns
    -------
    data
        The transformed data.
    """
    if transforms is not None:
        for transformation in transforms:
            if random.getrandbits(1):
                data = transformation(data)
                if segmented_labels is not None:
                    segmented_labels = transformation(segmented_labels)
    return data

# Deprecated
# def squeeze_and_convert(data_dict, keys, index, to_tensor=False, to_type=torch.float32):
    
#     feature_list = []
#     for key in keys:
#         feature = data_dict[key][index]
#         feature_list.append(feature)
            
#     features = np.transpose(np.squeeze(np.array(feature_list)))
#     if to_tensor:
#         features = torch.from_numpy(features) if len(features.shape) >= 1 else torch.tensor(features)
#         features = features.to(to_type)

#     return features


def match_type(obj_type: str):

    match obj_type:
        case 'int16':
            to_type = torch.int16
        case 'int32':
            to_type = torch.int32
        case 'int64':
            to_type = torch.int64
        case 'float16':
            to_type = torch.float16
        case 'float32':
            to_type = torch.float32
        case 'float64':
            to_type = torch.float64
        case _:
            log.info(f"match_type : Value Error, to_type {to_type} is not supported")
            log.info("Add the data type into the functionn or change the new target type\n\n")
            raise ValueError

    return to_type