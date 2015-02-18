#include <sys/stat.h>
#include <unistd.h>

void runPresenterB(TString ofname = "test.root") {
	gSystem->Load("libRutgersIAFAnalysisPresenter.so");
	gROOT->ProcessLine(TString::Format(".include %s/src", getenv("CMSSW_BASE")));
	gROOT->ProcessLine(".L helperAnalysisPresenter.C+");
	


	///////////////////////
	// Binning/selection //
	///////////////////////
	
	// Specify axes and bins of multidimensional histogram
	// For inclusive table
	std::string varexp = "NLEPTONS[0]{2,6,\"NLEPTONS\"}:MOSSF[0]{11,131,36,\"MOSSF\"}:NOSSF[0]{0,2,\"NOSSF\"}:ONZ{0,1,\"ONZ\"}:NGOODTAUS[0]{0,1,\"NGOODTAUS\"}:NBJETSCSVM[0]{0,10,\"NBJETSCSVM\"}:NBJETSCSVL[0]{0,10,\"NBJETSCSVL\"}:HT[0]{0,1000,10,\"HT\"}:MET[0]{0,1500,30,\"MET\"}:LT[0]{0,500,10,\"LT\"}";
	varexp += ":OSSFMAXMLL[0]{11,131,36,\"OSSFMAXMLL\"}:OSSFMINMLL[0]{11,131,36,\"OSSFMINMLL\"}";
	//varexp += ":PTGOODLEPTONS{10,500,49}";
	varexp += ":PTGOODLEPTONS[2]{10,500,49,\"PTLEP2\"}:PTGOODLEPTONS[0]{10,500,49,\"PTLEP0\"}";
	
	// Global cuts, if desired
	// Get rid of photon conversions
	TString selection = "(NOSSF[0] != 1 || NOTTRILEPTONONZ)";
	// Cut down charge flips
	// commented out because NPOSGOODMUONS etc. is not available in tcH ntuple
	//selection += " && (NLEPTONS != 3 || (NGOODMUONS == 3 || NGOODELECTRONS == 3 || abs(NPOSGOODMUONS+NPOSGOODELECTRONS-NNEGGOODMUONS-NNEGGOODELECTRONS) != 3))";
	//selection += " && max(PTGOODELECTRONS[0],PTGOODMUONS[0]) > 20";
	//selection += " && PTGOODLEPTONS@.size() > 2 && PTGOODLEPTONS[0] > 10 && PTGOODLEPTONS[1] > 10 && PTGOODLEPTONS[2] > 10";
	
	///////////////////////
	// Signal definition //
	///////////////////////
	//PhysicsContribution* signal = new PhysicsContribution("signal", "/cms/matt/mwalker/Analysis/20141008_phys14/allHistos_T1tttt_1500_100.root", 8.56418 * 0.389, "T1tttt_1500_100");
	PhysicsContribution* signal = new PhysicsContribution("signal", "/cms/matt/mwalker/Analysis/20141008_phys14/allHistos_T1tttt_1500_100.root", 0.0856418 * 0.389, "T1tttt_1500_100");
	//PhysicsContribution* signal = new PhysicsContribution("signal", "/cms/matt/mwalker/Analysis/20141008_phys14/allHistos_coNLSP_1400_1700.root", 0.09417, "coNLSP_1400_1700");
	signal->addWeight("WEIGHT[0]");
	//signal->addFlatUncertainty("dummy", 0.2);
	
	
	////////////////////////
	// Initialize and run //
	////////////////////////
	Assembler* assembler = new Assembler(ofname, "RECREATE");
	init(assembler);
	setupDataSingle(assembler);
	setupBackgroundMC(assembler);
	//setupBackgroundDD(assembler);
	assembler->addContribution(signal); // It is important to add the signal before setting up the rake rates
	//setupFakeRates(assembler);
	assembler->setDebug(true);
	assembler->process(varexp, selection);
	assembler->save();
		
	// At this point, we have the multidimensional histogram in memory and can start taking projections (tables, 1d histograms, ...)
	
	//mkdir("coNLSP_1400_1700_10_10_10", 0755);
	//chdir("coNLSP_1400_1700_10_10_10");
	mkdir("T1tttt_1500_100_10_10_10", 0755);
	chdir("T1tttt_1500_100_10_10_10");
	
	// Inclusive plots: 3L
	assembler->setRange("NLEPTONS", 3, 3);
	assembler->setRange("NGOODTAUS", 0, 0);
	
	assembler->setRange("NOSSF", 0, 1);
	assembler->setRange("ONZ", 0,0);
	assembler->setRange("NBJETSCSVM", 1, 10);
	assembler->setRange("HT", 0, 200);
	//assembler->setRange("MET", 0, 30, false);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L3B1HT0to200_MET.pdf");
	assembler->project("MET", true)->print();
	makeNicePlot(assembler->project("NBJETSCSVM",true)->plot(true),"N b-jets CSVM")->SaveAs("L3B1HT0to200_NBM.pdf");
	makeNicePlot(assembler->project("NBJETSCSVL",true)->plot(true),"N b-jets CSVL")->SaveAs("L3B1HT0to200_NBL.pdf");
	
	assembler->setRange("HT",200,500);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L3B1HT200to500_MET.pdf");
	makeNicePlot(assembler->project("NBJETSCSVM",true)->plot(true),"N b-jets CSVM")->SaveAs("L3B1HT200to500_NBM.pdf");
	makeNicePlot(assembler->project("NBJETSCSVL",true)->plot(true),"N b-jets CSVL")->SaveAs("L3B1HT200to500_NBL.pdf");
	assembler->project("MET", true)->print();

	assembler->setRange("HT",500);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L3B1HTgt500_MET.pdf");
	makeNicePlot(assembler->project("NBJETSCSVM",true)->plot(true),"N b-jets CSVM")->SaveAs("L3B1HTgt500_NBM.pdf");
	makeNicePlot(assembler->project("NBJETSCSVL",true)->plot(true),"N b-jets CSVL")->SaveAs("L3B1HTgt500_NBL.pdf");
	assembler->project("MET", true)->print();
	assembler->setRange("HT");
	//assembler->project("PTGOODLEPTONS",true)->plot(true)->SaveAs("L3B1_PTLEP.pdf");
	assembler->project("PTLEP2",true)->plot(true)->SaveAs("L3B1_PTLEP3.pdf");
	assembler->project("PTLEP0",true)->plot(true)->SaveAs("L3B1_PTLEP1.pdf");

	assembler->setRange("NLEPTONS",4,4);
	assembler->setRange("HT",0,200);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L4B1HT0to200_MET.pdf");
	assembler->project("MET", true)->print();

	assembler->setRange("HT",200,500);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L4B1HT200to500_MET.pdf");
	assembler->project("MET", true)->print();

	assembler->setRange("HT",500);
	makeNicePlot(assembler->project("MET", true)->plot(true),"MET [GeV]")->SaveAs("L4B1HTgt500_MET.pdf");
	assembler->project("MET", true)->print();
	assembler->setRange("HT");
	//assembler->project("PTGOODLEPTONS",true)->plot(true)->SaveAs("L4B1_PTLEP.pdf");
	makeNicePlot(assembler->project("PTLEP2",true)->plot(true),"third lepton p_{T} [GeV]")->SaveAs("L4B1_PTLEP3.pdf");
	makeNicePlot(assembler->project("PTLEP0",true)->plot(true),"leading lepton p_{T} [GeV]")->SaveAs("L4B1_PTLEP1.pdf");

	
	delete assembler;
}
