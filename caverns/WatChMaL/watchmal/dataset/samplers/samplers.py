"""
Sampler classes
"""

# torch imports
import torch
from torch.utils.data import Dataset, Sampler
from torch.utils.data.distributed import DistributedSampler

# generic imports
from operator import itemgetter
from typing import Optional

from typing import Iterator, Optional, Sized, Sequence


# def SubsetSequentialSampler(indices):
#     return indices


class SubsetSequentialSampler(Sampler[int]):
    r"""Samples elements sequentially, always in the same order.

    Args:
        indices (sequence): a sequence to sample (sequentially) from
    """

    def __init__(self, indices: Sequence[int]) -> None:
        self.indices = indices

    def __iter__(self) -> Iterator[int]:
        for i in self.indices:
            yield i

    def __len__(self) -> int:
        return len(self.indices)


class SubsetRandomSampler(Sampler[int]):
    r"""Samples elements randomly from a given list of indices, without replacement.
        Updated class of torch to handle 'device=cuda:x' (throw error with torch.randomper otherwise)
    Args:
        indices (sequence): a sequence of indices
        generator (Generator): Generator used in sampling.
        device (string) : device to perform the sampling 
    """

    indices: Sequence[int]

    def __init__(self, indices: Sequence[int], generator=None, device=None) -> None:
        self.indices = indices
        self.generator = generator
        self.device = device # Add, to indicate the device to torch.randperm

    def __iter__(self) -> Iterator[int]:
        for i in torch.randperm(len(self.indices), generator=self.generator, device=self.device):
            yield self.indices[i]

    def __len__(self) -> int:
        return len(self.indices)


class DistributedSamplerWrapper(DistributedSampler):
    """
    Wrapper for making general samplers compatible with multiprocessing.

    Allows you to use any sampler in distributed mode when training with 
    torch.nn.parallel.DistributedDataParallel. In such case, each process 
    can pass a DistributedSamplerWrapper instance as a DataLoader sampler, 
    and load a subset of subsampled data of the original dataset that is 
    exclusive to it.
    """

    def __init__(
        self,
        sampler,
        seed,
        num_replicas: Optional[int] = None,
        rank: Optional[int] = None,
        shuffle: bool = False,
        **kwargs
    ):
        """
        Initialises a sampler that wraps some other sampler for use with DistributedDataParallel

        Parameters
        ==========
        sampler
            The sampler used for subsampling.
        num_replicas : int, optional
            Number of processes participating in distributed training.
        rank : int, optional
            Rank of the current process within ``num_replicas``.
        shuffle : bool, optional
            If true sampler will shuffle the indices, false by default.
        """
        super().__init__(
            list(sampler),
            num_replicas=num_replicas,
            rank=rank,
            shuffle=shuffle,
            seed=seed, 
            **kwargs,
        )
        self.sampler = sampler

    def __iter__(self):

        # fetch DistributedSampler indices
        indexes_of_indexes = super().__iter__()
        
        # fetch subsampler indices with synchronized seeding
        subsampler_indices = list(self.sampler)
        
        # get subsampler_indexes[indexes_of_indexes]
        distributed_subsampler_indices = itemgetter(*indexes_of_indexes)(subsampler_indices)

        # Erwan : added it otherwise problem when testing with batch_size of 1 on each gpu
        if not isinstance(distributed_subsampler_indices, tuple): 
            distributed_subsampler_indices = distributed_subsampler_indices,
    
        return iter(distributed_subsampler_indices)
