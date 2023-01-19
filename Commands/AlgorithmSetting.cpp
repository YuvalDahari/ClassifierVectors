#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = "2. algorithm settings\n";
    this->approximation = 5;
    this->algorithm = "AUC";
}

void AlgorithmSetting::execute() {
    correntValues();
    receiveProtocol();
    // TODO: check if the empty work
    if (this->receive_data.empty()) {
        // the user doesn't want to change a thing.
        return;
    }
    int index = HandleIO::CheckAlgoK(this->receive_data);
    if (index < 0) {
        invalidInput(index);
    } else {
        setFields(index, this->receive_data);
    }
}

void AlgorithmSetting::setFields(int index, const string& settings) {
    setApproximation(stoi(settings.substr(0, index)));
    setAlgorithm(settings.substr(index + 2, settings.size()));
}

void AlgorithmSetting::setApproximation(int defineApproximation) {
    AlgorithmSetting::approximation = defineApproximation;
}

void AlgorithmSetting::setAlgorithm(string algo) {
    AlgorithmSetting::algorithm = std::move(algo);
}

int AlgorithmSetting::getApproximation() const {
    return this->approximation;
}

const string &AlgorithmSetting::getAlgorithm() const {
    return this->algorithm;
}

void AlgorithmSetting::correntValues() {
    AlgorithmSetting::send_data = "The current KNN parameters are: K = " + to_string(this->approximation) +
                                  ", distance metric = " + this->algorithm + "\n";
    sendProtocol();
}

void AlgorithmSetting::invalidInput(int indicator) {
    switch (indicator) {
        case INVALID_PARAMETERS:
            this->send_data = "invalid value for K\ninvalid value for metric\n";
            sendProtocol();
            return;
        case INVALID_APPROXIMATION:
            this->send_data = "invalid value for K\n";
            sendProtocol();
            return;
        case INVALID_ALGORITHM:
            this->send_data = "invalid value for metric\n";
            sendProtocol();
            return;
        default:
            return;
    }
}

AlgorithmSetting::~AlgorithmSetting() = default;