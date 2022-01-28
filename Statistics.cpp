//
// Created by manjaro on 28.01.22.
//




#include <valarray>
#include <sstream>
#include "Statistics.h"

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
void Statistics::addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation) {

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
 double Statistics::Accuracy(double TP, double TN, double FP, double FN) {
    return (TP + TN) / (TP + TN + FP + FN);
}


/** Compute Specificity
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::Specificity(double TN, double FP) {
    return (TN) / (TN + FP);
};


/** Compute Sensitivity
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::Sensitivity(double TP, double FN) {
    return (TP) / (TP + FN);
};


/** Compute Precision
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::Precision(double TP, double FP) {
    return (TP) / (TP + FP);
};


/** Compute F1Score
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::F1Score(double precision, double sensivity) {
    return 2 * ( (precision * sensivity) / (precision + sensivity) );
};


/** Compute Average
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::Average(std::vector<double> list) {
    double res = 0.0;
    for (double val : list) { res += val; }
    return res / list.size();
};


/** Compute Standard_deviation
 *
 * @all     :::
 * @return  H(X)
 * */
 double Statistics::Standard_deviation(std::vector<double> Xi,std::vector<double> pXi) {
    int count = Xi.size();
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
double Statistics::getfromList(stat max_min_avr,std::vector<double> values) {
    if (values.size() == 0) {return 0;}
    double res = 0.0;
    double max = values[0];
    double min = values[0];
    double avr = 0.0;
    switch (max_min_avr)
    {
        case MAX     : for (double val : values) { if (val > max) {max = val;} } res = max; break;
        case MIN     : for (double val : values) { if (val < min) {min = val;} } res = min;break;
        case AVERAGE : res = 0.0; for (double val : values) { avr += val; } res = avr / values.size(); break;
        default: break;
    }
    return res;
}



/** Creates a single graph bar for diagrams from all values with min max and
 *  average ( for console output )
 *
 * */
std::vector<std::string> Statistics::barGraph(double max_value,std::vector<double> values, Color color) {
    std::vector<std::string> res;
    //if (values.size() == 0) {return res;}

    double min = getfromList(MIN,values);
    double max = getfromList(MAX,values);
    //double avr = getfromList(AVERAGE,values);

    std::stringstream min_bar("");

    for (int i = 1 ; i <= 11 ; i ++ ) { // first value in vector is 5%

        std::stringstream bar("");
        double buf = 0.0;
        double percent = i * 5;

        // is min
        if (min > percent - 5.0 && min < percent ) {
            buf = min - (i-1) * 5;
            if (buf <  2.00) {min_bar << "__";}
            if (buf >= 2.00) {min_bar << "--";}
        } //else {min_bar << "  ";}

        // is max
        if (max >= percent - 5.0 )   {  bar << S::setStyle(color,Bold,White,"  ");
        } else {  bar << S::setStyle(Black,Bold,White,"  ");
        }

        res.push_back(bar.str());

    }
    return res;

}


