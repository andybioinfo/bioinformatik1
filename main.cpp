#include <iostream>
#include <fstream>
#include <valarray>



#include "console/console.h"
#include "snipper/Snipper.h"
#include "snipper/SingleSNP.h"
#include "Examples.h"
#include "SNPFileGenerator/SNPgen.h"



int main(int argc, char *argv[]) {

    // correct arg-count?
    if (argc < 3) { console::Help("  Not enough arguments!  ");return 0; }
    if (argc > 3) { console::Help("  Too many arguments!  ");return 0; }

    // ## Argument Variables
    std::string arg_In  = argv[1];
    std::string arg_Out = argv[2];
    std::ifstream input(arg_In);
    std::ofstream output(arg_Out);

    // ## File Check
    if (!input) { console::Help("  Input file error!  "); input.close(); return 0; }
    if (!output) { console::Help("  Output file error!  "); input.close(); output.close();return 0; }
    input.close();output.close();

    // ## Input okay -> Start SNP computing

    console::ShowHeader();
    Timer t;

    Snipper S(arg_In );                                 // read file and create Snipper SNP-Database

    double time1 = t.getMilliSecs();                            // timestamp after file in

    NaiveBayes NB(S, 10,true);     // Build NaiveBayes

    NB.BayesTrainingsstunde();                                  // compute Naive Bayes

    NB.outputFile(arg_Out);                            // write results in file

    double time2 = t.getMilliSecs();                            // timestamp after finish algorithm

    console::InputLine(                                         // write inputs to console
        NB.getSNPs().getSNPcount(), 
        NB.getSNPs().getClassifics().count(), 
        NB.get_k_COUNT(), 
        NB.get_k_SIZE(),
        arg_In,
        Timer::getFormatted(time2), 
        Timer::getFormatted(time1), 
        Timer::getFormatted(time2-time1)
        );

       

    console::Result(NB,arg_Out,"","","");

    return 0;
}
