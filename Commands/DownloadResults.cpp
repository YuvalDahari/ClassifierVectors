#include "DownloadResults.h"

DownloadResults::DownloadResults() {
    this->description = "5. download results\n";
}

void DownloadResults::execute() {
    vector<pair<string, vector<double>>> vectors = this->DB.getObjType().getProperties();
    this->sendData = "";
    unsigned long i = 1;
    for (const pair<string,vector<double>>& v:vectors) {
        this->sendData += to_string(i) + "," + v.first + "\n";
        i++;
    }
    this->sendData += this->getMenu();
    HandleIO::sendProtocol(this->clientSock, this->sendData);
}

void DownloadResults::setClassified(const DBCreator &classifier) {
    DownloadResults::DB = classifier;
}

DownloadResults::~DownloadResults() = default;

