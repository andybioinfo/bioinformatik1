#include <iostream>
#include <fstream>
#include <valarray>



#include "console/console.h"
#include "snipper/Snipper.h"
#include "snipper/SingleSNP.h"
#include "snipper/TestSNP.h"


bool test1() {
/*
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(2,20,80,40,20,10,60);
    stats.addStatsSet(2,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(1,20,80,40,20,10,60);

    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);

int sum = 0;
    for (Block k : NB.getK_Blocks()) {
        for (int id : k.getBlockPatients()) {
            sum += id;
        }
    }
    std::cout << "sum of all ids "<< sum << "\n";

        for (Block k : NB.getK_Blocks()) {
        k.print();
    }

*/
return false;
}






int main(int argc, char *argv[]) {


    // Provisorium
    console::ShowHeader();
    Timer t;
    std::string arg_In  = "testfile";

    Snipper S = createSNPs();              // read file and create Snipper SNP-Database

    double time1 = t.getMilliSecs();       // timestamp after file in

    NaiveBayes NB(S, 10);                  // Build NaiveBayes

    NB.BayesTrainingsstunde();             // compute Naive Bayes

    NB.outputFile("../bayes.txt");         // write results in file

    double time2 = t.getMilliSecs();       // timestamp after finish algorithm

    console::InputLine(                    // write inputs to console
        NB.getSNPs().getSNPcount(), 
        NB.getSNPs().getClassifics().count(), 
        NB.get_k_COUNT(), 
        NB.get_k_SIZE(),
        arg_In,
        Timer::getFormatted(time2), 
        Timer::getFormatted(time1), 
        Timer::getFormatted(time2-time1)
        );

       

    console::Result(NB,"../bayes.txt","1","1","1");

    




/*




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

    console::Result(NB,arg_Out,Timer::getFormatted(time2),Timer::getFormatted(time1),Timer::getFormatted(time2-time1)); // finish message to console


*/
    return 0;
}
