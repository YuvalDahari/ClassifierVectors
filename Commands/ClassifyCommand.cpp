#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    this->description = "3. classify data\n";
}

void ClassifyCommand::execute() {
    SpecialVector specialVector;
    pair<string,vector<double>> pair;
    specialVector.setLength(this->unclassified.at(0).size());
    for (const vector<double>& v: this->unclassified) {
        pair = {this->classifier.findDistances(v), v};
        specialVector.getProperties().push_back(pair);
    }
    this->classified.setObjType(specialVector);
    finish();
}

const Classified &ClassifyCommand::getClassifier() const {
    return this->classifier;
}

void ClassifyCommand::setClassifier(const Classified &classify) {
    ClassifyCommand::classifier = classify;
}

const DBCreator &ClassifyCommand::getClassified() const {
    return this->classified;
}

void ClassifyCommand::setClassified(const DBCreator &classify) {
    ClassifyCommand::classified = classify;
}

const vector<vector<double>> &ClassifyCommand::getUnclassified() const {
    return this->unclassified;
}

void ClassifyCommand::setUnclassified(const vector<vector<double>> &unclassify) {
    ClassifyCommand::unclassified = unclassify;
}

void ClassifyCommand::finish() {
    this->send_data = "classifying data complete";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

ClassifyCommand::~ClassifyCommand() = default;