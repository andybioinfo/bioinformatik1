#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <stdio.h> 
#include <stdlib.h>

#include "/opt/gurobi912/linux64/include/gurobi_c++.h"
#include "Graph.h"
#include "console.h"
#include "Gurobi.h"

using namespace std;

int main(int   argc, char *argv[])
{

    console::Title("file","A","B");

    std::ifstream input("../matrix.txt");
    if (!input) { console::Help("file error");
        return 0;
    }
    input.close();

    // ## Create Graph

    Graph G = Graph::createFromAdjacencyMatrixFile("../matrix.txt");
    console::Matrix(G.getNodes().size(),G.getEdges().size(),"OK",true);

    // ## Start Algorithm

    Gurobi::startAlgorithm(G,"A","B");

    // ## Return result

    console::Result(G.getPathWeight(),G.getPath().size(),"A","B",G.pathToString());
  return 0;
}
