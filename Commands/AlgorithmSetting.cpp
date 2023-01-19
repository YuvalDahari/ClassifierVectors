#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = "2. algorithm settings\n";
    this->approximation = 5;
    this->algorithm = "AUC";
}

void AlgorithmSetting::execute() {
    currentValues();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    if (this->receive_data == "\n") {
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
    ClassifyCommand* pClassifyCommand = (ClassifyCommand*)this->commandsMap.at(3);
    pClassifyCommand->getClassifier().setApproximation(this->approximation);
    pClassifyCommand->getClassifier().setAlgorithm(this->algorithm);
}

void AlgorithmSetting::setApproximation(int defineApproximation) {
    AlgorithmSetting::approximation = defineApproximation;
}

void AlgorithmSetting::setAlgorithm(string algo) {
    AlgorithmSetting::algorithm = std::move(algo);
}

void AlgorithmSetting::currentValues() {
    AlgorithmSetting::send_data = "The current KNN parameters are: K = " + to_string(this->approximation) +
                                  ", distance metric = " + this->algorithm + "\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void AlgorithmSetting::invalidInput(int indicator) {
    switch (indicator) {
        case INVALID_PARAMETERS:
            this->send_data = "invalid value for K\ninvalid value for metric\n" + this->getMenu();
            HandleIO::sendProtocol(this->client_sock, this->send_data);
            return;
        case INVALID_APPROXIMATION:
            this->send_data = "invalid value for K\n" + this->getMenu();
            HandleIO::sendProtocol(this->client_sock, this->send_data);
            return;
        case INVALID_ALGORITHM:
            this->send_data = "invalid value for metric\n" + this->getMenu();
            HandleIO::sendProtocol(this->client_sock, this->send_data);
            return;
        default:
            return;
    }
}

AlgorithmSetting::~AlgorithmSetting() = default;