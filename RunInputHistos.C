//
//  MakeInputHistos.C
//  
//
//  Created by Rishi Patel on 1/13/15.
//
//

#include <stdio.h>

void RunInputHistos(int mGlu, int mLSP){
    gROOT->ProcessLine(".L MakeDataCards_C.so");
    MakeInputHiso(mGlu, mLSP);
}