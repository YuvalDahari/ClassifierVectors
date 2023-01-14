#include "EuclideanDistance.h"

double EuclideanDistance::distance(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v = absDifferenceValues(v1, v2);
    double distance = 0;
    for (double num: v) {
        distance += num * num;
    }

    distance = sqrt(distance);
    return distance;
}

EuclideanDistance::~EuclideanDistance() = default;
