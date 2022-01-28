//
// Created by manjaro on 27.01.22.
//

#include <fstream>
#include <sstream>
#include "NaiveBayes.h"
#include "console/Format.h"



/** write the statistics as a table in a file
 *
 * @output_file     File
 * */
void NaiveBayes::outputFile(std::string output_file) {

    std::ofstream output(output_file);
    output << "Bayes Trainingsstunde Output:\n";
    output << "\n";
    output << "SNP's = "<< X.getSNPcount() <<"\n";
    output << "Patients = "<< X.getClassifics().count() <<"\n";
    output << "\n";
    output << "\n all Values are in percent %";
    output << "\n";
    output << "\n";

    std::stringstream a0("");
    std::stringstream a1("");
    std::stringstream a2("");
    std::stringstream a3("");
    std::stringstream a4("");
    std::stringstream a5("");
    std::stringstream a6("");
    std::stringstream a7("");

    a0 << "\n ______________|";
    a1 << "\n Accuracy      |";
    a2 << "\n Sensitivity   |";
    a3 << "\n Specificity   |";
    a4 << "\n Precision     |";
    a5 << "\n F1Score       |";
    a6 << "\n Average       |";
    a7 << "\n St. Deviation |";

    int i = 0;

    while(true){
        if (i >= (int)stats.get_stats_Accuracy().size()) {break;}
        a0 << "_____k_" << i << "_|";
        a1 <<  Format::double2String( stats.get_stats_Accuracy()[i]       )    << "|";
        a2 <<  Format::double2String( stats.get_stats_Sensitivity()[i]     )   << "|";
        a3 <<  Format::double2String( stats.get_stats_Specificity()[i]     )   << "|";
        a4 <<  Format::double2String( stats.get_stats_Precision()[i]       )   << "|";
        a5 <<  Format::double2String( stats.get_stats_F1Score()[i]         )   << "|";
        a6 <<  Format::double2String( stats.get_stats_Average() [i]        )   << "|";
        a7 <<  Format::double2String( stats.get_stats_Standard_deviation()[i]) << "|";
        i++;
        }

    // Get values over all k's:  { MIN, MAX, AVERAGE }

    a0 << " |" << "__K_MIN__|";
    a1 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Accuracy() ))           << "|";
    a2 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Sensitivity() ))        << "|";
    a3 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Specificity() ))        << "|";
    a4 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Precision() ))          << "|";
    a5 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_F1Score() ))            << "|";
    a6 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Average() ))            << "|";
    a7 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Standard_deviation()))  << "|";

    a0 << "K_AVERAGE|";
    a1 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Accuracy() ))           << "|";
    a2 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Sensitivity() ))        << "|";
    a3 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Specificity() ))        << "|";
    a4 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Precision() ))          << "|";
    a5 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_F1Score() ))            << "|";
    a6 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Average() ))            << "|";
    a7 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Standard_deviation()))  << "|";

    a0 << "__K_MAX__|";
    a1 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Accuracy() ))           << "|";
    a2 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Sensitivity() ))        << "|";
    a3 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Specificity() ))        << "|";
    a4 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Precision() ))          << "|";
    a5 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_F1Score() ))            << "|";
    a6 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Average() ))            << "|";
    a7 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Standard_deviation()))  << "|";

    output << a0.str();
    output << a1.str();
    output << a2.str();
    output << a3.str();
    output << a4.str();
    output << a5.str();
    output << a6.str();
    output << a7.str();
    output << "\n";

    }

