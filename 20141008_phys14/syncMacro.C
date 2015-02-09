void syncMacro(const char* ifname="/cms/matt/mwalker/NTUPLES/tmp/WZ/flat_WZ_0.root"
		  , const char* ofname="exampleAnalyzer.root"
		  , int mode = 0
		  , int maxEvents = 0
		  , const char* json = "/cms/thomassen/2013/tcH/RootC/Merged_190456-208686_8TeV_PromptReReco_Collisions12_19.490ifb.json"
)
{
  gSystem->Load("libRutgersIAFEventAnalyzer.so");
  gROOT->ProcessLine(TString::Format(".include %s/src", getenv("CMSSW_BASE")));
  gROOT->ProcessLine(".L helperMiniAOD.C+");
  gROOT->ProcessLine(".L helper2.C");
  //gROOT->ProcessLine(".L helperEventAnalyzer.C+");
  //gROOT->ProcessLine(".L helperTriggers.C");

  TChain* tree = new TChain("tree");
  TString input=ifname;
  //input += "/*.root";
  tree->Add(input);

  FlatTreeReader* reader = new FlatTreeReader(tree);

  BaseHandler* handler = new BaseHandler(ofname,reader);

  //AnalysisTreeWriter* writer = new AnalysisTreeWriter(handler,"treeR");

  //handler->setWriter(writer);

  //handler->readGoodRunLumiFromJSON(TString(json));

  handler->setDebugMode(true);
  setupPrintRA7Sync(handler);
  handler->addPrintModule(new PrintModuleEverything("everything"));
  //setupPrintElectrons(handler);

  setupProducts(handler);
  //setupTriggers(handler,mode);
  setupVariables2(handler);
  //setupFilterCuts(handler);

  //setupSignatures(handler);
  //setupOnZSignatures(handler);
  //addHistograms(handler);
  //setupEfficiencyProducts(handler);

  //handler->setMode("nEntryHigh",1);

  handler->initSignatures();
  //handler->eventLoop();
  handler->eventLoop(1,45939);
  //handler->eventLoop(1,99880);
  handler->finishSignatures();

  cout<<"Done, exiting ...."<<endl;
}
