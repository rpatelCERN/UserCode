//
//  MakeCards.C
//  
//
//  Created by Rishi Patel on 1/13/15.
//
//

#include <stdio.h>
void RunCards(int mGlu, int mLSP, TString Options="",  bool SingleBin=false, int Limitbin=0){
    gROOT->ProcessLine(".L MakeDataCards_C.so");
    MakeDataCards(mGlu, mLSP, Options, SingleBin, Limitbin);
}
