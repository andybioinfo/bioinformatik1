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

project(bayes)

set(CMAKE_CXX_STANDARD 17)

add_definitions(${CXX_FLAGS})

# Erstelle die Bibliothek "snp"
# Bibliotheken sind Codesammlungen, die von mehreren
# Programmen geteilt werden können.
#
# Dies ist für unser Projekt nötig, da wir sowohl
# Unittests, als auch eine ausführbare Anwendung
# erzeugen wollen.
add_library(snpbib SHARED
        console/Style.cpp
        console/Style.h
        console/console.h
        console/console.cpp
        console/Format.cpp
        console/Format.h
        console/Color.cpp
        console/Color.h
        matrix/Matrix.h
        matrix/Matrix.cpp
        snipper/States.h
        snipper/SingleSNP.cpp
        snipper/SingleSNP.h
        snipper/Classifics.cpp
        snipper/Classifics.h
        snipper/SnipperMain.cpp
        snipper/Snipper.h
        snipper/SnipperFile.cpp
        snipper/SnipperAlgorithm.cpp
        Examples.cpp
        Examples.h

        main.cpp
        BayesMain.cpp
        BayesAlgorithm.cpp
        BayesFile.cpp
        NaiveBayes.h
        Block.cpp
        Block.h

        Model.cpp Model.h)

# Erstelle das Programm "snipper".
add_executable(bayes main.cpp Statistics.cpp)

target_link_libraries(bayes snpbib ${CIP_STD_LIBS})


