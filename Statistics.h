//
// Created by manjaro on 27.01.22.
//

#ifndef STATS_H
#define STATS_H

#include <vector>
#include <string>
#include "console/Style.h"


enum stat { MIN, MAX, AVERAGE };


/**
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


    // ## Vector Methods

      void addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation);

      static double getfromList(stat max_min_avr,std::vector<double> values);

    // ## Console Diagram Methods

      static std::vector<std::string> barGraph(double max_value,std::vector<double> values, Color color);

// Getter

    std::vector<double> get_stats_Accuracy()            {return stats_Accuracy;             }
    std::vector<double> get_stats_Sensitivity()         {return stats_Sensitivity;          }
    std::vector<double> get_stats_Specificity()         {return stats_Specificity;          }
    std::vector<double> get_stats_Precision()           {return stats_Precision;            }
    std::vector<double> get_stats_F1Score()             {return stats_F1Score;              }

    std::vector<double> get_stats_Average1()             {return stats_Average1;            }
    std::vector<double> get_stats_Average2()             {return stats_Average2;            }
    std::vector<double> get_stats_Average3()             {return stats_Average3;            }
    std::vector<double> get_stats_Average4()             {return stats_Average4;            }
    std::vector<double> get_stats_Average5()             {return stats_Average5;            }

    std::vector<double> get_stats_Standard_deviation1()  {return stats_Standard_deviation1; }
    std::vector<double> get_stats_Standard_deviation2()  {return stats_Standard_deviation2; }
    std::vector<double> get_stats_Standard_deviation3()  {return stats_Standard_deviation3; }
    std::vector<double> get_stats_Standard_deviation4()  {return stats_Standard_deviation4; }
    std::vector<double> get_stats_Standard_deviation5()  {return stats_Standard_deviation5; }

private:

  std::vector<double> stats_Accuracy; 
  std::vector<double> stats_Sensitivity; 
  std::vector<double> stats_Specificity; 
  std::vector<double> stats_Precision;
  std::vector<double> stats_F1Score;

  std::vector<double> stats_Average1;
  std::vector<double> stats_Average2;
  std::vector<double> stats_Average3;
  std::vector<double> stats_Average4;
  std::vector<double> stats_Average5;

  std::vector<double> stats_Standard_deviation1;
  std::vector<double> stats_Standard_deviation2;
  std::vector<double> stats_Standard_deviation3;
  std::vector<double> stats_Standard_deviation4;
  std::vector<double> stats_Standard_deviation5;

};


#endif //STATS_H



