
# basic imports
import os 
import numpy as np
import wandb

# utils imports
import scipy.special as special
import sklearn.metrics as metrics

# display imports
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt




def roc_curve(wandb_run, data, targets, signal_key, folder_path, log_scale=False, plot_name='roc_curve', figsize=(10, 6)):
    """
    data (dataFrame) : contains all the model outputs for each class
    apply_softmax_on (list[str]) : list of columns of data on which to apply the softmax 
    signal_axis (int) : which index in apply_softmax_on should be considered as the signal

    folder_path (str) : Folder where to save the figure
    plot_name   (str) : Name to give to the plot when saving at folder_path & logging in wandb

    """

    # Defining usefull variables 
    preds = data[signal_key]
    #label_names = np.unique(data['target_names'])

    # Compute roc curves values
    fpr, tpr, _ = metrics.roc_curve(targets, preds)
    roc_auc = metrics.auc(fpr, tpr)

    # Plots
    fig, ax = plt.subplots(figsize=figsize)
    if log_scale:
        # Handling of 0 values if any
        # PROBLÈME : POURQUOI EST-CE QUE LE DEBUG COMMENT A 10e^-10 .?
        # À GÉRER (PLUS TARD)
        fpr = np.where(tpr <= 0, 1e-8, fpr)
        tpr = np.where(tpr <= 0, 1e-8, tpr)

        ax.set_xscale('log')
        ax.set_yscale('log')


    sub_data = pd.DataFrame({'fpr': fpr, 'tpr': tpr})
    ax = sns.lineplot(sub_data, x='fpr', y='tpr', label=f"AUC : {roc_auc}")
    #ax.plot(fpr, tpr, linewidth=1.5, label=f'AUC : {roc_auc}')

    # Increase appearence 
    plt.title(f"ROC for {signal_key[-2:]} as signal")
    
    ax.set_xlim([1e-10, 100])  # Extend x-limits
    ax.set_ylim([1e-10, 100])
    ax.grid(True, which="both")

    # plt.xlabel('False Positive Rate')
    # plt.ylabel('True Positive Rate')
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run is not None:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})

def p_r_curve(wandb_run, data, targets, signal_key, folder_path, log_scale=False, plot_name='p_r_curve', figsize=(10, 6)):
    """
    preds   (array) (n_samples, ) : 1-d array of the predictions
    targets (array) (n_samples, ) : 1-d array of the targets

    folder_path (str) : Folder where to save the figure
    plot_name   (str) : Name to give to the plot when saving at folder_path & logging in wandb

    """
    # Softmax the raw_predicitons + take only the "signal" inputs
    preds = data[signal_key]

    precision, recall, _ = metrics.precision_recall_curve(targets, preds)
    average_precision_score = metrics.average_precision_score(targets, preds)

    # Plot
    fig, ax = plt.subplots(figsize=figsize) 
    if log_scale:
        precision = np.where(precision <= 0, 1e-8, precision)
        recall    = np.where(recall <= 0, 1e-8, recall) 

        ax.set_xscale('log')
        ax.set_yscale('log')

    # Plot
    ax.plot(recall, precision, linewidth=2, label=f'AP : {average_precision_score}')

    # Increase appearence of the plot 
    plt.title(f"Precision - Recall for {signal_key[-2:]} as signal")
    
    ax.set_xlim([1e-10, 100])  # Extend limits
    ax.set_ylim([1e-10, 100])
    ax.grid(True, which="both")

    plt.xlabel('Recall')
    plt.ylabel('Precision')
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run is not None:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})

def confusion_matrix(wandb_run, data, targets, signal_key, folder_path, plot_name, threshold=None, label_names=None, figsize=(10, 6)):

    preds = data[signal_key]

    if threshold is None:
        threshold = 0.5
    
    pred_classes = preds >= threshold
    cm = metrics.confusion_matrix(targets, pred_classes)
    
    df_cm = pd.DataFrame(
        cm,
        index=[i for i in label_names],
        columns=[c for c in label_names]
    )

    # Plot
    fig, ax = plt.subplots(figsize=figsize)
    sns.heatmap(df_cm, ax=ax, annot=True, linewidths=0.8)

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run is not None:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})

def scatplot_2d(wandb_run, data, x, y, folder_path, plot_name='2d_scatplot', figsize=(10, 6)):
    """
    preds   (n_samples, 2) # For binary classification. Can be extended to more if wanted but you'll have to change the code
    targets (n_samples, )
    """

    fig, ax = plt.subplots(figsize=figsize) 
    ax = sns.scatterplot(data=data, x=x, y=y, hue='target_names', s=10, ax=ax)

    # Increase apperance
    plt.title('Model output with true labels')
    #plt.xlabel('1st dimension')
    #plt.ylabel('2nd dimension')
    plt.grid(True)
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})

def histogram_2d(
        wandb_run, 
        data, 
        x, 
        y,
        folder_path, 
        plot_name, 
        log_scale=(False, False), 
        figsize=(10, 6)
    ):

    fig, ax = plt.subplots(figsize=figsize)

    # Plot
    ax = sns.histplot(data, x=x, y=y, hue="target_names", log_scale=log_scale, cbar=True, ax=ax)

    plt.title("Model 2d output with true labels")
    plt.grid(True)
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})

def combined_histograms_plot(
        wandb_run, 
        data, 
        folder_path, 
        plot_name, 
        log_yscale=False, 
        fill=True,
        element='bars',
        figsize=(10, 6)):

    fig, ax = plt.subplots(figsize=figsize)

    # Plot
    for col in data.columns:
        label = str(col)  
        ax = sns.histplot(data[col], label=label, fill=fill, element=element, ax=ax)

    # Increase apperance
    if log_yscale:
        ax.set_yscale('log')

    plt.title("Empirical distributions of over model's outputs")
    plt.grid(True)
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})


def preds_targets_histogram(
        wandb_run, 
        preds, 
        targets,
        folder_path, 
        plot_name, 
        target_name,
        log_yscale=False, 
        fill=True,
        element='bars', 
        figsize=(10, 6)
    ):
    fig, ax = plt.subplots(figsize=figsize)

    # Plot   
    ax = sns.histplot(preds, label='model out', fill=fill, element=element, ax=ax)
    ax = sns.histplot(targets, label='targets', fill=fill, element=element, ax=ax)

    # Increase apperance
    if log_yscale:
        ax.set_yscale('log')

    plt.title(f"Model outputs vs targets for {target_name}")
    plt.grid(True)
    plt.legend()

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})



def count_plot(
    wandb_run,
    data,
    folder_path,
    plot_name,
    figsize=(10, 6)
):
    fig, ax = plt.subplots(figsize=figsize)

    # Plot
    sns.countplot(data, ax=ax)

    # Save the figure
    plt.savefig(f"{folder_path}/{plot_name}.png", dpi=300)
    plt.close(fig)

    # Reopen the image and log to wandb
    if wandb_run:
        image = plt.imread(f"{folder_path}/{plot_name}.png")
        wandb_run.log({plot_name: wandb.Image(image)})
    
    


""" Archive """

def wandb_roc_curve(wandb_run, targets, preds, softmax=False, labels=None, plot_name="roc_curve"):
    """
    The plot_name represents the id of the roc curve on wandb. Do NOT change it
    over the runs.
    """
    # Love ListConfig (cannot call label[np.int64] when label is a ListConfig)
    # convert & reshape to right type for wandb

    print(preds, targets)
    if not softmax:
        preds = special.softmax(preds, axis=1)

    print(preds.shape)
    print(preds)
    print(targets)

    rc_curve = wandb.plot.roc_curve(targets, preds, labels=labels)
    wandb_run.log({plot_name: rc_curve})

def wandb_p_r_curve(wandb_run, targets, preds, labels=None, plot_name="pr_curve"):
    """
    The plot_name represents the id of the precision-recall curve on wandb. Do NOT change it
    over the runs.
    """

    pr_curve = wandb.plot.pr_curve(targets, preds, labels=labels)
    wandb_run.log({plot_name: pr_curve})

def wandb_confusion_matrix(wandb_run, targets, preds, labels=None, plot_name='single_run_cm'):
    """
    Compute a scikit-learn confusion matrix, store it and log it on wandb (if using wandb)
    """
    cm = metrics.confusion_matrix(targets, preds, labels=labels)
    disp = metrics.ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=labels)

    # Plot the confusion matrix
    disp.plot(cmap='Blues', values_format='d')
    wandb_run.log({plot_name, plt})
    # plt.title('Confusion Matrix')
    # plt.xlabel('Predicted Labels')
    # plt.ylabel('True Labels')

    # Save the plot to a file
    #plt.savefig('confusion_matrix.png')
    plt.close()  # Close the figure to free up memory

def wandb_multi_run_confusion_matrix():
    # À faire
    pass


