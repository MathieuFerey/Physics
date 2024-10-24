import os
import logging
import matplotlib.pyplot as plt
import seaborn as sns
import wandb


def plot_features(data, feature_label, graph_folder_path, figsize=(10, 6)):
    
    nb_feat = data.shape[1] if len(data.shape) == 2 else 1
    for feature_index in range(nb_feat):
        try:
            plt.figure(figsize=figsize)
            plt.xlabel(f"{feature_label}_{feature_index}")
            if len(data.shape) == 2: # data is a multi-dim array
                sns.histplot(data[:, feature_index], kde=True)
            else: # data just contains one element
                sns.displot(data)


            fig_path = os.path.join(graph_folder_path, f'{feature_label}_{feature_index}.png')
            plt.savefig(fig_path, dpi=300)
            plt.close()
            wandb.save(fig_path)


        except Exception as e:
            logging.error(f"Error plotting {feature_label}_{feature_index}: {e}")


def plot_dataset_summary(dataset, graph_folder_path: str):

    # Statistics about the dataset
    summary_string = str(dataset.get_summary())

    # Save the string to a text file
    path = os.path.join(graph_folder_path, 'dataset_summary.txt')

    with open(path, "w") as file:
        file.write(summary_string)

    # Log this file as an artifact
    artifact = wandb.Artifact('dataset_summary', type='result')
    artifact.add_file(path)
    wandb.log_artifact(artifact)