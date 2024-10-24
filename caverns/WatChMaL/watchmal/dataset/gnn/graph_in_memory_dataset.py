import numpy as np
import uproot

import torch
from torch_geometric.data import InMemoryDataset, Data

# Watchmal imports
from watchmal.dataset.common_classes.root_dataset import RootDataset

import watchmal.dataset.data_utils as du
from watchmal.dataset.gnn import transformations

# imports when NOT using watchmal
# from Datasets.utils import squeeze_and_convert


# À FAIRE :
 
# 30/01 : - DONE Modifier le nom pre_transform en quelque chose de plus explicite.
#         - Expliquer le but des variables pre_filter, transforms, pre_transforms [les nouvelles..]
# 
# 01/01 : - DONE Nettoyer les commentaires et les prints, 

# 11/02 : - DONE Stocker des données au format torch.tensor directement pour éviter d'avoir à gérer 
#                la conversion à chaque appel. (Optimisation mémoire / efficacité)
# 14/02 : - Mettre à jour la doc de graphInMemoryDataset_v2


class GraphInMemoryDataset(RootDataset, InMemoryDataset):
    r"""" Last update of this documentation : 25/01/2024    
    Args :
        graph_dataset_path: string
            Location of the .pt of PROCESSED graphs
        beta_mode: bool
            Indicates if the dataset is in debug mode (max verbose)
        pre_transform: function
            Function to execute to create a graph from a root event
    
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

    def __init__(
            self, 
            config=None, 
            pre_filter=None,
            pre_transform=None,
            transform=None, 
            force_reload=False,
            transforms=None # For compatibility with watchmal. In discussion with Nick to solve this redundancy.
    ):
    
        # General variables
        self.config    = config

        self.split_path = config['split_path']
        # if "nb_beta_mode_datapoints" in self.config:
        #     self.beta_mode = True
        #     self.nb_beta_mode_datapoints = self.config['nb_beta_mode_datapoints']
        # else :
        #     self.beta_mode = False

        try : 
            self.nb_datapoints = self.config['nb_datapoints']
        except :
            self.nb_datapoints = 1_000_000 # Number of event never reached    
        self.verbose = config["verbose"] 

        # Variable to create the graphs
        self.graph_init = False

        # Get the function to compute the edge_index from the point cloud
        #self.compute_edge_index = config["compute_edge_index"]


        ### --- Not a clean way to call the __init__ of parents classes, but 
        ### --- still it seems the most comprehensible way for everyone to me

        # Instantiate the RootDataset class (to read the .root file)
        RootDataset.__init__(
            self,
            root_file_path=config['root_file_path'],
            tree_name=config['tree_name'],
            verbose=self.verbose
        )

        # Instantiate the PyG Dataset class
        # MUST BE AT THE END OF THE __INIT__ (JUST BEFORE THE self.load)
        InMemoryDataset.__init__(
            self,
            root=config["graph_dataset_path"], 
            pre_filter=pre_filter,
            pre_transform=pre_transform, # Pre transform is applied to the data only once, before creating the grah
            transform=transform # composition of transforms argument should go there. (Équivalent to torchvision "transformCompose class")
        )

        # Check if there is data in graph_dataset_path
        self.load(self.processed_paths[0])


    @property
    def raw_file_names(self):
        return self.root_file_path

    @property
    def processed_file_names(self):
        return ['data.pt']


    def graph_initialize(self, config):
        """
        Method to initialize variables associated to the creation of a graph given a .root file.
        I. e. the values uproot is going to look for.
        This method should belong to the RootDataset class (à faire)
        """
        self.train_keys   = config['train_keys']
        self.label_keys   = config['label_keys']
        self.edge_keys    = config['edge_keys']

        self.to_torch_tensor     = config['to_torch_tensor']
        self.graph_init = True


    def process(self):
        # If process() is called it means that path_to_gnn_dataset is empty
        print(f"No graphs found in the path : {self.config['graph_dataset_path']}.")
        print(f"Creating a dataset from the .root file : {self.config['root_file_path']}")
        
        if not self.graph_init:
            self.graph_initialize(self.config)
    
        if self.pre_filter is not None:
            pass 
            # Exemple : data_list = [data for data in data_list if self.pre_filter(data)]

        # Get the data from the .root file
        all_keys = self.train_keys + self.label_keys + self.edge_keys
        num_entries, data_dict = self.extract_data(all_keys) # returns (number_of_events, a dict with all the data)
        
        data_list = [] 
        for i in range(num_entries):
            x   = du.squeeze_and_convert(data_dict, self.train_keys, index=i, to_tensor=True, to_type=torch.float32)
            y   = du.squeeze_and_convert(data_dict, self.label_keys, index=i, to_tensor=True, to_type=torch.float32)
            pos = du.squeeze_and_convert(data_dict, self.edge_keys, index=i, to_tensor=True, to_type=torch.float32)

            graph = Data(x=x, y=y, pos=pos) # for .pos see torch_geometric.transforms.KNNGraph 
            data_list.append(graph)


            if self.verbose >= 1:
                if i % ( int((num_entries / 2)) - 1) == 0 :
                    print(f"\nÉvènement numéro {i}")
                    print(graph)
    
            if (i + 1) % self.nb_datapoints  == 0 :
                break

        if self.pre_transform is not None:
            data_list = [self.pre_transform(data) for data in data_list]

        self.save(data_list, self.processed_paths[0])


    def get(self, idx):
        """
        Linear layers need torch tensor as input, not ndarray

        This overcharge of the get method convert numpy arrays (the type of .x, .edge_index and .y) to torchTensors if they are not already torch tensors
        Note : Most of the loss of torch expect a float format, so even if the labels are stored as int, they will be converted to float when called.
        """

        # Caution : If transform functions are given in __init__(), this data object will NOT
        # have already be transformed. See the torch_geometric.Data.Dataset.__get_item__ 
        data = super().get(idx)
        data.idx = idx

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
        pass # Conversion can be done with one line using label_set.index(PID).
        # But the Dataset class needs to have this method for watchmal compatibility
        # See how to modify this in the future
        
    def add_data_information(self):
        print("Fonction to call if you want to add information on each Data object (i. e. each graph) in the data_list")
        print('You have to define this function in your child class')
        raise NotImplementedError

    
# Remarque : Si on souhaite transformer les données il faut créer une fonction transform
# et la passer en paramètre au début
# (Ou surcharger la fonction get de InMemoryDataset)


