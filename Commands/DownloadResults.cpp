#include "DownloadResults.h"

DownloadResults::DownloadResults() {
    this->description = "5. download results\n";
    this->classified = Classified(5, DBCreator(), "AUC");
}

void DownloadResults::execute() {

}

DownloadResults::~DownloadResults() = default;

