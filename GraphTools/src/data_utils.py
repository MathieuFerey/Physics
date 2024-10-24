
import numpy as np
import pprint

import uproot
import torch


class RootInterface:
    """
    Note for future :
    If memory becomes a problem when loading, look at .iterate(step_size) 
    events = uproot.open("https://scikit-hep.org/uproot3/examples/Zmumu.root:events")
    for batch in events.iterate(step_size=500):
        print(repr(batch))
    """

    def __init__(
            self,
            verbose=0,
            entry_start=None, # not used, but kept for future if needed
            entry_stop=None,  # same
        ):

        self.verbose        = verbose

    def extract_data(
            self, 
            file_path,
            tree_name,
            keys: list[str],
            nb_datapoints: int=100_000_000,
        ):
        r"""
        keys: (list) Contains all the keys (train, label, edge..) to lookup into the .root file 
        """
        with uproot.open(file_path) as root_file:

            root_tree   = root_file[tree_name]
            num_entries = min(root_tree.num_entries, nb_datapoints)
            data_dict   = root_tree.arrays(
                keys, 
                library='np', 
                entry_stop=num_entries
            )

            print("")
            print(f"Keys is the root file : \n{root_tree.keys()}\n")
            print(f"Type of each key : \n{root_tree.typenames()}\n")

        # --- Display additionnal informations --- #
        if self.verbose >= 1:
            
            for key, value in data_dict.items():
                print(f"\n[RootInterface] Key : {key}")
                #print(f"   Value (shape) : {value.shape}")
                
                if isinstance(value, np.ndarray):
                    print(f"   Value is a np.ndarray.\n   Value[0].shape : {value[0].shape}")

        print("")
        return num_entries, data_dict    

class ExtremaFinder:
    r"""

    Class for finding the extrema values of a set of tensors
    The keywords used at initialization must be the same ones called in compute_extrema. 

    Args:
        *args: List of keys whom values to monitor in a dictionnary. 
        Values are expected to be 1-d array each 
    """
    
    def __init__(
            self,
            *args
    ):

        self.all_extrema = {}

        # Initialiaze the dictionnary with the min / max values
        for key in args:
            self.all_extrema[key] = False
    
        # --- Display info --- #
        print("Extrema dictionnary config :")
        pprint.pprint(self.all_extrema)


    def update(self, key, data) -> None:
        """
        Compares extrema values of features between the previous events and the current one.
        """
        if isinstance(data, torch.Tensor):
            print("Input is a torch.Tensor. This format is currently not supported")
            print("The only supported format for now is np.ndarray.")
            raise TypeError

        # Get the min and max from the data
        x_min, x_max = np.min(data), np.max(data)
        
        # Compare to the current min and max
        if not self.all_extrema[key]:
            self.all_extrema[key] = [x_min, x_max]
        else:
            self.all_extrema[key][0] = min(x_min, self.all_extrema[key][0])
            self.all_extrema[key][1] = max(x_max, self.all_extrema[key][1])


    def print_extrema(self):
        """
        Prints extrema values for the keys.
        """
        print(f'KEYS EXTREMA:')
        for key, value in self.all_extrema.items():    
            print(f"\t{key}:")
            print(f"\t \tMinimum: {value[0]:.2f}")
            print(f"\t \tMaximum: {value[1]:.2f}")


def convert_from_keys(data_dict, keys, index, to_tensor=False, to_types=None):
    
    feature_list = []
    for key, to_type in zip(keys, to_types):
        feature = data_dict[key][index]

        if to_tensor:
            # Get the torch type
            to_type = match_type(to_type) 

            # Convert the numpy array to a torch tensor with the asked format
            if not isinstance(feature, np.ndarray): # Some ValueError raised when dealing with np.uint8 otherwise
                feature = np.array(feature)
            feature = torch.from_numpy(feature).to(to_type)
        
        feature_list.append(feature)

    # In the case of > 1 feature, transpose is needed to store as (node, features) in the Data object
    if feature_list[0].size() == ():
        features = torch.stack(feature_list, dim=0)
    else:
        features = torch.transpose(torch.stack(feature_list, dim=0), 1, 0)

    return features

def match_type(to_type: str):

    match to_type:
        case 'int16':
            torch_type = torch.int16
        case 'int32':
            torch_type = torch.int32
        case 'float16':
            torch_type = torch.float16
        case 'float32':
            torch_type = torch.float32
        case 'float64':
            torch_type = torch.float64
        case _:
            print(f"Value Error, to_type {to_type} is not supported")
            print("Add the data type into the transform or change the new target type")
            raise ValueError
        
    return torch_type
