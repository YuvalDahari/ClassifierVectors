#include "DisplayResults.h"

DisplayResults::DisplayResults() {
    this->description = "4. display results\n";
}

void DisplayResults::execute() {
    vector<pair<string, vector<double>>> vectors = this->DB.getObjType().getProperties();
    this->sendData = "";
    unsigned long i = 1;
    for (const pair<string,vector<double>>& v:vectors) {
        this->sendData += to_string(i) + "\t" + v.first + "\n";
        i++;
    }
    this->sendData += "Done." + this->getMenu();
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void DisplayResults::setClassified(const DBCreator &classifier) {
    DisplayResults::DB = classifier;
}

DisplayResults::~DisplayResults() = default;
