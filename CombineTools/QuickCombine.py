import os
import sys

commandSignif="combine -M ProfileLikelihood --significance "
commandUL=" combine -M HybridNew --frequentist --testStat  LHC" 
optionUL=" -H ProfileLikelihood  "

print sys.argv[4]

for i in range(0, 72):
	datacard="SensStudyLumi%s.00_Bin%d_M%s_m%s_%s.dat" %(sys.argv[5], i, sys.argv[2], sys.argv[3],sys.argv[1])
	if(sys.argv[4]=="signif"):
		output=" -n CombineCLsLimit%s_M%s_m%s_Bin%d_Lumi%s " %(sys.argv[1],sys.argv[2], sys.argv[3], i, sys.argv[5])
		os.system("%s %s -m %d %s" %(commandSignif, datacard,i,output))
	if(sys.argv[4] =="CLs"):
		output=" -n CombineSignifLimit%s_M%s_m%s_Bin%d_Lumi%s " %(sys.argv[1],sys.argv[2], sys.argv[3], i, sys.argv[4])
		os.system("%s %s -m %d %s %s" %(commandUL, datacard,i,optionUL, output))
