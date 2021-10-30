/*
 *
 * Tester für Übung 2
 * 
 *
 *
*/

using namespace std;


#include <iostream>
#include <string>
#include <ostream>
#include "InvalidCharacter.h"
#include "InvalidCharacter.cpp"
#include "DNA.h"
#include "DNA.cpp"
#include "RNA.h"
#include "Peptide.h"
#include "Fasta.h"
#include "Sequence.h"
#include "Graph.h"

using SeqList = std::vector<Sequence<Alphabet::DNA>>;

SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty);

int main() {
    cout << " - Bioinfo1 Uebung 2 - \n\n" << endl;

    cout << " => Print out: \n\n " << 'b' << endl;
string S = "E";

 Sequence<Alphabet::DNA> A = Sequence<Alphabet::DNA>::fromString("TAAGC");
 Sequence<Alphabet::DNA> B = Sequence<Alphabet::DNA>::fromString("AA");
 Sequence<Alphabet::DNA> C = Sequence<Alphabet::DNA>::fromString("TAGC");
 Sequence<Alphabet::DNA> D = Sequence<Alphabet::DNA>::fromString("TAGC");
 Sequence<Alphabet::DNA> E = Sequence<Alphabet::DNA>::fromString("AAAAA");
 Sequence<Alphabet::DNA> F = Sequence<Alphabet::DNA>::fromString("TA");
 A.setComment("DNA_A");
 B.setComment("DNA_B");
 C.setComment("DNA_C");
 D.setComment("DNA_D");
 E.setComment("DNA_E");
 F.setComment("DNA_F");



 cout << "\n DNA := " << A.toString() << " Name: " << A.getComment();
 cout << "\n DNA := " << B.toString() << " Name: " << B.getComment();

std::vector<Sequence<Alphabet::DNA>> List;
List.push_back(A);
List.push_back(B);
List.push_back(C);
List.push_back(D);
List.push_back(E);
List.push_back(F);
    cout << "\n DNA List := ";
    for (const Sequence<Alphabet::DNA>& var : List) {
        cout << " [" << var.getComment() << "," << var.size() << "]";
    }

    cout << "\n DNA overlap-Matrix := ";
    cout << "\n\n x  A  B  C  D  E  F";
    char letter[] = {'A','B','C','D','E','F'};
    int pos = 0;

    for (const Sequence<Alphabet::DNA>& zeile : List) {
        cout << "\n " << letter[pos]; pos++;
        for (const Sequence<Alphabet::DNA>& spalte : List) {
            cout << "  " << zeile.overlap(spalte);
        }
    }

    Graph<Sequence<Alphabet::DNA>> G(List);



    cout << "\n\n\n Graph: ";
    cout << "\n nodecount: " << G.numNodes();

    /*ITERATOR TEST*/
    auto start = G.beginNodes();


    auto destination = G.endNodes();
    G.addEdge((start++).operator->(),(--destination).operator->(),10);
    G.addEdge((start).operator->(),(--destination).operator->(),31);
    G.addEdge((start).operator->(),(--destination).operator->(),100);
    G.addEdge((start).operator->(),(--destination).operator->(),60);
    G.addEdge((start++).operator->(),(--destination).operator->(),99);start++;
    G.addEdge((start).operator->(),(--destination).operator->(),999);
    start = G.beginNodes();
    destination = G.endNodes();

        for (; start != destination; start++) {
            cout << "\n iter " << (start->label).getComment() << " OUT : (" << start->out_edges.size() << ")";
            auto inside = start->out_edges.begin();
            for (int i = 0 ; i < start->out_edges.size() ; i++) {cout << " " << (inside).operator->()->first->label.getComment() << "|" << (inside++).operator->()->second;}
        }

        start = G.beginNodes(); // reset
    cout << "\n after iter " << ((start)->label).getComment();

    cout << "\n________________________\n ";

    cout << "\n\b Kantenkontraktion Test:";
    Graph<Sequence<Alphabet::DNA>>::Edge EE(G.beginNodes().operator->(),(--destination).operator->(),100);

    G.contractEdge(EE);


}
/* Generates a Sequence List as std::vector
 *
 * generate_empty  -> returns a empty List if true
 * intervall_start -> start in the given List
 * intervall_end   -> end in the given List
 * [Range 0 - 6]
 * */



SeqList SequenceCombinator(int intervall_start,int intervall_end,bool generate_empty) {
    std::vector<Sequence<Alphabet::DNA>> List;
    if (generate_empty) {return List;}
        Sequence<Alphabet::DNA> sequences[] = {
                                         Sequence<Alphabet::DNA>::fromString("TAAGC")
                                        ,Sequence<Alphabet::DNA>::fromString("AA")
                                        ,Sequence<Alphabet::DNA>::fromString("TAGC")
                                        ,Sequence<Alphabet::DNA>::fromString("TAGC")
                                        ,Sequence<Alphabet::DNA>::fromString("AAAAA")
                                        ,Sequence<Alphabet::DNA>::fromString("TA")
                                    };

    std::string comment[] = {"DNA_A","DNA_B","DNA_C","DNA_D","DNA_E","DNA_F","DNA_G","DNA_H","DNA_I","DNA_J"};
    for (int id = 0 ; id < 6 ; id++) {
        sequences[id].setComment(comment[id]);}
    int max = 5;
    int start = (intervall_start < 0 || intervall_start > max) ? 0 : intervall_start;
    int end = (intervall_end < intervall_start || intervall_end > max) ? max : intervall_end;
    for (int val = start ; val <= end ; val++) {
        List.push_back(sequences[val]);
    }

    return List;
}



