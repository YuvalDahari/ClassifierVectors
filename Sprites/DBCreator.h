#ifndef CLASSIFIER_VECTORS_DBCREATOR_H
#define CLASSIFIER_VECTORS_DBCREATOR_H

#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "SpecialVector.h"
#include "../HandleIO.h"

/**
 * a class which represents the classified objects.
 */
class DBCreator {
private:
    SpecialVector objType;
public:
    /**
     * constructor for creating a new data base according to default's constructor.
     */
    DBCreator();

    /**
     * constructor for creating a new data base via file.
     * @param fileName (const string)
     */
    explicit DBCreator(const string& fileName);

    /**
     * the function returns a SpecialVector's instance.
     * @return SpecialVector - a SpecialVector's instance.
     */
    SpecialVector getObjType();
};

#endif
