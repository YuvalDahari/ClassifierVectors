#include "SpecialVector.h"

unsigned long SpecialVector::getLength() const {
    return this->length;
}

vector<pair<string, vector<double>>> &SpecialVector::getProperties() {
    return this->properties;
}

void SpecialVector::setLength(unsigned long newLength) {
    SpecialVector::length = newLength;
}
