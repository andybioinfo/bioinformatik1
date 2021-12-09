#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <stdio.h> 
#include <stdlib.h>
#include <getopt.h>

#include "/opt/gurobi912/linux64/include/gurobi_c++.h"
#include "Graph.h"
#include "console.h"
#include "Gurobi.h"

using namespace std;

int main(int   argc, char *argv[])
{
    // ## getopt : Create getopt variables
    int opt = 1;
    bool input_help = false;
    bool input_filename = false;
    bool input_target = false;
    bool input_source = false;
    char *infile_arg = NULL;
    stringstream target("");
    stringstream source("");

    // ## getopt : Look for input via getopt

    while ((opt = getopt(argc,argv, "hf:r:t:")) != -1) {
        switch (opt) {
            case 'h' : input_help = true; break;
            case 'f' : input_filename = true; infile_arg = optarg; break;
            case 't' : input_target = true; target << optarg; break;
            case 'r' : input_source = true; source << optarg; break;
            default  : break;
        }
    }

    // correct argument

    if (!input_filename) { console::Help("no file choosen");return 0;}
    if (!input_target)   { console::Help("no target choosen");return 0;}
    if (!input_source)   { console::Help("no root choosen");return 0;}

    std::ifstream input(infile_arg);
    if (!input) { console::Help("file error");
        return 0;
    }
    input.close();

    console::Title(infile_arg,source.str(),target.str());

    // ## Create Graph

    Graph G = Graph::createFromAdjacencyMatrixFile(infile_arg);
    console::Matrix(G.getNodes().size(),G.getEdges().size(),"OK",true);

    // ## Start Algorithm

    int weight = Gurobi::startAlgorithm(G,source.str(),target.str());

    // ## Return result

    console::Result(weight,G.getPath().size(),source.str(),target.str(),G.pathToString());

  return 1;
}
