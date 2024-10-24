This repository contains every softwares required to study Water Cherenkov detectors, from event simulation to data analysis based on Graph Neural Networks. The different softwares are

- WCSim: GEANT4 based C++ simulation tool for Water Cherenkov detectors.

- WCSimTools: code converting WCSim root outputs to standard root files, where relevant data is easily accessible.
  
- EventDisplay: a simple Python event display for SK, HK and WCTE, for vizualising events in root files.
  
- GraphTools: Python code which converts root files information (PMTs positions, charge, time...) into graphs which can be fed to GNNs.
  
- Caverns: a GNN software
