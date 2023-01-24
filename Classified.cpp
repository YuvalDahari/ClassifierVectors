#include "Classified.h"

void Classified::setApproximation(int defineApproximation) {
    Classified::approximation = defineApproximation;
}

void Classified::setAlgorithm(string &algo) {
    Classified::algorithm = algo;
}

Classified::Classified(int approximation, const DBCreator &db, const string &algorithm) {
    this->approximation = approximation;
    this->db = db;
    this->algorithm = algorithm;
}

string Classified::findDistances(const vector<double> &v) {
    string type;
    const AlgoMap algoMap;
    map<string, Algo *> algorithms = algoMap.getAlgorithms();
    Algo *algo = algorithms.at(this->algorithm);
    vector<pair<string, double>> distances;
    vector<pair<string, vector<double>>> properties = this->db.getObjType().getProperties();
    unsigned long size = properties.size();
    for (unsigned long i = 0; i < size; i++) {
        distances.emplace_back(properties[i].first, algo->distance(properties[i].second, v));
    }
    make_heap(distances.begin(), distances.end(),
              [](const pair<string, double> &pair1, const pair<string, double> &pair2)
                      -> bool { return pair1.second > pair2.second; });

    // if the approximation defined is greater than the size of the database we focus on the closest
    if (distances.size() > (unsigned long) this->approximation) {
        vector<pair<string, double>> kDistances;
        for (int i = 0; i < this->approximation; ++i) {
            kDistances.push_back(distances[0]);
            pop_heap(distances.begin(), distances.end());
        }
        type = identify(kDistances);
    } else {
        type = identify(distances);
    }
    return type;
}

string Classified::identify(const vector<pair<string, double>> &distances) {
    map<string, int> map;
    for (const pair<string, double> &pair: distances) {
        if (map.find(pair.first) != map.end()) {
            map.at(pair.first) = map.at(pair.first) + 1;
        } else {
            map[pair.first] = 0;
        }
    }
    vector<pair < string, int>>
    values(map.begin(), map.end());
    make_heap(values.begin(), values.end(),
              [](const pair<string, double> &pair1, const pair<string, double> &pair2)
                      -> bool { return pair1.second > pair2.second; });
    return values[0].first;
}

Classified::Classified() {
    this->approximation = 5;
    this->algorithm = "AUC";
}

