#!/bin/bash

# -- Settings --
base_folder_path=/pbs/home/m/mferey/ML/caverns
spe_folder=debug
config_name=debug_gnn_classification # or debug_gnn_reg

hydra_searchpath='[/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config/]'


# -- Executed code -- #
cd $base_folder_path
export HYDRA_FULL_ERROR=1


python \
    WatChMaL/main.py \
    --config-path=/pbs/home/m/mferey/ML/caverns/config/main/debug \
    --config-name=$config_name \
    hydra.searchpath=[/pbs/home/m/mferey/ML/caverns/config/] \
    'gpu_list=[]' # Quotes here are important for correct parsing from bash due to the comma


