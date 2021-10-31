#include "Assembler.h"

#include <vector>
/*

(2) Die Klasse Assembler soll aus einer Liste von DNA-Sequenzen einen Overlap-Graphen
erzeugen. Verwenden Sie dazu die Klasse Graph und Ihre Sequenzklasse aus Übung 1. Die
Klasse soll hierzu mindenstens die folgende Methode zur Verfügung stellen:

• Assembler(const std::vector<Assembler::Seq>& sequences) erstellt einen OverlapGraphen. Hierzu soll eine gerichtete Kante zwischen zwei beliebigen Knoten erzeugt
werden, wenn die Sequenzen der Knoten eine maximale Überlappung > 0 haben.
Speichern Sie die berechnete Überlappung im Graphen. Verwenden Sie dazu die
Methode overlap Ihrer Sequenzklasse.
Generieren Sie mittels Graphviz und Ihres Ausgabeoperators eine Visualisierung für die
Datei fragments.fasta. Zum Einlesen der Datei sollten Sie Ihre Klasse SequenceFastaReader
aus Übung 1 verwenden

*/

Assembler::Assembler(const std::vector<Assembler::Seq>& sequences){
    /*Assembler::OGraph::Graph(sequences);
    auto knoten_start = .beginNodes();
    auto knoten_ende = graph.endNodes();

        for (; knoten_start != knoten_ende; knoten_start++) {
            if (knoten_start->out_edges.size() == 0) {
                stream << "     " << knoten_start->label.getComment() << " [sequence=\""
                       << knoten_start.operator->()->label << "\"]\n";
            }
        }

    for (const Sequence<Alphabet::DNA>& var : sequences) {
        g.addNode(var);
        for (auto it = Assembler::OGraph::beginNodes(); it != Assembler::OGraph::endNodes(); ++it){
            
            if (var.overlap(it) > 0){
                Assembler::OGraph::addEdge(var, it, var.overlap(it));
            }
            if (it.overlap(var) > 0){
                Assembler::OGraph::addEdge(it, var, it.overlap(var));
            }
        } 
	}*/
    

//void Assembler::readFragments()
}