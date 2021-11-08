#include "Assembler.h"
#include "Fasta.h"
#include "Graph.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;
using namespace Alphabet;
using Seq = Sequence<Alphabet::DNA>;
using OGraph = Graph<Seq>;
using String = std::string;
using SeqStack = std::vector<Assembler::Seq>;
using Node = Graph<Seq>::Node;
using Triple = std::tuple<Node,Node,size_t>;

/**
 * Creates an Overlap-Graph from a Fasta-File and write this Graph as Graphviz-Format in an output-file.
 *
 * @inputfile  the Fasta-File (example "../fragments.fasta" )
 * @outputfile the Output-File (example "../output.digraph" )
 * */
void Assembler::FromFastaFileToGraph(const char *inputfile, const char *outputfile)
{

    // insert file
    std::ifstream input(inputfile);
    std::ofstream output(outputfile);

    // Is file read/writeable?
    std::cout << "\033[1m\033[33m"
              << " Fasta-File opening... \"" << inputfile << "\"\033[0m";
    if (!input)
    {
        std::cout << "\n";
        std::cerr << "Could not open file \"" << inputfile << "\" for reading!\n";
        return;
    }
    else
    {
        std::cout << "\033[1m\033[33m"
                  << " [opening SUCCESS]"
                  << "\033[0m";
    }
    if (!output)
    {
        std::cout << "\n";
        std::cerr << "Could not open file \"" << outputfile << "\" for writing!\n";
        return;
    }
    else
    {
        std::cout << "\033[1m\033[33m"
                  << " [output SUCCESS]"
                  << "\033[0m";
    }

    // Create Sequences-Container
    std::vector<Sequence<Alphabet::DNA>> stack;

    // Loop-Variables
    std::string line;
    Sequence<Alphabet::DNA> first_seq;
    stack.push_back(first_seq);

    // First line '>'
    char first;
    // if (first != '>') {return;}
    while (getline(input, line))
    {
        line.erase(0, 1);
        stack.back().setComment(line);
        break;
    }

    // ## File-Loop ##
    while (getline(input, line))
    {
        // read first char
        first = line.front();
        // Comment-Line
        if (first == '>')
        { // if Comment-Line => next Sequence...
            Sequence<Alphabet::DNA> next_seq;
            stack.push_back(next_seq);
            line.erase(0, 1);
            stack.back().setComment(line);
            continue; // next loop step
        }
        // No Comment-Line
        for (auto c : line)
        {
            stack.back().push_back(DNA::toCharacter(c));
        }
    }
    input.close();

    // Build the Overlap-Graph
    Assembler A(stack);
    Graph<Sequence<Alphabet::DNA>> graph = A.getGraph();



    // File Output
    output << A.getGraph();
    std::cout << "\033[1m\033[32m"
              << " [ File successfully created :) ]\n"
              << "\033[0m";
    output.close();
}

/**
 * Creates an Overlap-Graph with the given sequences.
 * @sequences the created Overlap-Graph
 * */
Assembler::Assembler(const std::vector<Sequence<Alphabet::DNA>> &sequences)
{

    // Creates the graph and add all sequences as nodes
    OverlapGraph = Graph<Sequence<Alphabet::DNA>>(sequences);

    auto start_a = OverlapGraph.beginNodes();
    auto destination_a = OverlapGraph.endNodes();

    // Loop: Rows
    for (; start_a != destination_a; start_a++)
    {
        auto start_b = OverlapGraph.beginNodes();
        auto destination_b = OverlapGraph.endNodes();
        // Loop: Columns
        for (; start_b != destination_b; start_b++)
        {
            if (start_a == start_b)
            {
                continue;
            } // continue to prevent reflexive-edges
            size_t weight = start_a->label.overlap(start_b->label);
            if (weight < 1)
            {
                continue;
            } // continue and create no edge if no Overlap between a and b
            OverlapGraph.addEdge(start_a.operator->(), start_b.operator->(), weight);
        }
    }
}

/**
 * @return the created Overlap-Graph
 * */
OGraph& Assembler::getGraph()
{
    return OverlapGraph;
}


/**
 * increase Greedy-Steps count (initial-value is 1)
 * */
void Assembler::Increase_Greedy_Step_Count() {
	greedy_steps++;
}

/**
 * Loads the File and more informations for the Greedy-Algorith and returns this Assembler
 * You can use on this Assember-Instance to run the Greedy Algorithm with (ASSEMBLER::FASTATOGREEDY).assemble()
 *
 * */
Assembler Assembler::FastaToGreedy(const char *inputfile, std::string folder, bool create_intermediates) {


	// insert file
	std::ifstream input(inputfile);

	// Create Sequences-Container
	std::vector<Sequence<Alphabet::DNA>> stack;

	// Loop-Variables
	std::string line;
	Sequence<Alphabet::DNA> first_seq;
	stack.push_back(first_seq);

	// First line '>'
	char first;
	// if (first != '>') {return;}
	while (getline(input, line))
	{
		line.erase(0, 1);
		stack.back().setComment(line);
		break;
	}

	// ## File-Loop ##
	while (getline(input, line))
	{
		// read first char
		first = line.front();
		// Comment-Line
		if (first == '>')
		{ // if Comment-Line => next Sequence...
			Sequence<Alphabet::DNA> next_seq;
			stack.push_back(next_seq);
			line.erase(0, 1);
			stack.back().setComment(line);
			continue; // next loop step
		}
		// No Comment-Line
		for (auto c : line)
		{
			stack.back().push_back(DNA::toCharacter(c));
		}
	}
	input.close();

	// Build the Overlap-Graph
	Assembler A(stack);
	Graph<Sequence<Alphabet::DNA>> graph = A.getGraph();

	// Make the Assembler ready for assembling with Greedy:
	A.set_intermediatesteps(create_intermediates);
	A.set_isgreedy();
	A.setOutputpath(folder); // TODO: Outputpath noch anpassen

	return A;

}






Seq Assembler::assemble() {

	int act_nodecount = getGraph().numNodes();
	int after = act_nodecount;
	// ## Write before-Graph in File (Step zero)
	if (get_intermediatesteps()) {Assembler::WriteGreedyFile(getGraph(), getOutputpath(),"greedy",0);}

	// ## Greedy-Loop:
		while (act_nodecount > 1) {
		    // Look for biggest edge-weight and merge this
		    joinLargestEdge();
		    act_nodecount = getGraph().numNodes();

		    // Success ? is the count of nodes decreased?
		    if (act_nodecount < after) {
			    act_nodecount = getGraph().numNodes();
			    if (get_intermediatesteps()) {
				    // write in file:
				    Assembler::WriteGreedyFile(getGraph(), getOutputpath(),"greedy",getStepCount());
			    }
			    Increase_Greedy_Step_Count();
			    after = getGraph().numNodes();
			    continue;
		    }

		    // No successful joining? -> Break this algorithm
		    break;

	    }

    if (getGraph().numNodes() == 1) return getGraph().beginNodes()->label;
    // TODO: Was soll der Assembler returnen wenn mehrere Knoten übrig sind?
	return getGraph().beginNodes()->label; // TODO: in dem fall einfach den ersten knoten als Sequenz returnen
}



    /**
     * Checks Edge-Connections with both nodes in the Ograph in the Assember-Instance
     * @return if both Edge-Connections correct.
     * */
bool Assembler::isValid(const OGraph::Edge& e) {

	bool found = false;

	auto start_node = e.source;
	auto target_node = e.target;
	auto iter = OverlapGraph.beginNodes();
	auto iter_end = OverlapGraph.endNodes();

	for (; iter != iter_end; iter++) {
		// iterate over nodes
		if (iter.operator->()->label != start_node->label) {continue;} // Is start_node in this Graph?
		auto edge_iter = iter->out_edges.begin();
		auto edge_iter_end = iter->out_edges.end();
		for (; edge_iter != edge_iter_end; edge_iter++) {
			// iterate over edges
			if (edge_iter->first->label == target_node->label) {found = true; break;} // Is target_node in this Graph?
		}
	}

	return found;
}



/**
 * Helper-method for mergeSequences
 * */
Seq merge_helper (Seq A , Seq B) {

    std::stringstream m("");
	m << "(" << A.getComment() << "^" << B.getComment() << ")";

	int cursor = 0;
	int follow = 0;
	auto iterA = A.begin();
	auto iterA_END = A.end();
	auto iterB = B.begin();

	for (; iterA != iterA_END; iterA++) {
		cursor++;
		//cout << "\n " << DNA::toChar(iterA.operator*()) << " == " << DNA::toChar(iterB.operator*()) ;
		if (iterA.operator*() == iterB.operator*()) { // same char
			if (iterB == --B.end()) {follow++;A.setComment(m.str());return A;} // if B ends return Seq A ( B is full part of A)
			follow++;iterB++;continue;}
		if (follow > 0) {follow = 0; iterB = B.begin();} // different char > reset
	}
	//cout << "(cursor:" << cursor << " follow: " << follow << ") ";
	while (follow > 0 && iterB != B.end()) {A.push_back(iterB.operator*());iterB++;}
	if (follow > 0) {A.setComment(m.str());return A;}

    // NOT WORKED:
	A.setComment("not merged sequence");
	return A;

}


/**
     * Merge two Sequences with his overlapping part
     * @A Sequence A
     * @B Sequence B
     * @return the merged sequence
     * */
Seq Assembler::mergeSequences(Seq A, Seq B) {

		//  A prefix B loop
		//  A:    CCAC|ATGA|
		//  B:        |ATGA|GTTAGA
	    Seq A_B = merge_helper (A,B);
	    if (A_B.getComment() != "not merged sequence") {return A_B;}

		// TODO: In diesem Fall fügt er es nicht zusammen wenn es 2 Möglichkeiten gibt des mergens
		//  A suffix B loop
		//  A:           |CCACA|TGA
		//  B:        TTC|CCACA|
	    Seq B_A = merge_helper (B,A);
	    if (B_A.getComment() != "not merged sequence") {return B_A;}

		// TODO: Was soll die Methode returnen wenn es nicht mergen lässt?
	    //cout <<  "merging impossible\n";
	    B_A.setComment("[mergeSeqError]");
		return B_A;
 }

/**
  * join the Edge with the biggest weight and adapt the remain nodes and edges this removed edge
 */
 void Assembler::joinLargestEdge(){
    // Find largest edge
    auto biggest = findLargestEdge();
	auto *source_node = &get<0>(biggest);
	auto *target_node = &get<1>(biggest);

	// biggest has not found an edge -> break this
	if ( get<2>(biggest) == 0) {return;}

	// Create the merged node
    auto *merged_node =  OverlapGraph.addNode(mergeSequences(source_node->label,target_node->label));
	auto z = OverlapGraph.beginNodes();



	// print
	//const char* RESET   = "\033[0m";
	//const char* BLUE    = "\033[0;34m";
	//auto Z1 = OverlapGraph.beginNodes();
	//auto Z1E = OverlapGraph.endNodes();
	//cout << BLUE <<"||  => before+: s:";
	//cout << source_node->label.getComment() << " t:" << target_node->label.getComment() << " w:" << get<2>(biggest)
	//<< " -> " << merged_node->label.getComment() << " | ";
	//for (; Z1 != Z1E; Z1++){ cout << Z1->label.getComment() << " "; }cout << "\n " << RESET;


	// Wer zeigt alles auf den Startknoten oder Endknoten?

	auto node_iter = OverlapGraph.beginNodes();
	auto node_iterE = OverlapGraph.endNodes();

	// Zwischenspeicher für Kanten
	std::vector<std::pair<Node*,Node*>> edgeStack;


	// Lösche alle Kanten

	for (; node_iter != node_iterE; node_iter++){ // iterate over nodes

		auto edge_beg = node_iter->out_edges.begin();
		while (edge_beg != node_iter->out_edges.end()) // iterate over edges
		{
			if (edge_beg->first->label.getComment() == source_node->label.getComment() ) // Is the target of this edge the old source or old target
			{
				// Create a new edge to the merged node
				//cout << "\n zeigt auf source : "<< node_iter->label.getComment() << "->" << edge_beg->first->label.getComment();
				std::pair<Node*,Node*> P(node_iter.operator->(),merged_node);
				edgeStack.push_back(P);
				// delete the old edge and continue
				node_iter->out_edges.erase(edge_beg);
				continue;
			}

			if ( edge_beg->first->label.getComment() == target_node->label.getComment()) // Is the target of this edge the old source or old target
			{
				// Create a new edge to the merged node
				//cout << "\n zeigt auf target : "<< node_iter->label.getComment() << "->" << edge_beg->first->label.getComment();
				std::pair<Node*,Node*> P(node_iter.operator->(),merged_node);
				edgeStack.push_back(P);
				// delete the old edge and continue
				node_iter->out_edges.erase(edge_beg);
				continue;
			}
			++edge_beg;
		}
	}

	// Füge erkannte neue Kanten hinzu

	auto stack_iter = edgeStack.begin();
	auto stack_iterE = edgeStack.end();
	for (; stack_iter != stack_iterE; stack_iter++){
		size_t weight = stack_iter->first->label.overlap(stack_iter->second->label);
		if (weight == 0) {continue;}
		OverlapGraph.addEdge(stack_iter->first,stack_iter->second,weight);


	}
	

	// Die Nachfolger von source

	auto edge_iter = source_node->out_edges.begin();

	while (edge_iter != source_node->out_edges.end()) // iterate over edges
	{
		// Replacing : Create new edge
		//cout << "\n s nachfolger : " << edge_iter->first->label.getComment();
		if (edge_iter->first->label.getComment() != target_node->label.getComment()) {
			size_t weight = merged_node->label.overlap(edge_iter->first->label);
			if (weight > 0) {OverlapGraph.addEdge(merged_node, edge_iter->first, weight);}
		}
		// Replacing : Delete the old edge
		source_node->out_edges.erase(edge_iter);

	}

	// Die Nachfolger von target

	edge_iter = target_node->out_edges.begin();

	while (edge_iter != target_node->out_edges.end()) // iterate over edges
	{
		// Replacing : Create new edge
		//cout << "\n t nachfolger : " << edge_iter->first->label.getComment();
		if (edge_iter->first->label.getComment() != source_node->label.getComment()) {
			size_t weight = merged_node->label.overlap(edge_iter->first->label);
			if (weight > 0) {OverlapGraph.addEdge(merged_node, edge_iter->first, weight );}
		}
		// Replacing : Delete the old edge
		target_node->out_edges.erase(edge_iter);

	}

	// Delete the old Nodes
	//cout << BLUE << "\n||" ;
	OverlapGraph.removeNode( &get<0>(biggest));
	OverlapGraph.removeNode( &get<1>(biggest));

	auto n1 = OverlapGraph.beginNodes();
	auto n1E = OverlapGraph.endNodes();

	//cout << "  => remaining: ";
	//for (; n1 != n1E; n1++){ cout << n1->label.getComment() << " "; }
	//cout << "\n" << RESET;

 }


Triple Assembler::findLargestEdge(){
    auto node_beg = OverlapGraph.beginNodes();
	// Create the start-triple
	Triple max_edge(node_beg.operator*(),node_beg.operator*(),0);

	// Counter
	int success = 0;

    // Loop over all nodes 
    while (node_beg != OverlapGraph.endNodes())
    {
        // Loop over all edges from the current node
        auto edge_beg = node_beg->out_edges.begin();
        while (edge_beg != node_beg->out_edges.end())
        {
            if (edge_beg->second > get<2>(max_edge)){
				// actualize the new Triple value from the bigger edge
                std::get<0>(max_edge) = node_beg.operator*();
				std::get<1>(max_edge) = *edge_beg->first;
				std::get<2>(max_edge) = edge_beg->second;
				success++;
            }
            ++edge_beg;
        }
        ++node_beg;
    }

    return max_edge;
 }

 /**
  * Write a numbered File in Graphviz-Format from the OGraph
  */
void Assembler::WriteGreedyFile(OGraph G, std::string path, const char* outputfile, int filenumber)
{
	// TODO: Wie den outputpath bzw. Ordnerpfad hier hinzufügen?

	std::stringstream filename;
	filename << path << outputfile << "_" << setw(6) << setfill('0') << filenumber << ".digraph";

	std::ofstream output(filename.str());

	if (!output) { std::cerr << "> Error creating/writing/whatever file: \"" << filename.str() << "\"\n"; return; }

	output << G;

}

int Assembler::getStepCount() {
	return greedy_steps;
}

void Assembler::setOutputpath(std::string path) {outputpath = path; }

std::string Assembler::getOutputpath() {return outputpath; }

void Assembler::set_isgreedy() {is_greedy = true;}
void Assembler::set_intermediatesteps(bool v) {intermediate_steps = v;}
bool Assembler::get_isgreedy() {return is_greedy;}
bool Assembler::get_intermediatesteps() {return intermediate_steps;}
