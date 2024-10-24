#!/bin/bash

# -- Settings --
base_folder_path=/pbs/home/m/mferey/ML/caverns
config_name=debug_gnn_reg # or debug_gnn_reg

# -- Executed code -- #
cd $base_folder_path
export HYDRA_FULL_ERROR=1

python \
    WatChMaL/main.py \
    --config-path=/pbs/home/m/mferey/ML/caverns/config/main/debug \
    --config-name=$config_name \
    hydra.searchpath=[/pbs/home/m/mferey/ML/caverns/config/] \
    'gpu_list=[]'