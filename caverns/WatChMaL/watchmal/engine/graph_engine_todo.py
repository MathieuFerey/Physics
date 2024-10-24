# generic imports
import numpy as np
from datetime import timedelta
from datetime import datetime
from abc import ABC, abstractmethod

# hydra imports
from hydra.utils import instantiate

# torch imports
import torch
from torch.nn.parallel import DistributedDataParallel

# WatChMaL imports
from watchmal.dataset.data_utils import get_data_loader, get_data_loader_v2, get_dataset
from watchmal.utils.logging_utils import CSVLog, setup_logging

log = setup_logging(__name__)


"""
Fichier de corps de fonction pour l'engine dédié aux graphes
"""


def new_evaluate(self, report_interval=20):
    """
    Evaluate the performance of the trained model on the test set.
    Multi-processes is supported
    
    Pour le futur  :
    
        Even if there more than one gpu, the test will be done 
        on the master (rank 0) one.
        (Nécessite de changer l'instantiation du test_sampler)
        To Do : compute the acceleration with multiple gpu : (Is n-gpus really usefull at test time ?)
    """

    self.model.eval()        
    start_time = datetime.now()
    loader = self.data_loaders['test']

    indices = None

    if self.rank == 0:
        log.info(f"\n\nEnd of the training. Evaluation starting. \nOutput directory: {self.dump_path}")

    for step, test_data in enumerate(loader):

        self.data = test_data['data'].to(self.device)
        self.target = test_data[self.truth_key].to(self.device)

        metrics = self.forward(forward_type='test') # will ouput loss + accuracy + softmax of the preds
        outputs = {'softmax': metrics.pop('softmax')} 


#  --- Step Logs --- # For now I see no reason to log at each step of the validation
# But I keep the code here if needed
# log_entries = {
#     "iteration": (self.iteration + step), 
#     "epoch": self.epoch, 
#     **outputs
# }

# self.val_log.log(log_entries) # add logs in the .csv file (each process has its csv file)

