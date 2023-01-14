cmake_minimum_required(VERSION 3.24)
project(ClassifierVectors)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vectors_Sockets HandleIO.h HandleIO.cpp Algorithms/Algo.h Algorithms/Algo.cpp Algorithms/EuclideanDistance.h Algorithms/EuclideanDistance.cpp Algorithms/ManhattanGeometry.h Algorithms/ManhattanGeometry.cpp Algorithms/ChebyshevDistance.h Algorithms/ChebyshevDistance.cpp Algorithms/CanberraDistance.h Algorithms/CanberraDistance.cpp Algorithms/MinkowskiDistance.h Algorithms/MinkowskiDistance.cpp Classified.h Classified.cpp Sprites/DBCreator.h Sprites/DBCreator.cpp Sprites/SpecialVector.h Sprites/SpecialVector.cpp Sprites/AlgoMap.cpp Sprites/AlgoMap.h Client.cpp Server.cpp)