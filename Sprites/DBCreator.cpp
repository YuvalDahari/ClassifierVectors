#include "DBCreator.h"

DBCreator::DBCreator() = default;

DBCreator::DBCreator(const string& fileName) {
    HandleIO handleIO;
    ifstream file(fileName);
    string line;
    getline(file, line);

    // extract the length of the first vector, for comparing it with the other attributes in the file
    this->objType.setLength(handleIO.lengthExtract(line));
    do {
        this->objType.getProperties().push_back(handleIO.pairExtract(line, this->objType.getLength()));
    } while (getline(file, line));
}

SpecialVector DBCreator::getObjType() {
    return this->objType;
}