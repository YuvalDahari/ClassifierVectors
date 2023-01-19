#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassifiedVectors csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    SpecialVector specialVector = HandleIO::createTrainDB(this->receive_data);
    this->DB.setObjType(specialVector);
    finishAnswer();
    secondAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    this->unclassifiedVectors = HandleIO::createTestVectors(this->receive_data);
    finishAnswer();
    updateCommands();
}

void UploadCommand::startAnswer() {
    this->send_data = "Please upload your local train CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::secondAnswer() {
    this->send_data = "Please upload your local test CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::finishAnswer(){
    this->send_data = "Upload Complete.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

const DBCreator &UploadCommand::getClassified() const {
    return this->DB;
}

const vector<vector<double>> &UploadCommand::getUnclassified() const {
    return this->unclassifiedVectors;
}

void UploadCommand::updateCommands() {
    ClassifyCommand* pClassifyCommand = (ClassifyCommand*)this->commandsMap.at(3);
    pClassifyCommand->setUnclassified(this->unclassifiedVectors);
    pClassifyCommand->getClassifier().setDbCreator(this->DB);
}

UploadCommand::~UploadCommand() = default;
