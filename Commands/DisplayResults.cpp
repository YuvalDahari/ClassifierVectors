#include "DisplayResults.h"

DisplayResults::DisplayResults() {
    this->description = "4. display results\n";
}

void DisplayResults::execute() {

}

void DisplayResults::setClassified(const DBCreator &classifier) {
    DisplayResults::classified = classifier;
}

DisplayResults::~DisplayResults() = default;
