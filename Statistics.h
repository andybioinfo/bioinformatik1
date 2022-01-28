//
// Created by manjaro on 27.01.22.
//

#ifndef STATS_H
#define STATS_H

#include <vector>
#include "States.h"
#include "Classifics.h"



enum stat { MIN, MAX, AVERAGE };


/** The X-Vector ( SNP )
 *
 *
 * */
class Statistics {

public:

    // ## Formulas

    static double Accuracy(); 
    static double Sensitivity(); 
    static double Specificity(); 
    static double Precision();
    static double F1Score();
    static double Average();
    static double Standard_deviation();

    void addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation);

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



  std::vector<double> Statistics::get_stats_Accuracy()            {return stats_Accuracy;             } 
  std::vector<double> Statistics::get_stats_Sensitivity()         {return stats_Sensitivity;          }  
  std::vector<double> Statistics::get_stats_Specificity()         {return stats_Specificity;          }  
  std::vector<double> Statistics::get_stats_Precision()           {return stats_Precision;            } 
  std::vector<double> Statistics::get_stats_F1Score()             {return stats_F1Score;              } 
  std::vector<double> Statistics::get_stats_Average()             {return stats_Average;              } 
  std::vector<double> Statistics::get_stats_Standard_deviation()  {return stats_Standard_deviation;   } 

    


/** Add a Set of Stats
 * 
 * */
addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation) {

  stats_Accuracy.push_back(accuracy); 
  stats_Sensitivity.push_back(sensitivity); 
  stats_Specificity.push_back(specificity); 
  stats_Precision.push_back(precision);
  stats_F1Score.push_back(f1Score);
  stats_Average.push_back(average);
  stats_Standard_deviation.push_back(standard_deviation);

}


/** Compute Accuracy
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Statistics::Accuracy(double TP, double TN, double FP, double FN) {
    return (TP + TN) / (TP + TN + FP + FN);
    }


/** Compute Specificity
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Statistics::Specificity(double TN, double FP) {
    return (TN) / (TN + FP);
    };  


/** Compute Sensitivity
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Statistics::Sensitivity(double TP, double FN) {
    return (TP) / (TP + FN);
    }; 


/** Compute Precision
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Statistics::Precision(double TP, double FP) {
    return (TP) / (TP + FP);
    }; 


/** Compute F1Score
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Statistics::F1Score(double precision, double sensivity) {
    return 2 * ( (precision * sensivity) / (precision + sensivity) );
    }; 


/** Compute Average
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Average(std::vector<double> list) { 
        double res = 0.0;
        for (double val : list) { res += val; }
        return res / list.size();
    };


/** Compute Standard_deviation
 * 
 * @all     :::
 * @return  H(X)  
 * */
    static double Standard_deviation(std::vector<double> Xi,std::vector<double> pXi) {
        int count = list.size();
        double E_Xi = 0.0;
        double E_Xi2 = 0.0;

        // Calculation E[Xi]
        for (int i = 0 ; i < count ; i++) { E_Xi += Xi[i] * pXi[i]; }

        // Calculation E[Xi²]
        for (int i = 0 ; i < count ; i++) { E_Xi2 += pow(Xi[i],2) * pXi[i]; }

        // Calculation Var_Xi
        double Var_Xi = E_Xi2 - pow(E_Xi,2);

        // Calculation sigma
        double devi = sqrt(Var_Xi);

        return devi;

    }


/** Returns the average, min or max from a vector
 *
 *
 * */
double getfromList(stat max_min_avr,std::vector<double> values) {
    double res = values[0];
    switch (max_min_avr)
    {
    case MAX     : for (double val : values) { if (val > max) {max = val;} } break;
    case MIN     : for (double val : values) { if (val < min) {min = val;} } break;
    case AVERAGE : res = 0.0; for (double val : values) { avr += val; } avr = avr / values.size(); break;
    default: break;
    }
    return res;
}



/** Creates a single graph bar for diagrams from all values with min max and
 *  average ( for console output )
 *
 * */
std::vector<std::string> barGraph(double max_value,std::vector<double> values, Color color) {

    double min = getfromList(MIN,values);
    double max = getfromList(MAX,values);
    double avr = getfromList(AVERAGE,values);

    std::stringstream min_bar("");
    
    std::vector<std::string> res;

    for (int i = 1 ; i <= 10 ; i ++ ) { // first value in vector is 5%

          std::stringstream bar("");
          double buf = 0.0;
          double percent = i * 5;

          // is min
          if (min > percent - 5.0 && min < percent ) { 
                 buf = min - (i-1) * 5;
                 if (buf <  2.00) {min_bar << "__";}
                 if (buf >= 2.00) {min_bar << "--";}
               }

          // is max
          if (max >= percent - 5.0 )   {  bar << S::setStyle(color,Bold,White,min_bar.str());
                                } else {  bar << S::setStyle(color,Bold,White,"  "); 
                                }

          res.push_back(bar.str());

    }
    return res;

}




#endif //STATS_H



