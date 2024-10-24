#!/bin/bash

# For now we use exported variable and not arguments
SWEEP_ID=${SWEEP_ID:-""} # "" works for no sweep

ENTITY=${ENTITY:-"erwanlbv"}
PROJECT=${PROJECT:-"sweep-playground"}
COUNT=${COUNT:-3}


if [ -z "$SWEEP_ID" ]; then
    echo "Failed to recognize the sweep id : ${SWEEP_ID}, exiting the code." 
    exit 1
fi 

echo "Sweep ID: $SWEEP_ID"
echo "Project : $PROJECT"
echo "Entity : $ENTITY"

echo "starting the agent"
wandb agent \
    -e $ENTITY \
    -p $PROJECT \
    --count $COUNT \
    $SWEEP_ID


