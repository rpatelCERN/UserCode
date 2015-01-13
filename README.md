# MAKE DATA CARDS For Higgs Combine tool datacards made for the Sensitivity study of RA2+RA2b. 
MakeDataCards.C contains the base functions: doing the binning and making the cards 
Modify the above to change the binning and then create a set of input histograms with RunInputHistos.C
To Make DataCards and run the combine tool you can use the python file: BatchSubmit.py with option:
"SubmitBins" for a datacard from a single bin or "Submit" to include all bins in a card. 
This code will output the combine root files that contain the expected and observed limit 
