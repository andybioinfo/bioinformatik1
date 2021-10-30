#include "Assembler.h"

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