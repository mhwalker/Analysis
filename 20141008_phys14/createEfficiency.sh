#!/bin/bash

MAINDIR=`pwd`
SCRIPTDIR=`pwd`
LOGDIR=$MAINDIR/logs
CMSDIR=$CMSSW_BASE/src

#basedir="../../NTUPLES/2014/DYJetsToLL_M-50_13TeV-madgraph-pythia8__MINIAODSIM__PU20bx25_POSTLS170_V5-v1"
#basedir="../../NTUPLES/2014/TT_Tune4C_13TeV-pythia8-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1"
#basedir="../../NTUPLES/2014/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/GluGluToHToZZTo4L_M-125_13TeV-powheg-pythia6__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/TTZJets_Tune4C_13TeV-madgraph-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/TTbarH_HToTauTau_M-125_13TeV_amcatnlo-pythia8-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/TTbarH_HToWWTo2L2Nu_M-125_13TeV_amcatnlo-pythia8-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/TTbarH_HToZZ_4LFilter_M-125_13TeV_pythia6__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/WH_ZH_HToWW_M-125_13TeV_pythia6__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/WH_ZH_HToZZ_4LFilter_M-125_13TeV_pythia6__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/WZTo3LNu_CT10_13TeV-powheg-pythia8-tauola__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/ZZTo4L_Tune4C_13TeV-powheg-pythia8__MINIAODSIM__PU20bx25_POSTLS170_V5-v1/"
#basedir="../../NTUPLES/2014/coNLSP_1400_1700/"
#basedir="../../NTUPLES/2014/T1tttt_1500_100/"
#basedir="../../NTUPLES/2014/TChiwz_300_100/"
basedir="../../NTUPLES/2014/TChiwz_200_100/"

#sample=DYJets_M50
#sample=TTbar
#sample=H2TauTau
#sample=TTH2TauTau
#sample=H2ZZ
#sample=T1tttt_1500_100
#sample=TTZ
#sample=TTH2TauTau
#sample=TTH2WW
#sample=TTH2ZZ
#sample=WHZH2WW
#sample=WHZH2ZZ
#sample=WZ
#sample=ZZ
#sample=coNLSP_1400_1700
#sample=TChiwz_300_100
sample=TChiwz_200_100

condorFile=$SCRIPTDIR/submitEfficiency_${sample}.condor


if [ -e $condorFile ]
then
    rm -rf $condorFile
fi
touch $condorFile

runScript=$SCRIPTDIR/runEfficiency.sh
if [ -e $runScript ]
then
    rm -rf $runScript
fi
touch $runScript
chmod a+x $runScript

echo "#!/bin/bash" >> $runScript
echo "export VO_CMS_SW_DIR=/cms/base/cmssoft" >> $runScript
echo "export COIN_FULL_INDIRECT_RENDERING=1" >> $runScript
echo 'echo $VO_CMS_SW_DIR' >> $runScript
echo 'source $VO_CMS_SW_DIR/cmsset_default.sh' >> $runScript
#echo "cd ~/Software" >> $runScript
#echo "source setup700.sh" >> $runScript
echo "cd $CMSDIR" >> $runScript
echo "export SCRAM_ARCH=slc5_amd64_gcc481" >> $runScript
echo 'eval `scramv1 runtime -sh` ' >> $runScript
#echo "cd $SCRIPTDIR/Datacards/coNLSP" >> $runScript
echo "cd $SCRIPTDIR" >> $runScript
echo 'root -q -b -l exampleMacro.C\(\"$1\",\"$2\",$3\)' >> $runScript
echo "" >> $runScript

echo "universe = vanilla" >> $condorFile
echo '+AccountingGroup = "group_rutgers.'$USER'"' >> $condorFile
echo 'Requirements = (Arch == "X86_64")' >> $condorFile
echo "Executable = $runScript" >> $condorFile
echo "should_transfer_files = NO" >> $condorFile
echo "Notification=never" >> $condorFile
echo "" >> $condorFile
echo "" >> $condorFile

tmplist=tmp.tmp
ls -l $basedir/*.root | grep root > $tmplist

#altlist=newconLSP2.txt
while read line
do
  #echo $line
  #base=`echo $line | awk '{split($9,array,"output_"); split(array[2],array2,".");print array2[1]}'`
  base=`echo $line | awk '{split($9,array,"flat_"); split(array[2],array2,"_");split(array2[4],array3,".");print array3[1]}'`
  #ifname=$basedir/output_${base}.root
  ifname=$basedir/flat_${sample}_${base}.root
  mode=0
  ofile=histograms/histo_${sample}_${base}.root
  echo "output = $LOGDIR/\$(Cluster)_efficiency_${sample}_${base}.out" >> $condorFile
  echo "error = $LOGDIR/\$(Cluster)_efficiency_${sample}_${base}.err" >> $condorFile
  echo "log = $LOGDIR/\$(Cluster)_efficiency_${sample}_${base}.log" >> $condorFile
  echo "arguments = $ifname $ofile $mode" >> $condorFile
  echo "queue" >> $condorFile
  echo "" >> $condorFile
done < $tmplist
rm -rf $tmplist
