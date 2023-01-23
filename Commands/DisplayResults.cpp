#include "DisplayResults.h"

DisplayResults::DisplayResults() {
    this->description = "4. display results\n";
}

void DisplayResults::execute() {
    vector<pair<string, vector<double>>> vectors = this->DB.getObjType().getProperties();
    this->send_data = "";
    unsigned long i = 1;
    for (const pair<string,vector<double>>& v:vectors) {
        this->send_data += to_string(i) + "\t" + v.first + "\n";
        i++;
    }
    this->send_data += "Done.";
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void DisplayResults::setClassified(const DBCreator &classifier) {
    DisplayResults::DB = classifier;
}

DisplayResults::~DisplayResults() = default;
