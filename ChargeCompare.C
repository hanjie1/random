void ChargeCompare(){

     int runN = 3753;
     TString rootpath = "/net/cdaq/cdaql2data/cdaq/hallc-online-nps2023/ROOTfiles/NPS/SCALERS/";
     
     TString filename = rootpath + Form("nps_replay_scalers_%d_1_-1.root",runN);
     TChain *T_hel = new TChain("TSHelH");
     T_hel->Add(filename);

     int nentries = T_hel->GetEntries();

     Double_t helicity,quartet, evNum_hel, BCMCharge_hel;
     T_hel->SetBranchAddress("actualHelicity", &helicity);
     T_hel->SetBranchAddress("quartetPhase", &quartet);
     T_hel->SetBranchAddress("evNumber", &evNum_hel);
     T_hel->SetBranchAddress("H.BCM4A_Hel.scalerCharge", &BCMCharge_hel);
     

     Double_t npos=0, nneg=0;
     Double_t firstEvt=0;
     for(int ii=0; ii<nentries; ii++){
        T_hel->GetEntry(ii);
	if(helicity==0)continue;

	if(firstEvt==0)firstEvt=evNum_hel;

        if(helicity==-1) npos = npos+BCMCharge_hel;
        if(helicity==1) nneg = nneg+BCMCharge_hel;

     }
      
     Double_t Hel_charge = npos+nneg;

     TChain *T = new TChain("TSH");
     T->Add(filename);

     nentries = T->GetEntries();

     Double_t evNum, BCMCharge;
     T->SetBranchAddress("evNumber", &evNum);
     T->SetBranchAddress("H.BCM4A.scalerCharge", &BCMCharge);
     

     Double_t deltaEvt=0;
     Double_t lastNum=0, lastCharge=0;
     for(int ii=0; ii<nentries; ii++){
        T->GetEntry(ii);
	if(evNum<firstEvt){
	   lastNum = evNum;
	   lastCharge = BCMCharge;
	   continue;
	}

	Double_t tmp1 = firstEvt - lastNum;
	Double_t tmp2 = firstEvt - evNum;

	if( abs(tmp1)<=abs(tmp2) ){
           deltaEvt = tmp1;
	}
	else{
           deltaEvt = tmp2;
	   lastCharge = BCMCharge;
	}

        break;
     }

     Double_t finalCharge = T->GetMaximum("H.BCM4A.scalerCharge");
     Double_t TSH_charge = finalCharge - lastCharge;


     cout<<"First good helicity event:               "<<firstEvt<<endl;
     cout<<"First good scaler event:                 "<<firstEvt-deltaEvt<<endl;
     cout<<"Total charge from helicity scaler:       "<<Hel_charge<<endl;
     cout<<"Total charge from helicity scaler*1.03:  "<<Hel_charge*1.03<<endl;
     cout<<"Total charge from normal scaler:         "<<TSH_charge<<endl;
     cout<<"Ratio of the above two:                  "<<TSH_charge/Hel_charge<<endl;
      

}
