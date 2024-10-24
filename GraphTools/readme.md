# Graph In-Memory Dataset

## Description

This Python package facilitates the conversion of data from a .root file into a graph dataset stored in memory. It's particularly useful for processing data in the high-energy physics domain.

## Installation

To download the repository use : 

```
git clone https://github.com/Erwanlbv/WCSimPackage/GraphDatasets.git
```

## Usage
From within the /WCSimPackage/GraphDatasets repository, run ``main.py`` in Python 3. Use ``-c`` to indicates the config system you want to use : 

```
python main.py -c <config_name>.yaml
```

## Configuration 
To create your configuration create a YAML file where you specify all parameters necessary for the conversion of the .root in a graph.
Example of a config : 

```
root_file_path: <root_path>
tree_name: <tree_name>

graph_dataset_path: <path_saving_direction>
train_keys: ['train_key1', 'train_key2', 'train_key3', 'train_key4']
label_keys: ['label1']
edge_keys: ['edge_key1', 'edge_key2', 'edge_key3']
to_torch_tensor: True

verbose: 1
```
#### Warning : If any transform argument is needed, it should NOT be passed here but at run time inside CAVERNS configuration files.

## Execution
In order the information returned during the execution of the code are : 
1. your configuration dictionary
2. indication that you have no graph present in <path_saving_direction>. If not, it means that your path already contain a graph
3. the .root file used for the graph creation
4. all the keys extracted from your .root file with : 
    - number of event 
    - shape of the key values for one event (example: (2739,) for PMTs hits and a scalar () for the type of event 0 or 1)
5. if you choose `verbose : 1`, shape of each tensor forming your train, edge and label keys will be printed for few events 
6. finally the minimum and maximum values will be printed for each sub keys in your train, edge and data keys. You can change which keys extrema (only training keys for example) are printed by modifying in /WCSimPackage/GraphDatasets/src/graph_in_memory_dataset.py the declaration of ExtremaFinder and compute_extrema method with the desired keys