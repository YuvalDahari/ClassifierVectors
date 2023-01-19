#include "DownloadResults.h"

DownloadResults::DownloadResults() {
    this->description = "5. download results\n";
}

void DownloadResults::execute() {
    vector<pair<string, vector<double>>> vectors = this->classified.getObjType().getProperties();
    this->send_data = "";
    unsigned long i = 1;
    for (const pair<string,vector<double>>& v:vectors) {
        this->send_data += to_string(i) + "\t" + v.first + "\n";
        i++;
    }
    HandleIO::sendProtocol(this->client_sock, this->send_data);
}

void DownloadResults::setClassified(const DBCreator &classifier) {
    DownloadResults::classified = classifier;
}

DownloadResults::~DownloadResults() = default;

