# Install script for directory: /pbs/home/m/mferey/WCSim/v1.12.8/WCSim

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/pbs/home/m/mferey/WCSim/v1.12.8/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/data/MuonFlux-HyperK-ThetaPhi.dat;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/biasprofile.dat;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/theta_cos15deg_FWHM.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/DSNBFluxes.json;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/LightInjectors.json;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/LI_OD_laser_ball_photon_positions.csv;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/mPMT_Position_WCTE.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/mPMT_Position_WCTE_CDS.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/ground_state_spectrum.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/first_excited_spectrum.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/second_excited_spectrum.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/CathodeParameters.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/CathodeParameters_SK.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/CathodeParameters_KCsCb.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/data/CathodeParameters_RbCsCb.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/data" TYPE FILE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/MuonFlux-HyperK-ThetaPhi.dat"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/biasprofile.dat"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/theta_cos15deg_FWHM.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/DSNBFluxes.json"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/LightInjectors.json"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/LI_OD_laser_ball_photon_positions.csv"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/mPMT_Position_WCTE.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/mPMT_Position_WCTE_CDS.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/ground_state_spectrum.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/first_excited_spectrum.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/second_excited_spectrum.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/CathodeParameters.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/CathodeParameters_SK.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/CathodeParameters_KCsCb.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/data/CathodeParameters_RbCsCb.txt"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/jobOptions.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/tuning_parameters.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/daq.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/geom_hk_mpmt_options.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/geom_hk_od_options.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_37pmtHK.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_interesting1.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_interesting2_SKwCover.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_nuPrism1.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_nuPrism2.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_radon_with_bias.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_radon_without_bias.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/visOGLSX.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/visRayTracer.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/visOGLQT.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/visOGLQT_2.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/visOGLQT-OD.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/vis_original.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCTE.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/NuPRISM.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCTE.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid_injector.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid_vectorfile.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_radon_with_bias.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/mPMT_radon_without_bias.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/OD.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/OD_10k.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/wcsim_temp.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_1part_HK.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid_vectorfile.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/WCSim_hybrid_injector.mac;/pbs/home/m/mferey/WCSim/v1.12.8/build/macros/LIGen.mac")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/macros" TYPE FILE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/jobOptions.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/tuning_parameters.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/daq.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/geom_hk_mpmt_options.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/geom_hk_od_options.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_37pmtHK.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_interesting1.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_interesting2_SKwCover.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_nuPrism1.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_nuPrism2.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_radon_with_bias.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_radon_without_bias.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/visOGLSX.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/visRayTracer.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/visOGLQT.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/visOGLQT_2.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/visOGLQT-OD.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/vis_original.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCTE.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/NuPRISM.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCTE.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid_injector.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid_vectorfile.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_radon_with_bias.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/mPMT_radon_without_bias.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/OD.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/OD_10k.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/wcsim_temp.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_1part_HK.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid_vectorfile.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/WCSim_hybrid_injector.mac"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/macros/LIGen.mac"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/WCSim.mac")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build" TYPE FILE FILES "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/WCSim.mac")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/rootwc;/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/MakeKin.py;/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/KinSplitter.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/rootwc/rootwc"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/sample-root-scripts/MakeKin.py"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/sample-root-scripts/KinSplitter.py"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/rootwc-files/loadincs.C;/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/rootwc-files/loadlibs.C;/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/rootwc-files/rootwc.C")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/rootwc-files" TYPE FILE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/rootwc/loadincs.C"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/rootwc/loadlibs.C"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/rootwc/rootwc.C"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_19_nuPrism.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_19_nuPrism_3ring.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_19_nuPrism_3ring_WCTE.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_30_13_3.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_33_13_1.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_33_50.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_33_50_1.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_34_22.5_1.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_34_22.5_2.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_34_22_1.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_34_22_2.txt;/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles/mPMTconfig_37_HK.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/mPMT-configfiles" TYPE FILE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_19_nuPrism.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_19_nuPrism_3ring.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_19_nuPrism_3ring_WCTE.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_30_13_3.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_33_13_1.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_33_50.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_33_50_1.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_34_22.5_1.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_34_22.5_2.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_34_22_1.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_34_22_2.txt"
    "/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/mPMT-configfiles/mPMTconfig_37_HK.txt"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/cmake/WCSim/WCSimConfigVersion.cmake;/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/cmake/WCSim/WCSimConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/lib/cmake/WCSim" TYPE FILE FILES
    "/pbs/home/m/mferey/WCSim/v1.12.8/build/WCSimConfigVersion.cmake"
    "/pbs/home/m/mferey/WCSim/v1.12.8/build/WCSimConfig.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin/this_wcsim.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/pbs/home/m/mferey/WCSim/v1.12.8/build/bin" TYPE FILE FILES "/pbs/home/m/mferey/WCSim/v1.12.8/build/this_wcsim.sh")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/pbs/home/m/mferey/WCSim/v1.12.8/build/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/pbs/home/m/mferey/WCSim/v1.12.8/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
