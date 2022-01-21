#include <iostream>
#include <fstream>
#include "SingleSNP.h"
#include "Snipper.h"
#include "console/console.h"


int main(int argc, char *argv[]) {

    // correct arg-count?
    if (argc < 3) { console::Help("  Not enough arguments!  ");return 0; }
    if (argc > 3) { console::Help("  Too many arguments!  ");return 0; }

    // Argument Variables
    std::string arg_In  = argv[1];
    std::string arg_Out = argv[2];
    std::ifstream input(arg_In);
    std::ofstream output(arg_Out);

    if (!input) { console::Help("  Input file error!  "); input.close(); return 0; }
    if (!output) { console::Help("  Output file error!  "); input.close(); output.close();return 0; }

    input.close();output.close();

    Snipper S(arg_In);

    console::ShowHeader();
    console::ShowInputs(arg_In,arg_Out,S);





    return 0;
}
