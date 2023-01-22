#include "DBCreator.h"

DBCreator::DBCreator() = default;

DBCreator::DBCreator(const string& fileName) {
    ifstream file(fileName);
    string line;
    getline(file, line);

    // extract the length of the first vector, for comparing it with the other attributes in the file
    this->objType.setLength(HandleIO::lengthExtract(line));
    do {
        this->objType.getProperties().push_back(HandleIO::pairExtract(line, this->objType.getLength()));
    } while (getline(file, line));
}

SpecialVector DBCreator::getObjType() {
    return this->objType;
}

void DBCreator::setObjType(const SpecialVector &obj) {
    DBCreator::objType = obj;
}
