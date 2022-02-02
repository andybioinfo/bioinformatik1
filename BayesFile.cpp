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

    std::stringstream a0("");  // names 

    std::stringstream a1("");  // value
    std::stringstream av1(""); // average
    std::stringstream dv1(""); // derovation
    std::stringstream lm1(""); // limiter

    std::stringstream a2("");
    std::stringstream av2("");  
    std::stringstream dv2("");  
    std::stringstream lm2("");  

    std::stringstream a3("");
    std::stringstream av3("");  
    std::stringstream dv3("");  
    std::stringstream lm3(""); 

    std::stringstream a4("");
    std::stringstream av4("");  
    std::stringstream dv4("");  
    std::stringstream lm4(""); 

    std::stringstream a5("");
    std::stringstream av5("");  
    std::stringstream dv5("");  
    std::stringstream lm5(""); 

    std::stringstream a6("");
    std::stringstream av6("");  
    std::stringstream dv6("");  
    std::stringstream lm6(""); 

    std::stringstream a7("");
    std::stringstream av7("");  
    std::stringstream dv7("");  
    std::stringstream lm7(""); 

    a0  << "\n ______________|";
    a1  << "\n Accuracy      |";
    av1 << "\n  -> Average   |";
    dv1 << "\n  -> Std.Dev   |";
    lm1 << "\n ______________|";
    a2  << "\n Sensitivity   |";
    av2 << "\n  -> Average   |";
    dv2 << "\n  -> Std.Dev   |";
    lm2 << "\n ______________|";
    a3  << "\n Specificity   |";
    av3 << "\n  -> Average   |";
    dv3 << "\n  -> Std.Dev   |";
    lm3 << "\n ______________|";
    a4  << "\n Precision     |";
    av4 << "\n  -> Average   |";
    dv4 << "\n  -> Std.Dev   |";
    lm4 << "\n ______________|";
    a5  << "\n F1Score       |";
    av5 << "\n  -> Average   |";
    dv5 << "\n  -> Std.Dev   |";
    lm5 << "\n ______________|";


    int i = 0;

    while(true){
        if (i >= (int)stats.get_stats_Accuracy().size()) {break;}
        a0 << "_____k_" << i << "_|";

        a1 <<  Format::double2String( stats.get_stats_Accuracy()[i]            )    << "|";
       av1 <<  Format::double2String( stats.get_stats_Average1()[i]            )    << "|";
       dv1 <<  Format::double2String( stats.get_stats_Standard_deviation1()[i] )    << "|";
       lm1 << "_________|";

        a2 <<  Format::double2String( stats.get_stats_Sensitivity()[i]         )    << "|";
       av2 <<  Format::double2String( stats.get_stats_Average2()[i]            )    << "|";
       dv2 <<  Format::double2String( stats.get_stats_Standard_deviation2()[i] )    << "|";
       lm2 << "_________|";

        a3 <<  Format::double2String( stats.get_stats_Specificity()[i]         )    << "|";
       av3 <<  Format::double2String( stats.get_stats_Average3()[i]            )    << "|";
       dv3 <<  Format::double2String( stats.get_stats_Standard_deviation3()[i] )    << "|";
       lm3 << "_________|";

        a4 <<  Format::double2String( stats.get_stats_Precision()[i]           )    << "|";
       av4 <<  Format::double2String( stats.get_stats_Average4()[i]            )    << "|";
       dv4 <<  Format::double2String( stats.get_stats_Standard_deviation4()[i] )    << "|";
       lm4 << "_________|";

        a5 <<  Format::double2String( stats.get_stats_F1Score()[i]             )    << "|";
       av5 <<  Format::double2String( stats.get_stats_Average5()[i]            )    << "|";
       dv5 <<  Format::double2String( stats.get_stats_Standard_deviation5()[i] )    << "|";
       lm5 << "_________|";

       i++;
       }




    // Get values over all k's:  { MIN, MAX, AVERAGE }

    a0 << " |" << "__K_MIN__|";
    a1 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Accuracy() ))           << "|";
    av1 << "         |";
    dv1 << "         |";
    lm1 << "_________|";
    
    a2 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Sensitivity() ))        << "|";
    av2 << "         |";
    dv2 << "         |";
    lm2 << "_________|";
    
    a3 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Specificity() ))        << "|";
    av3 << "         |";
    dv3 << "         |";
    lm3 << "_________|";
    
    a4 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_Precision() ))          << "|";
    av4 << "         |";
    dv4 << "         |";
    lm4 << "_________|";
    
    a5 << " |" <<  Format::double2String( Statistics::getfromList( MIN , stats.get_stats_F1Score() ))            << "|";
    av5 << "         |";
    dv5 << "         |";
    lm5 << "_________|";


    a0 << "K_AVERAGE|";
    a1 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Accuracy() ))           << "|";
    av1 << "         |";
    dv1 << "         |";
    lm1 << "_________|";

    a2 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Sensitivity() ))        << "|";
    av2 << "         |";
    dv2 << "         |";
    lm2 << "_________|";

    a3 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Specificity() ))        << "|";
    av3 << "         |";
    dv3 << "         |";
    lm3 << "_________|";

    a4 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_Precision() ))          << "|";
    av4 << "         |";
    dv4 << "         |";
    lm4 << "_________|";

    a5 <<  Format::double2String( Statistics::getfromList( AVERAGE , stats.get_stats_F1Score() ))            << "|";
    av5 << "         |";
    dv5 << "         |";
    lm5 << "_________|";


    a0 << "__K_MAX__|";
    a1 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Accuracy() ))           << "|";
    av1 << "         |";
    dv1 << "         |";
    lm1 << "_________|";

    a2 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Sensitivity() ))        << "|";
    av2 << "         |";
    dv2 << "         |";
    lm2 << "_________|";

    a3 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Specificity() ))        << "|";
    av3 << "         |";
    dv3 << "         |";
    lm3 << "_________|";

    a4 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_Precision() ))          << "|";
    av4 << "         |";
    dv4 << "         |";
    lm4 << "_________|";

    a5 <<  Format::double2String( Statistics::getfromList( MAX , stats.get_stats_F1Score() ))            << "|";
    av5 << "         |";
    dv5 << "         |";
    lm5 << "_________|";


    output << a0.str();
    
    output << a1.str();
    output << av1.str();
    output << dv1.str();
    output << lm1.str();

    output << a2.str();
    output << av2.str();
    output << dv2.str();
    output << lm2.str();

    output << a3.str();
    output << av3.str();
    output << dv3.str();
    output << lm3.str();

    output << a4.str();
    output << av4.str();
    output << dv4.str();
    output << lm4.str();

    output << a5.str();
    output << av5.str();
    output << dv5.str();
    output << lm5.str();

    output << "\n";

    }

