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
    this
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
    this->answer = "Please upload your local train CSV file.\n";
}

void UploadCommand::setFinishAnswer(){
    this->answer = "Upload Complete.\n";
}

void UploadCommand::setSecondAnswer() {
    this->answer = "Please upload your local test CSV file.\n";
}

UploadCommand::~UploadCommand() = default;
