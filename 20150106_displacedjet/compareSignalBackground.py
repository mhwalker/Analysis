from ROOT import *
import sys

print sys.argv

if len(sys.argv) != 3: print "missing arguments, usage: compareAllHistos.py signalFile bkgFile"

sigHistos = dict()
bkgHistos = dict()
signatures = []
histonames = []

sigfile = TFile(sys.argv[1])
keys = sigfile.GetListOfKeys()
sigN = sigfile.Get("noCutSignature_COUNT").Integral()
if sigN == 0:
    print "0 signature events, aborting"
    exit

nHistos = 0
for k in keys:
    if not "CALOJETSMATCHED" in k.GetName(): continue
    nsplit = k.GetName().split("_CALOJETSMATCHED_")
    if len(nsplit) != 2: continue
    if not nsplit[0] in signatures: signatures.append(nsplit[0])
    if not nsplit[1] in histonames: signatures.append(nsplit[1])
    if not sigHistos.has_key(nsplit[0]): sigHistos[nsplit[0]] = dict()
    h = sigfile.Get(k.GetName())
    h.SetDirectory(0)
    h.Scale(1./sigN)
    h.SetLineColor(kRed)
    sigHistos[nsplit[0]][nsplit[1]] = h
    nHistos += 1

bkgfile = TFile(sys.argv[2])
bkgN = bkgfile.Get("noCutSignature_COUNT").Integral()
if bkgN == 0:
    print "0 background events, aborting"
    exit
for sname,sdict in sigHistos.iteritems():
    if not bkgHistos.has_key(sname): bkgHistos[sname] = dict()
    for dname,dhisto in sdict.iteritems():
        hname = sname+"_CALOJETS_"+dname
        h = bkgfile.Get(hname)
        if h is None:
            print hname,"is missing from bkg"
            nHistos -= 1
            continue
        h.Scale(1./bkgN)
        h.SetDirectory(0)
        h.SetLineColor(kBlue)
        bkgHistos[sname][dname] = h

canvas = TCanvas("c","",800,1200)
divisions =  int(nHistos/2)+1 if nHistos % 2 else int(nHistos/2)
pages = int(divisions/8)+1 if divisions % 8 else int(divisions/8)
canvas.Divide(2,8)
npad = 1
npage = 1
outfilename="comparison.pdf"
for sname,sdict in sigHistos.iteritems():
    if not bkgHistos.has_key(sname): continue
    for dname,dhisto in sdict.iteritems():
        if not bkgHistos[sname].has_key(dname): continue
        smax = dhisto.GetMaximum()
        bmax = bkgHistos[sname][dname].GetMaximum()
        smin = dhisto.GetMinimum()
        bmin = bkgHistos[sname][dname].GetMinimum()
        dhisto.GetYaxis().SetRangeUser(0.5*min(smin,bmin),1.2*max(smax,bmax))
        canvas.cd(npad)
        dhisto.Draw()
        bkgHistos[sname][dname].Draw("same")
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
    canvas.SaveAs("comparison.pdf")
