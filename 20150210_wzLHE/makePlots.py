from ROOT import *
import sys

fname = sys.argv[1]
lfsplit = fname.split(".")
base = lfsplit[0]

tf = TFile(fname)

tree = tf.Get("treeR")

gROOT.SetStyle("Plain")
gStyle.SetOptStat(0)

canvas = TCanvas("c","",800,600)
treeR.Draw("ZPT:WPT>>hPT(200,0,200,200,0,200)","","goff")
treeR.Draw("ZPHI:WPHI>>hPHI(100,-3.142,3.142,100,-3.142,3.142)","","goff")

hPT = gDirectory.Get("hPT")
hPHI = gDirectory.Get("hPHI")

hPT.SetXTitle("W p_{T} [GeV]")
hPT.SetTitle("")
hPT.SetYTitle("Z p_{T} [GeV]")
hPT.Draw("colz")
canvas.SaveAs(base+"_PT.pdf")

hPHI.SetXTitle("W #phi")
hPHI.SetTitle("")
hPHI.SetYTitle("Z #phi")
hPHI.Draw("colz")
canvas.SaveAs(base+"_PHI.pdf")
