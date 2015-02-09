from ROOT import *
import sys

if len(sys.argv) < 3: print "missing arguments, usage: compareAllHistos.py file1 file2"
#colors = [kViolet-4,kBlue,kBlue+2,kViolet,kViolet+1,kViolet+3,kCyan+1,kCyan+2,kCyan+3,kBlue-3]
colors = [kBlue,kRed,kMagenta+1,kGreen+3,kOrange+2,kTeal-7,kAzure-6,kViolet-6,kCyan+3,kRed+3,kGreen-2]

gStyle.SetOptStat(0)

files = []
histonames = []
histos = dict()
for i in range(1,len(sys.argv)):
    if ".root" not in sys.argv[i]:continue
    ff = TFile(sys.argv[i])
    if not ff.IsOpen():continue
    keys = ff.GetListOfKeys()
    name = (sys.argv[i].split("."))[0]
    histos[name] = dict()
    for k in keys:
        if "_CALOJETS_" in k.GetName(): continue
        #print k.ClassName()
        h = ff.Get(k.GetName())
        if "TH2F" in h.ClassName(): continue
        if "TTree" in h.ClassName(): continue
        if k.GetName() not in histonames: histonames.append(k.GetName())
        h.SetDirectory(0)
        h.SetLineColor(colors[i-1])
        h.SetMarkerColor(colors[i-1])
        if h.GetEntries() > 0:h.Scale(1./h.GetEntries())
        histos[name][k.GetName()] = h

nHistos = len(histonames)
canvas = TCanvas("c","",800,1200)
divisions =  int(nHistos/2)+1 if nHistos % 2 else int(nHistos/2)
pages = int(divisions/8)+1 if divisions % 8 else int(divisions/8)
canvas.Divide(2,8)
npad = 1
npage = 1
legend = TLegend(0.7,0.65,0.88,0.85)
outfilename="comparisonAll.pdf"
for hname in histonames:
    drawn = 0
    pad = canvas.cd(npad)
    pad.SetLogy()
    legend.Clear()
    legend.SetFillColor(kWhite)
    for fname,fdict in histos.iteritems():
        if not fdict.has_key(hname): continue
        if drawn == 0:
            fdict[hname].Draw()
            fdict[hname].SetTitle(hname)
        else:
            fdict[hname].Draw("same")
        drawn += 1
        legend.AddEntry(fdict[hname],fname,"l")
    legend.Draw()
    npad += 1
    if npad > 8:
        if pages > 1 and npage == 1:
            canvas.Print(outfilename+"(","pdf")
        else:
            canvas.Print(outfilename,"pdf")
        npad = 1
        canvas.Clear()
        canvas.Divide(2,8)
        npage += 1

if pages > 1:
    canvas.Print(outfilename+")","pdf")
else:
    canvas.SaveAs(outfilename)

