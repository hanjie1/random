void CheckScaler(){
     int startNo =3844;
     int endNo = 3851;
     TString rootpath = "/net/cdaq/cdaql2data/cdaq/hallc-online-nps2023/ROOTfiles/COIN/PRODUCTION/";

     TGraph *gT_event0 = new TGraph();
     TGraph *gEDTM_event0 = new TGraph();
     TGraph *gev_event0 = new TGraph();

     int nrun=0;
     for(int ii=startNo; ii<=endNo; ii++){
         TString filename = rootpath + Form("nps_hms_coin_%d_0_*.root",ii);
         TChain *T = new TChain("T");
	 T->Add(filename);
	  
	 int nentries = T->GetEntries();
	 if(nentries==0) continue;

         T->SetBranchStatus("*",false);
         T->SetBranchStatus("g.evtime",true);
         T->SetBranchStatus("H.1MHz.scaler",true);
         T->SetBranchStatus("H.EDTM.scaler",true);

	 Double_t evtime, clock, edtm;
	 T->SetBranchAddress("g.evtime",&evtime);
	 T->SetBranchAddress("H.1MHz.scaler",&clock);
	 T->SetBranchAddress("H.EDTM.scaler",&edtm);

         T->GetEntry(0);
	 cout<<ii<<"  "<<evtime/250/1e6<<"  "<<clock/1e6<<"  "<<edtm/40<<endl;
	 gT_event0->SetPoint(nrun,ii,clock/1e6);
	 gEDTM_event0->SetPoint(nrun,ii,edtm/40);
	 gev_event0->SetPoint(nrun,ii,evtime/250/1e6);
	 nrun++;

	 delete T;
     }

     TCanvas *c1 = new TCanvas("c1");
     c1->Divide(3,1);
     c1->cd(1);
     gT_event0->SetMarkerStyle(8);
     gT_event0->Draw("AP");
     gT_event0->SetTitle("event 0 clock(s) vs. run number;runNo;1MHz clock (s)");

     c1->cd(2);
     gEDTM_event0->SetMarkerStyle(8);
     gEDTM_event0->Draw("AP");
     gEDTM_event0->SetTitle("event 0 EDTM(s) vs. run number;runNo;EDTM (s)");

     c1->cd(3);
     gev_event0->SetMarkerStyle(8);
     gev_event0->Draw("AP");
     gev_event0->SetTitle("event 0 CODA evtime vs. run number;runNo;evtime (s)");


}
