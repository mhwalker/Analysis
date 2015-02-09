#!/bin/bash

MAINDIR=`pwd`
SCRIPTDIR=`pwd`
LOGDIR=$MAINDIR/logs
CMSDIR=$CMSSW_BASE/src

tmplist=tmp.tmp
ls -l submitEfficiency_* | grep submit > $tmplist

#altlist=newconLSP2.txt
while read line
do
  #echo $line
  base=`echo $line | awk '{split($9,array,"submitEfficiency_"); split(array[2],array2,".");print array2[1]}'`
  ofile=allHistos_${base}.root
  haddR -f $ofile histograms/histo_${base}_*.root
done < $tmplist
rm -rf $tmplist
