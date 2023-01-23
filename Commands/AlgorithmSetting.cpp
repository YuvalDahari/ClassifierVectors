#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = DESCRIPTION_2;
    this->approximation = DEFAULT_APPROXIMATION;
    this->algorithm = DEFAULT_ALGORITHM;
}

void AlgorithmSetting::execute() {
    currentValues();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    if (this->receive_data == "-1") {
        // the user doesn't want to change a thing.
        AlgorithmSetting::send_data = this->getMenu();
        HandleIO::sendProtocol(this->client_sock, this->send_data);
        return;
    }
    int index = HandleIO::CheckAlgoK(this->receive_data);
    if (index < 0) {
        invalidInput(index);
    } else {
        setFields(index, this->receive_data);
        AlgorithmSetting::send_data = this->getMenu();
        HandleIO::sendProtocol(this->client_sock, this->send_data);
    }
}

void AlgorithmSetting::setFields(int index, const string& settings) {
    setApproximation(stoi(settings.substr(0, index + 1)));
    setAlgorithm(settings.substr(index + 2, settings.size() - 1));
    ClassifyCommand* pClassifyCommand = (ClassifyCommand*)this->commandsMap.at(COMMAND3);
    pClassifyCommand->getClassifier().setApproximation(this->approximation);
    pClassifyCommand->getClassifier().setAlgorithm(this->algorithm);
}

void AlgorithmSetting::setApproximation(int defineApproximation) {
    AlgorithmSetting::approximation = defineApproximation;
}

void AlgorithmSetting::setAlgorithm(string algo) {
    AlgorithmSetting::algorithm = std::move(algo);
}

int AlgorithmSetting::getApproximation() const {
    return AlgorithmSetting::approximation;
}

const string &AlgorithmSetting::getAlgorithm() const {
    return AlgorithmSetting::algorithm;
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