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

project(snipper)

set(CMAKE_CXX_STANDARD 17)

add_definitions(${CXX_FLAGS})

# Erstelle die Bibliothek "snp"
# Bibliotheken sind Codesammlungen, die von mehreren
# Programmen geteilt werden können.
#
# Dies ist für unser Projekt nötig, da wir sowohl
# Unittests, als auch eine ausführbare Anwendung
# erzeugen wollen.
add_library(snp SHARED
        main.cpp
        States.h
        SingleSNP.cpp
        SingleSNP.h
        Classifics.cpp
        Classifics.h
        SnipperMain.cpp
        Snipper.h
        SnipperFile.cpp
        console/Style.cpp
        console/Style.h
        console/console.h
        console/console.cpp
        console/Format.cpp
        console/Format.h
        console/Color.cpp
        console/Color.h

        SnipperAlgorithm.cpp)

# Erstelle das Programm "snipper".
add_executable(snipper main.cpp )

# Damit convert Ihren Code verwenden kann muss
# die sequence Bibliothek zum Programm "gelinkt" werden.
target_link_libraries(snipper snp ${CIP_STD_LIBS})

# Aktiviere die Unittestfunktionalität von CMake.
enable_testing()

add_subdirectory(${GTEST_SRC_DIR} "gtest")
add_subdirectory(test)

