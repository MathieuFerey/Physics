/**
 * @file get_data_from_root.C, former : get_sig_from_WCSim.C
 * @author Antoine Beauchêne, cleaned and upgraded by Lorenzo Perisse
 * @brief This macro creates a tree from simulated signal (ie with no noise) *
 * @version 1.1.0
 * @date May 2023
 * @copyright Copyright (c) 2022
 *
 */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TRandom1.h>

#include "WCSimRootEvent.hh"
#include "WCSimRootGeom.hh"
#include "WCSimPmtInfo.hh"

using namespace std;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Get the hits information of events from a WCSim file
 * @brief Return the total time of event duration
 *
 * @param infilename Name of the file containing the WCSim events
 * @param outfilename Name of the ROOT file in which the tree containing the relevant information of each event
 * @param startEvent Index of the event at which data extraction begins
 * @param endEvent Index of the event at which data extraction is completed
 */


vector<double> get_signal_from_WCSim(string infilename, string outfilename, const map<string, string> config) {


  // Extracted parameters from config 
  // Accessing the values (make sure to convert them to the appropriate type)
  const int maxHitsSig = std::stoi(config.at("MAX_HITS_SIG"));
  const short int verbose = std::stoi(config.at("VERBOSE"));
  //const int maxHitsBg = std::stoi(config["MAX_HITS_BG"]);
  //const double minDurationBg = std::stod(config["MIN_DURATION_BG"]);

  int eventType = std::stoi(config.at("EVENT_TYPE"));

  int ntrack=0;
  int nevents=0, nevents_check=0;
  double total_event_duration = 0.;
  vector<double > event_info(2);

  // Variable stockées dans le .root de sortie
  int n_hits;                                           //< Number of hits in event
  float charge[maxHitsSig], time[maxHitsSig];       //< Charge and time values of each hit
  float hitx[maxHitsSig], hity[maxHitsSig], hitz[maxHitsSig]; //< x, y, z arrays of hit coordinates
  float vertex[3];                                      //< x, y, z coordinates of vertex
  float particleDir[3];

  // Variables pour l'instant pas stockées
  float energy;                                         //< Energy of the incoming particle 
  int tubeIds[maxHitsSig];                              //< tubeID of each PMT registering a photo-electron  


  /*************************************************************************/
  // ####  Prepare data

  // ###################################
  // ##### ---- INTPUT  FILES ---- #####
  // ###################################
  // Open the file containing the tree, and its geometry
  TFile *file    = TFile::Open(infilename.data(), "READ");
  WCSimRootEvent *wcsimrootsuperevent = new WCSimRootEvent();         // (même raison que WCSImRootGeom) Create a WCSimRootEvent to store data from the tree in
  
  
  WCSimRootGeom *geo = new WCSimRootGeom();        // Classe pour GÉRER le TTree geotree (compatibilité root & WCSIM)
  TTree *geotree = (TTree*) file->Get("wcsimGeoT");
  geotree->SetBranchAddress("wcsimrootgeom", &geo);

  // Test if the inputfile isn't empty
  if( geotree->GetEntries() == 0 ){ 
    cout << "ERROR, there is 0 event in the Geometry TTree" << endl; 
    exit(2); 
  }

  // Get the wcsimT TTree object from the input file
  // Use of the WCSimRoot special classES to deal with root & WCSim
	TTree *wcsimT= (TTree*)file -> Get("wcsimT"); 	
 

  TBranch *branch;
  branch = wcsimT->GetBranch("wcsimrootevent");
  branch->SetAddress(&wcsimrootsuperevent);
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);     // Force deletion to prevent memory leak 
  
  
  // Creates the new file and its tree
  TFile *outfile = new TFile(outfilename.data(), "RECREATE");
  TTree *outtree = new TTree("root_event", "events_data");


  // Create the output tree branches
  // Erwan : Créer une fonction à part pour ça ? à voir
  outtree->Branch("eventType", &eventType, "eventType/b");

  outtree->Branch("vtx", vertex, "vtx[3]/F");
  outtree->Branch("energy", &energy, "energy/F");
  outtree->Branch("particleDir", particleDir, "particleDir[3]/D");  
  outtree->Branch("n_hits", &n_hits, "n_hits/I");


  outtree->Branch("tubeIds", &tubeIds, "tubeIds[n_hits]/I"); 
  outtree->Branch("hitx", hitx, "hitx[n_hits]/F");
  outtree->Branch("hity", hity, "hity[n_hits]/F");
  outtree->Branch("hitz", hitz, "hitz[n_hits]/F");
  outtree->Branch("charge", charge, "charge[n_hits]/F");
  outtree->Branch("time", time, "time[n_hits]/F");

  // Geometry Branch for event display

  //outtree->Branch("geo.", "WCSimRootGeom", &geo);

  

  // Branches for event display & analysis (in case of a classification model)
  // outtree->Branch("dwall", &dwall, "dwall/d");
  // outtree->Branch("twall", &twall, "twall/d");
  // outtree->Branch("lconv", &lconv, "lconv/d");
  //outtree->Branch("vtx0", vertex_0, "vtx_0[3]/F");
  

  /*************************************************************************/
  // Loop over the events


  // Variables for event management

  // Pointors for wcsimevent
  WCSimRootTrigger *wcsimrootevent = nullptr;

  // Pointors for GetNTrack
  TObject *element =  nullptr;
  WCSimRootTrack *wcsimroottrack = nullptr;
  
  // Pointors for GetNcherenkovdigihits
  TObject *Hit = nullptr;
  WCSimRootCherenkovDigiHit *cDigiHit = nullptr;
  WCSimRootPMT hitpmt; 

  // Display variable (if verbose is not set to 0 the program will call this variable)
  std::vector<int> eventsWithNoHits;


  geotree->GetEntry(0);   // Sert à quoi ?
  nevents = wcsimT->GetEntries();	



  if (verbose >= 1) {
    vector<double> PMTradius(2);
    
    PMTradius[0]=geo->GetWCPMTRadius();
    PMTradius[1]=geo->GetWCPMTRadius(true);
    cout << "\nNumber of PMTs of 1st type = " << geo->GetWCNumPMT() << ", radius = " << PMTradius[0] << endl;
    cout << "Number of PMTs of 2nd type = " << geo->GetWCNumPMT(true) << ", radius = " << PMTradius[1] <<endl;

    cout << "\n -- Looking for data in the file : " << infilename << endl;
    cout << " -- The file contains " << nevents << " events  -- \n" << endl;

    //cout << geo->GetWCCylRadius() << " " << geo->GetWCCylLength() << endl;

    if (verbose >= 2){
      cout << " -- Event type : " << eventType << "\n" << endl;
    }
  }

  if (verbose >= 1) {

  }
  
  for(int i=0 ; i<nevents ; i++)
  {
    //  Load the i^th event into wcsimrootsuperevent
    //  ------ ERWAN : question Pourquoi on ne fait pas branch -> GetEvent(i) plutôt ?
    wcsimT->GetEvent(i);     

    // Load the first (and only) trigger of this event into wcsimrootevent
    wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);   


    // Ncherenkovdighit deals with : HITS, CHARGES, TIME
    n_hits = wcsimrootevent->GetNcherenkovdigihits();

    // S'il n'y a pas de hits dans l'évènement il ne nous intéresse pas donc on ne le sauvegarde pas et on passe à l'évènement suivant
    if ( n_hits < 1 ) {
      eventsWithNoHits.push_back(i);
      continue; 
    }

    // Get the vertex of the mother particle
    for (int k = 0; k < 3; k++){
      vertex[k] = wcsimrootevent->GetVtx(k);
    }

    // On parcourt les données de l'évènement
    for(int j=0 ; j<n_hits ; j++) {

      Hit = ( wcsimrootevent->GetCherenkovDigiHits() ) -> At(j);
      cDigiHit = dynamic_cast<WCSimRootCherenkovDigiHit*> (Hit);
      hitpmt = geo->GetPMT(cDigiHit -> GetTubeId() - 1, false); // Pourquoi - 1 ? Est-ce que one_indexe=False dans watchaml alors ?

      charge[j]  = cDigiHit->GetQ();
      time[j]    = cDigiHit->GetT();
      hitx[j]  = hitpmt.GetPosition(0);
      hity[j]  = hitpmt.GetPosition(1);
      hitz[j]  = hitpmt.GetPosition(2);
      tubeIds[j] = cDigiHit -> GetTubeId();

    }

    //To set the table values at -1 ("sentinelle value") for each event over the loop
    for(int j=n_hits ; j<maxHitsSig ; j++) {
      hitx[j]  = -1.;
      hity[j]  = -1.;
      hitz[j]  = -1.;
      charge[j]= -1.;
      time[j]  = -1.;
      tubeIds[j] = -1;
    }
  
    // Ntrack deals with : ENERGY 
    ntrack = wcsimrootevent->GetNtrack();
    for(int k=0 ; k<ntrack ; k++) {

      element = (wcsimrootevent->GetTracks())->At(k);
      wcsimroottrack = dynamic_cast<WCSimRootTrack*> (element);

      if (wcsimroottrack->GetIpnu() != 0 && wcsimroottrack->GetFlag() == -1) {
        energy = wcsimroottrack->GetE();
        particleDir[0] = wcsimroottrack->GetDir(0);
        particleDir[1] = wcsimroottrack->GetDir(1);
        particleDir[2] = wcsimroottrack->GetDir(2);
        break; 
        // C'est quoi Ipnu, c'est quoi Getflag, c'est quoi le but de cette ligne (et de cette boucle for)
        // Hypothèse : y'a qu'un seul k qui vérifie cette condition, si on l'a trouvé on peut sortir de la boucle for
        // Mais pourquoi la particule mère ne se trouve pas au tout début de la track ? Donc a k = 0 ou k = n_track - 1
      }    
    }

    nevents_check++;
    outtree -> Fill();

    // Loop print
    if ( (i % 500 == 0) && (verbose >= 1) ) {
      cout << "Event #" << i << ", found " << n_hits << " Cherenkov hits" << endl;

      if ( verbose >= 2) {
        cout << "Event #" << i << ", ID=" << wcsimroottrack->GetIpnu() << "  Pnu=" << energy << endl;
      }
      // , lasting " << event_duration << " ns" << 
    }

  }

  outtree->Write();
  outfile->Close();


  
  /*************************************************************************/
  // End of function Print

  if ( verbose >=1 ) {
    cout << "\n -- End of the processing -- \n" << endl;
    cout << "There are "  << eventsWithNoHits.size() << " events without hits" << endl;
    cout << "   Events with no hits ids : ";
    for (int eventId : eventsWithNoHits) {
        std::cout << eventId << " ";
    }
    cout << "\n" << endl;
    
    cout << "There are " << nevents       << " events in the input file." << endl;
    cout << "There are " << nevents_check << " events in the output file." << endl;
    cout << "\n -- Saving the data at : " << outfilename << endl;
    // cout << "The total event duration is " << total_event_duration << " ns.\n\n" << endl;
  }

  event_info[0] = total_event_duration;
  event_info[1] = 1.*nevents;
  return event_info;

}



int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "\n --- Error --- \n Usage: " << argv[0] << " path_to_config.txt \n" << endl;
        return 1;
    }

    std::ifstream configFile(argv[1]);
    std::map<std::string, std::string> configValues;

    std::string line;
    while (std::getline(configFile, line)) {
        
        // Check if the line starts with '#' and skip it if it does
        if (!line.empty() && line[0] == '#') { continue; }

        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (std::getline(is_line, value)) {
                configValues[key] = value;
            }
        }
    }

    // Parameters for get_signal_from_WCSim
    const string input_file_path  = configValues["WCSIMROOT_FILE_PATH"];
    const string output_file_path = configValues["RESULT_FILE_PATH"];   

    // Call get_sign_from_wcsim with the extracted parameters

    vector<double> event_info = get_signal_from_WCSim(input_file_path, output_file_path, configValues);

    return 0;
}