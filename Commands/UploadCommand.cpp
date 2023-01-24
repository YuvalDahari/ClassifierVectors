#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "Welcome to the KNN Classifier Server. Please choose an option:\n"
                        "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->clientSock, this->receiveData);
    cout << receiveData << endl;
    this->DB.setObjType(HandleIO::createTrainDB(this->receiveData));
    finishFirstAnswer();
    HandleIO::receiveProtocol(this->clientSock, this->receiveData);
    this->unclassifiedVectors = HandleIO::createTestVectors(this->receiveData);
    updateCommands();
    finishAnswer();
}

void UploadCommand::startAnswer() {
    this->sendData = "Please upload your local train CSV file.\n";
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}


void UploadCommand::finishFirstAnswer() {
    this->sendData = "Upload Complete.\nPlease upload your local test CSV file.\n";
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void UploadCommand::finishAnswer() {
    this->sendData = "Upload Complete.\n" + this->getMenu();
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void UploadCommand::updateCommands() {
    ClassifyCommand *pClassifyCommand = (ClassifyCommand *) this->commandsMap.at(COMMAND3);
    AlgorithmSetting *pSettingCommand = (AlgorithmSetting *) this->commandsMap.at(COMMAND2);
    Classifier c = Classifier(pSettingCommand->getApproximation(), this->DB, pSettingCommand->getAlgorithm());
    pClassifyCommand->setClassifier(c);
    pClassifyCommand->setDb(DBCreator());
    pClassifyCommand->setUnclassified(this->unclassifiedVectors);
}

UploadCommand::~UploadCommand() = default;
