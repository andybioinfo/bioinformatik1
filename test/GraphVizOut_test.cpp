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

#include "../SequenceCombinator.h"
#include "../Sequence.h"
#include "../DNA.h"
#include "../Graph.h"
#include "../Assembler.h"

using namespace Alphabet;
using SeqList = std::vector<Sequence<Alphabet::DNA>>;
using Node = Graph<Sequence<Alphabet::DNA>>::Node;
using Edge = Graph<Sequence<Alphabet::DNA>>::Edge;

/** GRAPHVIZ OUTPUT TESTS - Test for check the correct output to Graphviz
 *
 *
 * */

TEST(GRAPH_GRAPHVIZ_TEST, emptyListToGraph_GraphvizOutput)
{
    // Generate Sequences
    SeqList emptySeqList = SequenceCombinator(0, 0, true);
    SeqList NotemptySeqList = SequenceCombinator(0, 0, false);

    // Build an Empty and not-Empty Graph
    Graph<Sequence<Alphabet::DNA>> graph_empty(emptySeqList);
    Graph<Sequence<Alphabet::DNA>> graph_one_node(NotemptySeqList);

    // Strings to compare
    std::string compstring = std::string("digraph overlapgraph { \n     nodecount=0\n}\n");
    std::stringstream comp_a("");
    std::stringstream comp_b("");
    std::stringstream comp_c("");
    comp_a << compstring;
    comp_b << graph_empty;
    comp_c << graph_one_node;

    // Check
    ASSERT_TRUE(comp_a.str() == comp_b.str());
    ASSERT_TRUE(comp_a.str() != comp_c.str());
}

TEST(GRAPH_GRAPHVIZ_TEST, CustomGraphNodesAndEdges_GraphvizOutput)
{
    // Create Graph with nodes and edges
    SeqList SixSeq = SequenceCombinator(0, 6, false);
    Graph<Sequence<Alphabet::DNA>> g(SixSeq);

    auto iter = g.beginNodes();
    // Create Node-pointers
    Node *_a = &iter.operator*();
    iter++;
    Node *_b = &iter.operator*();
    iter++;
    Node *_c = &iter.operator*();
    iter++;
    Node *_d = &iter.operator*();
    iter++;
    Node *_e = &iter.operator*();
    iter++;
    // Add Edges
    g.addEdge(_a, _b, 10);
    g.addEdge(_c, _b, 15);
    g.addEdge(_c, _a, 20);
    g.addEdge(_e, _d, 15);
    g.addEdge(_a, _e, 20);

    std::cout << g;

    std::string compstring = "digraph overlapgraph { \n     nodecount=7\n     DNA_B [sequence=\"AA\"]\n     DNA_D [sequence=\"TAGC\"]\n     DNA_F [sequence=\"TA\"]\n     DNA_G [sequence=\"TATATATATATA\"]\n     DNA_A -> DNA_B [weight=10 predecessor_sequence=\"AA\"]\n     DNA_A -> DNA_E [weight=20 predecessor_sequence=\"AAAAA\"]\n     DNA_C -> DNA_B [weight=15 predecessor_sequence=\"AA\"]\n     DNA_C -> DNA_A [weight=20 predecessor_sequence=\"TAAGC\"]\n     DNA_E -> DNA_D [weight=15 predecessor_sequence=\"TAGC\"]\n}\n";

    std::stringstream comp_a("");
    std::stringstream comp_b("");
    comp_a << compstring;
    comp_b << g;

    ASSERT_TRUE(comp_a.str() == comp_b.str());
}
