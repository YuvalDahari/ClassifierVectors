#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    SpecialVector specialVector = HandleIO::createTrainDB(this->receive_data);
    this->DB.setObjType(specialVector);
    finishFirstAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    this->unclassifiedVectors = HandleIO::createTestVectors(this->receive_data);
    finishAnswer();
    updateCommands();
}

void UploadCommand::startAnswer() {
    this->send_data = "Please upload your local train CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}


void UploadCommand::finishFirstAnswer(){
    this->send_data = "Upload Complete.\nPlease upload your local test CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::finishAnswer(){
    this->send_data = "Upload Complete.";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::updateCommands() {
    ClassifyCommand* pClassifyCommand = (ClassifyCommand*)this->commandsMap.at(3);
    pClassifyCommand->setUnclassified(this->unclassifiedVectors);
    pClassifyCommand->getClassifier().setDbCreator(this->DB);
}

UploadCommand::~UploadCommand() = default;
