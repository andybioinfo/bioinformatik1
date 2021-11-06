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

	        ,Sequence<Alphabet::DNA>::fromString("TCACTCATCTTATCACTCATCCAAATTATACACAGCAGCAGCATATCTATCACT")
	        ,Sequence<Alphabet::DNA>::fromString("ATAGGCTCGGATTAGCGGTATGCGTGGGGATTATGCGAGTCG")
	        ,Sequence<Alphabet::DNA>::fromString("ATCTACTAACAGCA")
	        ,Sequence<Alphabet::DNA>::fromString("GATGCTATCGATCGATACGACATAGCATACATACGCATACTACTACGCAGCAGCATCACATCTCACTCATCTT")
	        ,Sequence<Alphabet::DNA>::fromString("GCAGCATATCTATCACTAACGCAGCACGATAATCAGACCATCTACGACGACGAGACCGCACGACGACATTCAA")
	        ,Sequence<Alphabet::DNA>::fromString("TGCGAGTCGGCTAGCTATATATCGCGCTAATAGCTGATGCTATCGATCGATACGACAT")
	        ,Sequence<Alphabet::DNA>::fromString("GACCGCACGACGACATTCAATCACAGACAACTATCATACGCGATAATCAGCACGATCATCATCACTACTATCTACTA")
	        ,Sequence<Alphabet::DNA>::fromString("ACTGCGATGGCGATCGGATCGATAGGCT")

	        ,Sequence<Alphabet::DNA>::fromString("CTTTGC")
	        ,Sequence<Alphabet::DNA>::fromString("CATAC")
	        ,Sequence<Alphabet::DNA>::fromString("GGTCGCGACAA")
	        ,Sequence<Alphabet::DNA>::fromString("TTGCCGGTCG")
	        ,Sequence<Alphabet::DNA>::fromString("ACCATCTT")
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
	sequences[10].setComment("1");
	sequences[11].setComment("2");
	sequences[12].setComment("3");
	sequences[13].setComment("4");
	sequences[14].setComment("5");
	sequences[15].setComment("6");
	sequences[16].setComment("7");
	sequences[17].setComment("8");

	sequences[18].setComment("F.A");
	sequences[19].setComment("F.B");
	sequences[20].setComment("F.C");
	sequences[21].setComment("F.D");
	sequences[22].setComment("F.E");

    int max = 22;
    int start = (intervall_start < 0 || intervall_start > max) ? 0 : intervall_start;
    int end = (intervall_end < intervall_start || intervall_end > max) ? max : intervall_end;
    for (int val = start++ ; val <= end ; val++) {
        List.push_back(sequences[val]);
    }

    return List;
}

#endif // SEQUENCECOMBINATOR_H
