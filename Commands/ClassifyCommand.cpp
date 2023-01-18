#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    this->description = "3. classify data\n";
}

void ClassifyCommand::execute() {

}

const Classified &ClassifyCommand::getClassifier() const {
    return classifier;
}

void ClassifyCommand::setClassifier(const Classified &classify) {
    ClassifyCommand::classifier = classify;
}

const DBCreator &ClassifyCommand::getClassified() const {
    return classified;
}

void ClassifyCommand::setClassified(const DBCreator &classify) {
    ClassifyCommand::classified = classify;
}

const vector<vector<double>> &ClassifyCommand::getUnclassified() const {
    return unclassified;
}

void ClassifyCommand::setUnclassified(const vector<vector<double>> &unclassified) {
    ClassifyCommand::unclassified = unclassified;
}

ClassifyCommand::~ClassifyCommand() = default;