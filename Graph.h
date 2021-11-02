#ifndef BIOINFOI_GRAPH_H
#define BIOINFOI_GRAPH_H

#include <algorithm>
#include <list>
#include <memory>
#include <vector>
#include <string>


/**
 * Generic implementation of a graph class.
 */
template <typename NodeLabel> class Graph
{
  public:


  	/**
  	 * Node class that contains a label 
  	 * and all outgoing edges. Ingoing
  	 * edges are not needed.
  	 */
	struct Node
	{
		explicit Node(const NodeLabel& l) : label(l) {}
		NodeLabel label;
		std::vector<std::pair<Node*, size_t>> out_edges;
	};

	/**
  	 * Edge class that contains the 
  	 * source and target nodes as well as
  	 * a edge weight.
  	 */
	struct Edge
	{
		Edge(Node* a, Node* b, size_t w) : source(a), target(b), weight(w) {}
		Node* source;
		Node* target;
		size_t weight;
	};

	/**
	 * Defines how the data is stored internally.
	 *
	 * Can be changed if desired.
	 */
	using NodeContainer = std::list<Node>;
	using node_iterator = typename NodeContainer::iterator;
	using const_node_iterator = typename NodeContainer::const_iterator;

	/**
	 * Default constructor
	 */
	Graph() = default;

	/**
	 * Detailed constructor that also creates the nodes 
	 * od the Graph.
	 */
	explicit Graph(const std::vector<NodeLabel>& new_nodes);

	/**
	 * Node iterators.
	 */
	node_iterator beginNodes();
	node_iterator endNodes();

	const_node_iterator beginNodes() const;
	const_node_iterator endNodes() const;

	/**
	 * Creates a Node with a distict label and return a pointer to the new Node.
	 */
	Node* addNode(const NodeLabel& label);

	/**
	 * Creates an edge and returns a copy of it.
	 */
	Edge addEdge(Node* n1, Node* n2, size_t weight);

	/**
	 * Removes the given edge.
	 */
	void removeEdge(const Edge& e);

	/**
	 * If the graph contains an edge between n1 and n2,
	 * it is removed.
	 */
	void removeEdge(Node* n1, const Node* n2);

	/**
	 * Performs an edge contraction. (see: Wikipedia)
	 */
	Node* contractEdge(const Edge& rem);

	/**
	 * Return the number of nodes in the graph.
	 */
	size_t numNodes() const;
	
	/**
	 * << Operator override for Graph
	 */
	template <typename A>
	friend std::ostream& operator<<(std::ostream& stream, const Graph<A>& graph);

  private:
	NodeContainer nodes_;
};









/** Removes an edge by source and target
 *
 *  @n1 source Node
 *  @n2 target Node
 **/
template <typename NodeLabel> 
void Graph<NodeLabel>::removeEdge(Node* n1, const Node* n2) {

    // Look for the source Node:
    auto edge_ = n1->out_edges.begin();
    while(edge_ != n1->out_edges.end()) {
            if (edge_->first == n2) {
                n1->out_edges.erase(edge_);
                break;
            }
            ++edge_;
        }

}


/** Removes an edge with his edge-object
 *
 *  @e the edge to remove
 **/
template <typename NodeLabel> 
void Graph<NodeLabel>::removeEdge(const Edge& e) {
    // redirect to removeEdge(node n1,node n2)
    removeEdge(e.source,e.target);
}


/** Contracts an edge in this graph.
 *  All successors of the target node (from the edge to contract) becomes
 *  the successors of the start-node. The edge weights will be adopted.
 *  All edges to the target node are redirected to the start-node.
 *  (see: https://de.wikipedia.org/wiki/Kantenkontraktion)
 *
 *  @rem the edge to contract
 *  @return the pointer of the contracted node
 * */
template <typename NodeLabel> typename Graph<NodeLabel>::Node* Graph<NodeLabel>::contractEdge(const Graph<NodeLabel>::Edge& rem) {

	// Find the two nodes on the edge
    auto source_node = rem.source;
    auto target_node = rem.target;
    //std::cout << "\n folgende Kante soll gelöscht werden: " << source_node->label.getComment() << " -> " << target_node->label.getComment();

	// walk the edges of the target node and rewrite the source nodes of the target node to the source node of the edge to be contracted
    auto target_target = target_node->out_edges.begin();
    auto target_targets_end = target_node->out_edges.end();

	// iteration - read out and create new edges in Source-Node
    for (; target_target != target_targets_end; target_target++) {
        //std::cout << "\n readfrom target->target_target :" << (target_node->label).getComment() << " -> " << (target_target->first->label).getComment() << " : schreibe source_node->target_target" << (source_node->label).getComment() << " -> " << (target_target->first->label).getComment() ;
        // create Edge
        addEdge(source_node,target_target->first,target_target->second);
    }

    // delete all edges from the target_node
    target_node->out_edges.clear();

    // Loop for delete the argument-edge source_node->target_node
    auto source_target = source_node->out_edges.begin();
    while(source_target != source_node->out_edges.end()) {
        //std::cout << "\n search source->source_target :" << source_node->label.getComment() << " -> " << source_target->first->label.getComment() << " : ";
        if (source_target->first == target_node) {source_node->out_edges.erase(source_target);
		//cout << "deleted";
		break;}
        ++source_target;
    }
    // Redirect all edges: SUCCESSOR = target_node => SUCCESSOR = source_node
    auto node_beg = nodes_.begin();
    while(node_beg != nodes_.end()) {
        //Loop over all edges from the actual node
        auto edge_beg = node_beg->out_edges.begin();
        while(edge_beg != node_beg->out_edges.end()) {
            if (edge_beg->first == target_node) {
                // Redirect the edge to the source_node
                //auto E = Edge(node_beg.operator->(), source_node, 0);
                std::pair<Node*, size_t> P (source_node,0);
                //addEdge(node_beg,source_node,edge_beg->second);
                node_beg->out_edges.erase(edge_beg);
                node_beg->out_edges.push_back(P);
                continue;
            }
            ++edge_beg;
        }
        ++node_beg;
    }

    return source_node;

}




/** returns a constant of the node-iterator
 */
template <typename NodeLabel> typename Graph<NodeLabel>::node_iterator       Graph<NodeLabel>::beginNodes() {return nodes_.begin();}
/** returns a constant of the node-iterator
 */
template <typename NodeLabel> typename Graph<NodeLabel>::node_iterator       Graph<NodeLabel>::endNodes()   {return nodes_.end();}
/** returns a constant of the node-iterator
 */
template <typename NodeLabel> typename Graph<NodeLabel>::const_node_iterator Graph<NodeLabel>::beginNodes() const {return nodes_.begin();}
/** returns a constant of the node-iterator
 */
template <typename NodeLabel> typename Graph<NodeLabel>::const_node_iterator Graph<NodeLabel>::endNodes()   const {return nodes_.end();}


/** Creates a Graph. All sequences will be added as nodes in the graph.
 *
 *  @new_nodes the vector with the sequences.
 * */
template <typename NodeLabel>
Graph<NodeLabel>::Graph(const std::vector<NodeLabel>& new_nodes) {
    //was soll das Label sein?
    //                   Sequence.toString -> "ATTAG"   <- nodes_element.toString
    //oder getComment   -> "DNA_A"   <- nodes_element.getComment
    //std::cout << "\n Graph erstellen...";
    // iterate the list new_nodes
    for (const NodeLabel &var: new_nodes) {
        //cout << " [" << var.getComment() << "," << var.size() << "]";
        nodes_.push_back(Node(var)); // Erstelle den Knoten und füge ihn ein
    };
    //std::cout << "\n Prüfe ob die Knoten auch eingefügt wurden...";
    //for (Graph::Node &var: nodes_) {
        //cout << " [" << (var.label).getComment() << "]";
    //}

}



/** Inserts a Edge in the graph.
 *
 *  @n1 the pointer to the reference-node
 *  @n2 the pointer to the successor of the reference-node
 *  @weight the weight of this edge
 *  @return the reference-node
 * */
template <typename NodeLabel> typename Graph<NodeLabel>::Edge Graph<NodeLabel>::addEdge(Node* n1, Node* n2, size_t weight ) {
    // select start node and create an edge
    auto E = Edge(n1, n2, weight);
    std::pair<Node*, size_t> P (n2,weight);
    n1->out_edges.push_back(P);
    return E;
}

/** Inserts a Node in the graph.
 *
 *  @label the pointer to the sequence
 *  @n2 the pointer to the successor of the reference-node
 *  @weight the weight of this edge
 * */
template <typename NodeLabel> typename Graph<NodeLabel>::Node* Graph<NodeLabel>::addNode(const NodeLabel& label) {
    auto knoten = Node(label); // create node with label
    nodes_.push_back(Node(label)); // insert node into array
    return knoten;
}


/**
 *  @return the number of the nodes in this graph
 * */
template <typename NodeLabel> size_t  Graph<NodeLabel>::numNodes() const { return nodes_.size(); }


/** Overrides the << Operator for Graph-Classes.
 *  The return output-stream is the graph in Graphviz-Format.
 *
 *  This graph contains the number of nodes, sequences with comments and weight of the edges.
 *
 *  @graph the graph to be output
 *  @stream the stream to be used
 *  @return the graph in Graphviz-Format
 * */
template <typename NodeLabel>
std::ostream& operator<<(std::ostream& stream,const Graph<NodeLabel>& graph)
{
    /* graph representation: (https://de.wikipedia.org/wiki/Graphviz)

        digraph Name {
            nodecount=5
            ...
            A -> G [...]
            H -> F [...]
            Z -> F [...]
        }

    */



    //First line + output attributes
        std::string graphname = "overlapgraph";
        stream << std::string("digraph ") << graphname << std::string(" { \n");
        stream << std::string("     nodecount=") << graph.numNodes() << std::string("\n");
        //stream << "     sequencetype=" << "default" << "\n";

    //output Nodes without outgoing Edges (Impotant to identify all target nodes)
        auto knoten_start = graph.beginNodes();
        auto knoten_ende = graph.endNodes();

        for (; knoten_start != knoten_ende; knoten_start++) {
            if (knoten_start->out_edges.size() == 0) {
                stream << std::string("     ") << knoten_start->label.getComment() << std::string(" [sequence=\"")
                       << knoten_start.operator->()->label << std::string("\"]\n");
            }
        }

	// output Nodes with outgoing Edges (The sequence is also output at the start node)
	// For each node, all edges are listed one after the other
        knoten_start = graph.beginNodes();
        knoten_ende = graph.endNodes();

        for (; knoten_start != knoten_ende; knoten_start++) {
            if (knoten_start->out_edges.size() > 0) {
                auto inside = knoten_start->out_edges.begin();
                for (int i = 0 ; i < (int) knoten_start->out_edges.size() ; i++) {
                    stream << std::string("     ") << knoten_start->label.getComment() << std::string(" -> ")
					 << (inside).operator->()->first->label.getComment() << std::string(" [weight=") 
					 << (inside).operator->()->second << std::string(" predecessor_sequence=\"") << (inside).operator->()->first->label 
					 << std::string("\"]\n");
                    inside++;
                }
            }
        }

    //last line
        stream << std::string("}\n");

    return stream;
}






#endif // BIOINFOI_GRAPH_H

