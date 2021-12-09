
#ifndef SHORT_GUROBI_H
#define SHORT_GUROBI_H


#include "Graph.h"
#include "/opt/gurobi912/linux64/include/gurobi_c++.h"
#include <string>
#include <iostream>


class Gurobi {

public:
    static int startAlgorithm(Graph &G, std::string start, std::string target) ;

};




int Gurobi::startAlgorithm(Graph &G, std::string start, std::string target) {

  /*

      \ o/\o /
    --- |  | ---          <= That's not a bug, that's a
       / \/ \                feature ;-)
      /      \

  */



// Füge mit dieser Methode einen kürzesten Pfad zusammen, indem mit G.addToPath die Knoten
// in der richtigen Reihenfolge eingefügt werden.

/**
// nur zum Testen:
    G.addToPath(&G.getNodes().at(0));
    G.addToPath(&G.getNodes().at(1));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(3));
    G.addToPath(&G.getNodes().at(2));
    G.addToPath(&G.getNodes().at(0));
**/

  try {

   // Create an environment
    GRBEnv env = GRBEnv(true);
    env.set("LogFile", "mip1.log");
    env.start();

    // Create an empty model
    GRBModel model = GRBModel(env);


    // variablen
    auto n = (int) G.getNodes().size();
    int s = G.stringToID(start);
    int t = G.stringToID(target);
    

    GRBVar edges[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          edges[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY);
      }
    }

    // Set objective: min wij * xij
    GRBLinExpr obj = 0.0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        auto weight = G.getEdgeWeight(i,j);
        obj += weight*edges[i][j];
      }
    }
    model.setObjective(obj, GRB_MINIMIZE);
  
    // Add constraint: no incoming edge of vs is chosen 
    GRBLinExpr expr = 0;
    for (int i = 0; i < n; i++) {
        expr += edges[i][s];
    }
    model.addConstr(expr, GRB_EQUAL, 0, "c0");

    // Add constraint: only exactly one outgoing edge of vs is chosen 
    GRBLinExpr expr1 = 0;
    for (int i = 0; i < n; i++) {
        expr1 += edges[s][i];
    }
    model.addConstr(expr1, GRB_EQUAL, 1, "c1");

    // Add constraint: only exactly one incoming edge of vt is chosen
    GRBLinExpr expr2 = 0;
    for (int i = 0; i < n; i++) {
        expr2 += edges[i][s];
    }
    model.addConstr(expr2, GRB_EQUAL, 1, "c2");

    // Add constraint: no outgoing edge of vt is chosen
    GRBLinExpr expr3 = 0;
    for (int i = 0; i < n; i++) {
        expr3 += edges[t][i];
    }
    model.addConstr(expr3, GRB_EQUAL, 0, "c3");

    // Add constraint: to all remaining nodes: As many outgoing as incoming edges are selected 
    for (int i = 0; i < n; i++) {
      if( i != s && i != t){
      GRBLinExpr sum1 = 0;
      GRBLinExpr sum2 = 0;
      for (int j = 0; j < n; j++) {
        // sum 
        sum1 += edges[i][j];
        sum2 += edges[j][i];
      }

      model.addConstr(sum1, GRB_EQUAL, sum2, "c4");
      }
    }

    // Optimize model
    model.optimize();

    //result
    int pathWeight = 0;
    int j = s;
    while(j != t){
      for (int i = 0; i < n; i++) {
        if(edges[j][i].get(GRB_DoubleAttr_X) == 1.0){
          G.addToPath(&G.getNodes().at(0));
          pathWeight += G.getEdgeWeight(j,i);
          j = i;
          break;
        }
      }
    }
    return pathWeight;

  } catch(GRBException e) {
    std::cout << "Error code = " << e.getErrorCode() << std::endl;
    std::cout << e.getMessage() << std::endl;
  } catch(...) {
    std::cout << "Exception during optimization" << std::endl;
  }
  return -1;
}


#endif //SHORT_GUROBI_H