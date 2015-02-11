import os
import sys
#str=" "
for j in range (4, 5):
	str=" "
	q=[10,11, 26, 28, 29, 34, 35, 4, 41, 5,50, 52, 53, 58,59]
	b=[10,11,16, 17, 20, 21, 22, 23, 34,35, 41,44, 46, 47, 64, 65, 70,71]
	for i in range(30,72):
		
		#if(i is 46 or i is 47 or i is 64 or i is 65 or i is 68 or i is 70 or i is 71):
		
		#if(i is 16 or i is 17 or i is 22 or i is 22 or i is 23 or i is 40 or i is 41 or i is 46 or i is 47 or i is 70 or i is 71):
		#if( i is 10 or i is 11 or i is 28 or i is 29 or i is 34 or i is 35 or i is 52 or i is 53 or i is 59 or i is 4):	
		str=str + " SensStudyLumi%2.2f_Bin%d_M%s_m%s_%s.dat " %(j,i, sys.argv[2], sys.argv[3], sys.argv[1])
	os.system("combineCards.py %s >AllBins%s%s_Lumi%d.dat" %(str,sys.argv[1], sys.argv[2],j))
