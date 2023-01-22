#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    cout << receive_data << endl;
    this->DB.setObjType(HandleIO::createTrainDB(this->receive_data));
    finishFirstAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    cout << receive_data << endl;
    this->unclassifiedVectors = HandleIO::createTestVectors(this->receive_data);
    updateCommands();
    finishAnswer();
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
