void dumpMacro(const char* ifname="/cms/emmanuel/2015/MCData/DYJetsToLL_M-50_13TeV-madgraph-pythia8/Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM/150120_202711/0000"
		  , const char* ofname="exampleAnalyzer.root"
		  , int mode = 0
		  , int maxEvents = 0
		  , const char* json = "/cms/thomassen/2013/tcH/RootC/Merged_190456-208686_8TeV_PromptReReco_Collisions12_19.490ifb.json"
)
{
  gSystem->Load("libRutgersIAFEventAnalyzer.so");
  gROOT->ProcessLine(TString::Format(".include %s/src", getenv("CMSSW_BASE")));
  //gROOT->ProcessLine(".L helperMiniAOD.C+");
  //gROOT->ProcessLine(".L helper2.C");
  //gROOT->ProcessLine(".L helperEventAnalyzer.C+");
  //gROOT->ProcessLine(".L helperTriggers.C");

  TChain* tree = new TChain("tree");
  TString input=ifname;
  input += "/*.root";
  tree->Add(input);

  FlatTreeReader* reader = new FlatTreeReader(tree);

  BaseHandler* handler = new BaseHandler(ofname,reader);

  AnalysisTreeWriter* writer = new AnalysisTreeWriter(handler,"treeR");

  handler->setWriter(writer);

  //handler->readGoodRunLumiFromJSON(TString(json));

  handler->setDebugMode(true);
  //handler->addPrintModule(new PrintModuleEverything("everything"));
  //setupPrintElectrons(handler);

  //setupProducts(handler);
  //setupTriggers(handler,mode);
  //setupVariables2(handler);
  //setupFilterCuts(handler);
  handler->addProduct("ALLTAUS","ALL");
  handler->addProductCut("ALLTAUS","isTau");
  PrintModuleProduct* printTaus = new PrintModuleProduct("ALLTAUS","printTaus");
  double ddd=0;
  bool bbb = false;
  printTaus->addVariable("leadPFCandpt",ddd);
  printTaus->addVariable("byLooseCombinedIsolationDeltaBetaCorr3Hits",bbb);
  printTaus->addVariable("againstElectronMediumMVA3",bbb);
  printTaus->addVariable("againstMuonTight3",bbb);
  handler->addPrintModule(printTaus);
  //setupSignatures(handler);
  //setupOnZSignatures(handler);
  //addHistograms(handler);
  //setupEfficiencyProducts(handler);

  handler->setMode("nEntryHigh",50000000);

  handler->initSignatures();
  handler->eventLoop();
  //handler->eventLoop(1,24248);
  handler->finishSignatures();

  cout<<"Done, exiting ...."<<endl;
}
