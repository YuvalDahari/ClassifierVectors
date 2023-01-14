#include "AlgoMap.h"

AlgoMap::AlgoMap() {
    this->algorithms["AUC"] = new EuclideanDistance;
    this->algorithms["MAN"] = new ManhattanGeometry;
    this->algorithms["CHB"] = new ChebyshevDistance;
    this->algorithms["CAN"] = new CanberraDistance;
    this->algorithms["MIN"] = new MinkowskiDistance;
}

const map<string, Algo *> &AlgoMap::getAlgorithms() const {
    return this->algorithms;
}

AlgoMap::~AlgoMap() {
    for (const pair<const basic_string<char>, Algo*>& algorithm : this->algorithms) {
        delete(algorithm.second);
    }
}