
# basic imports 
import argparse
import yaml
import pprint

# monitoring import
import wandb
import matplotlib.pyplot as plt
import seaborn as sns

# GraphDataset imports
from src.root_to_graph import RootToGraph
from src.vis_utils import plot_dataset_summary, plot_features

def main(config_path):
    
    with open(config_path, 'r') as pre_config:
        config = yaml.safe_load(pre_config)
        
    wandb_config = config.pop('wandb') if 'wandb' in config.keys() else None

    if wandb_config is not None:

        wandb.init(**wandb_config, config=config)
        wandb.save(config_path)

    # Print the config and start processing the root files
    pprint.pprint(config)
    dataset = RootToGraph(**config)
    
    if wandb_config is not None:


        # Number of events in the dataset
        wandb.log({'len': dataset.len()})

        # Dataset summary
        plot_dataset_summary(dataset, config['graph_folder_path'])

        # Distributions of the variables
        for key in ['x', 'y', 'pos']:
            if key in dataset[0]:
                att = getattr(dataset, key)
                plot_features(
                    data=att, 
                    feature_label=key, 
                    graph_folder_path=config['graph_folder_path']
                )

        wandb.finish()


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Set the global configuration for the conversion")

    # Add the arguments
    parser.add_argument('-c', '--config_path', type=str, 
                        help='The path to the file to process.')

    args = parser.parse_args()

    print(f"\nProcessing file at: {args.config_path}") 

    main(args.config_path)