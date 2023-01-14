#include "ChebyshevDistance.h"

double ChebyshevDistance::distance(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v = absDifferenceValues(v1, v2);
    return maxAbsValue(v);
}

ChebyshevDistance::~ChebyshevDistance() = default;
