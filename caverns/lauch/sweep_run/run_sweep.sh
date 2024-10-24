#!/bin/bash


# For now
SWEEP_ID="345q59xs" # "" works for no sweep
ENTITY=erwanlbv
PROJECT=reprod_HK
COUNT=100

sweep_config=/sps/t2k/eleblevec/updated_watchmal/lauch/sweep_run/reprod_hk/e_mu_v001_sweep_config.yaml


#/sps/t2k/eleblevec/updated_watchmal/lauch/sweep_run/reprod_hk/e_pi0_v001_sweep_config.yaml


# -- Code part --- #
# Nothing to do from you below
source $work/miniconda3/bin/activate grant_cuda_12_1

if [ -z "$SWEEP_ID" ]; then
    echo "No sweep id provided. Creating a new sweep"

    # Create the sweep
    wandb sweep \
    -e $ENTITY \
    -p $PROJECT \
    $sweep_config
    
    echo "Provide the sweep id :"
    read SWEEP_ID
fi
  
if [ -z "$SWEEP_ID" ]; then
    echo "Failed to recognize the sweep id : ${SWEEP_ID}, exiting the code." 
    exit 1
fi 

export HYDRA_FULL_ERROR=1

echo "Sweep ID: $SWEEP_ID"
wandb agent \
    -e $ENTITY \
    -p $PROJECT \
    --count $COUNT \
    $SWEEP_ID


