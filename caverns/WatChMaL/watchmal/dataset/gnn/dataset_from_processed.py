
# generic imports
import sys
import os.path as osp
import logging

# torch imports 
import torch

# pyg imports
from torch_geometric.data import InMemoryDataset
from torch_geometric.transforms import KNNGraph

# watchmal imports
from watchmal.utils.logging_utils import setup_logging

log = setup_logging(__name__)

"""
Notes :
    About the graph creation from an event : decision NOT TO USE the pre_transform
    parameter existing in the InMemoryDataset class of torch_geometric because 
        1. The name would not be explicit
        2. Is it supposed to be a list of functions to apply to the data points 
            before turning them into a graph. So it should not changes the nature 
            of the data. Or creating a graph changes the nature of the data.
        3. There should be only one function to call to create a graph, so a list
            of function is not adapted.
"""


class DatasetFromProcessed(InMemoryDataset):
    r"""" 
    This class is it never supposed to see .root files  
    It can :
        - load graphs from a .pt
        - compute edges using self.compute_edges()
    And a transform argument can be passed at initialization.
    
    If compute_edges() is called, self._data will be changed (not self.data)
    and self._data_list will set to None.
    These modifications will only live inside the class (so 'locally'), 
    not flushed on the disk.

    Args:
            graph_folder_path: str 
                Root directory where the dataset should be saved.
            graph_file_names: str
                Names of the .pt files
            nb_datapoints : int # À FAIRE
                Number of datapoints to keep from the original dataset.
            verbose: int  [0 ou 1]
                Degree of information printed during the traitement of the .root
            transform (Optional): (list of) function
                transform argument from torch_geometric InMemoryDataset class
    """

    def __init__(
            self, 
            graph_folder_path : str,
            graph_file_names : list=[''],
            transform = None,
            verbose : int = 0,
            transforms= None  # Do not use. Only for compatibility with watchmal. In discussion with Nick to solve this redundancy.
    ):

        self.verbose = verbose

        # Where to look for the data
        self.graph_folder_path = graph_folder_path
        self.graph_file_names  = graph_file_names

        # What to apply to the data
        self.transform       = transform

        # Load the pre_transform argument
        f = self.graph_folder_path + '/processed/pre_transform.pt'
        log.info(f"Looking for pre_transform.pt at : {f}")
        if not osp.exists(f):
            log.info(f"No pre_transform.pt found")
            self.pre_transform = None
        else :
            log.info(f"Found a pre_transorm.pt")
            self.pre_transform = torch.load(f)

        super().__init__(
            root=self.graph_folder_path, 
            pre_transform=self.pre_transform,
            transform=self.transform,          # composition of transforms argument should go there. (Équivalent to torchvision "transformCompose class")
        )

        # --- Load big Data into the RAM --- # 
        self.load(self.processed_paths[0])
        
        # --- Display info --- #
        print("")
        log.info(f"Processed path     : {self.processed_paths}")
        log.info(f"Pre_transform      :  {self.pre_transform}")
        log.info(f"Len of the dataset : {self.len()}")  


    @property
    def raw_file_names(self):
        # The fact that it points to existing file doesn't matter for torch_geometric
        #[self.root_folder_path + '/' + root_file_name for root_file_name in self.root_file_names]
        return self.root_file_names

    @property
    def processed_file_names(self):
        # if called it returns self.processed_path[0] + what is returned here
        return self.graph_file_names

    def compute_edges(self, k: int, num_workers: int = 1, cosine: bool = False):

        # Set kNN
        pre_transform = KNNGraph(k=k, num_workers=num_workers, cosine=cosine)

        if self.verbose >= 1:
            print()
            log.info(f"Starting to compute edges..")

        for idx, data in enumerate(self):

            if isinstance(data, dict): # Check in case a transform argument has been passed
                data = data['data']

            new_data = pre_transform(data)
            self._data_list[idx] = new_data

        if self.verbose >= 1:
            log.info(f"Finished.")
            log.info(f"Size of data_list (in MB) : {sys.getsizeof(self._data_list)}")

        self._data, self.slices = self.collate(self._data_list)
        self._data_list = None 

    def get(self, idx):
        # Caution : 
        # The pipeline for get is : (starting at the loader)
        # getitem (Dataset) -> get (this class) 
        # If you can super().get() in this class, it's the one from
        # InMemoryDataset, where the big Data is sliced in Data cached in _data_list.
        # then Dataset gets this data, and apply transform.

        # Conclusion : If transform is given in __init__(),
        # this data object will NOT have already be transformed.
        # (See torch_geometric.Data.Dataset.__getitem__() l.292 - 293)

        data = super().get(idx)
        data.idx = idx # for watchmal compatibility

        return data

    def map_labels(in_label, label_set):
        """
        Maps the labels of the dataset into a range of integers from 0 up to N-1, where N is the number of unique labels
        in the provided label set.

        Parameters
        ----------
        label_set: sequence of labels
            Set of all possible labels to map onto the range of integers from 0 to N-1, where N is the number of unique
            labels.
        """
        # This method is for watchmal compatibility
        # This kind of conversion is not currently supported
        # But it will need ot in the future
        # Conversions can be done with one line using label_set.index(PID) i think.
        # Pay attention to the compatibility with the engine
        pass 