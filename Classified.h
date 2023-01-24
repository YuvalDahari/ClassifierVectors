#ifndef CLASSIFIERVECTORS_CLASSIFIED_H
#define CLASSIFIERVECTORS_CLASSIFIED_H

#include "Sprites/DBCreator.h"
#include "Algorithms/Algo.h"
#include <algorithm>
#include <map>

/**
 * a class which manages the classification of new vector of elements.
 */
class Classified {
private:
    int approximation;
    DBCreator db;
    string algorithm;
public:
    /**
     * the function creates new classifier with default values.
     */
    Classified();

    /**
     * the function creates new classifier according to given values.
     * @param approximation (int)
     * @param db (DBCreator)
     * @param algorithm (string)
     */
    Classified(int approximation, const DBCreator &db, const string &algorithm);

    /**
     * the function sets a new approximation.
     * @param defineApproximation (int)
     */
    void setApproximation(int defineApproximation);

    /**
     * the function sets a new algorithm.
     * @param algo (string)
     */
    void setAlgorithm(string &algo);

    /**
     * the function calculates the distances between the input vector and our data base's vectors.
     * @param v (vector<double>)
     * @return string - the type of the vector.
     */
    string findDistances(const vector<double> &v);

    /**
     * the function receives a vector of the k closest distances and identifies the type of the most appeared pair type.
     * @param distances (vector<pair<string, double>>)
     * @return string - the type of the vector.
     */
    string identify(const vector<pair<string, double>> &distances);
};

#endif
