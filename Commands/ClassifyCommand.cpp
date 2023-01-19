#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    this->description = "3. classify data\n";
}

void ClassifyCommand::execute() {
    SpecialVector specialVector;
    pair<string,vector<double>> pair;
    specialVector.setLength(this->unclassifiedVectors.at(0).size());
    for (const vector<double>& v: this->unclassifiedVectors) {
        pair = {this->classifier.findDistances(v), v};
        specialVector.getProperties().push_back(pair);
    }
    this->DB.setObjType(specialVector);
    finish();
    updateCommands();
}

Classified ClassifyCommand::getClassifier() const {
    return this->classifier;
}

void ClassifyCommand::setUnclassified(const vector<vector<double>> &unclassify) {
    ClassifyCommand::unclassifiedVectors = unclassify;
}

void ClassifyCommand::finish() {
    this->send_data = "classifying data complete\n" + this->getMenu();
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void ClassifyCommand::updateCommands() {
    DisplayResults* pDisplayResults = (DisplayResults*)this->commandsMap.at(4);
    DownloadResults* pDownloadResults = (DownloadResults*)this->commandsMap.at(5);
    pDisplayResults->setClassified(this->DB);
    pDownloadResults->setClassified(this->DB);
}

ClassifyCommand::~ClassifyCommand() = default;