
# basic imports
import numpy as np

# Nn imports
import torch

# watchmal imports
from watchmal.engine.reconstruction import ReconstructionEngine

from watchmal.utils.logging_utils import setup_logging
from watchmal.utils.viz_utils import preds_targets_histogram

log = setup_logging(__name__)


class RegressionEngine(ReconstructionEngine):
    """Engine for performing training or evaluation for a regression network."""
    def __init__(
        self, 
        truth_key, 
        model, 
        rank, 
        device, 
        dump_path, 
        wandb_run=None,
        dataset=None,
        output_center=0, 
        output_scale=1
    ):
        """
        Parameters
        ==========
        truth_key : string
            Name of the key for the target values in the dictionary returned by the dataloader
        model
            `nn.module` object that contains the full network that the engine will use in training or evaluation.
        rank : int
            The rank of process among all spawned processes (in multiprocessing mode).
        gpu : int
            The gpu that this process is running on.
        dump_path : string
            The path to store outputs in.
        output_center : float
            Value to subtract from target values
        output_scale : float
            Value to divide target values by
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
        

        self.output_center = output_center # define for the cnn. No idea when it is used
        self.output_scale = output_scale   # neither why to do scaling this way


    def make_plots(self, preds, targets, prefix_plot_name):

        # Denormalizing data
        # index 0 is maximum values, index 1 is minimum
        if self.feat_norm is not None:
            preds = self.feat_norm[1] + (self.feat_norm[0] - self.feat_norm[1]) * preds
        
        if self.target_norm is not None:
            targets = self.target_norm[1] + (self.target_norm[0] - self.target_norm[1]) * targets
        

        # Plots
        for i in range(len(self.target_names)):

            i_preds       = preds[:, i]
            i_targets     = targets[:, i]
            i_target_name = self.target_names[i]

            plot_name = prefix_plot_name + f"tgt_vs_out_{i_target_name}"
            preds_targets_histogram(
                self.wandb_run,
                i_preds,
                i_targets,
                target_name=i_target_name,
                fill=False,
                element='step',
                log_yscale=False,
                folder_path=self.dump_path,
                plot_name=plot_name
            )

    def to_disk_data_reformat(self, preds, targets, indices):

        preds = np.array(preds).reshape(-1, len(self.target_names))
        targets = np.array(targets).reshape(-1, len(self.target_names))
        indices = np.array(indices).flatten()

        return {'preds': preds,'targets': targets, 'indices': indices}

    def forward(self, forward_type='train'):
        """
        Compute predictions and metrics for a batch of data

        Parameters
        ==========
        train : bool
            Whether in training mode, requiring computing gradients for backpropagation

        Returns
        =======
        dict
            Dictionary containing loss and predicted values
        """

        metrics = {}
        outputs = {}
        grad_enabled = True if forward_type == 'train' else False

        with torch.set_grad_enabled(grad_enabled):

            model_out = self.model(self.data)
            #model_out = model_out.reshape(-1)
            
            loss = self.criterion(model_out, self.target)

            # Log data about the outputs
            outputs['pred_min']    = model_out.min()
            outputs['pred_max']    = model_out.max()
            outputs['pred_mean']   = model_out.mean()
            outputs['pred_median'] = model_out.median()
            
            # Log data about the metrics
            metrics['loss']     = loss

            if forward_type == 'test':
                outputs['pred'] = model_out

        # metrics and potentially outputs are still on the computational graph        
        return outputs, metrics

    def scale_values(self, data):
        scaled = (data - self.output_center) / self.output_scale
        return scaled



    # From previous version (for cnn, but unused by the config files)
    # model_out = self.model(self.data).reshape(self.target.shape)

    # scaled_target = self.scale_values(self.target)
    # scaled_model_out = self.scale_values(model_out)
    # self.loss = self.criterion(scaled_model_out, scaled_target)