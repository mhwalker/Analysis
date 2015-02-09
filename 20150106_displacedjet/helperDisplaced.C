#include <TF1.h>
#include <TH1F.h>
#include <TLorentzVector.h>
#include <TString.h>
#include "RutgersIAF/EventAnalyzer/interface/BaseHandler.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableCombined.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableInRange.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableMass.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableN.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableMT.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectWeightPtTF1.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableOS.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableOSSF.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariablePairMass.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableMixedPairMass.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableReversed.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableSumPT.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableThreshold.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableTH1.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableTriggerWeight.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableValue.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectComparisonDeltaR.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectComparisonMatchDisplacedDeltaRPtFrac.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableCombined.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableElectronTotalIso.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableInRange.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableMethod.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableMuonTotalIso.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableRelIso.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableReversed.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableValue.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_EventVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_ObjectVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_AssociateVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectComparisonSkimRecoTracks.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectComparisonElectron.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_N.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableValueInList.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableInRange.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectComparisonMatchDeltaRCharge.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableSmearMET.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableRename.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH2F_EventVariableVsEventVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH2F_ObjectVariableVsObjectVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_NearestVertexRank.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableMax.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableVector.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableMax.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableGenVertexR.h"
#include "RutgersIAF/EventAnalyzer/interface/PrintModuleProduct.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_TriggerName.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableExtreme.h"
void setupProducts(BaseHandler* handler, bool isSignal)
{
  handler->addObjectVariable("isPhoton",new ObjectVariableValue<TString>("INPUTTYPE","photon"));
  handler->addObjectVariable("isMC",new ObjectVariableValue<TString>("INPUTTYPE","mc"));
  handler->addObjectVariable("isVertex",new ObjectVariableValue<TString>("INPUTTYPE","vertex"));
  handler->addObjectVariable("isMET", new ObjectVariableValue<TString>("INPUTTYPE","met"));
  handler->addObjectVariable("isTrigger",new ObjectVariableValue<TString>("INPUTTYPE","trigger"));

  handler->addProduct("ALLMUONS","ALL");
  handler->addProductCut("ALLMUONS","isMuon");

  handler->addProduct("ALLELECTRONS","ALL");
  handler->addProductCut("ALLELECTRONS","isElectron");

  handler->addProduct("ALLTAUS","ALL");
  handler->addProductCut("ALLTAUS","isTau");

  handler->addProduct("ALLPHOTONS","ALL");
  handler->addProductCut("ALLPHOTONS","isPhoton");

  handler->addProduct("ALLTRACKS","ALL");
  handler->addProductCut("ALLTRACKS","isTrack");

  handler->addProduct("ALLJETS","ALL");
  handler->addProductCut("ALLJETS","isJet");

  handler->addProduct("ALLMC","ALL");
  handler->addProductCut("ALLMC","isMC");

  handler->addProduct("ALLVERTICES","ALL");
  handler->addProductCut("ALLVERTICES","isVertex");

  handler->addProduct("ALLMET","ALL");
  handler->addProductCut("ALLMET","isMET");

  handler->addProduct("TRIGGERS","ALL");
  handler->addProductCut("TRIGGERS","isTrigger");

  ///Some variables///

  handler->addObjectVariable("ETA",new ObjectVariableMethod("ETA", &SignatureObject::Eta));
  handler->addObjectVariable("PHI",new ObjectVariableMethod("PHI", &SignatureObject::Phi));
  handler->addObjectVariable("ETA2p3",new ObjectVariableInRange<double>("ETA",-2.3,2.3,"ETA2p3"));
  handler->addObjectVariable("ETA2p4",new ObjectVariableInRange<double>("ETA",-2.4,2.4));
  handler->addObjectVariable("ETA2p5",new ObjectVariableInRange<double>("ETA",-2.5,2.5,"ETA2p5"));
  handler->addObjectVariable("BARREL",new ObjectVariableInRange<double>("ETA",-1.5,1.5,"barrelEta"));
  handler->addObjectVariable("ENDCAP",new ObjectVariableReversed("BARREL","endcapEta"));
  handler->addObjectVariable("POSITIVE",new ObjectVariableInRange<int>("charge",0,10,"CHARGEPOS"));
  handler->addObjectVariable("NEGATIVE",new ObjectVariableInRange<int>("charge",-10,0,"CHARGENEG"));
  handler->addObjectVariable("PT6",new ObjectVariableInRange<double>("PT",6.0,10000.0,"PT6"));
  handler->addObjectVariable("PT7",new ObjectVariableInRange<double>("PT",7.0,10000.0,"PT7"));
  handler->addObjectVariable("PT20",new ObjectVariableInRange<double>("PT",20.0,10000.0,"PT20"));
  handler->addObjectVariable("PT30",new ObjectVariableInRange<double>("PT",30.0,10000.0,"PT30"));
  handler->addObjectVariable("PT40",new ObjectVariableInRange<double>("PT",40.0,100000.0));
  //handler->addObjectVariable("CHARGE",new ObjectVariableRename<int>("charge","CHARGE"));
  handler->addObjectVariable("genDxy", new ObjectVariableGenVertexR("genDxy"));

  ////////////////////
  ///Muon Variables///
  ////////////////////

  handler->addObjectVariable("MUON_normalizedChi2",new ObjectVariableInRange<double>("normalizedChi2",0,10));
  handler->addObjectVariable("MUON_numberOfValidMuonHits", new ObjectVariableInRange<int>("numberOfValidMuonHits",1,100000));
  handler->addObjectVariable("MUON_numberOfMatchedStations",new ObjectVariableInRange<int>("numberOfMatchedStations",2,1000000));
  handler->addObjectVariable("MUON_dxy", new ObjectVariableInRange<double>("dxy",-0.02,0.02));
  handler->addObjectVariable("MUON_nonprompt", new ObjectVariableReversed("MUON_dxy","MUON_nonprompt"));
  handler->addObjectVariable("MUON_dz", new ObjectVariableInRange<double>("dz",-0.5,0.5));
  handler->addObjectVariable("MUON_numberOfValidPixelHits", new ObjectVariableInRange<int>("numberOfValidPixelHits",1,1000000));
  handler->addObjectVariable("MUON_trackerLayersWithMeasurement", new ObjectVariableInRange<int>("trackerLayersWithMeasurement",6,1000000));
  handler->addObjectVariable("MUON_PFCHARGEDHADRONISO", new ObjectVariableRename<double>("pfIsolationR03sumChargedHadronPt","PF_CHARGEDHADRONISO"),false);
  handler->addObjectVariable("MUON_PFNEUTRALHADRONISO", new ObjectVariableRename<double>("pfIsolationR03sumNeutralHadronEt","PF_NEUTRALHADRONISO"),false);
  handler->addObjectVariable("MUON_PFPHOTONISO", new ObjectVariableRename<double>("pfIsolationR03sumPhotonEt","PF_PHOTONISO"),false);
  handler->addObjectVariable("MUON_BETA", new ObjectVariableRename<double>("pfIsolationR03sumPUPt","BETA"),false);

  ////////////////////////
  ///Electron Variables///
  ////////////////////////
  handler->addObjectVariable("ELECTRON_PFCHARGEDHADRONISO", new ObjectVariableRename<double>("sumChargedHadronPt","PF_CHARGEDHADRONISO"),false);
  handler->addObjectVariable("ELECTRON_PFNEUTRALHADRONISO", new ObjectVariableRename<double>("sumNeutralHadronEt","PF_NEUTRALHADRONISO"),false);
  handler->addObjectVariable("ELECTRON_PFPHOTONISO", new ObjectVariableRename<double>("sumPhotonEt","PF_PHOTONISO"),false);
  handler->addObjectVariable("ELECTRON_BETA", new ObjectVariableRename<double>("sumPUPt","BETA"),false);
  handler->addObjectVariable("ELECTRON_INGAPPOS",new ObjectVariableInRange<double>("superClustereta",1.4442,1.566));
  handler->addObjectVariable("ELECTRON_INGAPNEG",new ObjectVariableInRange<double>("superClustereta",-1.566,-1.4442));
  ObjectVariableCombined* electron_ingap = new ObjectVariableCombined("ELECTRON_INGAPPOS","ELECTRON_INGAPNEG",false,"ELECTORN_INGAP");
  handler->addObjectVariable("ELECTRON_INGAP",electron_ingap);
  handler->addObjectVariable("ELECTRON_NOTGAP",new ObjectVariableReversed("ELECTRON_INGAP","ELECTRON_NOTGAP"));
  handler->addObjectVariable("ELECTRON_BARREL_deltaEtaSuperClusterTrackAtVtx", new ObjectVariableInRange<double>("deltaEtaSuperClusterTrackAtVtx",-0.0181,0.0181));
  handler->addObjectVariable("ELECTRON_BARREL_deltaPhiSuperClusterTrackAtVtx", new ObjectVariableInRange<double>("deltaPhiSuperClusterTrackAtVtx",-0.0936,0.0936));
  handler->addObjectVariable("ELECTRON_ENDCAP_deltaEtaSuperClusterTrackAtVtx", new ObjectVariableInRange<double>("deltaEtaSuperClusterTrackAtVtx",-0.0124,0.0124));
  handler->addObjectVariable("ELECTRON_ENDCAP_deltaPhiSuperClusterTrackAtVtx", new ObjectVariableInRange<double>("deltaPhiSuperClusterTrackAtVtx",-0.0642,0.0642));
  handler->addObjectVariable("ELECTRON_BARREL_hadronicOverEm",new ObjectVariableInRange<double>("hadronicOverEm",0.0,0.141));
  handler->addObjectVariable("ELECTRON_ENDCAP_hadronicOverEm",new ObjectVariableInRange<double>("hadronicOverEm",0.0,0.1115));
  handler->addObjectVariable("ELECTRON_BARREL_sigmaIetaIeta",new ObjectVariableInRange<double>("full5x5_sigmaIetaIeta",0,0.0123));
  handler->addObjectVariable("ELECTRON_ENDCAP_sigmaIetaIeta",new ObjectVariableInRange<double>("full5x5_sigmaIetaIeta",0,0.035));
  handler->addObjectVariable("ELECTRON_BARREL_1oEm1oP", new ObjectVariableInRange<double>("1oEm1oP",0,0.1353));
  handler->addObjectVariable("ELECTRON_ENDCAP_1oEm1oP", new ObjectVariableInRange<double>("1oEm1oP",0,0.1443));
  handler->addObjectVariable("ELECTRON_passConversionVeto",new ObjectVariableValue<bool>("passConversionVeto",true));
  handler->addObjectVariable("ELECTRON_BARREL_dz", new ObjectVariableInRange<double>("dz",-0.54342,0.54342));
  handler->addObjectVariable("ELECTRON_BARREL_dxy", new ObjectVariableInRange<double>("dxy",-0.0166,0.0166));
  handler->addObjectVariable("ELECTRON_ENDCAP_dz", new ObjectVariableInRange<double>("dz",-0.9187,0.9187));
  handler->addObjectVariable("ELECTRON_ENDCAP_dxy", new ObjectVariableInRange<double>("dxy",-0.098,0.098));
  handler->addObjectVariable("ELECTRON_dz5", new ObjectVariableInRange<double>("dz",-5.0,5.0));

  /////////////////////
  ///Track variables///
  /////////////////////
  handler->addObjectVariable("TRACK_PFCHARGEDHADRONISO", new ObjectVariableRename<double>("chargedHadronIsoFromPF","PF_CHARGEDHADRONISO"),false);
  handler->addObjectVariable("TRACK_PFNEUTRALHADRONISO", new ObjectVariableRename<double>("neutralHadronIsoFromPF","PF_NEUTRALHADRONISO"),false);
  handler->addObjectVariable("TRACK_PFPHOTONISO", new ObjectVariableRename<double>("neutralPhotonIsoFromPF","PF_PHOTONISO"),false);
  handler->addObjectVariable("TRACK_BETA", new ObjectVariableRename<double>("betaIsoFromPF","BETA"),false);
  handler->addObjectVariable("TRACK_fromPV", new ObjectVariableInRange<int>("fromPV",2,100000));


  /////////////////
  ////Variables////
  /////////////////  
  handler->addObjectVariable("LEPTON_totalIso", new ObjectVariableMuonTotalIso("TOTALISO"),false);
  handler->addObjectVariable("RELISO",new ObjectVariableRelIso("RELISO"));
  handler->addObjectVariable("IREL0p15",new ObjectVariableInRange<double>("RELISO",0,0.15,"IREL0p15"));
  handler->addObjectVariable("IREL0p23",new ObjectVariableInRange<double>("RELISO",0,0.23,"IREL0p23"));
  handler->addObjectVariable("IREL0p24",new ObjectVariableInRange<double>("RELISO",0,0.24,"IREL0p24"));
  handler->addObjectVariable("IREL0p25",new ObjectVariableInRange<double>("RELISO",0,0.25,"IREL0p25"));
  handler->addObjectVariable("IREL0p35",new ObjectVariableInRange<double>("RELISO",0,0.3529,"IREL0p35"));


  ObjectVariableCombined* electron_barrel = new ObjectVariableCombined("BARREL","ELECTRON_BARREL_hadronicOverEm",true,"electron_barrel_good");
  electron_barrel->addVariable("ELECTRON_BARREL_sigmaIetaIeta");
  electron_barrel->addVariable("ELECTRON_BARREL_deltaPhiSuperClusterTrackAtVtx");
  electron_barrel->addVariable("ELECTRON_BARREL_deltaEtaSuperClusterTrackAtVtx");
  electron_barrel->addVariable("ELECTRON_BARREL_dz");
  electron_barrel->addVariable("ELECTRON_BARREL_dxy");
  electron_barrel->addVariable("ELECTRON_BARREL_1oEm1oP");
  electron_barrel->addVariable("IREL0p24");
  handler->addObjectVariable("ELECTRON_BARREL",electron_barrel);

  ObjectVariableCombined* electron_endcap = new ObjectVariableCombined("ENDCAP","ELECTRON_ENDCAP_hadronicOverEm",true,"electron_endcap_good");
  electron_endcap->addVariable("ELECTRON_ENDCAP_sigmaIetaIeta");
  electron_endcap->addVariable("ELECTRON_ENDCAP_deltaPhiSuperClusterTrackAtVtx");
  electron_endcap->addVariable("ELECTRON_ENDCAP_deltaEtaSuperClusterTrackAtVtx");
  electron_endcap->addVariable("ELECTRON_ENDCAP_dz");
  electron_endcap->addVariable("ELECTRON_ENDCAP_dxy");
  electron_endcap->addVariable("ELECTRON_ENDCAP_1oEm1oP");
  electron_endcap->addVariable("IREL0p35");
  handler->addObjectVariable("ELECTRON_ENDCAP",electron_endcap);

  handler->addObjectVariable("ELECTRON_COMBINED",new ObjectVariableCombined("ELECTRON_BARREL","ELECTRON_ENDCAP",false,"ELECTRON_COMBINED"));

  ObjectVariableCombined* electron_good = new ObjectVariableCombined("ELECTRON_COMBINED","PT10",true,"ELECTRON_GOOD");
  electron_good->addVariable("ETA2p4");
  electron_good->addVariable("ELECTRON_passConversionVeto");
  electron_good->addVariable("ELECTRON_NOTGAP");
  //electron_good->addVariable("ELECTRON_1oEm1oP");

  handler->addObjectVariable("ELECTRON_GOOD",electron_good);

  //////////////////
  ///Muon Product///
  //////////////////

  handler->addProduct("goodMuons","ALLMUONS");
  handler->addProductCut("goodMuons","PT10");
  handler->addProductCut("goodMuons","ETA2p4");
  handler->addProductCut("goodMuons","IREL0p15");
  handler->addProductCut("goodMuons","isGlobalMuon");
  handler->addProductCut("goodMuons","isPFMuon");
  handler->addProductCut("goodMuons","MUON_normalizedChi2");
  handler->addProductCut("goodMuons","MUON_numberOfValidMuonHits");
  handler->addProductCut("goodMuons","MUON_numberOfMatchedStations");
  handler->addProductCut("goodMuons","MUON_dxy");
  handler->addProductCut("goodMuons","MUON_dz");
  handler->addProductCut("goodMuons","MUON_numberOfValidPixelHits");
  handler->addProductCut("goodMuons","MUON_trackerLayersWithMeasurement");

  handler->addProduct("probeMuons","ALLMUONS");
  handler->addProductCut("probeMuons","ETA2p4");
  handler->addProductCut("probeMuons","isGlobalMuon");
  handler->addProductCut("probeMuons","MUON_dz");

  //////////////
  ///Electron///
  //////////////

  handler->addProduct("goodElectrons","ALLELECTRONS");
  handler->addProductCut("goodElectrons","PT10");
  handler->addProductCut("goodElectrons","ETA2p4");
  //handler->addProductCut("goodElectrons","IREL0p23");
  handler->addProductCut("goodElectrons","ELECTRON_COMBINED");
  //handler->addProductCut("goodElectrons","ELECTRON_dxy");
  handler->addProductCut("goodElectrons","ELECTRON_passConversionVeto");
  //handler->addProductCut("goodElectrons","ELECTRON_dz");
  handler->addProductCut("goodElectrons","ELECTRON_NOTGAP");
  //handler->addProductCut("goodElectrons","ELECTRON_1oEm1oP");

  handler->addProduct("probeElectrons","ALLELECTRONS");
  handler->addProductCut("probeElectrons","ETA2p4");
  handler->addProductCut("probeElectrons","ELECTRON_NOTGAP");
  handler->addProductCut("probeElectrons","ELECTRON_dz");
  handler->addProductCut("probeElectrons","ELECTRON_passConversionVeto");

  ////////
  ///MC///
  ////////
  ObjectVariableValueInList<int>* electronPDGID = new ObjectVariableValueInList<int>("pdgId",11);
  electronPDGID->addValue(-11);
  handler->addObjectVariable("ELECTRONPDGID",electronPDGID);
  ObjectVariableValueInList<int>* muonPDGID = new ObjectVariableValueInList<int>("pdgId",13);
  muonPDGID->addValue(-13);
  handler->addObjectVariable("MUONPDGID",muonPDGID);
  ObjectVariableValueInList<int>* tauPDGID = new ObjectVariableValueInList<int>("pdgId",15);
  tauPDGID->addValue(-15);
  handler->addObjectVariable("TAUPDGID",tauPDGID);
  handler->addObjectVariable("MOTHERZ",new ObjectVariableValue<int>("motherpdgId",23));
  ObjectVariableValueInList<int>* motherBoson = new ObjectVariableValueInList<int>("motherpdgId",23);
  motherBoson->addValue(24);
  motherBoson->addValue(-24);
  motherBoson->addValue(25);
  handler->addObjectVariable("MOTHERBOSON",motherBoson);

  ObjectVariableValueInList<int>* quarkPDGID = new ObjectVariableValueInList<int>("pdgId",1);
  quarkPDGID->addValue(-1);
  quarkPDGID->addValue(2);
  quarkPDGID->addValue(-2);
  quarkPDGID->addValue(3);
  quarkPDGID->addValue(-3);
  quarkPDGID->addValue(-4);
  quarkPDGID->addValue(4);
  handler->addObjectVariable("QUARK",quarkPDGID);

  ObjectVariableValue<int>* status23 = new ObjectVariableValue<int>("status",23);
  handler->addObjectVariable("STATUS23",status23);

  ObjectVariableValueInList<int>* motherTau = new ObjectVariableValueInList<int>("motherpdgId",15);
  motherTau->addValue(-15);
  handler->addObjectVariable("MOTHERTAU",motherTau);

  ObjectVariableValueInList<int>* isBoson = new ObjectVariableValueInList<int>("pdgId",23);
  isBoson->addValue(24);
  isBoson->addValue(-24);
  isBoson->addValue(25);
  handler->addObjectVariable("isBOSON",isBoson);


  handler->addProduct("BOSONS","ALLMC");
  handler->addProductCut("BOSONS","isBOSON");

  handler->addProduct("MCELECTRONS","ALLMC");
  handler->addProductCut("MCELECTRONS","ELECTRONPDGID");
  handler->addProduct("MCMUONS","ALLMC");
  handler->addProductCut("MCMUONS","MUONPDGID");
  handler->addProduct("MCTAUS","ALLMC");
  handler->addProductCut("MCTAUS","TAUPDGID");

  handler->addProduct("MCELECTRONSFROMZ","MCELECTRONS");
  handler->addProductCut("MCELECTRONSFROMZ","MOTHERZ");
  handler->addProduct("MCMUONSFROMZ","MCMUONS");
  handler->addProductCut("MCMUONSFROMZ","MOTHERZ");

  handler->addProduct("MCELECTRONSFROMBOSON","MCELECTRONS");
  handler->addProductCut("MCELECTRONSFROMBOSON","MOTHERBOSON");
  handler->addProduct("MCMUONSFROMBOSON","MCMUONS");
  handler->addProductCut("MCMUONSFROMBOSON","MOTHERBOSON");
  handler->addProduct("MCTAUSFROMBOSON","MCTAUS");
  handler->addProductCut("MCTAUSFROMBOSON","MOTHERBOSON");

  handler->addProduct("MCELECTRONSFROMTAU","MCELECTRONS");
  handler->addProductCut("MCELECTRONSFROMTAU","MOTHERTAU");
  handler->addProduct("MCMUONSFROMTAU","MCMUONS");
  handler->addProductCut("MCMUONSFROMTAU","MOTHERTAU");

  handler->addProduct("MCSIGNALQUARKS","ALLMC");
  handler->addProductCut("MCSIGNALQUARKS","QUARK");
  handler->addProductCut("MCSIGNALQUARKS","STATUS23");

  ////////////
  ///Tracks///
  ////////////
  handler->addProduct("basicTracks","ALLTRACKS");
  handler->addProductCut("basicTracks","PT6");
  handler->addProductCut("basicTracks","ETA2p4");
  handler->addProductCut("basicTracks","trackHighPurity");
  handler->addProductCut("basicTracks","MUON_dz");

  handler->addProduct("promptTracks","basicTracks");
  handler->addProductCut("promptTracks","MUON_dxy");
  handler->addProductCut("promptTracks","TRACK_fromPV");
  handler->addProduct("nonPromptTracks","basicTracks");
  handler->addProductCut("nonPromptTracks","MUON_nonprompt");

  handler->addProduct("goodTracks","promptTracks");
  handler->addProductCut("goodTracks","IREL0p24");
  handler->addProductCut("goodTracks","PT10");

  //////////////
  //Setup Jets//
  //////////////
  handler->addObjectVariable("JET_NEUTRALHADRONFRACTION", new ObjectVariableInRange<double>("neutralHadronEnergyFraction",0,0.99));
  handler->addObjectVariable("JET_NEUTRALEMFRACTION", new ObjectVariableInRange<double>("neutralEmEnergyFraction", 0,0.99));
  handler->addObjectVariable("JET_NUMBEROFCONSTITUENTS", new ObjectVariableInRange<int>("chargedMultiplicity",1,100000));
  handler->addObjectVariable("CSVM",new ObjectVariableInRange<double>("combinedSecondaryVertexBJetTags",0.679,1000.0));
  handler->addObjectVariable("CSVL",new ObjectVariableInRange<double>("combinedSecondaryVertexBJetTags",0.244,1000.0));
  handler->addObjectVariable("CALOJET", new ObjectVariableValue<TString>("INPUTTYPE","calojet"));
  handler->addProduct("goodJets","ALLJETS");
  handler->addProductCut("goodJets","PT30");
  handler->addProductCut("goodJets","ETA2p4");
  //handler->addProductCut("goodJets","CALOJET");
  handler->addProductCut("goodJets","JET_NEUTRALHADRONFRACTION");
  handler->addProductCut("goodJets","JET_NEUTRALEMFRACTION");
  handler->addProductCut("goodJets","JET_NUMBEROFCONSTITUENTS");

  handler->addProduct("bJetsCSVM","goodJets");
  handler->addProductCut("bJetsCSVM","CSVM");

  handler->addProduct("bJetsCSVL","goodJets");
  handler->addProductCut("bJetsCSVL","CSVL");

  handler->addProduct("caloJets","ALLJETS");
  handler->addProductCut("caloJets","CALOJET");
  handler->addProductCut("caloJets","PT30");
  handler->addProductCut("caloJets","ETA2p4");


  handler->addProduct("goodSignalJets","caloJets");
  if(isSignal){
    ObjectComparisonMatchDisplacedDeltaRPtFrac* matchDisplaced = new ObjectComparisonMatchDisplacedDeltaRPtFrac(0.5,0.5,"signalquark");
    handler->addProductComparison("goodSignalJets","MCSIGNALQUARKS",matchDisplaced,false);
  }

  ////////////////////////
  ///MC matched leptons///
  ////////////////////////
  handler->addProduct("goodElectronsMatched","goodElectrons");
  handler->addProduct("goodMuonsMatched","goodMuons");

  handler->addProduct("goodElectronsFromTau","goodElectrons");
  handler->addProduct("goodMuonsFromTau","goodMuons");

  handler->addProduct("goodElectronsNotMatched","goodElectrons");
  handler->addProduct("goodMuonsNotMatched","goodMuons");


  /////////////////
  ///Separations///
  /////////////////
  ObjectComparisonDeltaR* deltaR0p005 = new ObjectComparisonDeltaR(0.005);
  ObjectComparisonDeltaR* deltaR0p1 = new ObjectComparisonDeltaR(0.1);
  ObjectComparisonDeltaR* deltaR0p3 = new ObjectComparisonDeltaR(0.3);

  ObjectComparisonMatchDeltaRCharge* mcMatch = new ObjectComparisonMatchDeltaRCharge(0.1,"genParticle");

  handler->addProductSelfComparison("goodMuons",deltaR0p1);
  handler->addProductSelfComparison("goodElectrons",deltaR0p1);
  handler->addProductSelfComparison("probeMuons",deltaR0p1);
  handler->addProductSelfComparison("probeElectrons",deltaR0p1);
  handler->addProductSelfComparison("basicTracks",deltaR0p005);

  handler->addProductComparison("goodElectrons","goodMuons",deltaR0p1);
  handler->addProductComparison("basicTracks","goodMuons",deltaR0p3);
  handler->addProductComparison("basicTracks","goodElectrons",deltaR0p3);

  handler->addProductComparison("goodJets","goodMuons",deltaR0p3);
  handler->addProductComparison("goodJets","goodElectrons",deltaR0p3);
  handler->addProductComparison("caloJets","goodMuons",deltaR0p3);
  handler->addProductComparison("caloJets","goodElectrons",deltaR0p3);

  handler->addProductComparison("goodElectronsMatched","MCELECTRONSFROMBOSON",mcMatch,false);
  handler->addProductComparison("goodMuonsMatched","MCMUONSFROMBOSON",mcMatch,false);
  handler->addProductComparison("goodElectronsFromTau","MCELECTRONSFROMTAU",mcMatch,false);
  handler->addProductComparison("goodMuonsFromTau","MCMUONSFROMTAU",mcMatch,false);

  handler->addProductComparison("goodElectronsNotMatched","goodElectronsMatched",deltaR0p1);
  handler->addProductComparison("goodElectronsNotMatched","goodElectronsFromTau",deltaR0p1);
  handler->addProductComparison("goodMuonsNotMatched","goodMuonsMatched",deltaR0p1);
  handler->addProductComparison("goodMuonsNotMatched","goodMuonsFromTau",deltaR0p1);

  //////////////////////
  ///Derived Products////
  //////////////////////

  handler->addProduct("goodElectronsNEG","goodElectrons");
  handler->addProductCut("goodElectronsNEG","NEGATIVE");
  handler->addProduct("goodElectronsPOS","goodElectrons");
  handler->addProductCut("goodElectronsPOS","POSITIVE");
  handler->addProduct("probeElectronsNEG","probeElectrons");
  handler->addProductCut("probeElectronsNEG","NEGATIVE");
  handler->addProduct("probeElectronsPOS","probeElectrons");
  handler->addProductCut("probeElectronsPOS","POSITIVE");

  handler->addProduct("goodMuonsNEG","goodMuons");
  handler->addProductCut("goodMuonsNEG","NEGATIVE");
  handler->addProduct("goodMuonsPOS","goodMuons");
  handler->addProductCut("goodMuonsPOS","POSITIVE");
  handler->addProduct("probeMuonsNEG","probeMuons");
  handler->addProductCut("probeMuonsNEG","NEGATIVE");
  handler->addProduct("probeMuonsPOS","probeMuons");
  handler->addProductCut("probeMuonsPOS","POSITIVE");

  handler->addProduct("MCMUONSFROMZPOS","MCMUONSFROMZ");
  handler->addProductCut("MCMUONSFROMZPOS","POSITIVE");
  handler->addProduct("MCMUONSFROMZNEG","MCMUONSFROMZ");
  handler->addProductCut("MCMUONSFROMZNEG","NEGATIVE");

  handler->addProduct("MCELECTRONSFROMZPOS","MCELECTRONSFROMZ");
  handler->addProductCut("MCELECTRONSFROMZPOS","POSITIVE");
  handler->addProduct("MCELECTRONSFROMZNEG","MCELECTRONSFROMZ");
  handler->addProductCut("MCELECTRONSFROMZNEG","NEGATIVE");
}


void setupVariables(BaseHandler* handler)
{

  handler->addEventVariable("N_bosons", new EventVariableN("N_bosons","BOSONS"));
  handler->addEventVariable("N_bJetsCSVM", new EventVariableN("N_bJetsCSVM","bJetsCSVM"));
  handler->addEventVariable("N_bJetsCSVL", new EventVariableN("N_bJetsCSVL","bJetsCSVL"));
  handler->addEventVariable("WRITEEVENT", new EventVariableInRange<int>("N_bosons",0,10000));

  handler->addEventVariable("N_goodSignalJets", new EventVariableN("N_goodSignalJets","goodSignalJets"));
  handler->addEventVariable("PTGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("PT","goodSignalJets"));
  handler->addEventVariable("ETAGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("ETA","goodSignalJets"));
  handler->addEventVariable("refitVertexTotalChiSquaredGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("refitVertexTotalChiSquared","goodSignalJets"));
  handler->addEventVariable("refitVertexDegreesOfFreedomGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("refitVertexDegreesOfFreedom","goodSignalJets"));
  handler->addEventVariable("refitVertexChi2NDoFGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("refitVertexChi2NDoF","goodSignalJets"));
  handler->addEventVariable("refitVertexDistanceToBeamGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("refitVertexDistanceToBeam","goodSignalJets"));
  handler->addEventVariable("refitVertexTransverseSigGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("refitVertexTransverseSig","goodSignalJets"));
  handler->addEventVariable("sumIPGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("sumIP","goodSignalJets"));
  handler->addEventVariable("sumIPpTWeightGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("sumIPpTWeight","goodSignalJets"));
  handler->addEventVariable("sumIPpTNormGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("sumIPpTNorm","goodSignalJets"));
  handler->addEventVariable("sumIPSigGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("sumIPSig","goodSignalJets"));
  handler->addEventVariable("sumIPLogSigGOODSIGNALJETS", new EventVariableObjectVariableVector<double>("sumIPLogSig","goodSignalJets"));
  handler->addEventVariable("nMatchedTracksGOODSIGNALJETS", new EventVariableObjectVariableVector<int>("nMatchedTracks","goodSignalJets"));

  handler->addEventVariable("MET",new EventVariableObjectVariableExtreme<double>("PT","ALLMET"));
}

void addHistograms(BaseHandler* handler)
{

  handler->addHistogram(new SignatureTH1F_N("N_MCSIGNALQUARKS","MCSIGNALQUARKS"));
  handler->addHistogram(new SignatureTH1F_N("N_GOODJETS","goodJets"));
  handler->addHistogram(new SignatureTH1F_N("N_CALOJETS","caloJets"));
  handler->addHistogram(new SignatureTH1F_N("N_CALOJETSMATCHED","goodSignalJets"));
  handler->addHistogram(new SignatureTH1F_TriggerName("TriggerNames","TRIGGERS"));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("SIGNALQUARK_vx","vx","MCSIGNALQUARKS","x",100,-50,50));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("SIGNALQUARK_vy","vy","MCSIGNALQUARKS","y",100,-50,50));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("SIGNALQUARK_vz","vz","MCSIGNALQUARKS","z",100,-50,50));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("SIGNALQUARK_etaOnECAL","etaOnECAL","MCSIGNALQUARKS","",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("SIGNALQUARK_phiOnECAL","phiOnECAL","MCSIGNALQUARKS","",100,-3.142,3.142));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_jetArea","jetArea","caloJets","jet area",50,0,2.0));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_pileup","pileup","caloJets","pileup",50,0,1.0));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_maxEInEmTowers","maxEInEmTowers","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_maxEInHadTowers","maxEInHadTowers","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_energyFractionHadronic","energyFractionHadronic","caloJets","",50,0,1));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_emEnergyFraction","emEnergyFraction","caloJets","",50,0,1));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_hadEnergyInHB","hadEnergyInHB","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_hadEnergyInHO","hadEnergyInHO","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_hadEnergyInHE","hadEnergyInHE","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_hadEnergyInHF","hadEnergyInHF","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_emEnergyInEB","emEnergyInEB","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_emEnergyInEE","emEnergyInEE","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_emEnergyInHF","emEnergyInHF","caloJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_sumIP","sumIP","caloJets","",100,0,200));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_sumIPpTWeight","sumIPpTWeight","caloJets","",100,0,10000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_sumIPpTNorm","sumIPpTNorm","caloJets","",100,0,100));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_sumIPSig","sumIPSig","caloJets","",100,0,25000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_sumIPLogSig","sumIPLogSig","caloJets","",100,0,200));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<int>("CALOJETS_nMatchedTracks","nMatchedTracks","caloJets","N distribution",40,-0.5,39.5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexTotalChiSquared","refitVertexTotalChiSquared","caloJets","",100,0,10000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexDegreesOfFreedom","refitVertexDegreesOfFreedom","caloJets","",100,-0.5,99.5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexChi2NDOF","refitVertexChi2NDOF","caloJets","",100,0,5e6));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexDistanceToBeam","refitVertexDistanceToBeam","caloJets","",130,0,130));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexTransverseError","refitVertexTransverseError","caloJets","",100,0,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETS_refitVertexTransverseSig","refitVertexTransverseSig","caloJets","",100,0,5e6));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_jetArea","jetArea","goodSignalJets","jet area",50,0,2.0));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_pileup","pileup","goodSignalJets","pileup",50,0,1.0));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_maxEInEmTowers","maxEInEmTowers","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_maxEInHadTowers","maxEInHadTowers","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_energyFractionHadronic","energyFractionHadronic","goodSignalJets","",50,0,1));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_emEnergyFraction","emEnergyFraction","goodSignalJets","",50,0,1));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_hadEnergyInHB","hadEnergyInHB","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_hadEnergyInHO","hadEnergyInHO","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_hadEnergyInHE","hadEnergyInHE","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_hadEnergyInHF","hadEnergyInHF","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_emEnergyInEB","emEnergyInEB","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_emEnergyInEE","emEnergyInEE","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_emEnergyInHF","emEnergyInHF","goodSignalJets","energy",100,0,1000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_sumIP","sumIP","goodSignalJets","",100,0,200));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_sumIPpTWeight","sumIPpTWeight","goodSignalJets","",100,0,10000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_sumIPpTNorm","sumIPpTNorm","goodSignalJets","",100,0,100));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_sumIPSig","sumIPSig","goodSignalJets","",100,0,25000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_sumIPLogSig","sumIPLogSig","goodSignalJets","",100,0,200));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<int>("CALOJETSMATCHED_nMatchedTracks","nMatchedTracks","goodSignalJets","N distribution",40,-0.5,39.5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexTotalChiSquared","refitVertexTotalChiSquared","goodSignalJets","",100,0,10000));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexDegreesOfFreedom","refitVertexDegreesOfFreedom","goodSignalJets","",100,-0.5,99.5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexChi2NDOF","refitVertexChi2NDOF","goodSignalJets","",100,0,5e6));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexDistanceToBeam","refitVertexDistanceToBeam","goodSignalJets","",130,0,130));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexTransverseError","refitVertexTransverseError","goodSignalJets","",100,0,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("CALOJETSMATCHED_refitVertexTransverseSig","refitVertexTransverseSig","goodSignalJets","",100,0,5e6));

  handler->addHistogram(new SignatureTH2F_ObjectVariableVsObjectVariable<double,double>("ETA","PHI","goodSignalJets","ETAvsPHI_goodSignalJets","",100,-2.5,2.5,100,-3.142,3.142));

  handler->addHistogram(new SignatureTH1F_EventVariable<double>("MET","MET","MET",100,0,1000));
}
