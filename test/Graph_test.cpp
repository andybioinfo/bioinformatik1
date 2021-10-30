#include <gtest/gtest.h>

#include <memory>
#include <initializer_list>
#include <set>
#include <vector>
#include <deque>

#include "../Sequence.h"
#include "../main.cpp"
#include "../DNA.h"

#include "../Graph.h"

using namespace Alphabet;
using SeqList = std::vector<Sequence<Alphabet::DNA>>;

SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty);

// Empty-Graph-Tests

TEST(Graph, emptyListToGraph)
{
SeqList emptySeqList = SequenceCombinator(0,0,true);
SeqList NotemptySeqList = SequenceCombinator(0,0,false);
Graph<Sequence<Alphabet::DNA>> graph_empty(emptySeqList);
Graph<Sequence<Alphabet::DNA>> graph_not_empty(NotemptySeqList);
EXPECT_EQ(graph_empty.numNodes(),0);
EXPECT_NE(graph_not_empty.numNodes(),0);
}

TEST(Graph, emptyListToGraph_GraphvizOutput)
{
SeqList emptySeqList = SequenceCombinator(0,0,true);
SeqList NotemptySeqList = SequenceCombinator(0,0,false);

std::string compstring = "digraph " << "overlapgraph" << " { \n";
<< "     nodecount=" << "0" << "\n" << "}\n";

EXPECT_EQ(compstring,"" << emptySeqList);
EXPECT_NE(compstring,"" << NotemptySeqList);
}

TEST(Graph, CustomGraphOnlyNodes)
{
SeqList SixSeq = SequenceCombinator(0,6,false);

Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
custom_graph.beginNodes().
EXPECT_EQ(custom_graph.numNodes(),6);
EXPECT_EQ((custom_graph.beginNodes()++).operator->()).getComment(),"DNA_A");
EXPECT_EQ((custom_graph.beginNodes()++).operator->()).getComment(),"DNA_B");
EXPECT_EQ((custom_graph.beginNodes()++).operator->()).getComment(),"DNA_C");
EXPECT_EQ((custom_graph.beginNodes()++).operator->()).getComment(),"DNA_D");
EXPECT_EQ((custom_graph.beginNodes()++).operator->()).getComment(),"DNA_E");
EXPECT_EQ((custom_graph.beginNodes()).operator->()).getComment(),"DNA_F");

}

TEST(Graph, CustomGraphNodesAndEdges)
{
SeqList SixSeq = SequenceCombinator(0,6,false);
Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
auto start = custom_graph.beginNodes();
auto destination = custom_graph.endNodes();
size_t weight = 11;
for (; start != destination; start++ ) {
    custom_graph.addEdge((start).operator->(),(--destination).operator->(),weight);
EXPECT_EQ(start->out_edges.begin()->second,weight);
EXPECT_EQ(start->out_edges.begin()->first->label,(--destination)->label);
}
}

TEST(Graph, CustomGraphNodesAndEdges_GraphvizOutput)
{
SeqList SixSeq = SequenceCombinator(0,6,false);
Graph<Sequence<Alphabet::DNA>> custom_graph(SixSeq);
auto start = custom_graph.beginNodes();
auto destination = custom_graph.endNodes();
size_t weight = 11;
for (; start != destination; start++ ) {
custom_graph.addEdge((start).operator->(),(--destination).operator->(),weight);
}
std::string compstring = "digraph " << "overlapgraph" << " { \n"
<< "     nodecount=" << "6" << "\n"
<< "     DNA_D [sequence=\"TAGC\"]\n"
<< "     DNA_E [sequence=\"AAAAA\"]\n"
<< "     DNA_F [sequence=\"TA\"]\n"
<< "     DNA_A -> DNA_F [weight=11 predecessor_sequence=\"TA\"]\n"
<< "     DNA_B -> DNA_E [weight=11 predecessor_sequence=\"AAAAA\"]\n"
<< "     DNA_C -> DNA_D [weight=11 predecessor_sequence=\"TAGC\"]\n"
<< "}\n";
EXPECT_EQ(compstring,"" << custom_graph);
}

TEST(Graph, contractEdgeTest)
{
EXPECT_EQ(true,false);
}

TEST(Graph, removeEdgeTest)
{
EXPECT_EQ(true,false);
}


TEST(Graph, oneEdge)
{
EXPECT_EQ(true,false);
}



TEST(Graph, OverlapGraphTest)
{
EXPECT_EQ(true,false);
}

TEST(Graph, TestTest)
{
EXPECT_EQ(true,true);
}






SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty) {
    SeqList List;
    if (generate_empty) {return List;}
    Sequence<Alphabet::DNA> sequences[] = {
            Sequence<Alphabet::DNA>::fromString("TAAGC")
            ,Sequence<Alphabet::DNA>::fromString("AA")
            ,Sequence<Alphabet::DNA>::fromString("TAGC")
            ,Sequence<Alphabet::DNA>::fromString("TAGC")
            ,Sequence<Alphabet::DNA>::fromString("AAAAA")
            ,Sequence<Alphabet::DNA>::fromString("TA")
    };

    std::string comment[] = {"DNA_A","DNA_B","DNA_C","DNA_D","DNA_E","DNA_F","DNA_G","DNA_H","DNA_I","DNA_J"};
    for (int id = 0 ; id < 6 ; id++) {
        sequences[id].setComment(comment[id]);}
    int max = 5;
    int start = (intervall_start < 0 || intervall_start > max) ? 0 : intervall_start;
    int end = (intervall_end < intervall_start || intervall_end > max) ? max : intervall_end;
    for (int val = start ; val <= end ; val++) {
        List.push_back(sequences[val]);
    }

    return List;
}