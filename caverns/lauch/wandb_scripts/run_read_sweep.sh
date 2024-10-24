#!/bin/bash

source $work/miniconda3/bin/activate grant_cuda_12_1

# Initialize variables
config_path=""
SWEEP_ID=${SWEEP_ID:-""} # "" works for no sweep

ENTITY=erwanlbv
PROJECT=sweep-playground
COUNT=3

# Loop through arguments and process them
case $1 in
    -c|--config)  # Match -c or --config
        config_path="$2"  # Assign the next parameter as the value
        ;;
    *)  # Default case if no more known options
        echo "Unknown option: $1"
        exit 1
        ;;
esac

# Check if the config path was provided
if [[ -z "$config_path" ]]; then
    echo -e "\nError: Config path is required."
    exit 1
else
    echo -e "\nConfig path is set to: $config_path"
fi


# Check if a sweep id is provided
if [ -z "$SWEEP_ID" ]; then
    echo "No sweep id provided. Creating a new sweep"

    # Create the sweep
    wandb sweep \
    -e $ENTITY \
    -p $PROJECT \
    $config_path
    
    echo "Provide the sweep id :"
    read SWEEP_ID
fi
  
if [ -z "$SWEEP_ID" ]; then
    echo "Failed to recognize the sweep id : ${SWEEP_ID}, exiting the code." 
    exit 1
fi 

# Run an agent managed by the sweep
echo "Sweep ID: $SWEEP_ID"
wandb agent \
    -e $ENTITY \
    -p $PROJECT \
    --count $COUNT \
    $SWEEP_ID


