# Sets necessary environment variables to use this installation of WCSim in ROOT
# Also set PATH and LD_LIBRARY_PATH for convenience

export WCSIM_BUILD_DIR=/pbs/home/m/mferey/WCSim/v1.12.8/build/
export ROOT_INCLUDE_PATH=/pbs/home/m/mferey/WCSim/v1.12.8/build/include/WCSim:$ROOT_INCLUDE_PATH
export PATH=/pbs/home/m/mferey/WCSim/v1.12.8/build/bin:$PATH
export LD_LIBRARY_PATH=/pbs/home/m/mferey/WCSim/v1.12.8/build/lib:$LD_LIBRARY_PATH
export WCSIM_SOURCE_DIR=/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/
