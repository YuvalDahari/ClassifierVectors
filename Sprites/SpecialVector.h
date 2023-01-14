#ifndef CLASSIFIERVECTORS_SPECIALVECTOR_H
#define CLASSIFIERVECTORS_SPECIALVECTOR_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

/**
 * a class which represents a classified list of objects of the same length of attributes.
 */
class SpecialVector {
private:
    int length;
    vector<pair<string, vector<double>>> properties;

public:
    /**
     * the function gets the number of attributes.
     * @return int - length.
     */
    int getLength() const;

    /**
     * the function sets a new length of attributes.
     * @param newLength (int)     */
    void setLength(int newLength);

    /**
     * the function gets all the properties.
     * @return vector<pair<string, vector<double>>> - all the properties.
     */
    vector<std::pair<string, vector<double>>> &getProperties();
};

#endif
