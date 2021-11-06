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



TEST(AssemblerUB3, init)
{
	std::cout << "> GTAATC";
    EXPECT_EQ(lastConsoleOutput,"GTAATC");
}

TEST(AssemblerUB3, ValidEdgeCheck)
{
	SeqList stack =  SequenceCombinator(10, 17, false); // The fragments.fasta sequences
	Assembler B(stack);
	// load OGraph
	auto g = B.getGraph();
	auto iter = g.beginNodes();
	// Create Node-pointers
	Node* a = &iter.operator*();	iter++;
	Node* b = &iter.operator*();	iter++;
	Node* c = &iter.operator*();	iter++;
	Node* d = &iter.operator*();	iter++;
	Node* e = &iter.operator*();	iter++;
	Node pz = Node(Sequence<Alphabet::DNA>::fromString("TATAGATACACA"));
	pz.label.setComment("z");
	Node* z = &pz;
	Edge a_e = Edge(a, e, 0); // valid source -> valid target;
	Edge a_d = Edge(a, d, 0); // valid source -> invalid target;
	Edge z_e = Edge(z, e, 0); // invalid node -> valid target;
	Edge z_z = Edge(z, z, 0); // invalid node -> invalid target;
	ASSERT_TRUE(B.isValid(a_e));
	ASSERT_FALSE(B.isValid(a_e));
	ASSERT_FALSE(B.isValid(a_e));
	ASSERT_FALSE(B.isValid(a_e));
}


TEST(AssemblerUB3, JoinLargestEdge)
{
SeqList stack = SequenceCombinator(18,22,false); // The "Aufgabe 1: Greedy Ansatz" exercise sequences
Assembler B(stack);

// TODO
}

