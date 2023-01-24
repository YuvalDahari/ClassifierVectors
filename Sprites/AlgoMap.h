#ifndef CLASSIFIERVECTORS_ALGOMAP_H
#define CLASSIFIERVECTORS_ALGOMAP_H

#include <string>
#include <map>
#include "../Algorithms/Algo.h"
#include "../Algorithms/EuclideanDistance.h"
#include "../Algorithms/ManhattanGeometry.h"
#include "../Algorithms/ChebyshevDistance.h"
#include "../Algorithms/CanberraDistance.h"
#include "../Algorithms/MinkowskiDistance.h"

using namespace std;

/**
 * a class which represents the algorithms' map.
 */
class AlgoMap {
private:
    map<string, Algo*> algorithms;
public:
    /**
     * the function creates a map of all the distance algorithms.
     */
    AlgoMap();

    /**
     * the function returns the map's algorithms.
     * @return map<string, Algo*> - the map's algorithms.
     */
    const map<string, Algo*> &getAlgorithms() const;

    /**
     * destructor.
     */
    virtual ~AlgoMap();
};

#endif