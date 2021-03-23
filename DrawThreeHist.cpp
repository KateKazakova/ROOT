
#include <bitset>
#include <iostream>
#include <cmath>

#include "TLine.h"
#include "TLatex.h"
#include "TMarker.h"
#include "TPave.h"
#include "TH1.h"
#include "TString.h"
#include <vector>
#include "AtlasUtils.C"
#include "AtlasLabels.C"
#include "AtlasStyle.C"

  /// write a script, that will be draw two histogram same (one on other),
  /// and draw the ratio plot, that will be show the result of dividing process
  /// notice. that task is write a function
  /// for using this script in any other tasks


  TH1F *DrawRatioPlot(TString TitleY, TH1F* hist1, TH1F* hist2, TH1F* hist3, float setRangeA_Y = 0.51, float setRangeB_Y = 1.21, float setRangeA_X = 0., float setRangeB_X = 0.){
                                /// setRangeA_X and setRangeB_X it is a boundaries of ratio plot
                                /// it may not equal to boundaries of main hist, it is reason why we use if(setRangeA_X!=setRangeB_X) and if(setRangeA_X==setRangeB_X)

      if(!hist1) {
        cout<<"Something wrong with you histogram!"<<endl;
        exit(1);
      }
      if(!hist2) {
        cout<<"Something wrong with you histogram!"<<endl;
        exit(1);
      }

      TH1F* h_ratio = (TH1F*)hist2->Clone("Clone1");
      h_ratio->Divide(hist3, hist2);

      float rel_uncert_from_2histo, rel_uncert_from_3histo, rel_uncert_overall;

      int nBins = 0;
      nBins = h_ratio->GetNbinsX();  /// method GetNBinsX() provides get  number of bins in histogram

      for(int i = 1; i<=nBins; i++){

        rel_uncert_from_2histo = (hist2->GetBinContent(i) == 0) ? 0.: hist2->GetBinError(i)/hist2->GetBinContent(i);
        rel_uncert_from_3histo = (hist3->GetBinContent(i) == 0) ? 0.: hist3->GetBinError(i)/hist3->GetBinContent(i);
        rel_uncert_overall = sqrt(pow(rel_uncert_from_2histo,2)+pow(rel_uncert_from_3histo,2));
        h_ratio->SetBinError(i,rel_uncert_overall*h_ratio->GetBinContent(i));

      }

      h_ratio->GetXaxis()->SetTitle(hist1->GetXaxis()->GetTitle());  /// put Xtitle of hist1 to the XTitle h_ratio
      h_ratio->GetYaxis()->SetTitle(TitleY.Data());

      h_ratio->GetXaxis()->SetLabelSize(0.15);
      h_ratio->GetYaxis()->SetLabelSize(0.15);  /// set the size of the font ( <0.15 smaller, >0.15 bigger)

      h_ratio->GetYaxis()->SetTitleOffset(0.4);
      h_ratio->GetXaxis()->SetTitleOffset(1);    /// distinction between text (new/old bla bla) and axis
                                                 /// more - bigger distin-on, less - smaller dis-on

      h_ratio->GetXaxis()->SetTitleSize(0.15);
      h_ratio->GetYaxis()->SetTitleSize(0.15);    /// the size of the text around the ration plot
                                                  /// more - bigger, less

      h_ratio->GetXaxis()->SetTickLength(0.15);   /// the length of the hatches, that have perpendicular position in ratio plot
      h_ratio->GetYaxis()->SetTickLength(0);

      h_ratio->SetMarkerSize(1.5);
      h_ratio->SetMarkerColor(kBlack);
      h_ratio->SetMarkerStyle(43);
      h_ratio->SetLineColor(kBlack);
      h_ratio->SetLineWidth(0);



      h_ratio->GetYaxis()->SetRangeUser(setRangeA_Y,setRangeB_Y); /// setting the range of Y axis in ration plot

      if(setRangeA_X!=setRangeB_X) {

          h_ratio->GetXaxis()->SetRangeUser(setRangeA_X,setRangeB_X);
           /// setting boundaries of ration plot
          h_ratio->Draw("E");
      }


      if (setRangeA_X==setRangeB_X){
            float minX, maxX;
            minX = h_ratio->GetXaxis()->GetXmin();
            maxX = h_ratio->GetXaxis()->GetXmax();
            TLine *l = new TLine(minX, 1., maxX, 1.); /// setting the main line on ratio plot from minX from maxX, min and max range, 1.0 in is angle of line (horizontal)
            TLine *l1 = new TLine(minX, 0.7, maxX, 0.7);
            TLine *l2 = new TLine(minX, 0.8, maxX, 0.8);
            TLine *l3 = new TLine(minX, 0.9, maxX, 0.9);
            TLine *l4 = new TLine(minX, 1.1, maxX, 1.1);
            TLine *l5 = new TLine(minX, 1.2, maxX, 1.2);
            TLine *l6 = new TLine(minX, 0.6, maxX, 0.6);
            l->SetLineColor(kBlack);
            l->SetLineStyle(9);    /// breaking line
            l->SetLineWidth(2);
            l1->SetLineStyle(3);
            l1->SetLineWidth(2);
            l2->SetLineStyle(3);
            l2->SetLineWidth(2);
            l3->SetLineStyle(3);
            l3->SetLineWidth(2);
            l4->SetLineStyle(3);
            l4->SetLineWidth(2);
            l5->SetLineStyle(3);
            l5->SetLineWidth(2);
            l6->SetLineStyle(3);
            l6->SetLineWidth(2);
            h_ratio->Draw("E");
            l->Draw();
            l1->Draw();
            l2->Draw();
            l3->Draw();
            l4->Draw();
            l5->Draw();
            l6->Draw();
      } else{
            float minX, maxX;
            minX = h_ratio->GetXaxis()->GetXmin();
            maxX = h_ratio->GetXaxis()->GetXmax();
            TLine *l = new TLine(minX, 1., maxX, 1.);
             TLine *l1 = new TLine(minX, 0.7, maxX, 0.7);
            TLine *l2 = new TLine(minX, 0.8, maxX, 0.8);
            TLine *l3 = new TLine(minX, 0.9, maxX, 0.9);
            TLine *l4 = new TLine(minX, 1.1, maxX, 1.1);
            TLine *l5 = new TLine(minX, 1.2, maxX, 1.2);
            TLine *l6 = new TLine(minX, 0.6, maxX, 0.6);
            l1->SetLineStyle(3);
            l1->SetLineWidth(2);
            l2->SetLineStyle(3);
            l2->SetLineWidth(2);
            l3->SetLineStyle(3);
            l3->SetLineWidth(2);
            l4->SetLineStyle(3);
            l4->SetLineWidth(2);
            l5->SetLineStyle(3);
            l5->SetLineWidth(2);
            l6->SetLineStyle(3);
            l6->SetLineWidth(2);
            l->SetLineColor(kBlack);
            l->SetLineStyle(9);
            l->SetLineWidth(2);
            h_ratio->Draw("E");
            l->Draw();
            l1->Draw();
            l2->Draw();
            l3->Draw();
            l4->Draw();
            l5->Draw();
            l6->Draw();
      }

      return h_ratio;

  }


  TH1F *DrawThreeHist(TString name, TString band1, TString band2,TString band3, TH1F *hist1, TH1F *hist2,
                      TH1F *hist3, TString TitleX, TString TitleY, bool DrawPlot = false, bool SetNormalization = false, TString TitleY_sub = "ratio"){

      if(!hist1) {
        cout<<"Something wrong with you histogram!"<<endl;
        exit(1);
      }
      if(!hist2) {
        cout<<"Something wrong with you histogram!"<<endl;
        exit(1);
      }
      if(!hist3) {
        cout<<"Something wrong with you histogram!"<<endl;
        exit(1);
      }

      /// the size of the main canvas (ration + hist)
      TCanvas *c01 = new TCanvas(name.Data(), name.Data(), 147, 22, 800, 600);
      /// the size of the hist plot
      TPad *c1 = new TPad("c1", "c1",0.007905138,0.2347107,0.9891304,0.9950413);
      /// the size of the ratio plot
      TPad *c2 = new TPad("c2", "c2",0.008814887,0.006589786,0.9892262,0.2652389);

      float minx = hist1->GetXaxis()->GetXmin();
      float maxX = hist1->GetXaxis()->GetXmax();
      float minY = hist1->GetYaxis()->GetXmin();
      float maxY = hist1->GetYaxis()->GetXmax();

      if (DrawPlot){
        c1->Draw();
        c1->cd();
        ///set the size of the hist plot
        c1->SetLeftMargin(0.1596366);
        c1->SetRightMargin(0.05080911);
        c1->SetTopMargin(0.04981374);
        c1->SetBottomMargin(0.0448469);
      }

       /// set parameters of the histograms (color, width ...)
      hist1->SetMarkerSize(0.);
      hist1->SetMarkerColor(1);
      hist1->SetFillColor(kSpring);
      hist2->SetLineWidth(0.);
      hist1->SetLineColor(kSpring);
      hist2->SetMarkerColor(kRed);
      hist2->SetFillColor(kAzure);
      hist2->SetMarkerSize(0.);
      hist3->SetMarkerSize(1.5);
      hist3->SetMarkerColor(1);
      hist3->SetMarkerStyle(43);

      if(SetNormalization){
      float integral1 = hist1->Integral();
      float integral2 = hist2->Integral();
      float integral3 = hist3->Integral();
      hist1->Scale(1./integral1);
      hist2->Scale(1./integral2);
      hist3->Scale(1./integral3);
      }

      hist1->Sumw2();
      hist2->Sumw2();
      hist3->Sumw2();

      hist1->GetXaxis()->SetTitle(TitleX.Data());
      hist1->GetYaxis()->SetTitle(TitleY.Data());
      hist2->GetXaxis()->SetTitle(TitleX.Data());
      hist2->GetYaxis()->SetTitle(TitleY.Data());
      hist3->GetXaxis()->SetTitle(TitleX.Data());
      hist3->GetYaxis()->SetTitle(TitleY.Data());

      hist1->Draw("HIST");
      hist2->Draw("HISTsame");
      hist3->Draw("Same");

       /// setting the legend
      TLegend *leg = new TLegend(0.1729323,0.8330435,0.2230576,0.8678261);
      leg->SetShadowColor(10);
      leg->SetBorderSize(0);    /// without borders
      leg->SetTextSize(0.052);
      leg->SetFillStyle(1001);
      leg->SetFillColor(10);   /// white color
      leg->AddEntry(hist1,"#sqrt{s}=13 TeV, 43.6 fb^{-1}","");
      leg->Draw();

      TLegend *leg2 = new TLegend(0.1729323,0.6330435,0.2230576,0.8678261);
      leg2->SetShadowColor(10);
      leg2->SetBorderSize(0);    /// without borders
      leg2->SetTextSize(0.052);
      leg2->SetFillStyle(1001);
      leg2->SetTextFont(42);
      leg2->SetFillColor(10);   /// white color
      leg2->AddEntry(hist1,"Higt p_{T} ee","");
      leg2->Draw();

      TLegend *leg1 = new TLegend(0.7042607,0.6578261,0.839599,0.8330435);
      leg1->SetShadowColor(10);
      leg1->SetBorderSize(0);
      leg1->SetTextSize(0.05217391);
      leg1->SetFillStyle(1002);
      leg1->SetFillColor(10);
      ATLASLabel(0.19,0.90,"Internal");
      //leg1->AddEntry(hist1, Form("%s", band1.Data()),"f");
      //leg1->AddEntry(hist2, Form("%s", band2.Data()),"f");
      //leg1->AddEntry(hist3, Form("%s", band3.Data()),"lp");
      leg1->Draw();


      TLegend *leg4 = new TLegend(0.7042607,0.6578261,0.839599,0.8330435);
      leg4->SetShadowColor(10);
      leg4->SetBorderSize(0);
      leg4->SetTextSize(0.05217391);
      leg4->SetFillStyle(1002);
      leg4->SetFillColor(10);
      leg4->SetTextFont(42);
      leg4->AddEntry(hist1, Form("%s", band1.Data()),"f");
      leg4->AddEntry(hist2, Form("%s", band2.Data()),"f");
      leg4->AddEntry(hist3, Form("%s", band3.Data()),"lp");
      leg4->Draw();




      if (DrawPlot){
        c1->Modified();
        c01->cd();
        c2->Draw();
        c2->cd();
        c2->Range(-18.10151,-1.965632,32.61929,2.637034);
        c2->SetLeftMargin(0.1597275);
        c2->SetRightMargin(0.05164129);
        c2->SetTopMargin(0.0437885);
        c2->SetBottomMargin(0.3645084);

        DrawRatioPlot(TitleY_sub.Data(), hist1, hist2, hist3, -0.1, 2.1);
      }

      c01->SaveAs(Form("%s.pdf", name.Data()));
      return hist1;


 }



