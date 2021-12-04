
#ifndef SHORT_GUROBI_H
#define SHORT_GUROBI_H


#include "Graph.h"


class Gurobi {

public:
    static void startAlgorithm(Graph &G, std::string start, std::string target) ;

};




void Gurobi::startAlgorithm(Graph &G, std::string start, std::string target) {

  /*

      \ o/\o /
    --- |  | ---          <= That's not a bug, that's a
       / \/ \                feature ;-)
      /      \

  */



// Füge mit dieser Methode einen kürzesten Pfad zusammen, indem mit G.addToPath die Knoten
// in der richtigen Reihenfolge eingefügt werden.


// nur zum Testen:
    G.addToPath(&G.getNodes().at(0));
    G.addToPath(&G.getNodes().at(1));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(3));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(0));

}


#endif //SHORT_GUROBI_H