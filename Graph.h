#ifndef SHORT_GRAPH_H
#define SHORT_GRAPH_H

#include <list>
#include <sstream>
#include <fstream>
#include <vector>


class Edge {
public:
    Edge(int source, int target, int weight);
    int source;
    int target;
    int weight;
    friend std::ostream& operator<<(std::ostream& out, const Edge& e);
};

std::ostream &operator<<(std::ostream &out, const Edge& e) {
    out << "E[ " << e.source << " -> " << e.target << " w: " << e.weight << " ]";
    return out;
}

Edge::Edge(int source, int target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}






class Node {
public:
    Node(int id, std::string label);
    int id;
    std::string label;
    friend std::ostream& operator<<(std::ostream& out, const Node& c);
};

Node::Node(int id, std::string label) {
    this->id = id;
    this->label = label;
}

std::ostream &operator<<(std::ostream &out, const Node& c){
    out << "N[ " << c.id << " ; " << c.label << " ]";
    return out;
}




class Graph {

    public:
        static Graph createFromAdjacencyMatrixFile(std::string filename);
        std::vector<Node> getNodes();
        std::vector<Node*> getPath();
        void addToPath(Node* _node);
        std::vector<Edge> getEdges();
        std::string pathToString();
        int stringToID(std::string nodestr);
        int getEdgeWeight(int start, int target);


    private:
        std::vector<Node> _nodes;
        std::vector<Edge> _edges;
        std::vector<Node*> _path;

};



/*
 * Builds a graph from a adjacency-matrix file. All edges have the weight-values from the matrix-values

 * @filename A file as adjacency-matrix 
 * @return the graph from the file
 *
 * */
Graph Graph::createFromAdjacencyMatrixFile(std::string filename) {

    // ## Create empty Graph

        Graph G;

    // ## Variables

        std::ifstream input(filename);
        char c;
        int node_id = 0;
        std::stringstream buffer("");

    // ## read first line:

        while(input.get(c)) {

            // ignore the following whitespace chars:
            if (c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' ) {continue;}

            // is c a limiter -> next Node & break first line reading
            if (c == '\n' || c == ',') {
                if (buffer.str() != "") {
                    Node n(node_id,buffer.str());
                    G._nodes.push_back(n);
                    node_id++;
                }
                buffer.str("");
                if (c == '\n') {break;} else {continue;}
            }

            // add c to the actual node label
            buffer << c ;

        }

    // ## read the remain matrix

        int row = 0;
        int col = 0;
        bool end = true;

        while(input.get(c)) {

            // ignore the following whitespace chars:
            if (c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' ) {continue;}

            // is c a limiter -> next Edge & break first line reading
            if (c == ',' || c == '\n' || c == EOF) {
                if (buffer.str() != "") {
                    int weight = stoi(buffer.str());
                    //cout << "(" << weight << ")";
                    if (weight != 0) {  Edge e(row,col-1,weight);
                                        G._edges.push_back(e);
                    }

                }
                buffer.str("");
                if (c == '\n') {row++;col = 0;} else {col++;continue;}
            }

            // add c to the actual node label
            if (isdigit(c)) {buffer << c;}

        }


        if (buffer.str() != "") {
            int weight = stoi(buffer.str());
           // cout << "(" << weight << ")";
            if (weight != 0) {  Edge e(row,col-1,weight);
                                G._edges.push_back(e); }
        }

        input.close();

    return G;
}




/*
 * returns the nodes-list
 * @return
 *
 * */
std::vector<Node> Graph::getNodes() {
    return _nodes;
}

/*
 * returns the edges-list
 * @return 
 *
 * */
std::vector<Edge> Graph::getEdges() {
    return _edges;
}

/*
 * returns the path
 * @return path
 *
 * */
std::vector<Node*> Graph::getPath() {
    return _path;
}


/*
 * returns the node_id to a given string
 * @return node_id
 *
 * */
int Graph::stringToID(std::string nodestr) {

    for (auto n : _nodes) {
        if (n.label == nodestr) {return n.id;}

    }
    return -1;
}


int Graph::getEdgeWeight(int start, int target){
    for (auto e : _edges) {
        if (e.source == start && e.target == target){return e.weight;}
    }
    return -1;
}




/*
 * Adds a node to the path
 * @_node node-pointer
 *
 * */
void Graph::addToPath(Node *_node) {
    _path.push_back(_node);
}




/*
 * Creates a string for the path in the format:
 * A -> B
 * B -> C
 * ...
 *
 * @return the path as string
 *
 * */
std::string Graph::pathToString() {
    std::stringstream ss("");
    int length = _path.size();
    int pos = 1;
    if (length == 0) {return "[empty]\n";} else if (length == 1) {ss << _path[0]->label << "\n"; return ss.str();} else if (length == 2) {ss << _path[0]->label << " -> " << _path[1]->label << "\n"; return ss.str();}

    ss << _path[0]->label << " -> ";

    while ( pos < length-1) { ss << _path[pos]->label << "\n" <<  _path[pos]->label << " -> "; pos++;

    }

    ss << _path[length-1]->label << "\n";


    return ss.str();
}



#endif //SHORT_GRAPH_H
