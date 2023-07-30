#include <iostream>
#include <TH1D.h>
#include <vector> 
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>

//using namespace std;
//typedef 
using std::cout;
using std::endl;
void lhe_analysis ()
{

    TFile* read_lhe =new TFile("lhe.root","read");
    //TFile read_lhe("lhe.root","read");
    TTree* Physics= (TTree*) read_lhe->Get("Physics");
    auto c= new TCanvas;
    
    std::vector<int>* PID {};
    std::vector<double>* P_X {};
    std::vector<double>* P_Y {};
    //int PID=0;
    //double P_X=0, P_Y=0, P_T=0;
    double P_T=0;
    int count_leptons=0;
    int count_loop=0;
    std::vector<double> ss {};
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
            count_loop++;
            if (TMath::Abs( PID->at(j)) <=18 and TMath::Abs( PID->at(j)) >=11)
            {
                P_T= sqrt(pow(P_X->at(j),2)+pow(P_Y->at(j),2));
                ss.push_back(P_T);
                hist->Fill(P_T);
                //P_T=0;
                count_leptons++;
                cout <<"i is: "<< i << "j is :"<< j<< "P_T is" << P_T << endl;
            }
        }
    }
    hist->Draw();
    cout <<"no of leptons:" <<count_leptons << endl;
    cout <<"no of loops:" <<count_loop << endl;
    
    c->SaveAs("lhe2.pdf");
    for (double x: ss)
    { 
       // cout << " " << x << endl;
       
    }
    cout << "length is:" << ss.size() << endl;
    read_lhe->Write();
    read_lhe->Close();
}
