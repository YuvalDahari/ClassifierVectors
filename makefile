all: Server.exe Client.exe

Server.exe: Server.o HandleIO.o Classified.o DBCreator.o SpecialVector.o AlgoMap.o Algo.o CanberraDistance.o ChebyshevDistance.o EuclideanDistance.o ManhattanGeometry.o MinkowskiDistance.o Command.o UploadCommand.o AlgorithmSetting.o ClassifyCommand.o DisplayResults.o DownloadResults.o Exit.o CommandsMap.o CLI.o
	g++ -std=c++11 Server.o HandleIO.o Classified.o DBCreator.o SpecialVector.o AlgoMap.o Algo.o CanberraDistance.o ChebyshevDistance.o EuclideanDistance.o ManhattanGeometry.o MinkowskiDistance.o Command.o UploadCommand.o AlgorithmSetting.o ClassifyCommand.o DisplayResults.o DownloadResults.o Exit.o CommandsMap.o CLI.o -o server.out

Server.o: Server.cpp HandleIO.h Classified.h Sprites/DBCreator.h Sprites/SpecialVector.h Sprites/AlgoMap.h Algorithms/Algo.h Algorithms/CanberraDistance.h Algorithms/ChebyshevDistance.h Algorithms/EuclideanDistance.h Algorithms/ManhattanGeometry.h Algorithms/MinkowskiDistance.h Commands/Command.h Commands/UploadCommand.h Commands/AlgorithmSetting.h Commands/ClassifyCommand.h Commands/DisplayResults.h Commands/DownloadResults.h Commands/Exit.h Sprites/CommandsMap.h Sprites/CLI.h
	g++ -std=c++11 -c Server.cpp

Client.exe: Client.o HandleIO.o Classified.o DBCreator.o SpecialVector.o AlgoMap.o Algo.o CanberraDistance.o ChebyshevDistance.o EuclideanDistance.o ManhattanGeometry.o MinkowskiDistance.o Command.o UploadCommand.o AlgorithmSetting.o ClassifyCommand.o DisplayResults.o DownloadResults.o Exit.o CommandsMap.o CLI.o
	g++ -std=c++11 Client.o HandleIO.o Classified.o DBCreator.o SpecialVector.o AlgoMap.o Algo.o CanberraDistance.o ChebyshevDistance.o EuclideanDistance.o ManhattanGeometry.o MinkowskiDistance.o Command.o UploadCommand.o AlgorithmSetting.o ClassifyCommand.o DisplayResults.o DownloadResults.o Exit.o CommandsMap.o CLI.o -o client.out

Client.o: Client.cpp HandleIO.h Classified.h Sprites/DBCreator.h Sprites/SpecialVector.h Sprites/AlgoMap.h Algorithms/Algo.h Algorithms/CanberraDistance.h Algorithms/ChebyshevDistance.h Algorithms/EuclideanDistance.h Algorithms/ManhattanGeometry.h Algorithms/MinkowskiDistance.h Commands/Command.h Commands/UploadCommand.h Commands/AlgorithmSetting.h Commands/ClassifyCommand.h Commands/DisplayResults.h Commands/DownloadResults.h Commands/Exit.h Sprites/CommandsMap.h Sprites/CLI.h
	g++ -std=c++11 -c Client.cpp

HandleIO.o: HandleIO.cpp HandleIO.h
	g++ -std=c++11 -c HandleIO.cpp

Classified.o: Classified.cpp Classified.h
	g++ -std=c++11 -c Classified.cpp

DBCreator.o: Sprites/DBCreator.cpp Sprites/DBCreator.h
	g++ -std=c++11 -c Sprites/DBCreator.cpp

SpecialVector.o: Sprites/SpecialVector.cpp Sprites/SpecialVector.h
	g++ -std=c++11 -c Sprites/SpecialVector.cpp

AlgoMap.o: Sprites/AlgoMap.cpp Sprites/AlgoMap.h
	g++ -std=c++11 -c Sprites/AlgoMap.cpp

Algo.o: Algorithms/Algo.cpp Algorithms/Algo.h
	g++ -std=c++11 -c Algorithms/Algo.cpp

CanberraDistance.o: Algorithms/CanberraDistance.cpp Algorithms/CanberraDistance.h
	g++ -std=c++11 -c Algorithms/CanberraDistance.cpp

ChebyshevDistance.o: Algorithms/ChebyshevDistance.cpp Algorithms/ChebyshevDistance.h
	g++ -std=c++11 -c Algorithms/ChebyshevDistance.cpp

EuclideanDistance.o: Algorithms/EuclideanDistance.cpp Algorithms/EuclideanDistance.h
	g++ -std=c++11 -c Algorithms/EuclideanDistance.cpp

ManhattanGeometry.o: Algorithms/ManhattanGeometry.cpp Algorithms/ManhattanGeometry.h
	g++ -std=c++11 -c Algorithms/ManhattanGeometry.cpp

MinkowskiDistance.o: Algorithms/MinkowskiDistance.cpp Algorithms/MinkowskiDistance.h
	g++ -std=c++11 -c Algorithms/MinkowskiDistance.cpp

Command.o: Commands/Command.cpp Commands/Command.h
	g++ -std=c++11 -c Commands/Command.cpp

UploadCommand.o: Commands/UploadCommand.cpp Commands/UploadCommand.h
	g++ -std=c++11 -c Commands/UploadCommand.cpp

AlgorithmSetting.o: Commands/AlgorithmSetting.cpp Commands/AlgorithmSetting.h
	g++ -std=c++11 -c Commands/AlgorithmSetting.cpp

ClassifyCommand.o: Commands/ClassifyCommand.cpp Commands/ClassifyCommand.h
	g++ -std=c++11 -c Commands/ClassifyCommand.cpp

DisplayResults.o: Commands/DisplayResults.cpp Commands/DisplayResults.h
	g++ -std=c++11 -c Commands/DisplayResults.cpp

DownloadResults.o: Commands/DownloadResults.cpp Commands/DownloadResults.h
	g++ -std=c++11 -c Commands/DownloadResults.cpp

Exit.o: Commands/Exit.cpp Commands/Exit.h
	g++ -std=c++11 -c Commands/Exit.cpp

CommandsMap.o: Sprites/CommandsMap.cpp Sprites/CommandsMap.h
	g++ -std=c++11 -c Sprites/CommandsMap.cpp

CLI.o: Sprites/CLI.cpp Sprites/CLI.h
	g++ -std=c++11 -c Sprites/CLI.cpp
