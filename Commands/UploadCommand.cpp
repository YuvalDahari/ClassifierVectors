#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "1. upload an unclassified csv data file\n";
}

void UploadCommand::execute() {
    string file;
    int valid;
    setStartAnswer();
    sendProtocol();
    //receive path
    if (HandleIO::checkFile(file) < 0) {
        setInvalid();
        sendProtocol();
        return;
    }
    this->classified = DBCreator(file);
    this;
    setFinishAnswer();
    sendProtocol();
    setSecondAnswer();
    //receive path
    if (HandleIO::checkFile(file) < 0) {
        //setter to db = null;
        setInvalid();
        sendProtocol();
        return;
    }
    this->unclassified =

}

void UploadCommand::setStartAnswer() {
    this->send_data = "Please upload your local train CSV file.\n";
}

void UploadCommand::setFinishAnswer(){
    this->send_data = "Upload Complete.\n";
}

void UploadCommand::setSecondAnswer() {
    this->send_data = "Please upload your local test CSV file.\n";
}

void UploadCommand::setClassified(const DBCreator &classifier) {
    UploadCommand::classified = classifier;
}

void UploadCommand::setUnclassified(const vector<vector<double>> &unclassifier) {
    UploadCommand::unclassified = unclassifier;
}

const DBCreator &UploadCommand::getClassified() const {
    return classified;
}

const vector<vector<double>> &UploadCommand::getUnclassified() const {
    return unclassified;
}

UploadCommand::~UploadCommand() = default;
