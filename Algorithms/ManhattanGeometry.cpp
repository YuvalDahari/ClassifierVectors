#include "ManhattanGeometry.h"

double ManhattanGeometry::distance(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v = absDifferenceValues(v1, v2);
    double distance = 0;
    for (double num: v) {
        distance += num;
    }
    return distance;
}

ManhattanGeometry::~ManhattanGeometry() = default;
