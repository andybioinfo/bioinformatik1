#include <gtest/gtest.h>

#include <memory>
#include <initializer_list>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <ostream>
#include <istream>
#include <sstream>
#include <iostream>

#include "../Graph.h"
#include "../Gurobi.h"

TEST(GUROBI_TEST, createFromAdjacencyMatrixFile){
    Graph G = Graph::createFromAdjacencyMatrixFile("../adjacency_matrix.csv");
    EXPECT_EQ(13, G.getNodes().size());

}

TEST(GUROBI_TEST, startAlgorithm){
    Graph G = Graph::createFromAdjacencyMatrixFile("../adjacency_matrix.csv");
    Gurobi::startAlgorithm(G,"A","B");

}

TEST(GUROBI_TEST, getPath){

}

TEST(GUROBI_TEST, pathToString){

}

TEST(GUROBI_TEST, addToPath){

}

TEST(GUROBI_TEST, getEdgeWeight){

}

TEST(GUROBI_TEST, stringToID){
    Graph G = Graph::createFromAdjacencyMatrixFile("../adjacency_matrix.csv");
    EXPECT_EQ(1,G.stringToID("A"));
}