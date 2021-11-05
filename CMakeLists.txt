cmake_minimum_required(VERSION 2.8.9)

# Optionen an den Compiler
set(CXX_FLAGS
	-std=c++17               # Verwende den C++17 Standard
	-pedantic                # Achte auf genauere Einhaltung des Standards
	-Wall                    # Aktiviere alle Warnungen
)

# Diese Datei ist so vorkonfiguriert, dass sie auf den Bioinformatik
# CIPs problemlos funktioniert. Sollten Sie Ihren Code auf einem anderen
# Rechner testen wollen müssen sie einen aktuellen Compiler installiert
# haben (clang >= 3.5 || gcc >= 4.9) und cmake folgendermaßen aufrufen
# cmake .. -DUSE_CIPS=OFF -DGTEST_SRC_DIR=/path/to/googletest
option(USE_CIPS "Are we compiling on the Bioinformatics CIPs?" ON)

if(USE_CIPS)
	set(GTEST_SRC_DIR /usr/src/googletest/googletest/)
endif()

project(02_Graph)

add_definitions(${CXX_FLAGS})

# Erstelle die Bibliothek "sequence"
# Bibliotheken sind Codesammlungen, die von mehreren
# Programmen geteilt werden können.
#
# Dies ist für unser Projekt nötig, da wir sowohl
# Unittests, als auch eine ausführbare Anwendung
# erzeugen wollen.
add_library(sequence SHARED
	2Bit.h
	2Bit.cpp
	DNA.h
	DNA.cpp
	Fasta.h
	InvalidCharacter.h
	InvalidCharacter.cpp
	ParsingException.h
	ParsingException.cpp
	Peptide.h
	Peptide.cpp
	RNA.h
	RNA.cpp
	Sequence.h
	Graph.h
	Assembler.h
	Assembler.cpp
	SequenceCombinator.h
)

# Erstelle das Programm "Assembler".
add_executable(Assembler main.cpp)

# Damit convert Ihren Code verwenden kann muss
# die sequence Bibliothek zum Programm "gelinkt" werden.
target_link_libraries(Assembler sequence ${CIP_STD_LIBS})

# Aktiviere die Unittestfunktionalität von CMake.
enable_testing()

# Füge die Google Test Bibliothek zum Projekt hinzu.
add_subdirectory(${GTEST_SRC_DIR} "gtest")

# Füge die Unittests zum Project hinzu.
add_subdirectory(test)
