#include <iostream>
#include <TH1D.h>
#include <vector> 
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
//auto c1= new TCanvas;
//auto c2= new TCanvas;
//auto c3= new TCanvas;
TCanvas *c1= new TCanvas;
TCanvas *c2= new TCanvas;
TCanvas *c3= new TCanvas;
auto c4= new TCanvas;
auto c5= new TCanvas;

//using namespace std;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector; 
void lhe_analysis_Zpeak ()
{

    TFile* read_lhe =new TFile("lhe.root","read");
    //TFile read_lhe("lhe.root","read");
    TTree* Physics= (TTree*) read_lhe->Get("Physics");
    
    std::vector<int>* PID {};
    std::vector<double>* P_X {};
    std::vector<double>* P_Y {};
    std::vector<LorentzVector >* P4 {};
    std::vector<LorentzVector> P4_char_leptons {};
    //int PID=0;
    //double P_X=0, P_Y=0, P_T=0;
    double P_T=0;
    float M13=0, M23=0;
    
    int no_events = Physics->GetEntries();
    Physics->SetBranchAddress("PID",&PID);
    Physics->SetBranchAddress("P_X",&P_X);
    Physics->SetBranchAddress("P_Y",&P_Y);
    Physics->SetBranchAddress("P4",&P4);
    TH1D* hist=new TH1D("hist","transverse momentum of leptons",180,0,150);
    TH1D* hist_M13=new TH1D("hist_M13","M13",40,0,150);
    TH1D* hist_M23=new TH1D("hist_M23","M23",180,0,150);
    TH1D* hist4=new TH1D("hist4","hist4",180,0,150);
    TH1D* hist5=new TH1D("hist5","hist5",40,0,150);
    for (int i=0; i<no_events; i++)
    {
        Physics->GetEntry(i);
        for(int j=0; j<=6; j++)
        {
            if (TMath::Abs( PID->at(j)) ==11 or TMath::Abs( PID->at(j)) ==13 or TMath::Abs( PID->at(j))==15)
            {
                P4_char_leptons.push_back(P4->at(j));
                P_T= sqrt(pow(P_X->at(j),2)+pow(P_Y->at(j),2));
                hist->Fill(P_T);
            }
        }
        M13=(P4_char_leptons.at(0)+P4_char_leptons.at(2)).M();
        M23=(P4_char_leptons.at(1)+P4_char_leptons.at(2)).M();
        //cout << "sdsd" << M13 << "sdssss" << M23 << endl;
        hist_M13->Fill(M13);
        hist_M23->Fill(M23);
        if (abs(M13-91.18) < abs(M23-91.18))
        {
            hist4->Fill(M13);
        }   
        else
        {   hist4->Fill(M23);
        }    
         
         
         if (abs(M13-91.18) < abs(M23-91.18))
        {
            hist5->Fill(M23);
        }   
        else
        {   hist5->Fill(M13);
        } 
        
        P4_char_leptons.clear();  
    }
    hist->GetYaxis()->SetTitle("N_{Events}");
    hist->GetXaxis()->SetTitle("p_{T} (GeV)");
    c1->cd();
    hist->Draw();
    c1->SaveAs("lhe_analysis_Zpeak.pdf");
    
    c2->cd();
    hist_M13->Draw();
    c2->SaveAs("M13.pdf");
    
    c3->cd();
    hist_M23->Draw();
    c3->SaveAs("M23.pdf");
    
    c4->cd();
    hist4->Draw();
    c4->SaveAs("hist4.pdf");

    c5->cd();
    hist5->Draw();
    c5->SaveAs("hist5.pdf");
    
    
    read_lhe->Write();
    read_lhe->Close();
}
