
#!/bin/bash

# -- Settings --
base_folder_path=/pbs/home/m/mferey/caverns/WatChMaL

spe_folder_name=reprod_HK
config_name=main_config


# -- Executed code -- # (No need to change anything below)
cd $base_folder_path
export HYDRA_FULL_ERROR=1


python \
    main.py \
    --config-path=${base_folder_path}/config/main/${spe_folder_name} \
    --config-name=$config_name \
    hydra.searchpath=[/pbs/home/m/mferey/caverns/config/] \
    'gpu_list=[]' # Quotes here are important for correct parsing from bash due to the comma (if multiple gpus)




