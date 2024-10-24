#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WCSim::WCSimCore" for configuration "Release"
set_property(TARGET WCSim::WCSimCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSimCore PROPERTIES
  IMPORTED_LOCATION_RELEASE "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/libWCSimCore.so.1.12.17"
  IMPORTED_SONAME_RELEASE "libWCSimCore.so.1.12.17"
  )

list(APPEND _cmake_import_check_targets WCSim::WCSimCore )
list(APPEND _cmake_import_check_files_for_WCSim::WCSimCore "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/libWCSimCore.so.1.12.17" )

# Import target "WCSim::WCSimRoot" for configuration "Release"
set_property(TARGET WCSim::WCSimRoot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSimRoot PROPERTIES
  IMPORTED_LOCATION_RELEASE "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/libWCSimRoot.so.1.12.17"
  IMPORTED_SONAME_RELEASE "libWCSimRoot.so.1.12.17"
  )

list(APPEND _cmake_import_check_targets WCSim::WCSimRoot )
list(APPEND _cmake_import_check_files_for_WCSim::WCSimRoot "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/libWCSimRoot.so.1.12.17" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
