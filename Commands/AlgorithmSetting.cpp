#include "AlgorithmSetting.h"

AlgorithmSetting::AlgorithmSetting() {
    this->description = "2. algorithm settings\n";
    this->approximation = DEFAULT_APPROXIMATION;
    this->algorithm = DEFAULT_ALGORITHM;
}

void AlgorithmSetting::execute() {
    currentValues();
    HandleIO::receiveProtocol(this->clientSock, this->receiveData);
    if (this->receiveData == "-1") {
        // the user doesn't want to change a thing.
        AlgorithmSetting::sendData = this->getMenu();
        HandleIO::sendProtocol(this->clientSock, this->sendData);
        return;
    }
    int index = HandleIO::CheckAlgoK(this->receiveData);
    if (index < 0) {
        invalidInput(index);
    } else {
        setFields(index, this->receiveData);
        AlgorithmSetting::sendData = this->getMenu();
        HandleIO::sendProtocol(this->clientSock, this->sendData);
    }
}

void AlgorithmSetting::setFields(int index, const string& settings) {
    string string1 = settings.substr(0, index + 1);
    string string2 = settings.substr(index + 2, settings.size() - 1);
    if (HandleIO::extractApproximation(string1) < 0) {
        setApproximation(stoi(string2));
        setAlgorithm(string1);
    } else {
        setApproximation(stoi(string1));
        setAlgorithm(string2);
    }
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
    AlgorithmSetting::sendData = "The current KNN parameters are: K = " + to_string(this->approximation) +
                                 ", distance metric = " + this->algorithm + "\n";
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void AlgorithmSetting::invalidInput(int indicator) {
    switch (indicator) {
        case INVALID_PARAMETERS:
            this->sendData = "invalid value for K\ninvalid value for metric\n" + this->getMenu();
            HandleIO::sendProtocol(this->clientSock, this->sendData);
            return;
        case INVALID_APPROXIMATION:
            this->sendData = "invalid value for K\n" + this->getMenu();
            HandleIO::sendProtocol(this->clientSock, this->sendData);
            return;
        case INVALID_ALGORITHM:
            this->sendData = "invalid value for metric\n" + this->getMenu();
            HandleIO::sendProtocol(this->clientSock, this->sendData);
            return;
        default:
            return;
    }
}

AlgorithmSetting::~AlgorithmSetting() = default;