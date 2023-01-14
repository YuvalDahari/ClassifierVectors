#ifndef CLASSIFIERVECTORS_MANHATTANGEOMETRY_H
#define CLASSIFIERVECTORS_MANHATTANGEOMETRY_H

#include "Algo.h"

/**
 * a class which inherits from Algo class, and implements the distance logics.
 */
class ManhattanGeometry : public Algo {
public:
    /**
     * the function calculates the distance between the vectors according to manhattan algorithm.
     * @param v1 (const vector<double>)
     * @param v2 (const vector<double>)
     * @return double - the distance between the two vectors according to manhattan algorithm.
     */
    double distance(const vector<double> &v1, const vector<double> &v2) const override;

    /**
     * default destructor.
     */
    ~ManhattanGeometry() override;
};

#endif
