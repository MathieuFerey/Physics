
import numpy as np
import uproot


class RootDataset:

    def __init__(
            self,
            root_file_path,
            tree_name,
            verbose=0,
            **kwargs
        ):
        
        self.root_file_path = root_file_path
        self.tree_name      = tree_name
        self.verbose        = verbose


    def extract_data(self, keys):
        r"""
        keys: (list) Contains all the keys (train, label, edge..) to lookup into the .root file 
        """
        with uproot.open(self.root_file_path) as root_file:

            root_tree   = root_file[self.tree_name]
            num_entries = root_tree.num_entries
            data_dict   = root_tree.arrays(keys, library='np')


        if self.verbose >= 1:
            print(f"Extracting keys from the .root file")
            for key, value in data_dict.items():
                print(f"\nLooking at key : {key} \n")
                print(f"   Value (shape) : {value.shape} ")
                if isinstance(value, np.ndarray):
                    print(f"   Value is a np.ndarray. value[0].shape : {value[0].shape}")

        return num_entries, data_dict
    