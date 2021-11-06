#ifndef BIOINFO1_ASSEMBLER_H
#define BIOINFO1_ASSEMBLER_H

#include "Graph.h"
#include "Sequence.h"
#include "DNA.h"

class Assembler
{
  public:
  	
	using Seq = Sequence<Alphabet::DNA>;
	using OGraph = Graph<Seq>;



    /**
     * Awesome static Method to build the awesome Overlay-Graph with a given Fasta-file.
     * This method will return a File in Graphviz-Format
     */
    static void FromFastaFileToGraph(const char* inputfile,const char* outputfile);


	/**
	 * Creates an overlap-graph that contains the passed sequences as nodes.
	 */
	Assembler(const std::vector<Sequence<Alphabet::DNA>>& sequences);



    /**
     * returns the finished graph-instance
     * */
    OGraph getGraph();

	/**
     * Give a Fasta-File and return an Assembler
	 */
	static Assembler FastaToGreedy(const char* inputfile,const char* folder,bool create_intermediates);

	/**
     * Check if an Edge from the graph with valid nodes.
     * */
	bool isValid(const OGraph::Edge& e);

	/**
     * Assembles a Graph with the Greedy-Algorithm
     * */
	Seq assemble();

	/**
     * Merge two Sequences and return this
     * */
	static Seq mergeSequences(Seq A,Seq B);

	/**
	 * returns Greedy Step Count value
	 * */
	int getStepCount();

	/**
     * Increase Greedy-Step count:
     * */
	void Increase_Greedy_Step_Count();

  private:

    // Contains the finished Overlap-Graph
    OGraph OverlapGraph;
	int greedy_steps = 1;

};


#endif // BIOINFO1_ASSEMBLER_H

