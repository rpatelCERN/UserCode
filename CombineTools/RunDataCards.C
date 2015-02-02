void RunDataCards(){
gROOT->ProcessLine(".L MakeDataCards_C.so");
//MakeDataCards(1500,100,i, "T1tttt");
//MakeDataCards(1200,800,i, "T1tttt");
for(int i=1; i<8; ++i){
MakeDataCards(1500,100,i, "T1tttt");
MakeDataCards(1200,800,i, "T1tttt");
MakeDataCards(1500,100,i, "T1bbbb");
MakeDataCards(1000,900,i, "T1bbbb");
MakeDataCards(1400,100,i, "T1qqqq");
MakeDataCards(1000,800,i, "T1qqqq");
//for(int j=0; j<72; ++j)MakeDataCards(1500,100,5, "T1tttt",true, j);
//for(int j=0; j<72; ++j)MakeDataCards(1200,800,5, "T1tttt",true, j);;
//for(int j=0; j<72; ++j)MakeDataCards(1500,100,i, "T1bbbb",true, j);;
//for(int j=0; j<72; ++j)MakeDataCards(1000,900,i, "T1bbbb",true, j);;
//for(int j=0; j<72; ++j)MakeDataCards(1400,100,i, "T1qqqq",true, j);;
//for(int j=0; j<72; ++j)MakeDataCards(1000,800,i, "T1qqqq",true, j);;
}
}
