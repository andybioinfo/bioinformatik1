#include "Assembler.h"
#include "Fasta.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace Alphabet;
using Seq = Sequence<Alphabet::DNA>;
using OGraph = Graph<Seq>;
using String = std::string;
using SeqStack = std::vector<Assembler::Seq>;



/**
 * Creates an Overlap-Graph from a Fasta-File and write this Graph as Graphviz-Format in an output-file.
 *
 * @inputfile  the Fasta-File (example "../fragments.fasta" )
 * @outputfile the Output-File (example "../output.digraph" )
 * */
void Assembler::FromFastaFileToGraph(const char* inputfile,const char* outputfile) {

    // insert file
    std::ifstream input(inputfile);
    std::ofstream output(outputfile);

    // Is file read/writeable?
    if(!input)  { std::cerr << "Could not open file \"" << inputfile << "\" for reading!\n"; }
    if(!output) { std::cerr << "Could not open file \"" << outputfile << "\" for writing!\n"; }

    // Create Sequences-Container
    std::vector<Sequence<Alphabet::DNA>> stack;

    // Loop-Variables
    std::string line;
    bool begin = true;
    Sequence<Alphabet::DNA> first_seq;
    stack.push_back(first_seq);

    // First line '>'
    char first;
    //if (first != '>') {return;}
    while(getline(input,line)) {
        line.erase(0,1);
        stack.back().setComment(line);
    break;
    }

    // ## File-Loop ##
    while(getline(input,line)) {
        // read first char
        first = line.front();
        // Comment-Line
        if (first == '>' ) { // if Comment-Line => next Sequence...
                               Sequence<Alphabet::DNA> next_seq;
                               stack.push_back(next_seq);
                               line.erase(0,1);
                               stack.back().setComment(line);
                               continue; // next loop step
                          }
        // No Comment-Line
        for (auto c : line) {stack.back().push_back(DNA::toCharacter(c));}

    }
    input.close();

    // Build the Overlap-Graph
    Assembler A(stack);
    Graph<Sequence<Alphabet::DNA>> graph = A.getGraph();

    // File Output
    output << A.getGraph();
    output.close();

}



/**
 * Creates an Overlap-Graph with the given sequences.
 * @sequences the created Overlap-Graph
 * */
Assembler::Assembler(const std::vector<Sequence<Alphabet::DNA>>& sequences){

    // Creates the graph and add all sequences as nodes
    OverlapGraph = Graph<Sequence<Alphabet::DNA>>(sequences);

    auto start_a = OverlapGraph.beginNodes();
    auto destination_a = OverlapGraph.endNodes();

    // Loop: Rows
    for (; start_a != destination_a; start_a++ ) {
        auto start_b = OverlapGraph.beginNodes();
        auto destination_b = OverlapGraph.endNodes();
        // Loop: Columns
        for (; start_b != destination_b; start_b++ ) {
            if (start_a == start_b) {continue;} // continue to prevent reflexive-edges
            size_t weight = start_a->label.overlap(start_b->label);
            if (weight < 1) {continue;} // continue and create no edge if no Overlap between a and b
            OverlapGraph.addEdge(start_a.operator->(),start_b.operator->(),weight);

        }

    }
}


/**
 * @return the created Overlap-Graph
 * */
OGraph Assembler::getGraph() {
    return OverlapGraph;
}
