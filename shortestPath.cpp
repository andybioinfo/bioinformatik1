#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <stdio.h> 
#include <stdlib.h>

#include "/opt/gurobi912/linux64/include/gurobi_c++.h"

using namespace std;

int main(int   argc, char *argv[])
{
  
  
    console::Title("filefsd","A","B");

    std::ifstream input("../matrix.txt");
    if (!input) { console::Help("file error");
        return 0;
    }
    input.close();

    Graph G = Graph::createFromAdjacencyMatrixFile("../matrix.txt");

    G.addToPath(&G.getNodes().at(0));
    G.addToPath(&G.getNodes().at(1));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(3));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(0));

    console::Matrix(G.getNodes().size(),G.getEdges().size(),"OK",true);

    console::Result(G.getPathWeight(),G.getPath().size(),"A","B",G.pathToString());
  return 0;
}
