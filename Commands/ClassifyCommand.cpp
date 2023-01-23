#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    this->description = "3. classify data\n";
}

void ClassifyCommand::execute() {
    SpecialVector specialVector;
    pair<string, vector<double>> pair;
    specialVector.setLength(this->unclassifiedVectors.at(0).size());
    for (const vector<double> &v: this->unclassifiedVectors) {
        pair = {this->classifier.findDistances(v), v};
        specialVector.getProperties().push_back(pair);
    }
    this->DB.setObjType(specialVector);
    updateCommands();
    finish();
}

Classified ClassifyCommand::getClassifier() const {
    return this->classifier;
}

void ClassifyCommand::setClassifier(const Classified &classified) {
    ClassifyCommand::classifier = classified;
}

void ClassifyCommand::setDb(const DBCreator &db) {
    ClassifyCommand::DB = db;
}

void ClassifyCommand::setUnclassified(const vector<vector<double>> &vector) {
    ClassifyCommand::unclassifiedVectors = vector;
}

void ClassifyCommand::finish() {
    this->sendData = "classifying data complete\n" + this->getMenu();
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void ClassifyCommand::updateCommands() {
    DisplayResults *pDisplayResults = (DisplayResults *) this->commandsMap.at(COMMAND4);
    DownloadResults *pDownloadResults = (DownloadResults *) this->commandsMap.at(COMMAND5);
    pDisplayResults->setClassified(this->DB);
    pDownloadResults->setClassified(this->DB);
}

ClassifyCommand::~ClassifyCommand() = default;