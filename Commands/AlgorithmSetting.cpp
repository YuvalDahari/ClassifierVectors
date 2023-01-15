#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = "2. algorithm settings\n";
    this->approximation = 5;
    this->algorithm = "AUC";
}

void AlgorithmSetting::execute() {
    setGoodAnswer();
    sendProtocol();
    string settings;
    getline(cin, settings);
    if (settings.empty()) {
        return;
    }
    int index = HandleIO::CheckAlgoK(settings);
    if (index < 0) {
        setBadAnswer(index);
        sendProtocol();
    } else {
        setFields(index, settings);
    }
}

void AlgorithmSetting::setFields(int index, string settings) {
    string k;
    string alg;
    k = this.settings.substr(0, index);
    index += 2;
    alg = settings.substr(index, settings.size());
    setApproximation(stoi(k));
    setAlgorithm(alg);
}

void AlgorithmSetting::setApproximation(int defineApproximation) {
    AlgorithmSetting::approximation = defineApproximation;
}

void AlgorithmSetting::setAlgorithm(string algo) {
    AlgorithmSetting::algorithm = algo;
}

void AlgorithmSetting::setGoodAnswer() {
    AlgorithmSetting::answer = "The current KNN parameters are: K = " << this->approximation <<
                                  ", distance metric = " << this->algorithm + "\n";
}

void AlgorithmSetting::setBadAnswer(int indicator) {
    switch (indicator) {
        case -3:
            this->answer = "invalid value for K\ninvalid value for metric\n";
            return;
        case -2:
            this->answer = "invalid value for K\n";
            return;
        case -1:
            this->answer = "invalid value for metric\n";
            return;
    }
}


AlgorithmSetting::~AlgorithmSetting() = default;