#ifndef BIOINFOI_GRAPH_H
#define BIOINFOI_GRAPH_H

#include <algorithm>
#include <list>
#include <memory>
#include <vector>


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
	 * If the graph contains an edge betwenn n1 and n2,
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

  private:
	NodeContainer nodes_;
};




/*
	Konstruktor mit DNA-(Liste bzw Vector): Erstellt einen Graphen,
	der Knoten mit den übergebenen Labels beinhalten soll.

    was soll das Label sein?
    Sequence.toString -> "ATTAG"   <- nodes_element.toString
    oder getComment   -> "DNA_A"   <- nodes_element.getComment

*/
template <typename NodeLabel>
Graph<NodeLabel>::Graph(const std::vector<NodeLabel>& new_nodes) {
    std::cout << "\n Graph erstellen...";
    // Durchlaufe die Liste new_nodes
    for (const Sequence <Alphabet::DNA> &var: new_nodes) {
        cout << " [" << var.getComment() << "," << var.size() << "]";
        nodes_.push_back(Node(var)); // Erstelle den Knoten und füge ihn ein
    }
    std::cout << "\n Prüfe ob die Knoten auch eingefügt wurden...";
    for (Graph::Node &var: nodes_) {
        cout << " [" << (var.label).getComment() << "]";
    }

}

/*
    Fügt einen neuen Knoten mit entsprechendem Label in den Graphen ein.
*/

template <typename NodeLabel> typename Graph<NodeLabel>::Node* Graph<NodeLabel>::addNode(const NodeLabel& label) {
    auto knoten = Node(label); // Knoten mit Label erstellen
    nodes_.push_back(Node(label)); // Knoten in Array einfügen
    return knoten;
}





/*
	• Node* contractEdge(const Edge& rem) führt eine Kantenkontraktion durch. Dabei wird eine Kante entfernt und die beiden anliegenden Knoten werden zu einem
	neuen Knoten vereinigt. (siehe: https://de.wikipedia.org/wiki/Kantenkontraktion)
	Kontrahiert zwei Knoten zu einem und gibt den neuen Knoten zurück
	(https://de.wikipedia.org/wiki/Kantenkontraktion)
	[Noch überarbeiten]
*/

template <typename NodeLabel> typename Graph<NodeLabel>::Node* Graph<NodeLabel>::contractEdge(const Graph<NodeLabel>::Edge& rem) {

// Ermittle die beiden Knoten der Kante
auto source_node = rem.source;
auto target_node = rem.target;
cout << "\n folgende Kante soll gelöscht werden: " << source_node->label.getComment() << " -> " << target_node->label.getComment();

// laufe die Kanten des Zielknoten ab und schreibe die source-Knoten des target-Knoten zum source-Knoten der zu kontraktierenden Kante um
auto nodeB1 = target_node->out_edges.begin();
auto nodeB2 = target_node->out_edges.end();


return NULL;

}






/*
	• void removeEdge(Node* n1, const Node* n2) löscht die Kante zwischen Knoten
	n1 und Knoten n2.
*/
template <typename NodeLabel> 
void Graph<NodeLabel>::removeEdge(Node* n1, const Node* n2) {};


/*
	• void removeEdge(const Edge& e) löscht die entsprechende Kante.
*/
template <typename NodeLabel> 
void Graph<NodeLabel>::removeEdge(const Edge& e) {};





/*#################### FERTIGE METHODEN ###################### */

// + Iterator
// + AddNode ( ?? )
// + Graphviz-Ausgabe
// + AddEdge
//
/*
	Iteratoren für die Knotenliste.
	[Fehlerfrei, noch nicht getestet]
*/
template <typename NodeLabel> typename Graph<NodeLabel>::node_iterator       Graph<NodeLabel>::beginNodes() {return nodes_.begin();}
template <typename NodeLabel> typename Graph<NodeLabel>::node_iterator       Graph<NodeLabel>::endNodes()   {return nodes_.end();}
template <typename NodeLabel> typename Graph<NodeLabel>::const_node_iterator Graph<NodeLabel>::beginNodes() const {return nodes_.begin();}
template <typename NodeLabel> typename Graph<NodeLabel>::const_node_iterator Graph<NodeLabel>::endNodes()   const {return nodes_.end();}


/*
   Füge eine Kante zwischen 2 Knoten ein
*/
template <typename NodeLabel>
typename Graph<NodeLabel>::Edge Graph<NodeLabel>::addEdge(Node* n1, Node* n2, size_t weight ) {
    // Startknoten auswählen und eine Kante erstellen
    auto E = Edge(n1, n2, weight);
    std::pair<Node*, size_t> P (n2,weight);
    n1->out_edges.push_back(P);
    return E;
}


/*
	Gibt die Anzahl der Knoten mithilfe der Listenlänge std::list.size zurück
	[Fertig implementiert und ausprobiert]
*/
template <typename NodeLabel> size_t  Graph<NodeLabel>::numNodes() const { return nodes_.size(); }


/*
	Sendet den Graphen im Graphvix-Format in den outstream
	[funktioniert + getestet]
*/
template <typename NodeLabel>
std::ostream& operator<<(std::ostream& stream,const Graph<NodeLabel>& graph)
{
    /* Graphdarstellung: (https://de.wikipedia.org/wiki/Graphviz)

        digraph Name {
            nodecount=5
            ...
            A -> G [...]
            H -> F [...]
            Z -> F [...]
        }

    */



    //Erste Zeile + Attribute ausgeben
        std::string graphname = "overlapgraph";
        stream << "digraph " << graphname << " { \n";
        stream << "     nodecount=" << graph.numNodes() << "\n";
        //stream << "     sequencetype=" << "default" << "\n";

    //Knoten ausgeben, die keine ausgehenden Kanten haben ( Wichtig um auch alle Zielknoten zu identifizieren )
        auto knoten_start = graph.beginNodes();
        auto knoten_ende = graph.endNodes();

        for (; knoten_start != knoten_ende; knoten_start++) {
            if (knoten_start->out_edges.size() == 0) {
                stream << "     " << knoten_start->label.getComment() << " [sequence=\""
                       << knoten_start.operator->()->label << "\"]\n";
            }
        }

    //Knoten ausgeben, mit mindestens einer ausgehenden Kante ( Beim Startknoten wird zusätzlich die Sequenz ausgegeben )
    //FÜr jeden KNoten werden nacheinander alle Kanten aufgelistet
        knoten_start = graph.beginNodes();
        knoten_ende = graph.endNodes();

        for (; knoten_start != knoten_ende; knoten_start++) {
            if (knoten_start->out_edges.size() > 0) {
                auto inside = knoten_start->out_edges.begin();
                for (int i = 0 ; i < knoten_start->out_edges.size() ; i++) {
                    stream << "     " << knoten_start->label.getComment() << " -> " << (inside).operator->()->first->label.getComment()
                           << " [weight=" << (inside).operator->()->second << " predecessor_sequence=\"" << (inside).operator->()->first->label << "\"]\n";
                    inside++;
                }
            }
        }

    //Schlusszeile
        stream << "}\n";

    return stream;
}






#endif // BIOINFOI_GRAPH_H

