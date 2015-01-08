//
//  MakeDataCard13TeV.C
//  
//
//  Created by Rishi Patel on 11/24/14.
//
//

#include <stdio.h>


void MakeDataCard13TeVStdBin() {
    int mGlu=1500;
    int MLSP=100;

      const int njets = 3 ;
    
    const int nBinsBjets = 3 ;//add bin? 0bjet for RA2
    const int nBinsMET = 4 ;
    const int nBinsHT = 5 ;

    //Now also have real MHT and can do MET-HT/MET
    float HbinsAllJ[6] = {500.,800.,1000., 1250., 1500., 9999.};
    float MHTBin[5]={200, 300., 450., 600.,9999.};//can do 150 to
    float MHTBinRectangular[4]={200, 500., 750.,9999.};//can do 150 to
    float HTBinRectangular[4]={500., 800., 1200.,9999.};//can do 150 to
    //float NJets[5]={4, 6,8,9,99};
    char bcutstringRectangular[4][100] = { "nbjets==0", "nbjets==1","nbjets==2", "nbjets>=3" } ;

    float ratioMETHT[5]={0, 2, 4, 8, 9999.};
    float NJets[4]={3, 6,8,99};

     TChain t1tt("reducedTree");
   // t1tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2085_v73-skim.root");
    t1tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2120_v73-skim.root");
    
    TChain QCDCH("reducedTree") ;
    QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2118_v73-skim.root");
    QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-10to15_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2103_v73-skim.root");              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-120to170_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2109_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2101_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-15to30_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2104_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-170to300_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2098_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2100_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2099_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2135_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-30to50_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2126_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2136_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2137_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-50to80_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2127_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-5to10_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2125_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-600to800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2138_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2130_v73-skim.root");
              QCDCH.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.QCD_Pt-80to120_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2128_v73-skim.root");
    
      TChain WJets("reducedTree");
    WJets.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2097_v73-skim.root");
      WJets.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2096_v73-skim.root");
      WJets.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2121_v73-skim.root");
      WJets.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2122_v73-skim.root");

    TChain tt("reducedTree");
    
    tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2090_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2092_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2087_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU_S14_POSTLS170_V6-v1_MINIAODSIM_UCSB2088_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2091_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2107_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2093_v73-skim.root");
     tt.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2094_v73-skim.root");

     TChain Zinv("reducedTree") ;
     Zinv.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2106_v73-skim.root");
     Zinv.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2108_v73-skim.root");
     Zinv.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2111_v73-skim.root");
     Zinv.Add("reducedTree.JES0_JER0_PFMETTypeI_METunc0_PUunc0_hpt20.ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2112_v73-skim.root");
    
    const int nJetsCut = 3 ; // #jets >= nJetsCut MIGHT WANT TO CHANGE THIS nJetsCut>=2 get swamped by top?
    double minLeadJetPt = 50. ;
    double min3rdJetPt = 50. ;
    char commoncuts[10000] ;
    
    sprintf( commoncuts,"HT>500 && njets>=4 && MET>200 && nMuons==0 && nElectrons==0 && minDeltaPhiN_asin>4.0 && jetpt1>%g && jetpt2>%g && jetpt3>%g", minLeadJetPt,min3rdJetPt,min3rdJetPt );
    char weightstring[10000];
    sprintf(weightstring, "*(weight3*5000*hlteff)");
    
    char weightstringSig[10000];
   // sprintf(weightstringSig, "*((0.0856418 *5000)/(100322.0)*hlteff*SUSY_ISRweight)");

     sprintf(weightstringSig, "*((0.0141903 *5000)/(105679.0)*hlteff*SUSY_ISRweight)");

    char arg1[1000] ;
    char cuts[10000];
    
    TH3F*sig4t_zl[4];
    TH3F*qcd_zl[4];
    TH3F*tt_zl[4];
    TH3F*WJ_zl[4];
    TH3F*ZI_zl[4];
    for(int b=0; b<4; ++b){
        sig4t_zl[b]=new TH3F(TString::Format("sig4t_zl_b%d", b).Data(), "", 3, NJets,3,MHTBinRectangular,3,HTBinRectangular  );
   qcd_zl[b]=new TH3F(TString::Format("qcd_zl_b%d", b).Data(), "", 3, NJets,3,MHTBinRectangular, 3,HTBinRectangular );
  tt_zl[b]=new TH3F(TString::Format("tt_zl_b%d", b).Data(), "", 3, NJets,3,MHTBinRectangular,3,HTBinRectangular  );
   WJ_zl[b]=new TH3F(TString::Format("WJ_zl_b%d", b).Data(), "", 3, NJets,3,MHTBinRectangular,3,HTBinRectangular  );
   ZI_zl[b]=new TH3F(TString::Format("ZI_zl_b%d", b).Data(), "", 3, NJets,3,MHTBinRectangular,3,HTBinRectangular  );
    
    
        sprintf( arg1, TString::Format("HT:MHT:njets>>sig4t_zl_b%d",b).Data()) ;
    sprintf( cuts, "(%s && %s)%s", commoncuts,bcutstringRectangular[b],weightstringSig );
    t1tt.Draw( arg1, cuts );
    sprintf( cuts, "(%s && %s )%s", commoncuts,bcutstringRectangular[b],weightstring );



    sprintf( arg1, TString::Format("HT:MHT:njets>>qcd_zl_b%d",b).Data()) ;
    QCDCH.Draw( arg1, cuts ) ;
    sprintf( arg1, TString::Format("HT:MHT:njets>>tt_zl_b%d",b).Data()) ;
    tt.Draw( arg1, cuts ) ;
    sprintf( arg1, TString::Format("HT:MHT:njets>>WJ_zl_b%d",b).Data()) ;
    WJets.Draw( arg1, cuts );
    sprintf( arg1, TString::Format("HT:MHT:njets>>ZI_zl_b%d",b).Data()) ;
    Zinv.Draw( arg1, cuts ) ;
    }
   const int totalbins=3*3*3*4;
    float sigZL[totalbins];
    float qcdZL[totalbins];
    float ziZL[totalbins];
    float wjZL[totalbins];
    float ttZL[totalbins];
    int ibin=0;
    int nJBins=sig4t_zl[0]->GetNbinsX();
    int nHBins=sig4t_zl[0]->GetNbinsZ();
    int nMHBins=sig4t_zl[0]->GetNbinsY();
  //  cout<<"Nbins "<<sig4t_zl[0]->GetNbinsX()*sig4t_zl[0]->GetNbinsY()*sig4t_zl[0]->GetNbinsZ()<<std::endl;
    //return;
    TH2D*Bkg2d=new TH2D("Bkg2d", "", 3,MHTBinRectangular,3,HTBinRectangular  );

    int nonzero=0;
    for(int nb=0; nb<=3; nb++){
        for ( int hti=1; hti<=3; hti++ ) {
            for ( int mhti=1; mhti<=3; mhti++ ) {
                for ( int ij=1; ij<=3; ij++ ) {

                {
                   // std::cout<<sig4t_zl[nb]->GetBinContent( ij, mhti, hti )<<std::endl;
                    sigZL[ibin]=sig4t_zl[nb]->GetBinContent( ij, mhti, hti );
                    qcdZL[ibin]=qcd_zl[nb]->GetBinContent( ij, mhti, hti );
                    ziZL[ibin]=ZI_zl[nb]->GetBinContent( ij, mhti, hti );
                  wjZL[ibin]=WJ_zl[nb]->GetBinContent( ij, mhti, hti );
                  ttZL[ibin]=tt_zl[nb]->GetBinContent( ij, mhti, hti );
                    if( qcdZL[ibin]+ziZL[ibin]+wjZL[ibin]+ttZL[ibin]>0.00000001)++nonzero;
                    if(ij >=3 && nb>=2){
                        std::cout<<"QCD "<<qcdZL[ibin]<<std::endl;
                         std::cout<<"ZInv "<<ziZL[ibin]<<std::endl;
                        std::cout<<"Wjets "<< wjZL[ibin]<<std::endl;
                        std::cout<<"TTbar "<< ttZL[ibin]<<std::endl;
                        
                       // Bkg2d->SetBinContent(mhti, hti, qcdZL[ibin]+ziZL[ibin]+wjZL[ibin]+ttZL[ibin]);
                        Bkg2d->SetBinContent(mhti, hti, sigZL[ibin]);
                        
                    }
                    ++ibin;
                    //std::cout<<"ibin "<<ibin<<std::endl;
                }
            }
        }
      }
    }
    std::cout<<"Non zero bkg bins "<<nonzero<<std::endl;
     //   return;
    for ( int hti=1; hti<=3; hti++ ) {
        for ( int mhti=1; mhti<=3; mhti++ ) {
            Bkg2d->SetBinContent(mhti, hti,Bkg2d->GetBinContent(mhti, hti)/Bkg2d->Integral() );

        }
    }

    Bkg2d->Draw("colz");
    //this will be the method one data Card

    TString str=(TString::Format("datfiles/SensStudyRA2_M%d_m%d_DEFAULT.dat",mGlu, MLSP)).Data();
    const char outputfilename[100]=str.Data();
    
    FILE* fp = fopen( outputfilename, "w" ) ;
    
    fprintf(fp, "imax %d number of channels\n", nonzero);
    fprintf(fp, "jmax 1 number of backgrounds (QCD, Zinv, WJ, tt) all combined\n");
    fprintf(fp, "kmax * nuissance\n");
    fprintf(fp, "------------\n");
    fprintf(fp, "bin ");
    for(int i=1; i<=nonzero; ++i)fprintf(fp, "%d ", i-1);
    fprintf(fp, "\n observation ");
 
    for(int i=1; i<=108; ++i){
        double bkgyield=qcdZL[i-1]+ziZL[i-1]+ttZL[i-1]+wjZL[i-1];
        if(bkgyield<0.00000001)continue;
        fprintf(fp, "%g ", bkgyield);
    }
    
    for(int i=0; i<nonzero; ++i){
        if(i==0)fprintf(fp, "\nbin %d %d ", i, i);
        else fprintf(fp, "%d %d ", i, i);
    }
   
    for(int i=0; i<nonzero; ++i){
        if(i==0)fprintf(fp, "\n process sig bkg ", i, i);
        else fprintf(fp, "sig bkg ", i, i);
    }
    
    for(int i=0; i<nonzero; ++i)
    {
        if(i==0)fprintf(fp, "\n process %d %d ", 0, 1);
        else fprintf(fp, "0 1 ");
    }
    
    for(int i=0; i<108; ++i){
        
        double sigyield, bkgyield;
        sigyield=sigZL[i];
       bkgyield=qcdZL[i]+ziZL[i]+ttZL[i]+wjZL[i];
      if(bkgyield<0.00000001)continue;
        if(i==0)fprintf(fp, "\n rate %g %g ", sigyield, bkgyield);
        else fprintf(fp, "%g %g ", sigyield, bkgyield);
        
    }
    
    fclose( fp ) ;
    printf("\n\n Wrote results to %s\n\n", outputfilename ) ;
    
    return;
    
    TString str2=(TString::Format("datfiles/SensStudyRA2_M%d_m%d_SplitBkg.dat",mGlu, MLSP)).Data();
    const char outputfilename2[100]=str2.Data();

    FILE* fp2 = fopen( outputfilename2, "w" ) ;
    
    fprintf(fp2, "imax %d number of channels\n", totalbins);
    fprintf(fp2, "jmax 4 number of backgrounds (QCD, Zinv, WJ, tt) all combined\n");
    fprintf(fp2, "kmax * nuissance\n");
    fprintf(fp2, "------------\n");
    fprintf(fp2, "bin ");
    for(int i=1; i<=totalbins; ++i)fprintf(fp, "%d ", i-1);
    fprintf(fp2, "\n observation ");
    
    for(int i=1; i<=totalbins; ++i){
        double bkgyield=qcdZL[i-1]+ziZL[i-1]+ttZL[i-1]+wjZL[i-1];
        
        fprintf(fp, "%g ", bkgyield);
    }
    for(int i=0; i<totalbins; ++i){
        if(i==0)fprintf(fp2, "\nbin %d %d ", i, i);
        else fprintf(fp2, "%d %d ", i, i);
    }
    for(int i=0; i<totalbins; ++i){
        if(i==0)fprintf(fp2, "\n process sig QCD, Zinv, WJ, tt ", i, i);
        else fprintf(fp2, "sig QCD, Zinv, WJ, tt ", i, i);
    }
    for(int i=0; i<totalbins; ++i)
    {
        if(i==0)fprintf(fp2, "\n process %d %d %d %d %d", 0, 1, 2,3, 4);
        else fprintf(fp2, "0 1 ");
    }
    for(int i=0; i<totalbins; ++i){
        
        double sigyield, bkgyield;
        sigyield=sigZL[i];//bkgyield=qcdZL[i]+ziZL[i]+ttZL[i]+wjZL[i];
        if(i==0)fprintf(fp2, "\n rate %g %g %g %g %g", sigyield, qcdZL[i],ziZL[i],ttZL[i],wjZL[i]);
        else fprintf(fp2, "%g %g %g %g %g ", sigyield, qcdZL[i],ziZL[i],ttZL[i],wjZL[i]);
        
    }
    fclose( fp2 ) ;
    printf("\n\n Wrote results to %s\n\n", outputfilename2 ) ;
    
    
    TString str3=(TString::Format("datfiles/SensStudyRA2_M%d_m%d_Shapes2.dat",mGlu, MLSP)).Data();
    const char outputfilename2[100]=str2.Data();
    
    FILE* fp2 = fopen( outputfilename2, "w" ) ;
    
    fprintf(fp2, "imax %d number of channels\n", totalbins);
    fprintf(fp2, "jmax 4 number of backgrounds (QCD, Zinv, WJ, tt) all combined\n");
    fprintf(fp2, "kmax * nuissance\n");
    fprintf(fp2, "------------\n");
    fprintf(fp2, "bin ");
    for(int i=1; i<=totalbins; ++i)fprintf(fp, "%d ", i-1);
    fprintf(fp2, "\n observation ");
    
    for(int i=1; i<=totalbins; ++i){
        double bkgyield=qcdZL[i-1]+ziZL[i-1]+ttZL[i-1]+wjZL[i-1];
        
        fprintf(fp, "%g ", bkgyield);
    }
    for(int i=0; i<totalbins; ++i){
        if(i==0)fprintf(fp2, "\nbin %d %d ", i, i);
        else fprintf(fp2, "%d %d ", i, i);
    }
    for(int i=0; i<totalbins; ++i){
        if(i==0)fprintf(fp2, "\n process sig QCD, Zinv, WJ, tt ", i, i);
        else fprintf(fp2, "sig QCD, Zinv, WJ, tt ", i, i);
    }
    for(int i=0; i<totalbins; ++i)
    {
        if(i==0)fprintf(fp2, "\n process %d %d %d %d %d", 0, 1, 2,3, 4);
        else fprintf(fp2, "0 1 ");
    }
    for(int i=0; i<totalbins; ++i){
        
        double sigyield, bkgyield;
        sigyield=sigZL[i];//bkgyield=qcdZL[i]+ziZL[i]+ttZL[i]+wjZL[i];
        if(i==0)fprintf(fp2, "\n rate %g %g %g %g %g", sigyield, qcdZL[i],ziZL[i],ttZL[i],wjZL[i]);
        else fprintf(fp2, "%g %g %g %g %g ", sigyield, qcdZL[i],ziZL[i],ttZL[i],wjZL[i]);
        
    }
    fclose( fp2 ) ;
    printf("\n\n Wrote results to %s\n\n", outputfilename2 ) ;
    /*
    TH3F* sig4t_4D[3];
    TH3F* qcd_4D[3];
    TH3F* WJ_4D[3];
    TH3F* ZI_4D[3];
    TH3F* tt_4D[3];
    float HbinsAllJNEW[4] = {500.,800.,1200., 9999.};
    float MHTBinNEW[4]={150, 250., 400,9999.};
    for ( int bbi=0; bbi<nBinsBjets; bbi++ ) {
        char arg1[1000] ;
        char cuts[10000] ;
        sprintf( commoncuts,"HT>500 && njets>=3 && MET>175 && nMuons==0 && nElectrons==0 && minDeltaPhiN_asin>4.0 ");

       //  sprintf( cuts, "(%s && %s)%s", commoncuts,bcutstring[bbi],weightstringSig );
        sig4t_4D[bbi]=new TH3F(TString::Format("sig4t_4D_%d",bbi).Data(), "", 3, NJets,3,MHTBinNEW,3,HbinsAllJNEW  );
        sprintf( arg1, "HT:MHT:njets>>sig4t_4D_%d", bbi) ;
        
        sprintf( cuts, "(%s &&  %s)%s", commoncuts, bcutstringRectangular[bbi], weightstringSig );
        t1tt.Draw( arg1, cuts );
        sprintf( cuts, "(%s && %s)%s", commoncuts, bcutstringRectangular[bbi], weightstring);
        
        qcd_4D[bbi]=new TH3F(TString::Format("qcd_4D_%d",bbi).Data(), "", 3, NJets,3,MHTBinNEW,3,HbinsAllJNEW  );
        tt_4D[bbi]=new TH3F(TString::Format("tt_4D_%d",bbi).Data(), "",3, NJets,3,MHTBinNEW,3,HbinsAllJNEW  );
       WJ_4D[bbi]=new TH3F(TString::Format("WJ_4D_%d",bbi).Data(),"", 3, NJets,3,MHTBinNEW,3,HbinsAllJNEW  );
       ZI_4D[bbi]=new TH3F(TString::Format("ZI_4D_%d",bbi).Data(), "", 3, NJets,3,MHTBinNEW,3,HbinsAllJNEW  );
        
        sprintf( arg1, "HT:MHT:njets>>qcd_4D_%d", bbi);
        QCDCH.Draw( arg1, cuts ) ;
        sprintf( arg1, "HT:MHT:njets>>tt_4D_%d", bbi);
        tt.Draw( arg1, cuts ) ;
        sprintf( arg1,"HT:MHT:njets>>WJ_4D_%d", bbi);
        WJets.Draw( arg1, cuts );
        sprintf( arg1, "HT:MHT:njets>>ZI_4D_%d", bbi);
        Zinv.Draw( arg1, cuts ) ;

    }
    
    const int totalbinsnew=27+12+4;
    float sig4D[totalbinsnew];
    float qcd4D[totalbinsnew];
    float zi4D[totalbinsnew];
    float wj4D[totalbinsnew];
    float tt4D[totalbinsnew];
    int ibin=0;
    

    const int nBinsHTnew=3.;
    for(int nji=1; nji<=2; nji++){
        for ( int hti=1; hti<=nBinsHTnew; hti++ ) {
            
            
            
            // for(int nb=0; nb<3; ++nb){
            if(nji==1 ){
                for ( int mhti=1; mhti<=3; mhti++ ){
                    sig4D[ibin]=sig4t_4D[0]->GetBinContent( nji, mhti, hti );
                    qcd4D[ibin]=qcd_4D[0]->GetBinContent(nji, mhti, hti );
                    tt4D[ibin]=tt_4D[0]->GetBinContent(nji, mhti, hti );
                    zi4D[ibin]=ZI_4D[0]->GetBinContent(nji, mhti, hti );
                    wj4D[ibin]=WJ_4D[0]->GetBinContent(nji, mhti, hti );
                    ibin++;
                    sig4D[ibin]=sig4t_4D[1]->GetBinContent( nji, mhti, hti );
                    qcd4D[ibin]=qcd_4D[1]->GetBinContent(nji, mhti, hti );
                    tt4D[ibin]=tt_4D[1]->GetBinContent(nji, mhti, hti );
                    zi4D[ibin]=ZI_4D[1]->GetBinContent(nji, mhti, hti );
                    wj4D[ibin]=WJ_4D[1]->GetBinContent(nji, mhti, hti );
                    ibin++;
                    sig4D[ibin]=sig4t_4D[2]->GetBinContent( nji, mhti, hti );
                    qcd4D[ibin]=qcd_4D[2]->GetBinContent(nji, mhti, hti );
                    tt4D[ibin]=tt_4D[2]->GetBinContent(nji, mhti, hti );
                    zi4D[ibin]=ZI_4D[2]->GetBinContent(nji, mhti, hti );
                    wj4D[ibin]=WJ_4D[2]->GetBinContent(nji, mhti, hti );
                    ibin++;
                }
            }
            if(nji==2 && hti<2){
                for ( int mhti=1; mhti<=3; mhti++ ){
                    sig4D[ibin]=sig4t_4D[0]->GetBinContent( nji, mhti, hti )+sig4t_4D[1]->GetBinContent( nji, mhti, hti );
                    qcd4D[ibin]=qcd_4D[0]->GetBinContent(nji, mhti, hti )+qcd_4D[1]->GetBinContent(nji, mhti, hti );
                    tt4D[ibin]=tt_4D[0]->GetBinContent(nji, mhti, hti )+tt_4D[1]->GetBinContent(nji, mhti, hti );
                    zi4D[ibin]=ZI_4D[0]->GetBinContent(nji, mhti, hti )+ZI_4D[1]->GetBinContent(nji, mhti, hti );
                    wj4D[ibin]=WJ_4D[0]->GetBinContent(nji, mhti, hti )+WJ_4D[1]->GetBinContent(nji, mhti, hti );
                    ibin++;
                    sig4D[ibin]=sig4t_4D[2]->GetBinContent( nji, mhti, hti );
                    qcd4D[ibin]=qcd_4D[2]->GetBinContent(nji, mhti, hti );
                    tt4D[ibin]=tt_4D[2]->GetBinContent(nji, mhti, hti );
                    zi4D[ibin]=ZI_4D[2]->GetBinContent(nji, mhti, hti );
                    wj4D[ibin]=WJ_4D[2]->GetBinContent(nji, mhti, hti );
                    ibin++;
                }
            }
            
            if(nji==2 && hti==2){
                for ( int mhti=1; mhti<=3; mhti++ ){
                    sig4D[ibin]=sig4t_4D[0]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew )+sig4t_4D[1]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    qcd4D[ibin]=qcd_4D[0]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew )+qcd_4D[1]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    tt4D[ibin]=tt_4D[0]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew )+tt_4D[1]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    zi4D[ibin]=ZI_4D[0]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew )+ZI_4D[1]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    wj4D[ibin]=WJ_4D[0]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew )+WJ_4D[1]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    ++ibin;
                    
                    sig4D[ibin]=sig4t_4D[2]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    qcd4D[ibin]=qcd_4D[2]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    tt4D[ibin]=tt_4D[2]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    zi4D[ibin]=ZI_4D[2]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    wj4D[ibin]=WJ_4D[2]->Integral(nji, nji,mhti, mhti,hti,nBinsHTnew );
                    ++ibin;
                }
                
            }
            
        }
    }
    
    
    
    sig4D[ibin]=sig4t_4D[0]->Integral(3, 3,1, 1,1,nBinsHTnew )+sig4t_4D[1]->Integral(3, 3,1, 1,1,nBinsHTnew );
    qcd4D[ibin]=qcd_4D[0]->Integral(3, 3,1, 1,1,nBinsHTnew )+qcd_4D[1]->Integral(3, 3,1, 1,1,nBinsHTnew );
    tt4D[ibin]=tt_4D[0]->Integral(3, 3,1, 1,1,nBinsHTnew )+tt_4D[1]->Integral(3, 3,1, 1,1,nBinsHTnew );
    zi4D[ibin]=ZI_4D[0]->Integral(3, 3,1, 1,1,nBinsHTnew )+ZI_4D[1]->Integral(3, 3,1, 1,1,nBinsHTnew );
    wj4D[ibin]=WJ_4D[0]->Integral(3, 3,1, 1,1,nBinsHTnew )+WJ_4D[1]->Integral(3, 3,1, 1,1,nBinsHTnew );
    ++ibin;
    
    sig4D[ibin]=sig4t_4D[2]->Integral(3, 3,1, 1,1,nBinsHTnew );
    qcd4D[ibin]=qcd_4D[2]->Integral(3, 3,1, 1,1,nBinsHTnew );
    tt4D[ibin]=tt_4D[2]->Integral(3, 3,1, 1,1,nBinsHTnew );
    zi4D[ibin]=ZI_4D[2]->Integral(3, 3,1, 1,1,nBinsHTnew );
    wj4D[ibin]=WJ_4D[2]->Integral(3, 3,1, 1,1,nBinsHTnew );
    ++ibin;
    
    sig4D[ibin]=sig4t_4D[0]->Integral(3, 3,2, 3,1,nBinsHTnew )+sig4t_4D[1]->Integral(3, 3,2, 3,1,nBinsHTnew );
    qcd4D[ibin]=qcd_4D[0]->Integral(3, 3,2, 3,1,nBinsHTnew )+qcd_4D[1]->Integral(3, 3,2, 3,1,nBinsHTnew );
    tt4D[ibin]=tt_4D[0]->Integral(3, 3,2, 3,1,nBinsHTnew )+tt_4D[1]->Integral(3, 3,2, 3,1,nBinsHTnew );
    zi4D[ibin]=ZI_4D[0]->Integral(3, 3,2, 3,1,nBinsHTnew )+ZI_4D[1]->Integral(3, 3,2, 3,1,nBinsHTnew );
    wj4D[ibin]=WJ_4D[0]->Integral(3, 3,2, 3,1,nBinsHTnew )+WJ_4D[1]->Integral(3, 3,2, 3,1,nBinsHTnew );
    ++ibin;
    
    sig4D[ibin]=sig4t_4D[2]->Integral(3, 3,2,3,1,nBinsHTnew );
    qcd4D[ibin]=qcd_4D[2]->Integral(3, 3,2,3,1,nBinsHTnew );
    tt4D[ibin]=tt_4D[2]->Integral(3, 3,2,3,1,nBinsHTnew );
    zi4D[ibin]=ZI_4D[2]->Integral(3, 3,2,3,1,nBinsHTnew );
    wj4D[ibin]=WJ_4D[2]->Integral(3, 3,2,3,1,nBinsHTnew );
    ++ibin;
    TString str=(TString::Format("datfiles/SensStudyRA2_M%d_m%d_4Dbins.dat",mGlu, MLSP)).Data();
    const char outputfilename3[100]=str.Data();

    FILE* fp3 = fopen( outputfilename3, "w" ) ;
    fprintf(fp3, "imax %d number of channels\n", ibin);
    fprintf(fp3, "jmax 1 number of backgrounds (QCD, Zinv, WJ, tt) all combined\n");
    fprintf(fp3, "kmax * nuissance\n");
    fprintf(fp3, "------------\n");
    fprintf(fp3, "bin ");
    for(int i=1; i<=ibin; ++i)fprintf(fp3, "%d ", i-1);
    fprintf(fp3, "\n observation ");
    
    for(int i=1; i<=ibin; ++i){
        double bkgyield=qcd4D[i-1]+zi4D[i-1]+tt4D[i-1]+wj4D[i-1];
        
        fprintf(fp3, "%g ", bkgyield);
    }
    for(int i=0; i<ibin; ++i){
        if(i==0)fprintf(fp3, "\nbin %d %d ", i, i);
        else fprintf(fp3, "%d %d ", i, i);
    }
    for(int i=0; i<ibin; ++i){
        if(i==0)fprintf(fp3, "\n process sig QCD, Zinv, WJ, tt ", i, i);
        else fprintf(fp3, "sig QCD, Zinv, WJ, tt ", i, i);
    }
    for(int i=0; i<ibin; ++i)
    {
        if(i==0)fprintf(fp3, "\n process %d %d %d %d %d", 0, 1, 2,3, 4);
        else fprintf(fp3, "0 1 ");
    }
    for(int i=0; i<ibin; ++i){
        
        double sigyield, bkgyield;
        sigyield=sig4D[i];//bkgyield=qcdZL[i]+ziZL[i]+ttZL[i]+wjZL[i];
        if(i==0)fprintf(fp3, "\n rate %g %g %g %g %g", sigyield, qcd4D[i],zi4D[i],tt4D[i],wj4D[i]);
        else fprintf(fp3, "%g %g %g %g %g ", sigyield, qcd4D[i],zi4D[i],tt4D[i],wj4D[i]);
        
    }
    fclose( fp3 ) ;
    printf("\n\n Wrote results to %s\n\n", outputfilename3 ) ;
*/
    

}
