#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    // TODO: this function
    SpecialVector specialVector = HandleIO::createTrainDB(this->receive_data);
    this->classified.setObjType(specialVector);
    finishAnswer();
    secondAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    // TODO: this function
    this->unclassified = HandleIO::createTestVectors(this->receive_data);
    finishAnswer();
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
    return classified;
}

const vector<vector<double>> &UploadCommand::getUnclassified() const {
    return unclassified;
}

UploadCommand::~UploadCommand() = default;
