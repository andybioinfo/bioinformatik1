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

#include "../Sequence.h"
#include "../DNA.h"
#include "../Graph.h"
#include "../Assembler.h"

using namespace Alphabet;
using SeqList = std::vector<Sequence<Alphabet::DNA>>;

SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty);

using Node = Graph<Sequence<Alphabet::DNA>>::Node;
using Edge = Graph<Sequence<Alphabet::DNA>>::Edge;

/** GRAPH TESTS - Test for check the methods of the Graph-Class
 * - Add Nodes
 * - Add Edges
 * - Remove Edges
 * - Contract Edges
 * - Graph Constructor Tests
 * - Graphviz Tests
 * - Assembler Tests
 *
 * */

TEST(Graph, AssemblerTest_FastaFileOutput)
{
Assembler::FromFastaFileToGraph("../fragments.fasta","../output.diagraph");
}

TEST(Graph, emptyListToGraph)
{
SeqList emptySeqList = SequenceCombinator(0,0,true);
SeqList NotemptySeqList = SequenceCombinator(0,0,false);
Graph<Sequence<Alphabet::DNA>> graph_empty(emptySeqList);
Graph<Sequence<Alphabet::DNA>> graph_not_empty(NotemptySeqList);
EXPECT_EQ(graph_empty.numNodes(),0);
EXPECT_NE(graph_not_empty.numNodes(),0);
}

TEST(Graph, AddOneEdge)
{
//Create Graph:
SeqList SeqTriplePack = SequenceCombinator(0,3,false);
Graph<Sequence<Alphabet::DNA>> g(SeqTriplePack);
auto iter = g.beginNodes();
// Create Node-pointers
Node *_a = &iter.operator*(); iter++;
Node *_b = &iter.operator*(); iter++;
// Add Edges
g.addEdge(_a,_b,99);
// Check the count of the edges
EXPECT_EQ(_a->out_edges.size(),1);
// Check the values of the edges
EXPECT_EQ(_a->out_edges.front().first->label.toString(),"AA");
EXPECT_EQ(_a->out_edges.front().second,99);
}

TEST(Graph, AddMultiEdges)
{
//Create Graph:
SeqList SeqTriplePack = SequenceCombinator(0,3,false);
Graph<Sequence<Alphabet::DNA>> g(SeqTriplePack);
auto iter = g.beginNodes();
// Create Node-pointers
Node *_a = &iter.operator*(); iter++;
Node *_b = &iter.operator*(); iter++;
Node *_c = &iter.operator*(); iter++;
// Add Edges
g.addEdge(_a,_b,10);
g.addEdge(_c,_b,15);
g.addEdge(_c,_a,20);
// Check the count of the edges
EXPECT_EQ(_a->out_edges.size(),1);
EXPECT_EQ(_b->out_edges.size(),0);
EXPECT_EQ(_c->out_edges.size(),2);
// Check the values of the edges
EXPECT_EQ(_a->out_edges.front().first->label.toString(),"AA");
EXPECT_EQ(_c->out_edges.front().first->label.toString(),"AA");
EXPECT_EQ(_a->out_edges.front().second,10);
EXPECT_EQ(_c->out_edges.front().second,15);
}


TEST(Graph, CustomGraphOnlyNodes)
{
SeqList SixSeq = SequenceCombinator(0,6,false);

Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
custom_graph.beginNodes();
EXPECT_EQ(custom_graph.numNodes(),7);
EXPECT_EQ((custom_graph.beginNodes()).operator->()->label.getComment(),"DNA_A");
EXPECT_EQ((++custom_graph.beginNodes()).operator->()->label.getComment(),"DNA_B");
EXPECT_EQ((++(++custom_graph.beginNodes())).operator->()->label.getComment(),"DNA_C");
EXPECT_EQ((++(++(++custom_graph.beginNodes()))).operator->()->label.getComment(),"DNA_D");
EXPECT_EQ((++(++(++(++custom_graph.beginNodes())))).operator->()->label.getComment(),"DNA_E");
EXPECT_EQ((++(++(++(++(++custom_graph.beginNodes()))))).operator->()->label.getComment(),"DNA_F");

}

TEST(Graph, CustomGraphNodesAndEdges)
{
/*
SeqList SixSeq = SequenceCombinator(0,6,false);
Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
auto start = custom_graph.beginNodes();
auto destination = custom_graph.endNodes();
size_t weight = 11;
for (; start != destination; start++ ) {
    custom_graph.addEdge((start).operator->(),(--destination).operator->(),weight);
EXPECT_EQ(start->out_edges.begin()->second,weight);
--destination;
EXPECT_EQ(start->out_edges.begin()->first->label.getComment(),(destination)->label.getComment());
}*/
}



TEST(Graph, contractEdgeTest)
{
SeqList KK = SequenceCombinator(0,9,false);
Graph<Sequence<Alphabet::DNA>> KG(KK);
auto HH = KG.beginNodes();
// Erstelle Knotenpointer
Node *_A = &HH.operator*(); HH++;
Node *_B = &HH.operator*(); HH++;
Node *_C = &HH.operator*(); HH++;
Node *_D = &HH.operator*(); HH++;
Node *_E = &HH.operator*(); HH++;
Node *_F = &HH.operator*(); HH++;
Node *_S = &HH.operator*(); HH++;
Node *_T = &HH.operator*(); HH++;
Node *_Q = &HH.operator*(); HH++;

// Erstelle Kanten
KG.addEdge(_S,_D,10);
KG.addEdge(_S,_E,15);
KG.addEdge(_S,_F,20);
KG.addEdge(_S,_T,25);
KG.addEdge(_T,_A,30);
KG.addEdge(_T,_B,35);
KG.addEdge(_T,_C,40);
KG.addEdge(_Q,_T,45);
// Contract this edge:
Edge EE(_S,_T,25);
KG.contractEdge(EE);
// Check the new count of the edges from the source-node
EXPECT_EQ(_S->out_edges.size(),6);
// If the successor of _Q changed?
EXPECT_EQ(_Q->out_edges.front().first->label.toString(),"TATATATATATA");
}

TEST(Graph, removeEdgeTest)
{
//Create Graph:
SeqList SeqTriplePack = SequenceCombinator(0,3,false);
Graph<Sequence<Alphabet::DNA>> g(SeqTriplePack);
auto iter = g.beginNodes();
// Create Node-pointers
Node *_a = &iter.operator*(); iter++;
Node *_b = &iter.operator*(); iter++;
Node *_c = &iter.operator*(); iter++;
// Add Edges
g.addEdge(_a,_b,10);
g.addEdge(_a,_c,20);
g.addEdge(_c,_b,15);
g.addEdge(_c,_a,20);
g.removeEdge(_a,_b);
Edge for_delete(_c,_a,25);
g.removeEdge(for_delete);
// Check the count of the edges
EXPECT_EQ(_a->out_edges.size(),1);
EXPECT_EQ(_b->out_edges.size(),0);
EXPECT_EQ(_c->out_edges.size(),1);
// Check for deleting the correct Edge
EXPECT_EQ(_a->out_edges.front().second,20);
EXPECT_EQ(_c->out_edges.front().second,15);
}


TEST(GRAPH_GRAPHVIZ_TEST, emptyListToGraph_GraphvizOutput)
{
SeqList emptySeqList = SequenceCombinator(0,0,true);
SeqList NotemptySeqList = SequenceCombinator(0,0,false);
std::string compstring = std::string("digraph overlapgraph { \n     nodecount=0\n}\n"); 
//<< std::string("overlapgraph") << std::string(" { \n")
//<< std::string("     nodecount=") << std::string("0") << std::string("\n") << string("}\n");
Graph<Sequence<Alphabet::DNA>> graph_empty(emptySeqList);
Graph<Sequence<Alphabet::DNA>> graph_not_empty(NotemptySeqList);

//EXPECT_EQ(compstring, (std::stringstream("") << graph_empty).str());
//EXPECT_NE(compstring, (std::stringstream("") << graph_not_empty).str());
}


TEST(GRAPH_GRAPHVIZ_TEST, CustomGraphNodesAndEdges_GraphvizOutput)
{
SeqList SixSeq = SequenceCombinator(0,6,false);
Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
auto start = custom_graph.beginNodes();
auto destination = custom_graph.endNodes();
size_t weight = 11;
for (; start != destination; start++ ) {
custom_graph.addEdge((start).operator->(),(--destination).operator->(),weight);
}
std::string compstring = std::string("digraph ").append("overlapgraph").append(" { \n").append("     nodecount=6\n").append("     DNA_D [sequence=\"TAGC\"]\n").append(
   "     DNA_E [sequence=\"AAAAA\"]\n").append("     DNA_F [sequence=\"TA\"]\n").append("     DNA_A -> DNA_F [weight=11 predecessor_sequence=\"TA\"]\n").append(
    "     DNA_B -> DNA_E [weight=11 predecessor_sequence=\"AAAAA\"]\n").append("     DNA_C -> DNA_D [weight=11 predecessor_sequence=\"TAGC\"]\n").append("}\n");

//EXPECT_EQ(compstring, (std::stringstream("") << custom_graph).str());
}










/** Generates a Sequence List as std::vector
 *
 * @generate_empty  -> returns a empty List if true
 * @intervall_start -> start in the given List
 * @intervall_end   -> end in the given List
 * [Range 0 - 9]
 * */

SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty) {
    std::vector<Sequence<Alphabet::DNA>> List;
    if (generate_empty) {return List;}
    Sequence<Alphabet::DNA> sequences[] = {
            Sequence<Alphabet::DNA>::fromString("TAAGC")
            ,Sequence<Alphabet::DNA>::fromString("AA")
            ,Sequence<Alphabet::DNA>::fromString("TAGC")
            ,Sequence<Alphabet::DNA>::fromString("TAGC")
            ,Sequence<Alphabet::DNA>::fromString("AAAAA")
            ,Sequence<Alphabet::DNA>::fromString("TA")
            ,Sequence<Alphabet::DNA>::fromString("TATATATATATA")
            ,Sequence<Alphabet::DNA>::fromString("GCCGCG")
            ,Sequence<Alphabet::DNA>::fromString("CACATATA")
            ,Sequence<Alphabet::DNA>::fromString("TATACACAGGC")
    };

    sequences[0].setComment("DNA_A");
    sequences[1].setComment("DNA_B");
    sequences[2].setComment("DNA_C");
    sequences[3].setComment("DNA_D");
    sequences[4].setComment("DNA_E");
    sequences[5].setComment("DNA_F");
    sequences[6].setComment("DNA_G");
    sequences[7].setComment("DNA_H");
    sequences[8].setComment("DNA_I");
    sequences[9].setComment("DNA_J");
    /*
    const char* comment[10] = {"DNA_A","DNA_B","DNA_C","DNA_D","DNA_E","DNA_F","DNA_S","DNA_T","DNA_Q","DNA_X"};
    for (int id = 0 ; id < 10 ; id++) {
        sequences[id].setComment(comment[id]);}*/
    int max = 9;
    int start = (intervall_start < 0 || intervall_start > max) ? 0 : intervall_start;
    int end = (intervall_end < intervall_start || intervall_end > max) ? max : intervall_end;
    for (int val = start++ ; val <= end ; val++) {
        List.push_back(sequences[val]);
    }

    return List;
}
