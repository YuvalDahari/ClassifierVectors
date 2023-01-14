#include "SpecialVector.h"

int SpecialVector::getLength() const {
    return this->length;
}

vector<pair<string, vector<double>>> &SpecialVector::getProperties() {
    return this->properties;
}

void SpecialVector::setLength(int newLength) {
    SpecialVector::length = newLength;
}
