# WCSimConfig.cmake

get_filename_component( WCSim_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH )

include( CMakeFindDependencyMacro )
find_dependency( Geant4 REQUIRED )
find_dependency( ROOT REQUIRED )

include("${WCSim_CMAKE_DIR}/WCSim_Library_Targets.cmake")

set (WCSIM_CHECK_GEOMETRY_OVERLAPS $<IF:$<BOOL:OFF>,true,false>)
set (WCSIM_INCLUDE_DIRS /pbs/home/m/mferey/WCSim/v1.12.8/build/include/WCSim)

find_library(WCSimRoot_LIBRARIES REQUIRED
        NAMES WCSimRoot
        HINTS /pbs/home/m/mferey/WCSim/v1.12.8/build/lib)

find_library(WCSimCore_LIBRARIES REQUIRED
        NAMES WCSimCore
        HINTS /pbs/home/m/mferey/WCSim/v1.12.8/build/lib)

list(APPEND WCSim_LIBRARIES
        ${WCSimCore_LIBRARIES}
        ${WCSimRoot_LIBRARIES})
