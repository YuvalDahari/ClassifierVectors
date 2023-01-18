#include "DownloadResults.h"

DownloadResults::DownloadResults() {
    this->description = "5. download results\n";
}

void DownloadResults::execute() {

}

void DownloadResults::setClassified(const Classified &classifier) {
    DownloadResults::classified = classifier;
}

DownloadResults::~DownloadResults() = default;

