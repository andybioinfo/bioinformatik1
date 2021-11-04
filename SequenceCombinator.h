#ifndef SEQUENCECOMBINATOR_H
#define SEQUENCECOMBINATOR_H

#include "Sequence.h"
#include "DNA.h"
#include "Graph.h"

using SeqList = std::vector<Sequence<Alphabet::DNA>>;

/** Generates a Sequence List as std::vector
 *
 * @generate_empty  -> returns a empty List if true
 * @intervall_start -> start in the given List
 * @intervall_end   -> end in the given List
 * [Range 0 - 9]
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
            ,Sequence<Alphabet::DNA>::fromString("TATATATATATA")
            ,Sequence<Alphabet::DNA>::fromString("GCCGCG")
            ,Sequence<Alphabet::DNA>::fromString("CACATATA")
            ,Sequence<Alphabet::DNA>::fromString("TATACACAGGC")
    };

    sequences[0].setComment("DNA_A");
    sequences[1].setComment("DNA_B");
    sequences[2].setComment("DNA_C");
    sequences[3].setComment("DNA_D");
    sequences[4].setComment("DNA_E");
    sequences[5].setComment("DNA_F");
    sequences[6].setComment("DNA_G");
    sequences[7].setComment("DNA_H");
    sequences[8].setComment("DNA_I");
    sequences[9].setComment("DNA_J");
    /*
    const char* comment[10] = {"DNA_A","DNA_B","DNA_C","DNA_D","DNA_E","DNA_F","DNA_S","DNA_T","DNA_Q","DNA_X"};
    for (int id = 0 ; id < 10 ; id++) {
        sequences[id].setComment(comment[id]);}*/
    int max = 9;
    int start = (intervall_start < 0 || intervall_start > max) ? 0 : intervall_start;
    int end = (intervall_end < intervall_start || intervall_end > max) ? max : intervall_end;
    for (int val = start++ ; val <= end ; val++) {
        List.push_back(sequences[val]);
    }

    return List;
}

#endif // SEQUENCECOMBINATOR_H
