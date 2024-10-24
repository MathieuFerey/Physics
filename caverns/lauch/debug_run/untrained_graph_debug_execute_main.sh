#!/bin/bash

# -- Settings --
base_folder_path=/sps/t2k/eleblevec/updated_watchmal/WatChMaL
config_name=debug_gnn_untrained # or debug_gnn_reg

# -- Executed code -- #
cd $base_folder_path
export HYDRA_FULL_ERROR=1


python \
    main.py \
    --config-path=/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config/main/debug \
    --config-name=$config_name \
    hydra.searchpath=[/sps/t2k/eleblevec/updated_watchmal/WatChMaL/config/] \
    'gpu_list=[0]'