//
//  MakeDataCards.C
//  
//
//  Created by Rishi Patel on 1/13/15.
//
//

#include <TH3F.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <stdio.h>
#include <TString.h>
#include <TGraph.h>
#include <TCanvas.h>
#include<TH1F.h>

void MakeDataCards2bin(int mGlu, int MLSP, int lumi=4, TString Options="",  bool SingleBin=false, int Limitbin=0){
    //DEFINE Options FOR DataCards
    //Sum Bkg Yields: "SUMBKG"
    //Include Systematics: "SYS"
    // can AND Options with '&&'
    
//define binning (for now rectangular):

    
    const int nBinsjets = 3 ;
    const int nBinsBjets = 4 ;
    const int nBinsMHT = 3 ;
    const int nBinsHT = 3 ;

    //array of the signal and background yields:
    TH3F*sig4t1200_[4];
    TH3F*sig4t1500_[4];
    
    TH3F*sig4b1500_[4];
    TH3F*sig4b1000_[4];
    TH3F*sig4q1400_[4];
    TH3F*sig4q1000_[4];
    
    TH3F*qcd_[4];
    TH3F*tt_[4];
    TH3F*WJ_[4];
    TH3F*ZI_[4];
    
    TFile*f0=new TFile(TString::Format("Bins4DBINS%dfb.root", lumi).Data());
 //   TFile*f0=new TFile("Bins4DMETBINS.root");
  //  TFile*f0=new TFile("Bins4DBINS4fbSL.root");
    for(int b=0; b<nBinsBjets; ++b){
        
        sig4t1500_[b]=(TH3F*)f0->Get(TString::Format("sig4t1500__b%d",b).Data());
        sig4t1200_[b]=(TH3F*)f0->Get(TString::Format("sig4t1200__b%d",b).Data());

        sig4b1500_[b]=(TH3F*)f0->Get(TString::Format("sig4b1500__b%d",b).Data());
        sig4b1000_[b]=(TH3F*)f0->Get(TString::Format("sig4b1000__b%d",b).Data());
        
        sig4q1400_[b]=(TH3F*)f0->Get(TString::Format("sig4q1400__b%d",b).Data());
        sig4q1000_[b]=(TH3F*)f0->Get(TString::Format("sig4q1000__b%d",b).Data());
        
        qcd_[b]=(TH3F*)f0->Get(TString::Format("qcd__b%d",b).Data());
        tt_[b]=(TH3F*)f0->Get(TString::Format("tt__b%d",b).Data());
        WJ_[b]=(TH3F*)f0->Get(TString::Format("WJ__b%d",b).Data());
        ZI_[b]=(TH3F*)f0->Get(TString::Format("ZI__b%d",b).Data());
    }
    const int totalbins=72;
///   const int totalbins=54;

    float sig4t1500[totalbins];
    float sig4t1200[totalbins];
    
    float sig4q1400[totalbins];
    float sig4q1000[totalbins];
    float sig4b1500[totalbins];
    float sig4b1000[totalbins];
    
    
    float qcd[totalbins];
    float zi[totalbins];
    float wj[totalbins];
    float ttbar[totalbins];
    float obs[totalbins];
    float nuis[totalbins];//this would be the systematics
    
    int ibin=0;//bin counter
    float mu=1.0; //change this to add signal to the observed data for tests (DEFAULT obs set to SM)
    /*
    for(int nb=0; nb<=3; nb++){
        for ( int hti=1; hti<=3; hti++ ) {
            for ( int mhti=1; mhti<=3; mhti++ ) {
                for ( int ij=1; ij<=3; ij++ ) {
     */
    //reorder binning
    
     FILE* fp = fopen(  "OutputTableSL.tex", "w" ) ;
    
    
    fprintf(fp, "\\documentclass[10pt,a4paper]{article}\n");
    fprintf(fp, "\\usepackage[utf8]{inputenc}\n");
    fprintf(fp, "\\usepackage{amsmath}\n");
    fprintf(fp, "\\usepackage{amsfonts}\n");
    fprintf(fp, "\\usepackage{amssymb}\n");
    fprintf(fp, "\\usepackage{multirow}\n");
    fprintf(fp,"\\usepackage{graphicx}\n");

    fprintf(fp, "\\begin{document}\n");
    fprintf(fp, "\\begin{table}\n");
    fprintf(fp,"\\resizebox{1.2\\textwidth}{0.95\\textwidth}{\n");

    fprintf(fp, "\\begin{tabular}{|l|c|c|c|c|c|c|c|c|c|c|}\n");;
    fprintf(fp, "\\hline\n");
    fprintf(fp, "\\hline\n");
    fprintf(fp, "\\multicolumn{6}{ |c| }{Signal and Background Yields} \\\\\n");
    fprintf(fp, "\\hline\n");
    fprintf(fp, "\\hline\n");
    fprintf(fp,"&QCD&ttbar&Z&W&T1tttt&T1tttt&T1qqqq&T1qqqq&T1bbbb&T1bbbb\\\\\n");
    fprintf(fp, "& & & & &$M_{glu},M_{\\chi}$ & $M_{glu},M_{\\chi}$ &$M_{glu},M_{\\chi}$ & $M_{glu},M_{\\chi}$ & $M_{glu},M_{\\chi}$ &$M_{glu},M_{\\chi}$\\\\\n");
    fprintf(fp, "& & & & &1500,100 & 1200,800 &1400,100 & 1000,800 & 1500,100 &1200,900 \\\\\n");
    fprintf(fp,"\\hline\n");

    int boxcount=0;
                for ( int ij=1; ij<=3; ij++ ) {
                    for(int nb=0; nb<=3; nb++){
                        for ( int mhti=1; mhti<=3; mhti++ ){
                            for ( int hti=1; hti<=3; hti++ ) {
                                
                         //                   fprintf(fp, "& 1 &2 &3 \\\\\n");
                        //Need to merge some bins
                        // std::cout<<sig4t_[nb]->GetBinContent( ij, mhti, hti )<<std::endl;
                        



                        if(hti<2 && mhti==3)continue;
                                        
                        if(mhti==1){
                            boxcount=hti+mhti-1;
                            sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( ij, mhti, hti );
                            sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( ij, mhti, hti );
                            sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( ij, mhti, hti );
                            sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( ij, mhti, hti );
                            
                            sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( ij, mhti, hti );
                            sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( ij, mhti, hti );
                            
                                            qcd[ibin]=qcd_[nb]->GetBinContent( ij, mhti, hti );
                                            zi[ibin]=ZI_[nb]->GetBinContent( ij, mhti, hti );
                                            wj[ibin]=WJ_[nb]->GetBinContent( ij, mhti, hti );
                                            ttbar[ibin]=tt_[nb]->GetBinContent( ij, mhti, hti );
                                            //for now observed data is set to total bkg yield
                                            ++ibin;
                                            
                        }
                                
                        if(mhti==3){
                            if(hti==3)continue;
                            boxcount=4+hti;

                            sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( ij, mhti, 2 )+sig4t1500_[nb]->GetBinContent( ij, mhti, 3 );
                            sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( ij, mhti, 2 )+sig4t1200_[nb]->GetBinContent( ij, mhti, 3 );
                            sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( ij, mhti, 2 )+sig4q1400_[nb]->GetBinContent( ij, mhti, 3 );
                            sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( ij, mhti, 2 )+sig4q1000_[nb]->GetBinContent( ij, mhti, 3 );
                            sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( ij, mhti, 2 )+sig4b1500_[nb]->GetBinContent( ij, mhti, 3 );
                            sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( ij, mhti, 2 )+sig4b1000_[nb]->GetBinContent( ij, mhti, 3 );
                            
                            qcd[ibin]=qcd_[nb]->GetBinContent( ij, mhti, 2 )+qcd_[nb]->GetBinContent( ij, mhti, 3 );
                            zi[ibin]=ZI_[nb]->GetBinContent( ij, mhti, 2 )+ZI_[nb]->GetBinContent( ij, mhti, 3 );
                            wj[ibin]=WJ_[nb]->GetBinContent( ij, mhti, 2 )+WJ_[nb]->GetBinContent( ij, mhti, 3 );
                            ttbar[ibin]=tt_[nb]->GetBinContent( ij, mhti, 2)+tt_[nb]->GetBinContent( ij, mhti, 3);

                            ++ibin;
                        }
                                
                        if(mhti==2){
                            if(hti==2)continue;
                            boxcount=4;
                                    // if(ij==1&& nb==0)++boxcount;
                            sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( ij, mhti, 1 )+sig4t1500_[nb]->GetBinContent( ij, mhti, 2 );
                            sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( ij, mhti, 1 )+sig4t1200_[nb]->GetBinContent( ij, mhti, 2 );
                            sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( ij, mhti, 1 )+sig4q1400_[nb]->GetBinContent( ij, mhti, 2 );
                            sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( ij, mhti, 1 )+sig4q1000_[nb]->GetBinContent( ij, mhti, 2 );
                            sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( ij, mhti, 1 )+sig4b1500_[nb]->GetBinContent( ij, mhti, 2 );
                            sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( ij, mhti, 1 )+sig4b1000_[nb]->GetBinContent( ij, mhti, 2 );
                                    qcd[ibin]=qcd_[nb]->GetBinContent( ij, mhti, 1 )+qcd_[nb]->GetBinContent( ij, mhti, 2 );
                                    zi[ibin]=ZI_[nb]->GetBinContent( ij, mhti, 1 )+ZI_[nb]->GetBinContent( ij, mhti, 2 );
                                    wj[ibin]=WJ_[nb]->GetBinContent( ij, mhti, 1 )+WJ_[nb]->GetBinContent( ij, mhti, 2 );
                                    ttbar[ibin]=tt_[nb]->GetBinContent( ij, mhti, 1)+tt_[nb]->GetBinContent( ij, mhti, 2);
                            
                            if(hti==3){
                                boxcount=5;
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( ij, mhti, hti );
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( ij, mhti, hti );
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( ij, mhti, hti );
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( ij, mhti, hti );
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( ij, mhti, hti );
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( ij, mhti, hti );
                                qcd[ibin]=qcd_[nb]->GetBinContent( ij, mhti, hti );
                                zi[ibin]=ZI_[nb]->GetBinContent( ij, mhti, hti );
                                wj[ibin]=WJ_[nb]->GetBinContent( ij, mhti, hti );
                                ttbar[ibin]=tt_[nb]->GetBinContent( ij, mhti, hti );
                            }
                                    ++ibin;
                        }
                        fprintf(fp, "HT-MHTBin%d jetbin%d btag%d & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f  & %4.2f & %4.2f  \\\\ \n", boxcount,ij, nb,qcd[ibin-1], ttbar[ibin-1],zi[ibin-1],wj[ibin-1],sig4t1500[ibin-1],sig4t1200[ibin-1],sig4q1400[ibin-1],sig4q1000[ibin-1],sig4b1500[ibin-1],sig4b1000[ibin-1] );
                                
                        //obs[ibin-1]=qcd[ibin-1]+ zi[ibin-1]+wj[ibin-1]+ttbar[ibin-1] + (mu*sig4t1500[ibin-1]);
                        if( qcd[ibin-1]+zi[ibin-1]+wj[ibin-1]+ttbar[ibin-1]<0.00000001)std::cout<<"ERROR:Bkg 0 for this bin"<<std::endl;
                        std::cout<<"Ibin "<<ibin<<std::endl;
                    }
                }
            }
        }
    fprintf(fp,"\\hline\n");
    fprintf(fp,"\\end{tabular}}\n");
    fprintf(fp,"\\caption{TEST}\n");
    fprintf(fp,"\\end{table}\n");
    fprintf(fp,"\\end{document}\n");
 //   return;
    //merged bins
/*
    float ttbarMCV[totalbins];
    float ttbarPred[totalbins];
    float ttbarUNC[totalbins];

    for ( int ij=1; ij<=3; ij++ ) {
        for(int nb=0; nb<=3; nb++){
            for ( int mhti=1; mhti<=3; mhti++ ){
                for ( int hti=1; hti<=3; hti++ ) {
                    
                    //                   fprintf(fp, "& 1 &2 &3 \\\\\n");
                    //Need to merge some bins
                    // std::cout<<sig4t_[nb]->GetBinContent( ij, mhti, hti )<<std::endl;
                    
                    
                    
                    
                    if(hti<2 && mhti==3)continue;
                    
                    if(mhti==1){
                        boxcount=hti+mhti-1;
                        sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( ij, mhti, hti );
                        sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( ij, mhti, hti );
                        sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( ij, mhti, hti );
                        sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( ij, mhti, hti );
                        
                        sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( ij, mhti, hti );
                        sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( ij, mhti, hti );
                        
                        qcd[ibin]=qcd_[nb]->GetBinContent( ij, mhti, hti );
                        zi[ibin]=ZI_[nb]->GetBinContent( ij, mhti, hti );
                        wj[ibin]=WJ_[nb]->GetBinContent( ij, mhti, hti );
                        ttbar[ibin]=tt_[nb]->GetBinContent( ij, mhti, hti );
                        ttbarMCV[ibin]=ttbar[ibin];
                        ttbarPred[ibin]=ttbar[ibin];
                        ttbarUNC[ibin]=sqrt(ttbar[ibin]);
                        //for now observed data is set to total bkg yield
                        ++ibin;
                        
                    }
                   // if(ij>1)continue;//have merged jet bins
                    if(mhti==3){
                        if(ij>1)continue;
                        if(hti!=2)continue;
                        boxcount=4+hti;
                        float sig4t1500Sum=0;
                        float sig4t1200Sum=0;
                        float sig4b1500Sum=0;
                        float sig4b1000Sum=0;
                        float sig4q1400Sum=0;
                        float sig4q1000Sum=0;
                        float qcdsum=0;
                        float wsum=0;
                        float zsum=0;
                        float ttsum=0;
                        for(int j=1; j<=3; ++j){
                            sig4t1500Sum=sig4t1500_[nb]->GetBinContent( j, mhti, 2 )+sig4t1500_[nb]->GetBinContent( j, mhti, 3 )+sig4t1500Sum;
                        sig4t1200Sum=sig4t1200_[nb]->GetBinContent( j, mhti, 2 )+sig4t1200_[nb]->GetBinContent( j, mhti, 3 )+sig4t1200Sum;
                        sig4q1400Sum=sig4q1400_[nb]->GetBinContent( j, mhti, 2 )+sig4q1400_[nb]->GetBinContent( j, mhti, 3 )+sig4q1400Sum;
                       sig4q1000Sum=sig4q1000_[nb]->GetBinContent( j, mhti, 2 )+sig4q1000_[nb]->GetBinContent( j, mhti, 3 )+sig4q1000Sum;
                        sig4b1500Sum=sig4b1500_[nb]->GetBinContent( j, mhti, 2 )+sig4b1500_[nb]->GetBinContent( j, mhti, 3 )+sig4b1500Sum;
                        sig4b1000Sum=sig4b1000_[nb]->GetBinContent( j, mhti, 2 )+sig4b1000_[nb]->GetBinContent( j, mhti, 3 )+sig4b1000Sum;
                        
                        
                        qcdsum=qcd_[nb]->GetBinContent( j, mhti, 2 )+qcd_[nb]->GetBinContent( j, mhti, 3 )+qcdsum;
                        zi[ibin]=ZI_[nb]->GetBinContent( j, mhti, 2 )+ZI_[nb]->GetBinContent( j, mhti, 3 );
                        wsum=WJ_[nb]->GetBinContent( j, mhti, 2 )+WJ_[nb]->GetBinContent( j, mhti, 3 )+wsum;
                            ttsum=tt_[nb]->GetBinContent( j, mhti, 2)+tt_[nb]->GetBinContent( j, mhti, 3)+ttsum;
                        }
                        sig4t1500[ibin]=sig4t1500Sum;
                        sig4t1200[ibin]=sig4t1200Sum;
                        sig4q1400[ibin]=sig4q1400Sum;
                        sig4q1000[ibin]=sig4q1000Sum;
                        sig4b1500[ibin]=sig4b1500Sum;
                        sig4b1000[ibin]=sig4b1000Sum;
                        qcd[ibin]=qcdsum;
                        wj[ibin]=wsum;
                        ttbar[ibin]=ttsum;
                        if(nb==0){
                        ttbarMCV[ibin]=2;
                        ttbarPred[ibin]=3.2;
                        ttbarUNC[ibin]=0.11;
                        }
                        if(nb==1){
                            ttbarMCV[ibin]=17;
                            ttbarPred[ibin]=13.81;
                            ttbarUNC[ibin]=0.45;
                        }
                        if(nb==2){
                            ttbarMCV[ibin]=18;
                            ttbarPred[ibin]=18.97;
                            ttbarUNC[ibin]=0.61;
                        }
                        if(nb==3){
                            ttbarMCV[ibin]=14;
                            ttbarPred[ibin]=8.93;
                            ttbarUNC[ibin]=0.28;
                        }
                        zi[ibin]=wsum;
                        ++ibin;
                    }
                    //if(nb>0)continue;
                    if(mhti==2){
                        if(hti==2)continue;
                        boxcount=4;
                        // if(ij==1&& nb==0)++boxcount;
                        
                        if(hti==1){
                            if(nb==0){
                                if(ij!=1)continue;
                        sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 1, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 1, mhti, 2 )+sig4t1500_[nb]->GetBinContent( 2, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 2, mhti, 2 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 1, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 1, mhti, 2 )+sig4t1200_[nb]->GetBinContent( 2, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 2, mhti, 2 )+sig4t1200_[nb]->GetBinContent( 3, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 1, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 1, mhti, 2 )+sig4q1400_[nb]->GetBinContent( 2, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 2, mhti, 2 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 1, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 1, mhti, 2 )+sig4q1000_[nb]->GetBinContent( 2, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 2, mhti, 2 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 1, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 1, mhti, 2 )+sig4b1500_[nb]->GetBinContent( 2, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 2, mhti, 2 )+sig4b1500_[nb]->GetBinContent( 3, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 1, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 1, mhti, 2 )+sig4b1000_[nb]->GetBinContent( 2, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 2, mhti, 2 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 2 );
                                
                        qcd[ibin]=qcd_[nb]->GetBinContent( 1, mhti, 1 )+qcd_[nb]->GetBinContent( 1, mhti, 2 )+qcd_[nb]->GetBinContent( 2, mhti, 1 )+qcd_[nb]->GetBinContent( 2, mhti, 2 )+qcd_[nb]->GetBinContent( 3, mhti, 1 )+qcd_[nb]->GetBinContent( 3, mhti, 2 );
                        zi[ibin]=ZI_[nb]->GetBinContent( 1, mhti, 1 )+ZI_[nb]->GetBinContent( 1, mhti, 2 )+ZI_[nb]->GetBinContent( 2, mhti, 1 )+ZI_[nb]->GetBinContent( 2, mhti, 2 )+ZI_[nb]->GetBinContent( 3, mhti, 1 )+ZI_[nb]->GetBinContent( 3, mhti, 2 );
                        wj[ibin]=WJ_[nb]->GetBinContent( 1, mhti, 1 )+WJ_[nb]->GetBinContent( 1, mhti, 2 )+WJ_[nb]->GetBinContent( 2, mhti, 1 )+WJ_[nb]->GetBinContent( 2, mhti, 2 )+WJ_[nb]->GetBinContent( 3, mhti, 1 )+WJ_[nb]->GetBinContent( 3, mhti, 2 );
                        ttbar[ibin]=tt_[nb]->GetBinContent( 1, mhti, 1)+tt_[nb]->GetBinContent( 1, mhti, 2)+tt_[nb]->GetBinContent( 2, mhti, 1)+tt_[nb]->GetBinContent( 2, mhti, 2)+tt_[nb]->GetBinContent( 3, mhti, 1)+tt_[nb]->GetBinContent( 3, mhti, 2);
                                ttbarMCV[ibin]=45;
                                ttbarPred[ibin]=42.84;
                                ttbarUNC[ibin]=1.55;
                            ++ibin;
                            }
                            if(nb>0 && ij==1){
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 1, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 1, mhti, 2 );
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 1, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 1, mhti, 2 );
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 1, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 1, mhti, 2 );
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 1, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 1, mhti, 2 );
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 1, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 1, mhti, 2 );
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 1, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 1, mhti, 2 );
                                qcd[ibin]=qcd_[nb]->GetBinContent( 1, mhti, 1 )+qcd_[nb]->GetBinContent( 1, mhti, 2 );
                                zi[ibin]=ZI_[nb]->GetBinContent( 1, mhti, 1 )+ZI_[nb]->GetBinContent( 1, mhti, 2 );
                                wj[ibin]=WJ_[nb]->GetBinContent( 1, mhti, 1 )+WJ_[nb]->GetBinContent( 1, mhti, 2 );
                                ttbar[ibin]=tt_[nb]->GetBinContent( 1, mhti, 1)+tt_[nb]->GetBinContent( 1, mhti, 2);
                                if(nb==1){
                                    ttbarMCV[ibin]=120;
                                    ttbarPred[ibin]=117.48;
                                    ttbarUNC[ibin]=1.48;
                                }
                                if(nb==2){
                                    ttbarMCV[ibin]=145;
                                    ttbarPred[ibin]=133.15;
                                    ttbarUNC[ibin]=1.70;
                                }
                                if(nb==3){
                                    ttbarMCV[ibin]=50;
                                    ttbarPred[ibin]=45.02;
                                    ttbarUNC[ibin]=0.59;
                                }
                                ++ibin;
                            }
                            if(nb>0 && ij==2){
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 2, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 2, mhti, 2 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 1 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 2 );
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 2, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 2, mhti, 2 )+sig4t1200_[nb]->GetBinContent( 3, mhti, 1 )+sig4t1200_[nb]->GetBinContent( 3, mhti, 2 );
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 2, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 2, mhti, 2 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 1 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 2 );
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 2, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 2, mhti, 2 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 1 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 2 );
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 2, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 2, mhti, 2 )+sig4b1500_[nb]->GetBinContent( 3, mhti, 1 )+sig4b1500_[nb]->GetBinContent( 3, mhti, 2 );
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 2, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 2, mhti, 2 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 1 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 2 );
                                qcd[ibin]=qcd_[nb]->GetBinContent(2, mhti, 1 )+qcd_[nb]->GetBinContent( 2, mhti, 2 )+qcd_[nb]->GetBinContent( 3, mhti, 1 )+qcd_[nb]->GetBinContent( 3, mhti, 2 );
                                zi[ibin]=ZI_[nb]->GetBinContent( 2, mhti, 1 )+ZI_[nb]->GetBinContent( 2, mhti, 2 )+ZI_[nb]->GetBinContent( 3, mhti, 1 )+ZI_[nb]->GetBinContent( 3, mhti, 2 );
                                wj[ibin]=WJ_[nb]->GetBinContent( 1, mhti, 1 )+WJ_[nb]->GetBinContent( 1, mhti, 2 );
                                ttbar[ibin]=tt_[nb]->GetBinContent( 1, mhti, 1)+tt_[nb]->GetBinContent( 1, mhti, 2);
                                
                                if(nb==1){
                                    ttbarMCV[ibin]=26;
                                    ttbarPred[ibin]=18.03;
                                    ttbarUNC[ibin]=0.43;
                                }
                                if(nb==2){
                                    ttbarMCV[ibin]=31;
                                    ttbarPred[ibin]=26;
                                    ttbarUNC[ibin]=0.68;
                                }
                                if(nb==3){
                                    ttbarMCV[ibin]=18;
                                    ttbarPred[ibin]=15.93;
                                    ttbarUNC[ibin]=0.42;
                                }
                                ++ibin;
                            }
                        }
                        if(hti==3){
                            if(nb==0){
                                if(ij!=1)continue;
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 1, mhti, 3 )+sig4t1500_[nb]->GetBinContent( 2, mhti, 3 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 1, mhti, 3 )+sig4t1200_[nb]->GetBinContent( 2, mhti, 3 ) +sig4t1200_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 1, mhti, 3 )+sig4q1400_[nb]->GetBinContent( 1, mhti, 3 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 1, mhti, 3 )+sig4q1000_[nb]->GetBinContent( 2, mhti, 3 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 1, mhti, 3 )+sig4b1500_[nb]->GetBinContent( 2, mhti, 3 )+sig4b1500_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 1, mhti, 3)+sig4b1000_[nb]->GetBinContent( 2, mhti, 3 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 3 );
                                
                                qcd[ibin]=qcd_[nb]->GetBinContent( 1, mhti, 3 )+qcd_[nb]->GetBinContent( 2, mhti, 3 )+qcd_[nb]->GetBinContent( 3, mhti, 3 );
                                zi[ibin]=ZI_[nb]->GetBinContent( 1, mhti, 3 )+ZI_[nb]->GetBinContent( 2, mhti, 3 )+ZI_[nb]->GetBinContent( 3, mhti, 3 );
                                wj[ibin]=WJ_[nb]->GetBinContent( 1, mhti, 3 )+WJ_[nb]->GetBinContent( 2, mhti, 3 )+WJ_[nb]->GetBinContent( 3, mhti, 3 );
                                ttbar[ibin]=tt_[nb]->GetBinContent( 1, mhti, 3)+tt_[nb]->GetBinContent( 2, mhti, 3)+tt_[nb]->GetBinContent( 3, mhti, 3);
                                ttbarMCV[ibin]=62;
                                ttbarPred[ibin]=58.42;
                                ttbarUNC[ibin]=0.92;
                                ++ibin;
                            }
                            if(nb>0 && ij==1){
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 1, mhti, 3 );
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 1, mhti, 3 );
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 1, mhti, 3 );
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 1, mhti, 3 );
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 1, mhti, 3 );
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 1, mhti, 3 );
                                qcd[ibin]=qcd_[nb]->GetBinContent( 1, mhti, 3 );
                                zi[ibin]=ZI_[nb]->GetBinContent( 1, mhti, 3 );
                                wj[ibin]=WJ_[nb]->GetBinContent( 1, mhti, 3 );
                                ttbar[ibin]=tt_[nb]->GetBinContent( 1, mhti, 3);
                                if(nb==1){
                                    ttbarMCV[ibin]=62;
                                    ttbarPred[ibin]=58.42;
                                    ttbarUNC[ibin]=1.49;
                                }
                                if(nb==2){
                                    ttbarMCV[ibin]=65;
                                    ttbarPred[ibin]=75.87;
                                    ttbarUNC[ibin]=1.68;
                                }
                                if(nb==3){
                                    ttbarMCV[ibin]=27;
                                    ttbarPred[ibin]=26.50;
                                    ttbarUNC[ibin]=0.65;
                                }
                                ++ibin;
                            }
                            if(nb>0 && ij==2){
                                sig4t1500[ibin]=sig4t1500_[nb]->GetBinContent( 2, mhti, 3 )+sig4t1500_[nb]->GetBinContent( 3, mhti, 3 );
                                sig4t1200[ibin]=sig4t1200_[nb]->GetBinContent( 2, mhti, 3 )+sig4t1200_[nb]->GetBinContent( 3, mhti, 3 );
                                sig4q1400[ibin]=sig4q1400_[nb]->GetBinContent( 2, mhti, 3 )+sig4q1400_[nb]->GetBinContent( 3, mhti, 3 );
                                sig4q1000[ibin]=sig4q1000_[nb]->GetBinContent( 2, mhti, 3 )+sig4q1000_[nb]->GetBinContent( 3, mhti, 3 );
                                sig4b1500[ibin]=sig4b1500_[nb]->GetBinContent( 2, mhti, 3 )+sig4b1500_[nb]->GetBinContent(3, mhti, 3 );
                                sig4b1000[ibin]=sig4b1000_[nb]->GetBinContent( 2, mhti,3 )+sig4b1000_[nb]->GetBinContent( 3, mhti, 3 );
                                qcd[ibin]=qcd_[nb]->GetBinContent(2, mhti, 3 )+qcd_[nb]->GetBinContent( 3, mhti, 3 );
                                zi[ibin]=ZI_[nb]->GetBinContent( 2, mhti, 3 )+ZI_[nb]->GetBinContent( 3, mhti, 3 );
                                wj[ibin]=WJ_[nb]->GetBinContent( 2, mhti, 3 )+WJ_[nb]->GetBinContent( 3, mhti, 3 );
                                ttbar[ibin]=tt_[nb]->GetBinContent( 2, mhti, 3)+tt_[nb]->GetBinContent( 3, mhti,3);
                                if(nb==1){
                                    ttbarMCV[ibin]=28;
                                    ttbarPred[ibin]=29.85;
                                    ttbarUNC[ibin]=0.81;
                                }
                                if(nb==2){
                                    ttbarMCV[ibin]=38;
                                    ttbarPred[ibin]=48.08;
                                    ttbarUNC[ibin]=1.35;
                                }
                                if(nb==3){
                                    ttbarMCV[ibin]=27;
                                    ttbarPred[ibin]=32.66;
                                    ttbarUNC[ibin]=1.05;
                                }
                                ++ibin;
                            }
                        }
                       
                    }
                    fprintf(fp, "HT-MHTBin%d jetbin%d btag%d & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f & %4.2f  & %4.2f & %4.2f  \\\\ \n", boxcount,ij, nb,qcd[ibin-1], ttbar[ibin-1],zi[ibin-1],wj[ibin-1],sig4t1500[ibin-1],sig4t1200[ibin-1],sig4q1400[ibin-1],sig4q1000[ibin-1],sig4b1500[ibin-1],sig4b1000[ibin-1] );
                    
                    if( qcd[ibin-1]+zi[ibin-1]+wj[ibin-1]+ttbar[ibin-1]<0.00000001)std::cout<<"ERROR:Bkg 0 for this bin"<<std::endl;
                    std::cout<<"Ibin "<<ibin<<std::endl;
                }
            }
        }
    }
    */
    std::cout<<"TOTAL BINS"<<ibin<<std::endl;
//    return;
    fprintf(fp, "\\hline\n");
   
    float sig[totalbins];

    float fbins[totalbins];
    float totalsigT14t=0;
    float totalsigT14b=0;
    float totalsigT14q=0;

    float sumtotalbkg=0;
    float qcdmax=-99;
    int maxbin=0;

    for(int i=0; i<totalbins; ++i){
        if(Options=="T1tttt" && mGlu==1500)sig[i]=sig4t1500[i];
      if(Options=="T1tttt" && mGlu==1200)sig[i]=sig4t1200[i];
        if(Options=="T1qqqq" && mGlu==1400)sig[i]=sig4q1400[i];
        if(Options=="T1qqqq"  && mGlu==1000)sig[i]=sig4q1000[i];
        if(Options=="T1bbbb" && mGlu==1500)sig[i]=sig4b1500[i];
        if(Options=="T1bbbb" && mGlu==1000)sig[i]=sig4b1000[i];
        totalsigT14t=totalsigT14t+sig4t1500[i];
        totalsigT14b=totalsigT14b+sig4b1500[i];
        totalsigT14q=totalsigT14q+sig4q1400[i];
        obs[i]=(qcd[i]+ zi[i]+wj[i]+ttbar[i] + (mu*sig[i]));
        if(qcdmax<qcd[i]){qcdmax=qcd[i]; maxbin=i;}
        fbins[i]=i;
        sumtotalbkg=sumtotalbkg+qcd[i]+zi[i]+wj[i]+ttbar[i];
    }
    std::cout<<"max bin"<<maxbin<<std::endl;
    //for graphs
     float totalbkg[totalbins];
    float SensT4t[totalbins];
    float SensT4b[totalbins];
    float SensT4q[totalbins];

    for(int i=0; i<totalbins; ++i){
        totalbkg[i]=qcd[i]+zi[i]+wj[i]+ttbar[i];
        
        SensT4t[i]=sig4t1500[i]/sqrt(sig4t1500[i]+totalbkg[i]);
        SensT4b[i]=sig4b1500[i]/sqrt(sig4b1500[i]+totalbkg[i]);
        SensT4q[i]=sig4q1400[i]/sqrt(sig4q1400[i]+totalbkg[i]);


    }
     fprintf(fp,"\\end{tabular}}\n");
    fprintf(fp,"\\caption{TEST}\n");
    fprintf(fp,"\\end{table}\n");
    fprintf(fp,"\\end{document}\n");

    float qcdscale=10.0;
    float uncScale=1.0;
    float ttbarScale=1.0;
    //define different datacard modes
    if(SingleBin){
    TString str=(TString::Format("SensTestCards/SensStudy2binLumi%d_Bin%d_M%d_m%d_%s.dat",lumi,Limitbin, mGlu, MLSP,Options.Data())).Data();
   // const char outputfilename[100]=str.Data();
    
    FILE* fp = fopen(  str.Data(), "w" ) ;
    
    fprintf(fp, "imax %d number of channels\n", 4);//signal region PLUS 3 control bins
        fprintf(fp, "jmax %d number of backgrounds (QCD, Zinv, WJ, ttbar)\n",4);
        fprintf(fp, "kmax * nuissance\n");
        fprintf(fp, "------------\n");
        fprintf(fp, "bin Bin%d BinContQ%d BinContW%d BinContT%d ", Limitbin,Limitbin, Limitbin,Limitbin);
        //4 bins
        fprintf(fp, "\n observation %g %g %g %g", obs[Limitbin], qcdscale*qcd[Limitbin],wj[Limitbin],ttbarScale*ttbar[Limitbin]);
        //4 Expected Count bins (MC)
        fprintf(fp, "\nbin Bin%d  Bin%d  Bin%d  Bin%d  Bin%d ",Limitbin, Limitbin,Limitbin, Limitbin, Limitbin);
        fprintf(fp, "BinContQ%d  BinContQ%d  BinContQ%d  BinContQ%d  BinContQ%d ",Limitbin, Limitbin,Limitbin, Limitbin, Limitbin);
        fprintf(fp, "BinContW%d  BinContW%d  BinContW%d  BinContW%d  BinContW%d ",Limitbin, Limitbin,Limitbin, Limitbin, Limitbin);
        fprintf(fp, "BinContT%d  BinContT%d  BinContT%d  BinContT%d  BinContT%d ",Limitbin, Limitbin,Limitbin, Limitbin, Limitbin);
        
        fprintf(fp, "\nprocess sig QCD Zinv WJ ttbar ");
        fprintf(fp, "sig QCD Zinv WJ ttbar  ");
        fprintf(fp, "sig QCD Zinv WJ ttbar  ");
        fprintf(fp, "sig QCD Zinv WJ ttbar ");
       
        fprintf(fp, "\nprocess %d %d %d %d %d ", 0, 1,2,3,4);
        fprintf(fp, "%d %d %d %d %d ",0, 1,2,3,4);
        fprintf(fp, "%d %d %d %d %d ",0, 1,2,3,4);
        fprintf(fp, "%d %d %d %d %d ",0, 1,2,3,4);
        
        //NOW THIS IS MY EXPECTED SIGNAL REGION!
   //    fprintf(fp, "\nrate %g %g %g %g %g  ", sig[Limitbin], qcd[Limitbin],zi[Limitbin],wj[Limitbin],ttbar[Limitbin]);
    
        fprintf(fp, "\nrate %g ", sig[Limitbin]);
        if(qcd[Limitbin]>0.0000000000000000001)fprintf(fp, " %g ", qcd[Limitbin]);
        else fprintf(fp, " %g ",1.);
        
        fprintf(fp, " %g ", zi[Limitbin]);
        
       if(wj[Limitbin]>0.0000000000000000001)fprintf(fp, " %g ",wj[Limitbin]);
        else fprintf(fp, " %g ",1.);

       if(ttbar[Limitbin]>0.0000000000000000001)fprintf(fp, " %g ",ttbar[Limitbin]);
        else fprintf(fp, " %g ",1.);
        
        
        //QCD Region 1
        fprintf(fp, " %g ",0.);
        if(qcd[Limitbin]>0.0000000000000000001)fprintf(fp, " %g ",qcdscale*qcd[Limitbin]);
        else fprintf(fp, " %g ",qcdscale*1.);
        //fprintf(fp, " %g ",10.);
        fprintf(fp, " %g %g %g ",0., 0., 0.);
        
         //WJ Region 1
        fprintf(fp, " %g %g %g ",0.,0.,0.);
        if(wj[Limitbin]>0.0000000000000000001)fprintf(fp, " %g ",wj[Limitbin]);
        else fprintf(fp, " %g ",1.);
        fprintf(fp, " %g ",0.);
         //TT Region 1
        fprintf(fp, " %g %g %g %g ",0., 0.,0.,0.);
        if(ttbar[Limitbin]>0.0000000000000000001)fprintf(fp, " %g \n",ttbarScale*ttbar[Limitbin]);
        else fprintf(fp, " %g \n",ttbarScale*1.);
        
        float logUErr=100.;
        while(qcdscale*qcd[Limitbin]/logUErr>0.1)logUErr=logUErr+(1*logUErr);
        fprintf(fp, "rateBqcd%d lnU - %8.1f - - - ",Limitbin, logUErr );
        fprintf(fp, " - %8.1f - - - ",logUErr);
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - \n");
        
        
        fprintf(fp, "LogBqcd%d lnN - %g - - - ",Limitbin, 1.3 );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - \n");
        
        while(wj[Limitbin]/logUErr>0.1)logUErr=logUErr+(1.0*logUErr);
        fprintf(fp, "rateBW%d lnU - - - %8.1f - ",Limitbin, logUErr );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - %8.1f - ",logUErr);
        fprintf(fp, " - - - - - \n");
       
        fprintf(fp, "LogBW%d lnN - - - %g - ",Limitbin, 1.3 );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - \n");
    
        while(ttbarScale*ttbar[Limitbin]/logUErr>0.1)logUErr=logUErr+(1.0*logUErr);

        fprintf(fp, "rateBttbar%d lnU - - - - %8.1f ",Limitbin, logUErr );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - %8.1f \n",logUErr);
       
        fprintf(fp, "rateBtt%d lnN - - - - %g ",Limitbin, 1.3 );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - \n");
        
        fprintf(fp, "rateBZ%d lnN - - %g - - ",Limitbin, 1.3 );
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - ");
        fprintf(fp, " - - - - - \n");

        
    }
    else{
        int nbins=72;
        TString str=(TString::Format("SensTestCards/SensStudySys_M%d_m%d_%s_Lumi%d.dat", mGlu, MLSP,Options.Data(), lumi));
        //std::cout<<str.Data()<<std::endl;
      //  const char outputfilename[100]=str.Data();
        
        FILE* fp = fopen( str.Data(), "w" ) ;
        fprintf(fp, "imax %d number of channels\n", totalbins+(totalbins*3));
        fprintf(fp, "jmax %d number of backgrounds (QCD Zinv WJ ttbar)\n",4);
        fprintf(fp, "kmax * nuissance\n");
        fprintf(fp, "------------\n");
        fprintf(fp, "bin ");
        for(int i=0; i<nbins; ++i){
            fprintf(fp, " Bin%d contQCD%d contWJ%d contTT%d ",i,i,i,i);
            
        }
        
        fprintf(fp, "\n observation ");
        for(int i=0; i<nbins; ++i)fprintf(fp, " %g %g %g %g ",obs[i], qcdscale*qcd[i], wj[i], ttbar[i]);

            fprintf(fp, "\nbin ");
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "Bin%d Bin%d Bin%d Bin%d Bin%d ", i, i, i, i, i);
            fprintf(fp, " contQCD%d contQCD%d contQCD%d contQCD%d contQCD%d ", i, i, i, i, i);
            fprintf(fp, " contWJ%d contWJ%d contWJ%d contWJ%d contWJ%d ", i, i, i, i, i);
            fprintf(fp, " contTT%d contTT%d contTT%d contTT%d contTT%d ", i, i, i, i, i);

        }
            fprintf(fp, "\nprocess ");
        for(int i=0; i<nbins; ++i){
            
            fprintf(fp, " sig QCD Zinv WJ ttbar ");
            fprintf(fp, " sig QCD Zinv WJ ttbar ");
            fprintf(fp, " sig QCD Zinv WJ ttbar ");
            fprintf(fp, " sig QCD Zinv WJ ttbar ");
        }
            fprintf(fp, "\nprocess ");
        for(int i=0; i<nbins; ++i){
            fprintf(fp, " %d %d %d %d %d", 0,1,2,3,4);
            fprintf(fp, " %d %d %d %d %d", 0,1,2,3,4);
            fprintf(fp, " %d %d %d %d %d", 0,1,2,3,4);
            fprintf(fp, " %d %d %d %d %d", 0,1,2,3,4);
        }
            fprintf(fp, "\nrate ");
        for(int i=0; i<nbins; ++i){
            fprintf(fp, " %g ",sig[i]);
            
            if(qcd[i]>0.0000000000000000001)fprintf(fp, " %g ",qcd[i]);
            else fprintf(fp, " %g ",1.0);
            fprintf(fp, " %g ",zi[i]);
             if(wj[i]>0.0000000000000000001)fprintf(fp, " %g ",wj[i]);
            else fprintf(fp, " %g ",1.0);
            if(ttbar[i]>0.0000000000000000001)fprintf(fp, " %g ",ttbar[i]);
            else fprintf(fp, " %g ",1.0);
            
            if(qcd[i]>0.0000000000000000001)fprintf(fp, " %g %g %g %g %g ",0.0, qcdscale*qcd[i], 0.0,0.0,0.0);
            else fprintf(fp, " %g %g %g %g %g ",0.0, qcdscale*1.0, 0.0,0.0,0.0);
            if(wj[i]>0.0000000000000000001)fprintf(fp, " %g %g %g %g %g ",0.0, 0.0, 0.0,wj[i],0.0);
            else fprintf(fp, " %g %g %g %g %g ",0.0, 0.0, 0.0,1.0,0.0);
            if(ttbar[i]>0.0000000000000000001)fprintf(fp, " %g %g %g %g %g ",0.0, 0.0, 0.0,0.0,ttbar[i]);
            else fprintf(fp, " %g %g %g %g %g ",0.0, 0.0, 0.0,0.0,1.0);
            
        }
            fprintf(fp, "\n ------------ \n ");
         for(int i=0; i<nbins; ++i){
             fprintf(fp, "rateBqcd%d lnU ", i);
             float logUErr=100.;
             while(10*qcd[i]/logUErr>0.1)logUErr=logUErr+(1.0*logUErr);
             for(int j=0; j<nbins; ++j ){
                 if(i==j){
             fprintf(fp," - %8.2f - - - ", logUErr );
             fprintf(fp, " - %8.2f - - - ",logUErr);
             fprintf(fp, " - - - - - ");
             fprintf(fp, " - - - - - ");
                 }
                 else{
                     fprintf(fp, " - - - - - ");
                     fprintf(fp, " - - - - - ");
                     fprintf(fp, " - - - - - ");
                     fprintf(fp, " - - - - - ");
                     
                 }
             }
              fprintf(fp, " \n ");
             
             
         }
        
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBwj%d lnU ", i);
            float logUErr=100.;
           while(10*wj[i]/logUErr>0.1)logUErr=logUErr+(1.0*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - - - %8.2f - ", logUErr );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - %8.2f - ",logUErr);
                    fprintf(fp, " - - - - - ");
                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
        }
        
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBttbar%d lnU ", i);
            float logUErr=100.;
            while(10*ttbar[i]/logUErr>0.1)logUErr=logUErr+(1.0*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - - - - %8.2f ", logUErr );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - %8.2f ",logUErr);

                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
        }
        
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBZ%d lnN ", i);
         //   float logUErr=100.;
           // while(10*qcd[i]/logUErr>0.2)logUErr=logUErr+(0.1*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - - %g - - ", 1.25 );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
            
            
        }
        
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBQCDLog%d lnN ", i);
              //float logUErr=100.;
             //while(10*qcd[i]/logUErr>0.2)logUErr=logUErr+(0.1*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - %g - - - ", 1.25 );
                    fprintf(fp," - - - - - " );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
        }

        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBWLog%d lnN ", i);
              //float logUErr=100.;
            //while(10*qcd[i]/logUErr>0.2)logUErr=logUErr+(0.1*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - - - %g - ", 1.25 );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp," - - - - - " );
                    fprintf(fp, " - - - - - ");
                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
        }
        
        for(int i=0; i<nbins; ++i){
            fprintf(fp, "rateBTTLog%d lnN ", i);
              //float logUErr=100.;
            //while(10*qcd[i]/logUErr>0.2)logUErr=logUErr+(0.1*logUErr);
            for(int j=0; j<nbins; ++j ){
                if(i==j){
                    fprintf(fp," - - - - %g ", 1.25 );
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp," - - - - - " );

                }
                else{
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    fprintf(fp, " - - - - - ");
                    
                }
            }
            fprintf(fp, " \n ");
        }

    }
}

void MakeInputHiso(){  //all input files
    const int nBinsjets = 3 ;
    const int nBinsBjets = 4 ;
    const int nBinsMHT = 3 ;
    const int nBinsHT = 3 ;
    //float METBinRectangular[4]={200, 500., 750.,9999.};

    float MHTBinRectangular[4]={200, 500., 750.,9999.};
    float HTBinRectangular[4]={500., 800., 1200.,9999.};//can do 150 to
    
    char bcutstringRectangular[nBinsBjets][100] = { "BTags30==0", "BTags30==1","BTags30==2", "BTags30>=3" } ;
    float NJets[4]={4, 7,9,99};

TChain t1tt1500("TreeMaker2/ReducedTree");
t1tt1500.Add(TString::Format("./SignalFiles/ReducedTree_SMSttttM1500.root"));

TChain t1tt1200("TreeMaker2/ReducedTree");
t1tt1200.Add(TString::Format("./SignalFiles/ReducedTree_SMSttttM1200.root"));
    
TChain t1bb1000("TreeMaker2/ReducedTree");
t1bb1000.Add(TString::Format("./SignalFiles/ReducedTree_SMSbbbbM1000.root"));
    
TChain t1bb1500("TreeMaker2/ReducedTree");
t1bb1500.Add(TString::Format("./SignalFiles/ReducedTree_SMSbbbbM1500.root"));

    TChain t1qq1000("TreeMaker2/ReducedTree");
    t1qq1000.Add(TString::Format("./SignalFiles/ReducedTree_SMSqqqqM1000.root"));
    
    TChain t1qq1400("TreeMaker2/ReducedTree");
    t1qq1400.Add(TString::Format("./SignalFiles/ReducedTree_SMSqqqqM1400.root"));
    
TChain QCDCH("TreeMaker2/ReducedTree") ;
QCDCH.Add("./QCD/ReducedTree_QCDHT500.root");
QCDCH.Add("./QCD/ReducedTree_QCDHT250.root");
QCDCH.Add("./QCD/ReducedTree_QCDHT1000.root");

TChain WJets("TreeMaker2/ReducedTree");
WJets.Add("./WJets/ReducedTree_WJ100.root");
WJets.Add("./WJets/ReducedTree_WJ200.root");
WJets.Add("./WJets/ReducedTree_WJ400.root");
WJets.Add("./WJets/ReducedTree_WJ600Merged.root");


TChain tt("TreeMaker2/ReducedTree");
tt.Add("./TTJets/ReducedTree_TBarToLeptons_t.root");
tt.Add("./TTJets/ReducedTree_TToLeptons_t.root");
tt.Add("./TTJets/ReducedTree_TTJetsMSDecaysCKM.root");
tt.Add("./TTJets/ReducedTree_T_tW.root");
tt.Add("./TTJets/ReducedTree_Tbar_tW.root");


TChain Zinv("TreeMaker2/ReducedTree") ;
Zinv.Add("./ZInv/ReducedTree_ZInv100.root");
    Zinv.Add("./ZInv/ReducedTree_ZInv200.root");
    Zinv.Add("./ZInv/ReducedTree_ZInv400.root");
    Zinv.Add("./ZInv/ReducedTree_ZInv600.root");



char commoncuts[10000] ;

sprintf( commoncuts,"HT30>500 && NJets30>=4 && MHT>200 && (Muons==0 && Electrons==0) && abs(minDeltaPhiN)<4.0 && isoTracks==0" ); //event selection

char weightstring[10000];
sprintf(weightstring, "*(weight*4000)"); //bkg xsec weight

char weightstringSig[10000];
//sprintf(weightstringSig, "*((0.0141903 *5000)/(105679.0))"); //sig xsec added by hand for phys14 it will be in the ntuple
char arg1[1000] ;
char cuts[10000];
//yields stored in a TH3* (one for each btag) so 4D
TH3F*sig4t1200_[4];
TH3F*sig4t1500_[4];

    TH3F*sig4b1500_[4];
    TH3F*sig4b1000_[4];
    TH3F*sig4q1400_[4];
    TH3F*sig4q1000_[4];
    
TH3F*qcd_[4];
TH3F*tt_[4];
TH3F*WJ_[4];
TH3F*ZI_[4];

//REALLY NEED TO ONLY DO THIS ONCE
TFile*f0=new TFile(TString::Format("Bins4DBINS4fbSL.root").Data(), "RECREATE");
for(int b=0; b<nBinsBjets; ++b){
    
    sig4t1500_[b]=new TH3F(TString::Format("sig4t1500__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    sig4t1200_[b]=new TH3F(TString::Format("sig4t1200__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );

    
    sig4b1500_[b]=new TH3F(TString::Format("sig4b1500__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    sig4b1000_[b]=new TH3F(TString::Format("sig4b1000__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    
    sig4q1000_[b]=new TH3F(TString::Format("sig4q1000__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    sig4q1400_[b]=new TH3F(TString::Format("sig4q1400__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    
    qcd_[b]=new TH3F(TString::Format("qcd__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular, nBinsHT,HTBinRectangular );
    tt_[b]=new TH3F(TString::Format("tt__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    WJ_[b]=new TH3F(TString::Format("WJ__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    ZI_[b]=new TH3F(TString::Format("ZI__b%d", b).Data(), "", nBinsjets, NJets,nBinsMHT,MHTBinRectangular,nBinsHT,HTBinRectangular  );
    
    sprintf( cuts, "(%s && %s )%s", commoncuts,bcutstringRectangular[b],weightstring );
    //HT30:MHT:NJets30
    
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4t1500__b%d",b).Data()) ;
    t1tt1500.Draw( arg1, cuts );
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4t1200__b%d",b).Data()) ;
    t1tt1200.Draw( arg1, cuts );
    
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4q1400__b%d",b).Data()) ;
    t1qq1400.Draw( arg1, cuts );
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4q1000__b%d",b).Data()) ;
    t1qq1000.Draw( arg1, cuts );
    
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4b1500__b%d",b).Data()) ;
    t1bb1500.Draw( arg1, cuts );
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>sig4b1000__b%d",b).Data()) ;
    t1bb1000.Draw( arg1, cuts );

    
    //sprintf( cuts, "(%s && %s )%s", commoncuts,bcutstringRectangular[b],weightstring );
    
    
    
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>qcd__b%d",b).Data()) ;
    QCDCH.Draw( arg1, cuts ) ;
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>tt__b%d",b).Data()) ;
    tt.Draw( arg1, cuts ) ;
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>WJ__b%d",b).Data()) ;
    WJets.Draw( arg1, cuts );
    sprintf( arg1, TString::Format("HT30:MHT:NJets30>>ZI__b%d",b).Data()) ;
    Zinv.Draw( arg1, cuts ) ;
    
    sig4t1500_[b]->Write();
    sig4t1200_[b]->Write();
    
    sig4q1000_[b]->Write();
    sig4q1400_[b]->Write();
    
    sig4b1500_[b]->Write();
    sig4b1000_[b]->Write();
    
    qcd_[b]->Write();
    WJ_[b]->Write();
    tt_[b]->Write();
    ZI_[b]->Write();
    }
}
