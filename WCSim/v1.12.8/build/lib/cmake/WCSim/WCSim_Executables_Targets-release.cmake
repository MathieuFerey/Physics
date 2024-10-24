#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WCSim::WCSim" for configuration "Release"
set_property(TARGET WCSim::WCSim APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSim PROPERTIES
  IMPORTED_LOCATION_RELEASE "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/WCSim"
  )

list(APPEND _cmake_import_check_targets WCSim::WCSim )
list(APPEND _cmake_import_check_files_for_WCSim::WCSim "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/WCSim" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
