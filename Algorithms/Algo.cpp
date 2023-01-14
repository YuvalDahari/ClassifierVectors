#include "Algo.h"

vector<double> Algo::absDifferenceValues(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> absVector;
    for (int i = 0; i < v1.size(); ++i) {
        absVector.push_back(abs(v1[i] - v2[i]));
    }
    return absVector;
}

vector<double> Algo::absSumValues(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v;
    for (int i = 0; i < v1.size(); ++i) {
        v.push_back(abs(v1[i]) + abs(v2[i]));
    }
    return v;
}

double Algo::maxAbsValue(const vector<double> &v) const {
    double max = v[0];
    for (double num: v) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

double Algo::distance(const vector<double> &v1, const vector<double> &v2) const { return 0; }

Algo::~Algo() = default;

