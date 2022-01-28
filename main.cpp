#include <iostream>
#include <fstream>
#include <valarray>

#include "console/console.h"
#include "snipper/Snipper.h"


int main(int argc, char *argv[]) {


    // Provisorium
    std::string arg_In  = "../snp.txt";
    std::string arg_Out = "../bayes.t";


















    // correct arg-count?
    //if (argc < 3) { console::Help("  Not enough arguments!  ");return 0; }
    //if (argc > 3) { console::Help("  Too many arguments!  ");return 0; }

    // ## Argument Variables
    //std::string arg_In  = argv[1];
    //std::string arg_Out = argv[2];
    std::ifstream input(arg_In);
    std::ofstream output(arg_Out);

    // ## File Check
    if (!input) { console::Help("  Input file error!  "); input.close(); return 0; }
    if (!output) { console::Help("  Output file error!  "); input.close(); output.close();return 0; }
    input.close();output.close();

    // ## Input okay -> Start SNP computing

    console::ShowHeader();   // show header

    Timer t;                 // timestamp

    Snipper S(arg_In);       // read file

    NaiveBayes NB(S, 10);    // Build NaiveBayes

    //console::ShowInputs(arg_In,arg_Out,S); // show inputs

    double time1 = t.getMilliSecs();       // timestamp after file in

    NB.BayesTrainingsstunde();                    // algorithm

    // ## Results Output

    NB.outputFile(arg_Out);                  // write results in file

    double time2 = t.getMilliSecs();       // timestamp after finish algorithm

    console::Result(NB,"",Timer::getFormatted(time2),Timer::getFormatted(time1),Timer::getFormatted(time2-time1)); // finish message to console

    return 0;
}
