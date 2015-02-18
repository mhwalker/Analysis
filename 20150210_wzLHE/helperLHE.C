#include <TF1.h>
#include <TH1F.h>
#include <TLorentzVector.h>
#include <TString.h>
#include "RutgersIAF/EventAnalyzer/interface/BaseHandler.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableValue.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableValueInList.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableAssociateVariable.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableMethod.h"
#include "RutgersIAF/EventAnalyzer/interface/ObjectVariableCombined.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableVector.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableObjectVariableExtreme.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableN.h"
#include "RutgersIAF/EventAnalyzer/interface/EventVariableInRange.h"
#include "RutgersIAF/EventAnalyzer/interface/SignatureTH1F_ObjectVariable.h"

void setupObjectVariables(BaseHandler* handler)
{
  ObjectVariableValueInList<int>* electronPDGID = new ObjectVariableValueInList<int>("PDGID",11);
  electronPDGID->addValue(-11);
  handler->addObjectVariable("isElectron",electronPDGID);

  ObjectVariableValueInList<int>* muonPDGID = new ObjectVariableValueInList<int>("PDGID",13);
  muonPDGID->addValue(-13);
  handler->addObjectVariable("isMuon",muonPDGID);

  ObjectVariableValueInList<int>* tauPDGID = new ObjectVariableValueInList<int>("PDGID",15);
  tauPDGID->addValue(-15);
  handler->addObjectVariable("isTau",tauPDGID);

  ObjectVariableValueInList<int>* wPDGID = new ObjectVariableValueInList<int>("PDGID",24);
  wPDGID->addValue(-24);
  handler->addObjectVariable("isW",wPDGID);

  handler->addObjectVariable("isZ", new ObjectVariableValue<int>("PDGID",23));
  handler->addObjectVariable("isH", new ObjectVariableValue<int>("PDGID",25));

  ObjectVariableCombined* isBoson = new ObjectVariableCombined("isZ","isH");
  isBoson->addVariable("isW");
  handler->addObjectVariable("isBoson",isBoson);

  handler->addObjectVariable("MOTHERPDGID", new ObjectVariableAssociateVariable<int>("MOTHER","PDGID"));

  handler->addObjectVariable("MOTHERZ",new ObjectVariableValue<int>("MOTHERPDGID",23));
  ObjectVariableValueInList<int>* motherW = new ObjectVariableValueInList<int>("MOTHERPDGID",24);
  motherW->addValue(-24);
  handler->addObjectVariable("MOTHERW",motherW);

  handler->addObjectVariable("ETA",new ObjectVariableMethod("ETA",&SignatureObject::Eta));
  handler->addObjectVariable("PT",new ObjectVariableMethod("PT",&SignatureObject::Pt));
  handler->addObjectVariable("PHI",new ObjectVariableMethod("PHI",&SignatureObject::Phi));
}

void setupProducts(BaseHandler* handler)
{

  handler->addProduct("Z","ALLMCPARTICLES");
  handler->addProductCut("Z","isZ");

  handler->addProduct("W","ALLMCPARTICLES");
  handler->addProductCut("W","isW");

  handler->addProduct("BOSONS","ALLMCPARTICLES");
  handler->addProductCut("BOSONS","isBoson");

  handler->addProduct("ELECTRONS","ALLMCPARTICLES");
  handler->addProductCut("ELECTRONS","isElectron");

  handler->addProduct("MUONS","ALLMCPARTICLES");
  handler->addProductCut("MUONS","isMuon");

  handler->addProduct("TAUS","ALLMCPARTICLES");
  handler->addProductCut("TAUS","isTau");

  handler->addProduct("ELECTRONSFROMZ","ELECTRONS");
  handler->addProductCut("ELECTRONSFROMZ","MOTHERZ");

  handler->addProduct("MUONSFROMZ","MUONS");
  handler->addProductCut("MUONSFROMZ","MOTHERZ");

  handler->addProduct("TAUSFROMZ","TAUS");
  handler->addProductCut("TAUSFROMZ","MOTHERZ");

  handler->addProduct("ELECTRONSFROMW","ELECTRONS");
  handler->addProductCut("ELECTRONSFROMW","MOTHERW");

  handler->addProduct("MUONSFROMW","MUONS");
  handler->addProductCut("MUONSFROMW","MOTHERW");

  handler->addProduct("TAUSFROMW","TAUS");
  handler->addProductCut("TAUSFROMW","MOTHERW");

}


void setupVariables(BaseHandler* handler)
{
  handler->addEventVariable("NTAUSFROMZ", new EventVariableN("NTAUSFROMZ","TAUSFROMZ"));
  handler->addEventVariable("NMUONSFROMZ", new EventVariableN("NMUONSFROMZ","MUONSFROMZ"));
  handler->addEventVariable("NELECTRONSFROMZ", new EventVariableN("NELECTRONSFROMZ","ELECTRONSFROMZ"));

  handler->addEventVariable("NTAUSFROMW", new EventVariableN("NTAUSFROMW","TAUSFROMW"));
  handler->addEventVariable("NMUONSFROMW", new EventVariableN("NMUONSFROMW","MUONSFROMW"));
  handler->addEventVariable("NELECTRONSFROMW", new EventVariableN("NELECTRONSFROMW","ELECTRONSFROMW"));

  handler->addEventVariable("ZPT", new EventVariableObjectVariableExtreme<double>("PT","Z"));
  handler->addEventVariable("ZETA", new EventVariableObjectVariableVector<double>("ETA","Z"));
  handler->addEventVariable("ZPHI", new EventVariableObjectVariableVector<double>("PHI","Z"));
  handler->addEventVariable("WPT", new EventVariableObjectVariableExtreme<double>("PT","W"));
  handler->addEventVariable("WETA", new EventVariableObjectVariableVector<double>("ETA","W"));
  handler->addEventVariable("WPHI", new EventVariableObjectVariableVector<double>("PHI","W"));

  handler->addEventVariable("TAUZETA", new EventVariableObjectVariableVector<double>("ETA","TAUSFROMZ"));
  handler->addEventVariable("TAUZPHI", new EventVariableObjectVariableVector<double>("PHI","TAUSFROMZ"));

  handler->addEventVariable("TAUWETA", new EventVariableObjectVariableVector<double>("ETA","TAUSFROMW"));
  handler->addEventVariable("TAUWPHI", new EventVariableObjectVariableVector<double>("PHI","TAUSFROMW"));

  handler->addEventVariable("NBOSONS", new EventVariableN("NBOSONS","BOSONS"));
  handler->addEventVariable("WRITEEVENT", new EventVariableInRange<int>("NBOSONS",0,100000));

}


void setupHistograms(BaseHandler* handler)
{
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ZETA","ETA","Z","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ZPHI","PHI","Z","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ZPT","PT","Z","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("WETA","ETA","W","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("WPHI","PHI","W","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("WPT","PT","W","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUZETA","ETA","TAUSFROMZ","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUZPHI","PHI","TAUSFROMZ","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUZPT","PT","TAUSFROMZ","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUWETA","ETA","TAUSFROMW","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUWPHI","PHI","TAUSFROMW","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("TAUWPT","PT","TAUSFROMW","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONZETA","ETA","MUONSFROMZ","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONZPHI","PHI","MUONSFROMZ","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONZPT","PT","MUONSFROMZ","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONWETA","ETA","MUONSFROMW","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONWPHI","PHI","MUONSFROMW","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("MUONWPT","PT","MUONSFROMW","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONZETA","ETA","ELECTRONSFROMZ","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONZPHI","PHI","ELECTRONSFROMZ","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONZPT","PT","ELECTRONSFROMZ","ETA",200,0,400));

  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONWETA","ETA","ELECTRONSFROMW","ETA",100,-5,5));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONWPHI","PHI","ELECTRONSFROMW","PHI",100,-3.142,3.142));
  handler->addHistogram(new SignatureTH1F_ObjectVariable<double>("ELECTRONWPT","PT","ELECTRONSFROMW","ETA",200,0,400));


}
