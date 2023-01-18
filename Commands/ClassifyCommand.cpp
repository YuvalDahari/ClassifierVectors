#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    this->description = "3. classify data\n";
    this->classifier = Classified(5, DBCreator(),"AUC");
    this->classified = DBCreator();
}

void ClassifyCommand::execute() {

}

const Classified &ClassifyCommand::getClassifier() const {
    return classifier;
}

void ClassifyCommand::setClassifier(const Classified &classifier) {
    ClassifyCommand::classifier = classifier;
}

const DBCreator &ClassifyCommand::getClassified() const {
    return classified;
}

void ClassifyCommand::setClassified(const DBCreator &classified) {
    ClassifyCommand::classified = classified;
}

const vector<vector<double>> &ClassifyCommand::getUnclassified() const {
    return unclassified;
}

void ClassifyCommand::setUnclassified(const vector<vector<double>> &unclassified) {
    ClassifyCommand::unclassified = unclassified;
}

ClassifyCommand::~ClassifyCommand() = default;