//
// Created by manjaro on 27.01.22.
//

#include "NaiveBayes.h"



/** write the results as a Table in a file
 *
 * @output_file     File
 * */
void NaiveBayes::outputFile(std::string output_file) {

    std::ofstream output(output_file);
    output << "Bayes Trainingsstunde Output:\n";
    output << "\n";
    output << "SNP's = "<< X.getSNPcount() <<"\n";
    output << "\n";
    output << "\n";

    std::stringstream a0("");
    std::stringstream a1("");
    std::stringstream a2("");
    std::stringstream a3("");
    std::stringstream a4("");
    std::stringstream a5("");
    std::stringstream a6("");
    std::stringstream a6("");

    a0 << "\n ______________|";
    a1 << "\n Accuracy      |";
    a2 << "\n Sensitivity   |";
    a3 << "\n Specificity   |";
    a4 << "\n Precision     |";
    a5 << "\n F1Score       |";
    a6 << "\n Average       |";
    a7 << "\n St. Deviation |";

    int pos = 0;

    while(true){
        if (pos >= ST.get_stats_Accuracy().size()) {break;}
        a0 << "____k_" << (pos+1) << "_|";
        a1 <<  Format::double2String( ST.get_stats_Accuracy()           << "|";
        a2 <<  Format::double2String( ST.get_stats_Sensitivity()        << "|";
        a3 <<  Format::double2String( ST.get_stats_Specificity()        << "|";
        a4 <<  Format::double2String( ST.get_stats_Precision()          << "|";
        a5 <<  Format::double2String( ST.get_stats_F1Score()            << "|";
        a6 <<  Format::double2String( ST.get_stats_Average()            << "|";
        a7 <<  Format::double2String( ST.get_stats_Standard_deviation() << "|";
        }

    // Get values over all k's:  { MIN, MAX, AVERAGE }

    a0 << " |" << " __K_MIN_______|";
    a1 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Accuracy() ))           << "|";
    a2 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Sensitivity() ))        << "|";
    a3 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Specificity() ))        << "|";
    a4 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Precision() ))          << "|";
    a5 << " |" <<  Format::double2String( getfromList( MIN , get_stats_F1Score() ))            << "|";
    a6 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Average() ))            << "|";
    a7 << " |" <<  Format::double2String( getfromList( MIN , get_stats_Standard_deviation()))  << "|";

    a0 << " __K_AVERAGE___|";
    a1 <<  Format::double2String( getfromList( AVERAGE , get_stats_Accuracy() ))           << "|";
    a2 <<  Format::double2String( getfromList( AVERAGE , get_stats_Sensitivity() ))        << "|";
    a3 <<  Format::double2String( getfromList( AVERAGE , get_stats_Specificity() ))        << "|";
    a4 <<  Format::double2String( getfromList( AVERAGE , get_stats_Precision() ))          << "|";
    a5 <<  Format::double2String( getfromList( AVERAGE , get_stats_F1Score() ))            << "|";
    a6 <<  Format::double2String( getfromList( AVERAGE , get_stats_Average() ))            << "|";
    a7 <<  Format::double2String( getfromList( AVERAGE , get_stats_Standard_deviation()))  << "|";

    a0 << " __K_MAX_______|";
    a1 <<  Format::double2String( getfromList( MAX , get_stats_Accuracy() ))           << "|";
    a2 <<  Format::double2String( getfromList( MAX , get_stats_Sensitivity() ))        << "|";
    a3 <<  Format::double2String( getfromList( MAX , get_stats_Specificity() ))        << "|";
    a4 <<  Format::double2String( getfromList( MAX , get_stats_Precision() ))          << "|";
    a5 <<  Format::double2String( getfromList( MAX , get_stats_F1Score() ))            << "|";
    a6 <<  Format::double2String( getfromList( MAX , get_stats_Average() ))            << "|";
    a7 <<  Format::double2String( getfromList( MAX , get_stats_Standard_deviation()))  << "|";

    output << a0;
    output << a1;
    output << a2;
    output << a3;
    output << a4;
    output << a5;
    output << a6;
    output << a7;
    output << "\n";

    }

