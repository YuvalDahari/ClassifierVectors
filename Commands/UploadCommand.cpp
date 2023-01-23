#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = DESCRIPTION_1;
}

void UploadCommand::execute() {
    startAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    this->DB.setObjType(HandleIO::createTrainDB(this->receive_data));
    finishFirstAnswer();
    HandleIO::receiveProtocol(this->client_sock, this->receive_data);
    this->unclassifiedVectors = HandleIO::createTestVectors(this->receive_data);
    updateCommands();
    finishAnswer();
}

void UploadCommand::startAnswer() {
    this->send_data = "Please upload your local train CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}


void UploadCommand::finishFirstAnswer() {
    this->send_data = "Upload Complete.\nPlease upload your local test CSV file.\n";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::finishAnswer() {
    this->send_data = "Upload Complete.\n" + this->getMenu();
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void UploadCommand::updateCommands() {
    ClassifyCommand *pClassifyCommand = (ClassifyCommand *) this->commandsMap.at(COMMAND3);
    AlgorithmSetting *pSettingCommand = (AlgorithmSetting *) this->commandsMap.at(COMMAND2);
    Classified c = Classified(pSettingCommand->getApproximation(), this->DB, pSettingCommand->getAlgorithm());
    pClassifyCommand->setClassifier(c);
    pClassifyCommand->setDb(DBCreator());
    pClassifyCommand->setUnclassified(this->unclassifiedVectors);
}

UploadCommand::~UploadCommand() = default;
