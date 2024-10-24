
import numpy as np
import torch

import omegaconf
from omegaconf import OmegaConf

import torch_geometric
from torch_geometric.data import Data
from torch_geometric.data.datapipes import functional_transform
from torch_geometric.transforms import BaseTransform
from torch_geometric.utils import to_undirected

# watchmal imports
from watchmal.dataset.data_utils import match_type
from watchmal.utils.logging_utils import setup_logging

log = setup_logging(__name__)


"""
This file should contain all the callables (i.e python functions or class with a __call__ attribut) 
used for creating graph datasets.

"""

# À FAIRE : 
# 30/01 :  - Ajouter une erreur si les tailles de feat/target_norm et du nombre de features dans data.x/y ne correspondent pas
#          - Ajouter de la doc sur les appels [0] et [1]
# 14/02 :  - Mettre à jour la doc de cette fonction

class Normalize(torch.nn.Module):
    """Normalize a torch_geometric Data object with mean and standard deviation.
    Given mean: ``(mean[1],...,mean[n])`` and std: ``(std[1],..,std[n])`` for ``n``
    channels, this transform will normalize each channel of the input
    ``torch.*Tensor`` i.e.,
    ``output[channel] = (input[channel] - mean[channel]) / std[channel]``

    .. note::
        This transform acts out of place, i.e., it does not mutate the input tensor.

    Args:
        mean (sequence): Sequence of means for each channel.
        std (sequence): Sequence of standard deviations for each channel.
        inplace(bool,optional): Bool to make this operation in-place.

    """

    def __init__(
            self, 
            feat_norm,
            target_norm=None, 
            eps=1e-8, 
            inplace=False        
    ):
        
        super().__init__()
        
        self.feat_norm   = feat_norm
        self.target_norm = target_norm
        self.eps         = eps
        self.inplace     = inplace
        
        # For hydra compatibility
        if isinstance(self.feat_norm, omegaconf.listconfig.ListConfig):
            self.feat_norm = OmegaConf.to_container(self.feat_norm)
            if self.target_norm is not None:
                self.target_norm = OmegaConf.to_container(self.target_norm)

        # Need to convert list to torch tensor to perform addition & subtraction
        self.feat_norm = torch.tensor(self.feat_norm)
        if self.target_norm is not None:
            self.target_norm = torch.tensor(self.target_norm)


    def forward(self, data):
        """
        self.feat_norm and self.target_norm must contain Tensor object
        """

        #log.info(f"\n\nType de data : {type(data)}")
        #log.info(f"Normalize - Contenant : {data.x[:5]}\n\n")
        if self.feat_norm is not None:
            data.x = (data.x - self.feat_norm[1]) / (self.feat_norm[0] - self.feat_norm[1] + self.eps)
        
        if self.target_norm is not None:
            data.y = (data.y - self.target_norm[1]) / (self.target_norm[0] - self.target_norm[1] + self.eps)

        return data

class MapLabels(torch.nn.Module):
    """
    Arguments:
        label_set (list of integers) : which label to assign the PID to. 
            For example label_set=[11, 13, 111] will convert 11 -> 0, 13 -> 1 and 111 -> 2. 
    """
    def __init__(self, label_set: list):
        super().__init__()
        self.label_set = label_set

    def forward(self, data):
        
        new_target = self.label_set.index(data.y)
        data.y = torch.tensor([new_target])

        return data

class ConvertAndToDict(torch.nn.Module):
    """
    Arguments:
        feature_to_type (string)      : type to convert each feature to
        target_to_type (string)       : type to convert the target to 

    Note :
        - "idx" is only used when looking at the output folder (for evaluation only in watchmal)
        - The class Negative Log Likelyhood of torch requires int as labels
    """

    def __init__(self, feature_to_type: str, target_to_type: str):
        super().__init__()

        # We consider homogeneous graphs for now (the 'Data' obj). 
        # So all features are of the same type
        # Hence the should be converted to the same type also (no need to make a list for feat..type and target..type)
        self.feature_to_type = match_type(feature_to_type) 
        self.target_to_type  = match_type(target_to_type)

    def forward(self, data):

        # log.info(f"\n\nType de data : {type(data.y)}")
        # log.info(f"Convert - Contenant : {data.y}\n\n")
        
        if isinstance(data, dict): 
            return data

        data.x = data.x.to(self.feature_to_type)
        data.y = data.y.to(self.target_to_type)

        data_dict = {
            'data': data,
            'target': data.y,
            'indice': data.idx # might a better for for this. We duplicate the idx information (data + dict)
        }

        return data_dict 
    
class Threshold(torch.nn.Module):

    def __init__(self, key: str, max_thresholds: list, min_thresholds: list):

        super().__init__()

        self.key = key

        # And inf when no thresholds
        max_thresholds = [value if value is not None else torch.inf for value in max_thresholds]
        min_thresholds = [value if value is not None else -torch.inf for value in min_thresholds]

        # Convert to torch tensor necessary for torch.maximum and torch.minimum
        self.max_thresholds = torch.tensor(max_thresholds)
        self.min_thresholds = torch.tensor(min_thresholds)

        assert len(self.max_thresholds) == len(self.min_thresholds), f"max_threshold and min_thresold should be of same lentgh. Received {len(self.max_thresholds)} and {len(self.min_thresholds)}."

    def forward(self, data):

        #log.info(f"\n\nType de data : {type(data)}")
        #log.info(f"Threshold - Contenant : {data.x[:5]}\n\n")

        att = getattr(data, self.key) # return the attribute directly. No deepcopy
        assert att.shape[1] == len(self.max_thresholds), f"The threshold list does not match the input shape. Threshold : {len(self.thresholds)} vs {att.shape[0]} for data."

        # Need to use att.clamp_(..) to do in-place modification, 
        # torch.clamp(att, ..) points to a new tensor
        att.clamp_(min=self.min_thresholds, max=self.max_thresholds)

        return data

class AddPosInFeat(torch.nn.Module):

    def __init__(self):
        pass                                                                              
        
