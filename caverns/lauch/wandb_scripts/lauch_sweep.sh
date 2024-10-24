#!/bin/bash

# SLURM options:
#SBATCH --mail-user=er.leblevec@gmail.com           # Where to send mail
#SBATCH --mail-type=ALL                             # Mail events (NONE, BEGIN, END, FAIL, ALL)


#SBATCH --job-name=sweep_gpus                         # Job name
#SBATCH --output=/sps/t2k/eleblevec/updated_watchmal/WatChMaL_Sweep/logs/sweep_gpus%j.log             # Standard output and error log

#SBATCH --partition=gpu                              # Partition choice
#SBATCH --mem=10G                                     # Amount of memory required
#SBATCH --gres=gpu:v100:2                          # Number and type of gpu

#SBATCH --ntasks=1                                   # Maximum number of parallel processes
#SBATCH --time=0:10:00                              # 7 days by default on htc partition


# --- Settings --- #
path_to_miniconda=$work/miniconda3
conda_env_name=grant_cuda_12_1

# "export" below must be kept for now 
#(argument support will be for later)
export SWEEP_ID="06jq6tg9" 
export ENTITY="erwanlbv"
export PROJECT="sweep-playground"
export COUNT=3

# -- Executed code --- #
export HYDRA_FULL_ERROR=1

source  ${path_to_miniconda}/bin/activate $conda_env_name

bash /sps/t2k/eleblevec/updated_watchmal/lauch/wandb_scripts/run_agent.sh