void CompareHSEvent(){

     int runN = 3848;
//     TString rootpath = "/net/cdaq/cdaql2data/cdaq/hallc-online-nps2023/ROOTfiles/COIN/PRODUCTION/";
     TString rootpath = "/net/cdaq/cdaql2data/cdaq/hallc-online-nps2023/ROOTfiles/NPS/SCALERS/";

     TString filename = rootpath + Form("nps_replay_scalers_%d_1_-1.root",runN);
     //TString filename = rootpath + Form("nps_replay_scalers_%d_1_50000.root",runN);
     TChain *T = new TChain("TSH");
     T->Add(filename);
      
     int nentries = T->GetEntries();

     // hodo scope 
     Double_t hodo_1x_p[16]={0}, hodo_1y_p[10]={0}, hodo_2x_p[16]={0}, hodo_2y_p[10]={0};
     Double_t hodo_1x_n[16]={0}, hodo_1y_n[10]={0}, hodo_2x_n[16]={0}, hodo_2y_n[10]={0};

     for(int ii=0; ii<16; ii++){
	 TString bname = Form("H.hod.1x%d.posScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_1x_p[ii]);
     }

     for(int ii=0; ii<16; ii++){
	 TString bname = Form("H.hod.1x%d.negScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_1x_n[ii]);
     }

     for(int ii=0; ii<16; ii++){
	 TString bname = Form("H.hod.2x%d.posScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_2x_p[ii]);
     }

     for(int ii=0; ii<16; ii++){
	 TString bname = Form("H.hod.2x%d.negScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_2x_n[ii]);
     }

     for(int ii=0; ii<10; ii++){
	 TString bname = Form("H.hod.1y%d.posScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_1y_p[ii]);
     }

     for(int ii=0; ii<10; ii++){
	 TString bname = Form("H.hod.1y%d.negScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_1y_n[ii]);
     }

     for(int ii=0; ii<10; ii++){
	 TString bname = Form("H.hod.2y%d.posScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_2y_p[ii]);
     }

     for(int ii=0; ii<10; ii++){
	 TString bname = Form("H.hod.2y%d.negScaler",ii+1);
         T->SetBranchAddress(bname,&hodo_2y_n[ii]);
     }

     Double_t S2X,S2Y,S1X,S1Y;
     Double_t S1XS1Y,S2XS2Y;

     T->SetBranchAddress("H.S1X.scaler",&S1X);
     T->SetBranchAddress("H.S1Y.scaler",&S1Y);
     T->SetBranchAddress("H.S1XS1Y.scaler",&S1XS1Y);
     T->SetBranchAddress("H.S2X.scaler",&S2X);
     T->SetBranchAddress("H.S2Y.scaler",&S2Y);
     T->SetBranchAddress("H.S2XS2Y.scaler",&S2XS2Y);

     // Heavy gas cherenkov
     Double_t CER;
     T->SetBranchAddress("H.CER.scaler",&CER);

     // shower and preshower
     Double_t PRHI,PRLO,hPRE40,hPRE100,hPRE150,hPRE200;
     Double_t SHLO, ASUM, BSUM, CSUM, DSUM; 

     T->SetBranchAddress("H.PRHI.scaler",&PRHI);
     T->SetBranchAddress("H.PRLO.scaler",&PRLO);
     T->SetBranchAddress("H.hPRE40.scaler",&hPRE40);
     T->SetBranchAddress("H.hPRE100.scaler",&hPRE100);
     T->SetBranchAddress("H.hPRE150.scaler",&hPRE150);
     T->SetBranchAddress("H.hPRE200.scaler",&hPRE200);
     T->SetBranchAddress("H.SHLO.scaler",&SHLO);
     T->SetBranchAddress("H.ASUM.scaler",&ASUM);
     T->SetBranchAddress("H.BSUM.scaler",&ASUM);
     T->SetBranchAddress("H.CSUM.scaler",&ASUM);
     T->SetBranchAddress("H.DSUM.scaler",&ASUM);

     // triggers
     Double_t hEL_LO_LO,hEL_LO,hEL_HI,hEL_REAL,hEL_CLEAN,hSTOF;
     Double_t hTRIG1,hTRIG2,hTRIG3,hTRIG4,hTRIG5,hTRIG6;

     T->SetBranchAddress("H.hEL_LO_LO.scaler",&hEL_LO_LO);
     T->SetBranchAddress("H.hEL_LO.scaler",&hEL_LO);
     T->SetBranchAddress("H.hEL_HI.scaler",&hEL_HI);
     T->SetBranchAddress("H.hEL_REAL.scaler",&hEL_REAL);
     T->SetBranchAddress("H.hEL_CLEAN.scaler",&hEL_CLEAN);
     T->SetBranchAddress("H.hSTOF.scaler",&hSTOF);
     T->SetBranchAddress("H.hTRIG1.scaler",&hTRIG1);
     T->SetBranchAddress("H.hTRIG2.scaler",&hTRIG2);
     T->SetBranchAddress("H.hTRIG3.scaler",&hTRIG3);
     T->SetBranchAddress("H.hTRIG4.scaler",&hTRIG4);
     T->SetBranchAddress("H.hTRIG5.scaler",&hTRIG5);
     T->SetBranchAddress("H.hTRIG6.scaler",&hTRIG6);

     // BCM
     Double_t BCM1,BCM2,BCM4A,BCM4B,BCM4C,Unser;
     T->SetBranchAddress("H.BCM1.scaler",&BCM1);
     T->SetBranchAddress("H.BCM2.scaler",&BCM2);
     T->SetBranchAddress("H.BCM4A.scaler",&BCM4A);
     T->SetBranchAddress("H.BCM4B.scaler",&BCM4B);
     T->SetBranchAddress("H.BCM4C.scaler",&BCM4C);
     T->SetBranchAddress("H.Unser.scaler",&Unser);

     // others reference
     Double_t hL1ACCP,EDTM,c1MHz,c1MHz_CP,EDTM_CP,hTREF1;
     T->SetBranchAddress("H.hL1ACCP.scaler",&hL1ACCP);
     T->SetBranchAddress("H.EDTM.scaler",&EDTM);
     T->SetBranchAddress("H.EDTM_CP.scaler",&EDTM_CP);
     T->SetBranchAddress("H.1MHz.scaler",&c1MHz);
     T->SetBranchAddress("H.1MHz_CP.scaler",&c1MHz_CP);
     T->SetBranchAddress("H.hTREF1.scaler",&hTREF1);

     Double_t pre_hodo_1x_p[16]={0}, pre_hodo_1y_p[10]={0}, pre_hodo_2x_p[16]={0}, pre_hodo_2y_p[10]={0};
     Double_t pre_hodo_1x_n[16]={0}, pre_hodo_1y_n[10]={0}, pre_hodo_2x_n[16]={0}, pre_hodo_2y_n[10]={0};
     Double_t pre_S2X,pre_S2Y,pre_S1X,pre_S1Y;
     Double_t pre_S1XS1Y,pre_S2XS2Y;
     Double_t pre_CER;
     Double_t pre_PRHI,pre_PRLO,pre_hPRE40,pre_hPRE100,pre_hPRE150,pre_hPRE200;
     Double_t pre_SHLO, pre_ASUM, pre_BSUM, pre_CSUM, pre_DSUM; 
     Double_t pre_hEL_LO_LO,pre_hEL_LO,pre_hEL_HI,pre_hEL_REAL,pre_hEL_CLEAN,pre_hSTOF;
     Double_t pre_hTRIG1,pre_hTRIG2,pre_hTRIG3,pre_hTRIG4,pre_hTRIG5,pre_hTRIG6;
     Double_t pre_BCM1,pre_BCM2,pre_BCM4A,pre_BCM4B,pre_BCM4C,pre_Unser;
     Double_t pre_hL1ACCP,pre_EDTM,pre_c1MHz,pre_c1MHz_CP,pre_EDTM_CP,pre_hTREF1;

     Double_t DIFF=pow(2,31);

     for(int ii=0; ii<(nentries-1); ii++){
         T->GetEntry(ii);

         double delta = -1;
	 if(ii>0){

            delta = c1MHz - pre_c1MHz;
	    Double_t delta_clock = delta;
	    if(delta<10 || delta>DIFF){
	       printf("Event %d: 1MHz diff=%f\n",ii,delta);
	    }

               for(int jj=0; jj<16; jj++){
                   delta = hodo_1x_p[jj] - pre_hodo_1x_p[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 1x %d pos diff=%f\n",ii,jj,delta);
                   delta = hodo_2x_p[jj] - pre_hodo_2x_p[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 2x %d pos diff=%f\n",ii,jj,delta);

                   delta = hodo_1x_n[jj] - pre_hodo_1x_n[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 1x %d neg diff=%f\n",ii,jj,delta);
                   delta = hodo_2x_n[jj] - pre_hodo_2x_n[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 2x %d neg diff=%f\n",ii,jj,delta);
	       }

               for(int jj=0; jj<10; jj++){
                   delta = hodo_1y_p[jj] - pre_hodo_1y_p[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 1y %d pos diff=%f\n",ii,jj,delta);
                   delta = hodo_2y_p[jj] - pre_hodo_2y_p[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 2y %d pos diff=%f\n",ii,jj,delta);

                   delta = hodo_1y_n[jj] - pre_hodo_1y_n[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 1y %d neg diff=%f\n",ii,jj,delta);
                   delta = hodo_2y_n[jj] - pre_hodo_2y_n[jj];
	           if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hodo 2y %d neg diff=%f\n",ii,jj,delta);
	       }

               delta = S2X - pre_S2X;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S2X diff=%f\n",ii,delta);
               delta = S2Y - pre_S2Y;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S2Y diff=%f\n",ii,delta);

               delta = S1X - pre_S1X;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S1X diff=%f\n",ii,delta);
               delta = S1Y - pre_S1Y;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S1Y diff=%f\n",ii,delta);

               delta = S1XS1Y - pre_S1XS1Y;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S1XS1Y diff=%f\n",ii,delta);
                
               delta = S2XS2Y - pre_S2XS2Y;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: S2XS2Y diff=%f\n",ii,delta);

               delta = CER - pre_CER;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: CER diff=%f\n",ii,delta);

               delta = PRHI - pre_PRHI;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: PRHI diff=%f\n",ii,delta);
               delta = PRLO - pre_PRLO;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: PRLO diff=%f\n",ii,delta);
               delta = hPRE40 - pre_hPRE40;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hPRE40 diff=%f\n",ii,delta);
               delta = hPRE100 - pre_hPRE100;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hPRE100 diff=%f\n",ii,delta);
               delta = hPRE150 - pre_hPRE150;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hPRE150 diff=%f\n",ii,delta);
               delta = hPRE200 - pre_hPRE200;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hPRE200 diff=%f\n",ii,delta);

               delta = SHLO - pre_SHLO;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: SHLO diff=%f\n",ii,delta);
               delta = ASUM - pre_ASUM;
	       /*
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: ASUM diff=%f\n",ii,delta);
               delta = BSUM - pre_BSUM;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BSUM diff=%f\n",ii,delta);
               delta = CSUM - pre_CSUM;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: CSUM diff=%f\n",ii,delta);
               delta = DSUM - pre_DSUM;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: DSUM diff=%f\n",ii,delta);
*/
               delta = hEL_LO_LO - pre_hEL_LO_LO;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hEL_LO_LO diff=%f\n",ii,delta);
               delta = hEL_LO - pre_hEL_LO;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hEL_LO diff=%f\n",ii,delta);
               delta = hEL_HI - pre_hEL_HI;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hEL_HI diff=%f\n",ii,delta);
               delta = hEL_REAL - pre_hEL_REAL;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hEL_REAL diff=%f\n",ii,delta);
               delta = hEL_CLEAN - pre_hEL_CLEAN;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hEL_CLEAN diff=%f\n",ii,delta);
               delta = hSTOF - pre_hSTOF;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hSTOF diff=%f\n",ii,delta);

               delta = hTRIG1 - pre_hTRIG1;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG1 diff=%f\n",ii,delta);
/*	       
               delta = hTRIG2 - pre_hTRIG2;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG2 diff=%f\n",ii,delta);
*/

               delta = hTRIG3 - pre_hTRIG3;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG3 diff=%f\n",ii,delta);
               delta = hTRIG4 - pre_hTRIG4;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG4 diff=%f\n",ii,delta);
               delta = hTRIG5 - pre_hTRIG5;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG5 diff=%f\n",ii,delta);
               delta = hTRIG6 - pre_hTRIG6;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTRIG6 diff=%f\n",ii,delta);

               delta = BCM1 - pre_BCM1;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BCM1 diff=%f\n",ii,delta);
               delta = BCM2 - pre_BCM2;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BCM2 diff=%f\n",ii,delta);
               delta = BCM4A - pre_BCM4A;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BCM4A diff=%f\n",ii,delta);
               delta = BCM4B - pre_BCM4B;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BCM4B diff=%f\n",ii,delta);
               delta = BCM4C - pre_BCM4C;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: BCM4C diff=%f\n",ii,delta);
               delta = Unser - pre_Unser;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: Unser diff=%f\n",ii,delta);

               delta = hL1ACCP - pre_hL1ACCP;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hL1ACCP diff=%f\n",ii,delta);
               delta = EDTM - pre_EDTM;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: EDTM diff=%f\n",ii,delta);
               delta = c1MHz_CP - pre_c1MHz_CP;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: 1MHz_CP diff=%f\n",ii,delta);
               delta = EDTM_CP - pre_EDTM_CP;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: EDTM_CP diff=%f\n",ii,delta);
               delta = hTREF1 - pre_hTREF1;
	       if(delta==0 || delta_clock==0 || delta>DIFF) printf("Event %d: hTREF1 diff=%f\n",ii,delta);
//	    }
	 }

         for(int jj=0; jj<16; jj++){
             pre_hodo_1x_p[jj] = hodo_1x_p[jj];
             pre_hodo_1x_n[jj] = hodo_1x_n[jj];

             pre_hodo_2x_p[jj] = hodo_2x_p[jj];
             pre_hodo_2x_n[jj] = hodo_2x_n[jj];
	 }

         for(int jj=0; jj<10; jj++){
             pre_hodo_1y_p[jj] = hodo_1y_p[jj];
             pre_hodo_1y_n[jj] = hodo_1y_n[jj];

             pre_hodo_2y_p[jj] = hodo_2y_p[jj];
             pre_hodo_2y_n[jj] = hodo_2y_n[jj];
	 }

         pre_S2X = S2X;
	 pre_S2Y = S2Y;

         pre_S1X = S1X;
	 pre_S1Y = S1Y;

         pre_S1XS1Y = S1XS1Y;
         pre_S2XS2Y = S2XS2Y;

         pre_CER = CER;
     
         pre_PRHI = PRHI;
         pre_PRLO = PRLO;
         pre_hPRE40 = hPRE40;
         pre_hPRE100 = hPRE100;
         pre_hPRE150 = hPRE150;
         pre_hPRE200 = hPRE200;

         pre_SHLO = SHLO;
         pre_ASUM = ASUM;
         pre_BSUM = BSUM;
         pre_CSUM = CSUM;
         pre_DSUM = DSUM;

         pre_hEL_LO = hEL_LO;
         pre_hEL_LO_LO = hEL_LO_LO;
         pre_hEL_HI = hEL_HI;
         pre_hEL_REAL = hEL_REAL;
         pre_hEL_CLEAN = hEL_CLEAN;
         pre_hSTOF = hSTOF;

         pre_hTRIG1 = hTRIG1;
         pre_hTRIG2 = hTRIG2;
         pre_hTRIG3 = hTRIG3;
         pre_hTRIG4 = hTRIG4;
         pre_hTRIG5 = hTRIG5;
         pre_hTRIG6 = hTRIG6;

         pre_BCM1 = BCM1;
         pre_BCM2 = BCM2;
         pre_BCM4A = BCM4A;
         pre_BCM4B = BCM4B;
         pre_BCM4C = BCM4C;
         pre_Unser = Unser;

         pre_hL1ACCP = hL1ACCP;
         pre_EDTM_CP = EDTM_CP;
         pre_EDTM = EDTM;
         pre_c1MHz = c1MHz;
         pre_c1MHz_CP = c1MHz_CP;
         pre_hTREF1 = hTREF1;

     }

}
