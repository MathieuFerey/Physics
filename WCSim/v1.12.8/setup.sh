# add CC-Lyon modules

module add Production/cmake/3.25.0
module add Compilers/gcc/13.2.0
module add Modelisation/geant4/10.04.p02
module add Analysis/root/6.30.06
module add Programming_Languages/python/3.9.1
module add DataManagement/xrootd/5.6.9
module add HEP/hepmc3/3.2.7

# setup WCSim

source build/bin/this_wcsim.sh

module list
