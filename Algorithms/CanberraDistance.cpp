#include "CanberraDistance.h"

double CanberraDistance::distance(const vector<double> &v1, const vector<double> &v2) const {
    vector<double> v = absDifferenceValues(v1, v2);
    vector<double> divider = absSumValues(v1, v2);
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        // if we have 2 zeros values we adding zero to the sum.
        if (divider[i] != 0) {
            sum += v[i] / divider[i];
        }
    }
    return sum;
}

CanberraDistance::~CanberraDistance() = default;
