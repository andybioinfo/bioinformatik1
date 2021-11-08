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



TEST(Assembler, CreateGraphvizFileFromFasta)
{
    Assembler::FromFastaFileToGraph("../../fragments.fasta", "../../output.digraph");
    FILE *f = fopen("../../output.digraph", "r");
    ASSERT_TRUE(f != NULL);
}

TEST(Assembler, AlgorithmCheck)
{
    
    // Create Graph with nodes and edges
    SeqList Seqs = SequenceCombinator(0, 3, false);
    Graph<Sequence<Alphabet::DNA>> g(Seqs);

    // Start Assembler
    Assembler A(Seqs);
    Graph<Sequence<Alphabet::DNA>> graph = A.getGraph();

    // Look for Nodes
    auto iter = graph.beginNodes();
    Node *a = &iter.operator*();
    iter++;
    Node *b = &iter.operator*();
    iter++;
    Node *c = &iter.operator*();
    iter++;
    Node *d = &iter.operator*();

    EXPECT_EQ(a->out_edges.size(), 0); // Edge-Count Node A = 0
    EXPECT_EQ(b->out_edges.size(), 0); // Edge-Count Node B = 0
    EXPECT_EQ(c->out_edges.size(), 1); // Edge-Count Node C = 1
    EXPECT_EQ(d->out_edges.size(), 1); // Edge-Count Node D = 1

    EXPECT_EQ(c->out_edges.front().second, 4); // Edge-Weight C -> D = 4
    EXPECT_EQ(d->out_edges.front().second, 4); // Edge-Weight D -> C = 4

    EXPECT_EQ(c->out_edges.front().first->label.getComment(), "DNA_D"); // Edge C -> D => DNA_D
    EXPECT_EQ(d->out_edges.front().first->label.getComment(), "DNA_C"); // Edge D -> C => DNA_C
}

