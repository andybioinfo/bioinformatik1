cmake_minimum_required(VERSION 2.8.9)

set(CXX_FLAGS
        -std=c++17               # Verwende den C++17 Standard
        -pedantic                # Achte auf genauere Einhaltung des Standards
        -Wall                    # Aktiviere alle Warnungen
)

option(USE_CIPS "Are we compiling on the Bioinformatics CIPs?" ON)

if(USE_CIPS)
        set(GTEST_SRC_DIR /usr/src/googletest/googletest/)
	set(GUROBI_LIBRARIES /opt/gurobi912/linux64/lib/libgurobi_g++5.2.a /opt/gurobi912/linux64/lib/libgurobi91.so)
endif()

project(07_ILPs)

add_definitions(${CXX_FLAGS})

add_executable(example example.cpp)
target_link_libraries(example ${CIP_STD_LIBS} ${GUROBI_LIBRARIES})

add_executable(shortestPath shortestPath.cpp)
target_link_libraries(shortestPath ${CIP_STD_LIBS} ${GUROBI_LIBRARIES})


enable_testing()
add_subdirectory(${GTEST_SRC_DIR} "gtest")
add_subdirectory(test)

