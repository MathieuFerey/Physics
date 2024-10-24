#!/bin/bash

# ------------------------------------------------------- #
# This code will be executed by a sweep agent.
# this is why some source and export are re-defined here
# ------------------------------------------------------- #


# ----- Agent Settings ------ #
env_name=grant_cuda_12_1
miniconda_path=/sps/t2k/eleblevec/miniconda3

working_dir=/sps/t2k/eleblevec/updated_watchmal/WatChMaL

# ---- Executed code by the agent ----- 
export HYDRA_FULL_ERROR=1
source ${miniconda_path}/bin/activate $env_name

cd $working_dir
python \
    main_sweep.py \
    --config-path=/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config \
    --config-name=TEST_hk_gnn \
    'gpu_list=[]'