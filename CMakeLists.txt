cmake_minimum_required(VERSION 2.8.9)

# Optionen an den Compiler
set(CXX_FLAGS
	-std=c++17               # Verwende den C++17 Standard
	-pedantic                # Achte auf genauere Einhaltung des Standards
	-Wall                    # Aktiviere alle Warnungen
)


project(UB5_Sequence_Alignment)

add_definitions(${CXX_FLAGS})

# Erstelle die Bibliothek "sequence"
# Bibliotheken sind Codesammlungen, die von mehreren
# Programmen geteilt werden können.
#
# Dies ist für unser Projekt nötig, da wir sowohl
# Unittests, als auch eine ausführbare Anwendung
# erzeugen wollen.
add_library(sequence SHARED

	sequence/DNA.h
	sequence/DNA.cpp
	sequence/Fasta.h
	sequence/InvalidCharacter.h
	sequence/InvalidCharacter.cpp
	sequence/ParsingException.h
	sequence/ParsingException.cpp
	sequence/Peptide.h
	sequence/Peptide.cpp
	sequence/RNA.h
	sequence/RNA.cpp
	sequence/Sequence.h
	sequence/SequenceCombinator.h
		Matrix.h
		Distance.h
		EditDistance.h
		Alignment.h
		Alignment.cpp
		
	)

# Erstelle das Programm "Align".
add_executable(align main.cpp )

# Damit convert Ihren Code verwenden kann muss
# die sequence Bibliothek zum Programm "gelinkt" werden.
target_link_libraries(align sequence ${CIP_STD_LIBS})



