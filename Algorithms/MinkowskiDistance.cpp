#include "MinkowskiDistance.h"

double MinkowskiDistance::distance(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v = absDifferenceValues(v1, v2);
    double distance = 0;
    for (double num: v) {
        // P is defined.
        distance += pow(num, P);
    }
    distance = pow(distance, 1.0 / P);
    return distance;
}

MinkowskiDistance::~MinkowskiDistance() = default;
