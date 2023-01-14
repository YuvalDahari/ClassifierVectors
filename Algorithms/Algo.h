#ifndef CLASSIFIER_VECTORS_ALGO_H
#define CLASSIFIER_VECTORS_ALGO_H

// a constant for the minkowski distance algorithm
#define P 2

#include <vector>
#include <cmath>

using namespace std;

/**
 * a virtual class which is the base for all the distance algorithms' classes.
 */
class Algo {
public:
    /**
    * a virtual function which calculates the distance between the vectors.
    * @param v1 (const vector<double>)
    * @param v2 (const vector<double>)
    * @return double - the distance between the two vectors according to the child's algorithm.
    */
    virtual double distance(const vector<double> &v1, const vector<double> &v2) const = 0;

    /**
     * the function calculates the differences between the values of the vectors.
     * @param v1 (const vector<double>)
     * @param v2 (const vector<double>)
     * @return vector<double> - a new vector which is the difference between the two vectors' values.
     */
    vector<double> absDifferenceValues(const vector<double> &v1, const vector<double> &v2) const;

    /**
     * the function calculates the sum between the absolute values of the vectors.
     * @param v1 (const vector<double>)
     * @param v2 (const vector<double>)
     * @return vector<double> - a new vector of the sum between the two vectors' absolute values.
     */
    vector<double> absSumValues(const vector<double> &v1, const vector<double> &v2) const;

    /**
    * the function calculates the maximum sum between the absolute values of the vectors.
    * @param v (const vector<double>)
    * @return double - the maximum sum between the absolute values of the vectors.
    */
    double maxAbsValue(const vector<double> &v) const;

    /**
     * a virtual function of destructor.
     */
    virtual ~Algo();
};

#endif
