void setupVariables2(BaseHandler* handler,bool isMC = false)
{
  const double mZ = 91;
  const double mW = 80.385;

  EventVariableThreshold* pt201010 = new EventVariableThreshold("PT201010","goodElectrons");
  pt201010->addProduct("goodMuons");
  pt201010->addThreshold(20);
  pt201010->addThreshold(10);
  pt201010->addThreshold(10);
  handler->addEventVariable("PT201010",pt201010);

  EventVariableThreshold* pt202010 = new EventVariableThreshold("PT202010","goodElectrons");
  pt202010->addProduct("goodMuons");
  pt202010->addThreshold(20);
  pt202010->addThreshold(20);
  pt202010->addThreshold(10);
  handler->addEventVariable("PT202010",pt202010);

  EventVariableThreshold* pt202020 = new EventVariableThreshold("PT202020","goodElectrons");
  pt202020->addProduct("goodMuons");
  pt202020->addThreshold(20);
  pt202020->addThreshold(20);
  pt202020->addThreshold(20);
  handler->addEventVariable("PT202020",pt202020);

  EventVariableThreshold* pt302020 = new EventVariableThreshold("PT302020","goodElectrons");
  pt302020->addProduct("goodMuons");
  pt302020->addThreshold(30);
  pt302020->addThreshold(20);
  pt302020->addThreshold(20);
  handler->addEventVariable("PT302020",pt302020);

  EventVariableObjectVariableVector<double>* leptonPts = new EventVariableObjectVariableVector<double>("PT","goodMuons",true);
  leptonPts->addProduct("goodElectrons");
  handler->addEventVariable("PTGOODLEPTONS",leptonPts);
  
  handler->addEventVariable("NGOODELECTRONS", new EventVariableN("NGOODELECTRONS","goodElectrons"));
  handler->addEventVariable("QGOODELECTRONS", new EventVariableObjectVariableVector<double>("CHARGE","goodElectrons"));
  handler->addEventVariable("PTGOODELECTRONS", new EventVariableObjectVariableVector<double>("PT","goodElectrons"));
  handler->addEventVariable("ETAGOODELECTRONS", new EventVariableObjectVariableVector<double>("ETA","goodElectrons"));
  
  handler->addEventVariable("NGOODMUONS",new EventVariableN("NGOODMUONS","goodMuons"));
  handler->addEventVariable("QGOODMUONS", new EventVariableObjectVariableVector<double>("CHARGE","goodMuons"));
  handler->addEventVariable("PTGOODMUONS", new EventVariableObjectVariableVector<double>("PT","goodMuons"));
  handler->addEventVariable("ETAGOODMUONS", new EventVariableObjectVariableVector<double>("ETA","goodMuons"));
  
  handler->addEventVariable("NBASICTAUS", new EventVariableN("NBASICTAUS","basicTaus"));
  
  handler->addEventVariable("NGOODTAUS", new EventVariableN("NGOODTAUS","goodTaus"));
  handler->addEventVariable("QGOODTAUS", new EventVariableObjectVariableVector<double>("CHARGE","goodTaus"));
  handler->addEventVariable("PTGOODTAUS", new EventVariableObjectVariableVector<double>("PT","goodTaus"));
  handler->addEventVariable("ETAGOODTAUS", new EventVariableObjectVariableVector<double>("ETA","goodTaus"));
  
  handler->addEventVariable("NSIDEBANDTAUS", new EventVariableN("NSIDEBANDTAUS","sidebandTaus"));
  handler->addEventVariable("NOTHERTAUS", new EventVariableN("NOTHERTAUS","otherTaus"));
  
  handler->addEventVariable("NGOODJETS", new EventVariableN("NGOODJETS","goodJets"));
  handler->addEventVariable("PTGOODJETS", new EventVariableObjectVariableVector<double>("PT","goodJets"));
  handler->addEventVariable("ETAGOODJETS", new EventVariableObjectVariableVector<double>("ETA","goodJets"));
  
  handler->addEventVariable("NGOODPHOTONS", new EventVariableN("NGOODPHOTONS","goodPhotons"));
  handler->addEventVariable("PTGOODPHOTONS", new EventVariableObjectVariableVector<double>("PT","goodPhotons"));
  handler->addEventVariable("ETAGOODPHOTONS", new EventVariableObjectVariableVector<double>("ETA","goodPhotons"));

  handler->addEventVariable("nINPELECTRONS", new EventVariableN("nINPELECTRONS","isoNonPromptElectrons"));
  handler->addEventVariable("QINPELECTRONS", new EventVariableObjectVariableVector<double>("CHARGE","isoNonPromptElectrons"));
  handler->addEventVariable("PTINPELECTRONS", new EventVariableObjectVariableVector<double>("PT","isoNonPromptElectrons"));
  handler->addEventVariable("ETAINPELECTRONS", new EventVariableObjectVariableVector<double>("ETA","isoNonPromptElectrons"));

  handler->addEventVariable("nNIPELECTRONS", new EventVariableN("nNIPELECTRONS","promptNonIsoElectrons"));
  handler->addEventVariable("QNIPELECTRONS", new EventVariableObjectVariableVector<double>("CHARGE","promptNonIsoElectrons"));
  handler->addEventVariable("PTNIPELECTRONS", new EventVariableObjectVariableVector<double>("PT","promptNonIsoElectrons"));
  handler->addEventVariable("ETANIPELECTRONS", new EventVariableObjectVariableVector<double>("ETA","promptNonIsoElectrons"));

  handler->addEventVariable("nNINPELECTRONS", new EventVariableN("nNIPELECTRONS","nonPromptNonIsoElectrons"));
  handler->addEventVariable("QNINPELECTRONS", new EventVariableObjectVariableVector<double>("CHARGE","nonPromptNonIsoElectrons"));
  handler->addEventVariable("PTNINPELECTRONS", new EventVariableObjectVariableVector<double>("PT","nonPromptNonIsoElectrons"));
  handler->addEventVariable("ETANINPELECTRONS", new EventVariableObjectVariableVector<double>("ETA","nonPromptNonIsoElectrons"));
  
  handler->addEventVariable("nINPMUONS", new EventVariableN("nINPMUONS","isoNonPromptMuons"));
  handler->addEventVariable("QINPMUONS", new EventVariableObjectVariableVector<double>("CHARGE","isoNonPromptMuons"));
  handler->addEventVariable("PTINPMUONS", new EventVariableObjectVariableVector<double>("PT","isoNonPromptMuons"));
  handler->addEventVariable("ETAINPMUONS", new EventVariableObjectVariableVector<double>("ETA","isoNonPromptMuons"));
  
  handler->addEventVariable("nNIPMUONS", new EventVariableN("nNIPMUONS","promptNonIsoMuons"));
  handler->addEventVariable("QNIPMUONS", new EventVariableObjectVariableVector<double>("CHARGE","promptNonIsoMuons"));
  handler->addEventVariable("PTNIPMUONS", new EventVariableObjectVariableVector<double>("PT","promptNonIsoMuons"));
  handler->addEventVariable("ETANIPMUONS", new EventVariableObjectVariableVector<double>("ETA","promptNonIsoMuons"));
  
  handler->addEventVariable("nNINPMUONS", new EventVariableN("nNIPMUONS","nonPromptNonIsoMuons"));
  handler->addEventVariable("QNINPMUONS", new EventVariableObjectVariableVector<double>("CHARGE","nonPromptNonIsoMuons"));
  handler->addEventVariable("PTNINPMUONS", new EventVariableObjectVariableVector<double>("PT","nonPromptNonIsoMuons"));
  handler->addEventVariable("ETANINPMUONS", new EventVariableObjectVariableVector<double>("ETA","nonPromptNonIsoMuons"));

  // Inclusive tracks
  handler->addEventVariable("NGOODINCLUSIVETRACKS", new EventVariableN("NGOODTRACKS","goodInclusiveTracks"));
  
  handler->addEventVariable("NINCLUSIVETRACKS", new EventVariableN("NINCLUSIVETRACKS","inclusiveTracks"));
  handler->addEventVariable("NISOINCLUSIVETRACKS", new EventVariableN("NISOINCLUSIVETRACKS","isoInclusiveTracks"));
  handler->addEventVariable("NPROMPTINCLUSIVETRACKS", new EventVariableN("NPROMPTINCLUSIVETRACKS","promptInclusiveTracks"));
  handler->addEventVariable("NISONONPROMPTINCLUSIVETRACKS", new EventVariableN("NISONONPROMPTINCLUSIVETRACKS","isoNonPromptInclusiveTracks"));
  handler->addEventVariable("NPROMPTNONISOINCLUSIVETRACKS", new EventVariableN("NPROMPTNONISOINCLUSIVETRACKS","promptNonIsoInclusiveTracks"));
  
  handler->addEventVariable("NINCLUSIVETRACKS7", new EventVariableN("NINCLUSIVETRACKS7","inclusiveTracks7"));
  handler->addEventVariable("NISOINCLUSIVETRACKS7", new EventVariableN("NISOINCLUSIVETRACKS7","isoInclusiveTracks7"));
  handler->addEventVariable("NPROMPTINCLUSIVETRACKS7", new EventVariableN("NPROMPTINCLUSIVETRACKS7","promptInclusiveTracks7"));
  handler->addEventVariable("NPROMPTIREL0p30INCLUSIVETRACKS7", new EventVariableN("NPROMPTIREL0p30INCLUSIVETRACKS7","promptIREL0p30InclusiveTracks7"));
  handler->addEventVariable("NISONONPROMPTINCLUSIVETRACKS7", new EventVariableN("NISONONPROMPTINCLUSIVETRACKS7","isoNonPromptInclusiveTracks7"));
  handler->addEventVariable("NPROMPTNONISOINCLUSIVETRACKS7", new EventVariableN("NPROMPTNONISOINCLUSIVETRACKS7","promptNonIsoInclusiveTracks7"));
  
  // Regular tracks
  handler->addEventVariable("NGOODTRACKS", new EventVariableN("NGOODTRACKS","goodTracks"));
  handler->addEventVariable("QGOODTRACKS", new EventVariableObjectVariableVector<double>("CHARGE","goodTracks"));
  handler->addEventVariable("PTGOODTRACKS", new EventVariableObjectVariableVector<double>("PT","goodTracks"));
  handler->addEventVariable("ETAGOODTRACKS", new EventVariableObjectVariableVector<double>("ETA","goodTracks"));
  
  handler->addEventVariable("NBASICTRACKS", new EventVariableN("NBASICTRACKS","basicTracks"));
  handler->addEventVariable("NISOTRACKS", new EventVariableN("NISOTRACKS","isoTracks"));
  handler->addEventVariable("NPROMPTTRACKS", new EventVariableN("NPROMPTTRACKS","promptTracks"));

  handler->addEventVariable("NISONONPROMPTTRACKS", new EventVariableN("NISONONPROMPTTRACKS","isoNonPromptTracks"));
  handler->addEventVariable("PTISONONPROMPTTRACKS", new EventVariableObjectVariableVector<double>("PT","isoNonPromptTracks"));
  handler->addEventVariable("ETAISONONPROMPTTRACKS", new EventVariableObjectVariableVector<double>("ETA","isoNonPromptTracks"));

  handler->addEventVariable("NPROMPTNONISOTRACKS", new EventVariableN("NPROMPTNONISOTRACKS","promptNonIsoTracks"));
  handler->addEventVariable("PTPROMPTNONISOTRACKS", new EventVariableObjectVariableVector<double>("PT","promptNonIsoTracks"));
  handler->addEventVariable("ETAPROMPTNONISOTRACKS", new EventVariableObjectVariableVector<double>("ETA","promptNonIsoTracks"));
  
  handler->addEventVariable("NBASICTRACKS7", new EventVariableN("NBASICTRACKS7","basicTracks7"));
  handler->addEventVariable("NISOTRACKS7", new EventVariableN("NISOTRACKS7","isoTracks7"));
  handler->addEventVariable("NPROMPTTRACKS7", new EventVariableN("NPROMPTTRACKS7","promptTracks7"));
  handler->addEventVariable("NISONONPROMPTTRACKS7", new EventVariableN("NISONONPROMPTTRACKS7","isoNonPromptTracks7"));
  handler->addEventVariable("NPROMPTNONISOTRACKS7", new EventVariableN("NPROMPTNONISOTRACKS7","promptNonIsoTracks7"));
  
  handler->addEventVariable("NRECOVERTICES", new EventVariableN("NRECOVERTICES","ALLRECOVERTICES"));

  handler->addEventVariable("NBOSONS",new EventVariableN("NBOSONS","BOSONS"));
  handler->addEventVariable("N_McMuonsFromZ", new EventVariableN("N_McMuonsFromZ","MCMUONSFROMZ"));
  handler->addEventVariable("N_McElectronsFromZ", new EventVariableN("N_McElectronsFromZ","MCELECTRONSFROMZ"));

  handler->addEventVariable("N_McTausFromBoson", new EventVariableN("N_McTausFromBoson","MCTAUSFROMBOSON"));
  handler->addEventVariable("N_McMuonsFromBoson", new EventVariableN("N_McMuonsFromBoson","MCMUONSFROMBOSON"));
  handler->addEventVariable("N_McElectronsFromBoson", new EventVariableN("N_McElectronsFromBoson","MCELECTRONSFROMBOSON"));

  EventVariableSumPT* HT = new EventVariableSumPT("HT","goodJets");
  handler->addEventVariable("HT",HT);

  if(isMC){
    EventVariableSmearMET* MET = new EventVariableSmearMET("MET","MET","HT","NRECOVERTICES",2.68,4.14,3.48,2.68,5.10,3.48);
    MET->setSeed(3141592654);
    handler->addEventVariable("MET",MET);
  }else{
    EventVariableSumPT* MET = new EventVariableSumPT("MET","MET");
    handler->addEventVariable("MET",MET);
  }

  EventVariableSumPT* LT = new EventVariableSumPT("LT","goodMuons");
  LT->addProduct("goodElectrons");
  LT->addProduct("goodTaus");
  handler->addEventVariable("LT",LT);
  
  EventVariableSumPT* ST = new EventVariableSumPT("ST","goodMuons");
  ST->addProduct("goodElectrons");
  ST->addProduct("goodTaus");
  ST->addProduct("goodJets");
  ST->addProduct("MET");
  handler->addEventVariable("ST",ST);

  EventVariableSumPT* pTbjetsCSVL = new EventVariableSumPT("HTCSVL","bJetsCSVL");
  handler->addEventVariable("HTCSVL",pTbjetsCSVL);

  EventVariableSumPT* pTbjetsCSVM = new EventVariableSumPT("HTCSVM","bJetsCSVM");
  handler->addEventVariable("HTCSVM",pTbjetsCSVM);

  EventVariableOSSF* OSSF = new EventVariableOSSF("OSSF","goodMuons","",mZ,15);
  OSSF->addProduct("goodElectrons");
  handler->addEventVariable("OSSF",OSSF);

  EventVariableMass* massLeptons = new EventVariableMass("MLEPTONS", "goodElectrons");
  massLeptons->addProduct("goodMuons");
  massLeptons->addProduct("goodTaus");
  handler->addEventVariable("MLEPTONS", massLeptons);

  EventVariableMass* massPhotons = new EventVariableMass("MPHOTONS", "goodPhotons");
  handler->addEventVariable("MPHOTONS", massPhotons);

  EventVariableOS* mLowDY = new EventVariableOS("MLOWDY", "goodElectrons", "LOWDY");
  mLowDY->addProduct("goodMuons");
  handler->addEventVariable("MLOWDY", mLowDY);
  
  EventVariableMT* MT = new EventVariableMT("MT", mZ,"","goodElectrons","goodMuons","");
  handler->addEventVariable("MT",MT);

  EventVariablePairMass* mWdijet = new EventVariablePairMass("WDIJETMASS", "goodJets", "WJET", mW, 10);
  handler->addEventVariable("WDIJETMASS", mWdijet);
  
  EventVariableN* nbJetsCSVM = new EventVariableN("NBJETSCSVM", "bJetsCSVM");
  handler->addEventVariable("NBJETSCSVM", nbJetsCSVM);
  
  EventVariableN* nbJetsCSVL = new EventVariableN("NBJETSCSVL", "bJetsCSVL");
  handler->addEventVariable("NBJETSCSVL", nbJetsCSVL);
  
  EventVariableN* nLeptons = new EventVariableN("NLEPTONS", "goodElectrons");
  nLeptons->addProduct("goodMuons");
  nLeptons->addProduct("goodTaus");
  handler->addEventVariable("NLEPTONS", nLeptons);
  
  EventVariableInRange<int>* el2 = new EventVariableInRange<int>("NGOODELECTRONS", 2, 2, "El2");
  handler->addEventVariable("El2", el2);
  
  EventVariableInRange<int>* dileptons = new EventVariableInRange<int>("NLEPTONS", 2, 1e6, "DILEPTONS");
  handler->addEventVariable("DILEPTONS", dileptons);
  
  EventVariableInRange<int>* trileptons = new EventVariableInRange<int>("NLEPTONS", 3, 1e6, "TRILEPTONS");
  handler->addEventVariable("TRILEPTONS", trileptons);
  
  EventVariableInRange<double>* mLeptonsOnZ = new EventVariableInRange<double>("MLEPTONS", mZ-10, mZ+10, "MLEPTONSONZ");
  handler->addEventVariable("MLEPTONSONZ", mLeptonsOnZ);

  EventVariableInRange<double>* met0to50 = new EventVariableInRange<double>("MET", 0, 50, "MET0to50");
  handler->addEventVariable("MET0to50", met0to50);

  EventVariableInRange<double>* ht0to200 = new EventVariableInRange<double>("HT", 0, 200, "HT0to200");
  handler->addEventVariable("HT0to200", ht0to200);

  EventVariableReversed* offZ = new EventVariableReversed("ONZ", "OFFZ");
  handler->addEventVariable("OFFZ", offZ);

  EventVariableInRange<int>* NOSSFgt0 = new EventVariableInRange<int>("NOSSF", 1, 1e6, "NOSSFgt0");
  handler->addEventVariable("NOSSFgt0", NOSSFgt0);

  EventVariableCombined* trileptonOnZcut = new EventVariableCombined("TRILEPTONS", "MLEPTONSONZ", true, "TRILEPTONONZ");
  trileptonOnZcut->addVariable("MET0to50");
  trileptonOnZcut->addVariable("HT0to200");
  trileptonOnZcut->addVariable("NOSSFgt0");
  trileptonOnZcut->addVariable("OFFZ");
  handler->addEventVariable("TRILEPTONONZ", trileptonOnZcut);
  
  EventVariableReversed* notTrileptonOnZcut = new EventVariableReversed("TRILEPTONONZ", "NOTTRILEPTONONZ");
  handler->addEventVariable("NOTTRILEPTONONZ", notTrileptonOnZcut);
  
  EventVariableInRange<double>* mLowDYcut = new EventVariableInRange<double>("LOWDYOSMINMLL", 12, 1e6, "MLOWDYCUT");
  handler->addEventVariable("MLOWDYCUT", mLowDYcut);
  
  EventVariableCombined* writeEvent = new EventVariableCombined("DILEPTONS", "MLOWDYCUT", true, "WRITEEVENT");
//  writeEvent->addVariable("NOTTRILEPTONONZ");
  handler->addEventVariable("WRITEEVENT", writeEvent);

  TF1* flatWeight = new TF1("flat","1",0,10000000);
  handler->addEventVariable("FLATWEIGHT",new EventVariableTF1<int>("FLATWEIGHT","RUN",flatWeight));
  handler->addWeightVariable("FLATWEIGHT");
}

