//
// Created by manjaro on 27.01.22.
//

#ifndef STATS_H
#define STATS_H

#include <vector>
#include <string>
#include "console/Style.h"


enum stat { MIN, MAX, AVERAGE };


/** The X-Vector ( SNP )
 *
 *
 * */
class Statistics{

public:

    // ## Formulas

    static double Accuracy(double TP, double TN, double FP, double FN);
    static double Sensitivity(double TN, double FP);
    static double Specificity(double TP, double FN);
    static double Precision(double TP, double FP);
    static double F1Score(double precision, double sensivity);
    static double Average(std::vector<double> list);
    static double Standard_deviation(std::vector<double> Xi,std::vector<double> pXi);

    void addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation);

    static double getfromList(stat max_min_avr,std::vector<double> values);


    static std::vector<std::string> barGraph(double max_value,std::vector<double> values, Color color);

    // ## Getter

     std::vector<double> get_stats_Accuracy();
     std::vector<double> get_stats_Sensitivity();
     std::vector<double> get_stats_Specificity();
     std::vector<double> get_stats_Precision();
     std::vector<double> get_stats_F1Score();
     std::vector<double> get_stats_Average();
     std::vector<double> get_stats_Standard_deviation();

private:

  std::vector<double> stats_Accuracy; 
  std::vector<double> stats_Sensitivity; 
  std::vector<double> stats_Specificity; 
  std::vector<double> stats_Precision;
  std::vector<double> stats_F1Score;
  std::vector<double> stats_Average;
  std::vector<double> stats_Standard_deviation;

};


#endif //STATS_H



