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



  private:

    // Contains the finished Overlap-Graph
    OGraph OverlapGraph;

};


#endif // BIOINFO1_ASSEMBLER_H

