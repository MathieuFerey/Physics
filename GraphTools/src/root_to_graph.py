
# generic imports
import os.path as osp
import numpy as np
import torch

# pyg imports
import torch_geometric.transforms as T

from torch_geometric.data import InMemoryDataset, Data
from torch_geometric.transforms import KNNGraph

# WCSimPackage imports
import src.data_utils as du
from src.data_utils import RootInterface, ExtremaFinder



class RootToGraph(RootInterface, InMemoryDataset):
    r"""" 
    This class purpose is only to convert .root files
    to graphs and them save as a "big" Data as a .pt (.pytorch)

    This is __NOT__ intended to process already existing .pt

    Args:
            root_folder_path: str
                path to the existing .root file
            graph_folder_path: str 
                Root directory where the dataset should be saved.
            tree_name: str
                name of the tree to convert in the .root file
            nb_datapoints : int
                number of datapoint, if none define to 5 000 000 
            train_keys : list
                variables in the dataset that will be used as features during training
            label_keys : list
                variables in the dataset that will be used as labels during training
            edge_keys : list
                variables in the dataset that will be used to compute edges in the graph representation of the data
            to_torch_tensor : bool
               Specifies whether to convert data to PyTorch tensors (True) or not (False)
            verbose: int  [0 ou 1]
                Degree of information printed during the traitement of the .root
            pre_filter (Optional) : (list of) function 
                Apply filters to the data before doing any pre_processing
            pre_transform (Optional) : (list of) function
                pre_transform argument from torch_geometric InMemoryDataset class
                Will be used to compute the edges of the graph
            transform (Optional): function
                transform argument from torch_geometric InMemoryDataset class
    """

    def __init__(
            self, 
            graph_folder_path : str,
            graph_file_names : list=[''],
            nb_datapoints : int=None,
            root_folder_path : str='',
            root_file_names: list=[''],
            tree_name : str='',
            train_data_info: dict=None,
            label_data_info: dict=None,
            edge_data_info: dict=None,
            to_torch_tensor : bool = True,
            verbose : int = 0,
            pre_filter = None,
            pre_transform = None, 
    ):

        self.verbose = verbose

        # Variables to get the root file
        self.root_folder_path  = root_folder_path
        self.root_file_names   = root_file_names 
        self.tree_name         = tree_name

        # Where to look for / save the data
        self.graph_folder_path = graph_folder_path
        self.graph_file_names  = graph_file_names
        
        # What to apply to the data
        self.to_torch_tensor  = to_torch_tensor
        self.pre_filter    = pre_filter
        self.pre_transform = pre_transform

        # All the variables in the if below are used only by self.process()
        self.nb_datapoints = nb_datapoints    

        # Check how many events to store
        if nb_datapoints is not None  : 
            self.nb_datapoints = nb_datapoints
        else :
            self.nb_datapoints = 100_000_000 # Number of events never reached

        self.train_keys, self.train_types = train_data_info['keys'], train_data_info['types']
        self.label_keys, self.label_types = label_data_info['keys'], label_data_info['types']
        self.edge_keys, self.edge_types   = edge_data_info['keys'], edge_data_info['types']

        # We consider only kNN as a possible pre_transform for now
        if self.pre_transform is not None:
            pre_transform_list = [KNNGraph(**self.pre_transform['kNN'])]
            self.pre_transform = T.Compose(pre_transform_list)
        

        # Est-ce que cette classe est vraiment utile ? 
        # ou une méthode / une simple instantiation 
        # self.root_interface = RootInterface()
        # sans héritage est suffisant ?    
                    
        RootInterface.__init__(
            self,
            verbose=self.verbose,
        )

        # This will execute self.process(), so all variables called there need to be defined before
        InMemoryDataset.__init__(
            self,
            root=self.graph_folder_path, 
            pre_filter=self.pre_filter,
            pre_transform=self.pre_transform, # Pre transform is applied to the data only once, before creating the grah
        )

        # --- Load the big Data.pt in self.data ---
        self.load(self.processed_paths[0])
        
        # --- Display info --- #
        print(f"\nProcessed path     : {self.processed_paths}")
        print(f"Pre_transform :  {self.pre_transform}")
        print(f"Len of the dataset : {self.len()}")
        if root_folder_path:
            print(f"From .root files   : {self.raw_file_names}")   



    @property
    def raw_file_names(self):
        #returns : [self.root_folder_path + '/' + root_file_name for root_file_name in self.root_file_names]
        return self.root_file_names

    @property
    def processed_file_names(self):
        # Where the graph data will be looked at
        # If self.processed_paths + self.processed_file_names is empty, self.process() will be called.
        return self.graph_file_names

    def process(self):

        data_list = [] 
        all_keys = self.train_keys + self.label_keys + self.edge_keys
       
        # Class to monitor extrema of the data
        extrema_monitor = ExtremaFinder(*all_keys)

        for i, root_file_name in enumerate(self.root_file_names):

            if self.verbose >= 1:
                print(f"\nFichier root : {i}")
                print(f"From : {self.root_folder_path + '/' + root_file_name}")

            # Get the data from the current .root file
            num_entries, data_dict = self.extract_data(
                file_path=self.root_folder_path + '/' + root_file_name,
                tree_name=self.tree_name,
                keys=all_keys,
                nb_datapoints=self.nb_datapoints
                ) # returns (number_of_events, dictionnary)
            
            # Awkward array format makes complex the use of
            # np.min directly on data_dict (even flattening is not trivial)
            # so we chose to compute the maxs / mins while iterating (see below)
            for j in range(num_entries):

                # Monitor extrema while they are numpy arrays
                for key in all_keys:
                    extrema_monitor.update(key, data_dict[key][j])
            
                # Extract train, label and edge data and convert to torch.Tensor
                x   = du.convert_from_keys(data_dict, index=j, keys=self.train_keys, to_types=self.train_types, to_tensor=self.to_torch_tensor)
                y   = du.convert_from_keys(data_dict, index=j, keys=self.label_keys, to_types=self.label_types, to_tensor=self.to_torch_tensor)
                pos = du.convert_from_keys(data_dict, index=j, keys=self.edge_keys, to_types=self.edge_types, to_tensor=self.to_torch_tensor)
                
                graph = Data(x=x, y=y, pos=pos) # for .pos see torch_geometric.transforms.KNNGraph 
                data_list.append(graph)

                # --- Display --- #
                if self.verbose >= 1:
                    if j % int(num_entries / 2) == 0 :
                        print(f"Évènement numéro {j}")
                        print(graph)

        if self.pre_filter is not None:
            # data_list = [data for data in data_list if self.pre_filter(data)]
            pass 
        
        if self.pre_transform is not None:
            print("Computing pre_transform")
            data_list = [self.pre_transform(data) for data in data_list]

        # --- Display --- #
        extrema_monitor.print_extrema()
        print(f"\nLen of data_list : {len(data_list)}")
        
        # --- Saving --- #
        self.save(data_list, self.processed_paths[0])
