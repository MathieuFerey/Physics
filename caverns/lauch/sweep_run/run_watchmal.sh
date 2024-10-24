#!/bin/bash

# ----- Settings ------

env_name=grant_cuda_12_1
miniconda_path=/sps/t2k/eleblevec/miniconda3

working_dir=/sps/t2k/eleblevec/updated_watchmal/WatChMaL/
spe_folder_name=reprod_HK
config_name=e_mu_20keach_100_1kMeV_X_t_q_Edges_hits 


#e_20k_energy 
#e_pi0_20keach_100_1kMeV_X_t_q_Edges_hits #e_mu_20keach_100_1kMeV_X_t_q_Edges_hits 
#debug_gnn_reg

# /!\ CAUTION : You might need to change the varirable "hydra.searchpath" below also


# ---- Executed code -----
source ${miniconda_path}/bin/activate $env_name

export HYDRA_FULL_ERROR=1

cd $working_dir
python \
    main.py \
    --config-path=/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config/main/${spe_folder_name} \
    --config-name=$config_name \
    hydra.searchpath=[/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config/] \
    'gpu_list=[0]'