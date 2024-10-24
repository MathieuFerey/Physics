import torch
import numpy as np
import pandas as pd

import scipy.special as special

# watchmal imports
from watchmal.engine.reconstruction import ReconstructionEngine

from watchmal.utils.logging_utils import setup_logging
from watchmal.utils.viz_utils import roc_curve, p_r_curve, confusion_matrix, scatplot_2d, combined_histograms_plot, histogram_2d, count_plot

log = setup_logging(__name__)

class ClassifierEngine(ReconstructionEngine):
    """Engine for performing training or evaluation for a classification network."""
    def __init__(
            self, 
            truth_key, 
            model, 
            rank, 
            device, 
            dump_path,
            wandb_run=None, 
            dataset=None,
            flatten_model_output=False, 
            prediction_threshold=None,
        ):
        """
        Parameters
        ==========
        truth_key : string
            Name of the key for the target labels in the dictionary returned by the dataloader
        model
            `nn.module` object that contains the full network that the engine will use in training or evaluation.
        rank : int
            The rank of process among all spawned processes (in multiprocessing mode).
        gpu : int
            The gpu that this process is running on.
        dump_path : string
            The path to store outputs in.
        label_set : sequence
            The set of possible labels to classify (if None, which is the default, then class labels in the data must be
            0 to N).
        """
        # create the directory for saving the log and dump files
        super().__init__(
            truth_key, 
            model, 
            rank, 
            device, 
            dump_path,
            wandb_run=wandb_run,
            dataset=dataset
        )
        
        self.flatten_model_output = flatten_model_output
        self.prediction_threshold = prediction_threshold

        self.softmax = torch.nn.Softmax(dim=1)
        self.sigmoid = torch.nn.Sigmoid()

        self.signal_key = ""
        self.label_set = []


    def set_dataset(self, dataset, dataset_config):

        super().set_dataset(dataset, dataset_config)

        self.signal_key = dataset_config.signal_key
        
        # Get the label_set
        for trf in dataset.transform.transforms: # dataset.transform is a T.Compose() object, to access the list of transform calling .transforms is needed
            if trf.__class__.__name__ == 'MapLabels':
                label_set = trf.label_set
                break
        
        self.label_set = list(label_set)
        
        

    def make_plots(self, preds, targets, prefix_plot_name):
        """
        Only rank 0 should call make_plots()
        """
      

        softmax_preds = special.softmax(preds, axis=1)
        class_preds = np.argmax(softmax_preds, axis=1)
        pred_names = [self.target_names[i] for i in class_preds]

        raw_columns = ['raw_preds_' + name  for name in self.target_names]
        sft_columns = ['softmax_preds_' + name for name in self.target_names]

        data = pd.DataFrame({})
        data['target_names'] = [self.target_names[int(i)] for i in targets]

        for raw_name, softmax_name, i in zip(raw_columns, sft_columns, range(len(self.target_names))):
            data[raw_name]     = preds[:, i]
            data[softmax_name] = softmax_preds[:, i]


        raw_decision_threshold = -0.1
        #raw_decision_threshold = data[raw_columns].mean(axis=None) # None for over all the data
        sft_decision_threshold = data[sft_columns].mean(axis=None) # same

        # Caution : raw_preds is [a, b] right now, and we consider raw_preds[1] as the signal
        roc_curve(
            self.wandb_run,
            data,
            targets,
            signal_key='softmax_preds_'+ self.signal_key,
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + '_roc_curve',
            log_scale=True,
        )

        p_r_curve(
            self.wandb_run,
            data,
            targets,
            signal_key='softmax_preds_'+ self.signal_key,
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + '_pr_curve',
            log_scale=True,
        )

        confusion_matrix(
            self.wandb_run,
            data,
            targets,
            label_names=self.target_names,
            signal_key='raw_preds_' + self.signal_key,
            threshold=raw_decision_threshold,
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + '_cf_matrix',
        )

        scatplot_2d(
            self.wandb_run,
            data,
            x=raw_columns[0],
            y=raw_columns[1],
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + '_raw_2d_scatterplot'
        )

        scatplot_2d(
            self.wandb_run,
            data,
            x=sft_columns[0],
            y=sft_columns[1],
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + '_softmax_2d_scatterplot'
        )

        histogram_2d(
            self.wandb_run,
            data,
            x=raw_columns[0],
            y=raw_columns[1],
            plot_name=prefix_plot_name + '_histogram_2d',
            folder_path=self.dump_path,
            log_scale=(False, False),
            figsize=(10, 6)
        )

        combined_histograms_plot(
            self.wandb_run,
            data[raw_columns], # we use the name of the columns to plot
            fill=False,
            element='step',
            log_yscale=False,
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + 'combined_histograms'
        ) # Maybe should do a dict for seaborn config


        count_plot(
            self.wandb_run,
            pred_names,
            folder_path=self.dump_path,
            plot_name=prefix_plot_name + 'predicted_class_countplot'
        ) # Maybe should do a dict for seaborn config


    def metric_data_reformat(self, loss, accuracy):
        """
        If new metrics are added in the classification forward loop, they need to be added here too.
        We keep the argument as a a, b, b and not **kwargs to prevent no support of new metrics
        """

        loss = np.array(loss).flatten()
        accuracy = np.array(accuracy).flatten()

        res = {'loss': loss, 'accuracy': accuracy}
        return res

    def to_disk_data_reformat(self, preds, targets, indices):

        preds   = np.array(preds).reshape(-1, len(self.label_set))
        targets = np.array(targets).flatten()
        indices = np.array(indices).flatten()

        res = {'preds': preds,'targets': targets, 'indices': indices}
        return res


    def forward(self, forward_type='train'):
        """
        Compute predictions and metrics for a batch of data.

        Parameters
        ==========
        forward_type : (str) either 'train', 'val' or 'test'
            Whether in training mode, requiring computing gradients for backpropagation
            For 'test' also returns the softmax value in outputs
        Returns
        =======
        dict
            Dictionary containing loss, predicted labels, softmax, accuracy, and raw model outputs
        """
        metrics = {}
        outputs = {}
        grad_enabled = True if forward_type == 'train' else False

        with torch.set_grad_enabled(grad_enabled):
    
            model_out = self.model(self.data) # even in ddp, the forward is done with self.model and not self.module
            
            # Compute the loss
            if self.flatten_model_output:
                model_out = torch.flatten(model_out)

            self.target = self.target.reshape(-1)
            loss = self.criterion(model_out, self.target)

            # Apply softmax to model_out
            if self.flatten_model_output:
                softmax = self.sigmoid(model_out)
            else: 
                softmax = self.softmax(model_out)

            # Compute accuracy based on the softmax values
            if self.flatten_model_output:
                preds = ( softmax >= self.prediction_threshold )
            else :
                preds = torch.argmax(model_out, dim=-1)
            
            accuracy = (preds == self.target).sum() / len(self.target)

            # Add the metrics to the output dictionnary
            metrics['loss']     = loss
            metrics['accuracy'] = accuracy

            # Note : this softmax saving will be modified. Even maybe deleted
            if forward_type == 'test': # In testing mode we also save the softmax values
                outputs['pred'] = model_out

        # metrics and potentially outputs contains tensors linked to the gradient graph (and on gpu is any) 
        return outputs, metrics


        # if needed one day : predicted_labels.nelement() see https://pytorch.org/docs/stable/generated/torch.numel.html#torch.numel (nelement is an alias for .numel())






"""Archives"""


    # def make_wandb_plots(self, prefix_plot_name, preds, targets):

    #     # Love ListConfig (cannot call label[np.int64] when label is a ListConfig)
    #     # convert & reshape to right type for wandb
    #     label_names = ['e-', 'mu-']
    #     preds = np.array(preds).reshape(-1, len(self.label_set))
    #     targets = np.array(targets).flatten()

    #     wandb_roc_curve(
    #         self.wandb_run, 
    #         targets=targets,
    #         preds=preds,
    #         labels=label_names,
    #         wandb_plot_name=prefix_plot_name + '_roc_curve'
    #     )

    #     wandb_p_r_curve(
    #         self.wandb_run, 
    #         targets=targets,
    #         preds=preds,
    #         labels=label_names,
    #         wandb_plot_name=prefix_plot_name + '_p_r_curve'
    #     )

    #     # confusion_matrix(
    #     #     self.wandb_run, 
    #     #     targets=targets,
    #     #     preds=preds,
    #     #     labels=label_names,
    #     #     wandb_plot_name=prefix_plot_name + '_confusion_matrix'
    #     # )
