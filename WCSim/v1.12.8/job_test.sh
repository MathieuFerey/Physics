#!/bin/bash

#SBATCH --mail-user=<ferey@llr.in2p3.fr>   # Where to send mail

. setup.sh
cd build/
bin/WCSim custom_macros/GPS_WCTE.mac macros/tuning_parameters.mac