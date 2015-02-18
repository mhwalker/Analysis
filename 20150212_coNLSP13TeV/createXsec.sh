#!/bin/bash

MAINDIR=`pwd`
SCRIPTDIR=`pwd`
LOGDIR=$MAINDIR/logs
CMSDIR=$CMSSW_BASE/src

condorFile=$SCRIPTDIR/submitXsec.condor


if [ -e $condorFile ]
then
    rm -rf $condorFile
fi
touch $condorFile

runScript=$SCRIPTDIR/runXsec.sh
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
#echo "cd $SCRIPTDIR/Datacards/coNLSP" >> $runScript
echo "cd $CMSDIR" >> $runScript
echo "export SCRAM_ARCH=slc5_amd64_gcc481" >> $runScript
echo 'eval `scramv1 runtime -sh` ' >> $runScript
echo "cd $SCRIPTDIR/on_the_web_10_17_14/" >> $runScript
echo './prospino_2.run $1 $2 $3 $4 $5 $6 $7 $8 $9 ${10}' >> $runScript
echo "" >> $runScript

echo "universe = vanilla" >> $condorFile
echo '+AccountingGroup = "group_rutgers.'$USER'"' >> $condorFile
echo 'Requirements = (Arch == "X86_64")' >> $condorFile
echo "Executable = $runScript" >> $condorFile
echo "should_transfer_files = NO" >> $condorFile
echo "Notification=never" >> $condorFile
echo "" >> $condorFile
echo "" >> $condorFile

#altlist=newconLSP2.txt
while read line
do
  base=`echo $line | awk '{split($1,array,"/"); split(array[3],array2,".");print array2[1]}'`
  i=0
  while read line2
  do
    echo "output = $LOGDIR/\$(Cluster)_xsec_${base}_${i}.out" >> $condorFile
    echo "error = $LOGDIR/\$(Cluster)_xsec_${base}_${i}.err" >> $condorFile
    echo "log = $LOGDIR/\$(Cluster)_xsec_${base}_${i}.log" >> $condorFile
    echo "arguments = $line2 ../${line} ../prospinoOutput/${base}_${i}.dat ../prospinoOutput/${base}_${i}.dat2 ../prospinoOutput/${base}_${i}.dat3" >> $condorFile
    echo "queue" >> $condorFile
    echo "" >> $condorFile
    let i++
  done < settings.txt
done < files.list

