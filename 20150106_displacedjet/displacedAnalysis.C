void displacedAnalysis(const char* ifname="../20141204_displacedSim/output"
		  , const char* ofname="exampleAnalyzed.root"
		  , bool isSignal = false
		  , int mode = 0
		  , int maxEvents = 1000000
		  , const char* json = "/cms/thomassen/2013/tcH/RootC/Merged_190456-208686_8TeV_PromptReReco_Collisions12_19.490ifb.json"
)
{
  gSystem->Load("libRutgersIAFEventAnalyzer.so");
  gROOT->ProcessLine(TString::Format(".include %s/src", getenv("CMSSW_BASE")));
  gROOT->ProcessLine(".L helperDisplaced.C+");

  TChain* tree = new TChain("tree");
  TString input=ifname;
  //input += "/*.root";
  tree->Add(input);

  FlatTreeReader* reader = new FlatTreeReader(tree);

  BaseHandler* handler = new BaseHandler(ofname,reader);

  AnalysisTreeWriter* writer = new AnalysisTreeWriter(handler,"treeR");

  handler->setWriter(writer);

  ////////////////////////////////////////////////////
  //Setup some products jets, electrons, muons, etc//
  ///////////////////////////////////////////////////
  setupProducts(handler,isSignal);
  //handler->addProductCut("goodSignalJets","fromSecondary");

  //////////////////////
  //Add some variables//
  //////////////////////
  setupVariables(handler);

  //////////////////////////
  //Create some histograms//
  //////////////////////////
  addHistograms(handler);

  //////////////////////////////////
  //Final bookkeeping and execution//
  ///////////////////////////////////

  handler->setMode("nEntryHigh",maxEvents);
  //handler->setMode("nEntryHigh",1);
  //handler->setDebugMode(true);
  //handler->addPrintModule(new PrintModuleEverything("everything"));

  handler->initSignatures();
  handler->eventLoop();
  //handler->eventLoop(1,24248);
  handler->finishSignatures();

  cout<<"Done, exiting ...."<<endl;
}
