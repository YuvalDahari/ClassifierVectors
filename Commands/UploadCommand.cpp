#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    startAnswer();
    receiveProtocol();
    // TODO: this function
    SpecialVector specialVector = HandleIO::createTrainDB(this->receive_data);
    this->classified.setObjType(specialVector);
    finishAnswer();
    secondAnswer();
    receiveProtocol();
    // TODO: this function
    this->unclassified = HandleIO::createTestVectors(this->receive_data);
    finishAnswer();
}

void UploadCommand::startAnswer() {
    this->send_data = "Please upload your local train CSV file.\n";
    sendProtocol();
}

void UploadCommand::secondAnswer() {
    this->send_data = "Please upload your local test CSV file.\n";
    sendProtocol();
}

void UploadCommand::finishAnswer(){
    this->send_data = "Upload Complete.\n";
    sendProtocol();
}

const DBCreator &UploadCommand::getClassified() const {
    return classified;
}

const vector<vector<double>> &UploadCommand::getUnclassified() const {
    return unclassified;
}

UploadCommand::~UploadCommand() = default;
