#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = "2. algorithm settings\n";
    this->approximation = 5;
    this->algorithm = "EUC";
}

void AlgorithmSetting::execute() {
    string settings;
    string k;
    string alg;
    getline(cin, settings);
    if (settings.empty()) {
        return;
    }
    int index = HandleIO::CheckAlgoK(settings);
    switch (index) {
        case -3:
            //send two msgs to client
            break;
        case -2:
            //send invalid k
            break;
        case -1:
            //send invalid alg
            break;
        default:
            k = settings.substr(0, index);
            index+=2;
            alg = settings.substr(index, settings.size());
            setApproximation(stoi(k));
            setAlgorithm(alg);
    }
}

void AlgorithmSetting::setApproximation(int defineApproximation) {
    AlgorithmSetting::approximation = defineApproximation;
}

void AlgorithmSetting::setAlgorithm(string algo) {
    AlgorithmSetting::algorithm = algo;
}

AlgorithmSetting::~AlgorithmSetting() = default;