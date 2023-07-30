#include <iostream>
#include <TH1D.h>
#include <vector> 
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
auto c= new TCanvas;
//using namespace std;
//typedef 
void lhe_analysis1 ()
{

    TFile* read_lhe =new TFile("lhe.root","read");
    //TFile read_lhe("lhe.root","read");
    TTree* Physics= (TTree*) read_lhe->Get("Physics");
    
    std::vector<int>* PID {};
    std::vector<double>* P_X {};
    std::vector<double>* P_Y {};
    //int PID=0;
    //double P_X=0, P_Y=0, P_T=0;
    double P_T=0;
    
    int no_events = Physics->GetEntries();
    Physics->SetBranchAddress("PID",&PID);
    Physics->SetBranchAddress("P_X",&P_X);
    Physics->SetBranchAddress("P_Y",&P_Y);
    TH1D* hist=new TH1D("hist","transverse momentum of leptons",180,0,150);
    for (int i=0; i<no_events; i++)
    {
        Physics->GetEntry(i);
        for(int j=0; j<=6; j++)
        {
            if (TMath::Abs( PID->at(j)) ==11 or TMath::Abs( PID->at(j)) ==13 or TMath::Abs( PID->at(j))==15)
            {
                P_T= sqrt(pow(P_X->at(j),2)+pow(P_Y->at(j),2));
                hist->Fill(P_T);
            }
        }
    }
    hist->GetYaxis()->SetTitle("N_{Events}");
    hist->GetXaxis()->SetTitle("p_{T} (GeV)");
    hist->Draw();
    c->SaveAs("lhe_charged_leptons.pdf");
    read_lhe->Write();
    read_lhe->Close();
}
