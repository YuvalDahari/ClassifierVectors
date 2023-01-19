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
    unsigned long length;
    vector<pair<string, vector<double>>> properties;

public:
    /**
     * the function gets the number of attributes.
     * @return unsigned long - length.
     */
    unsigned long getLength() const;

    /**
     * the function sets a new length of attributes.
     * @param newLength (unsigned long)
     * */
    void setLength(unsigned long newLength);

    /**
     * the function gets all the properties.
     * @return vector<pair<string, vector<double>>> - all the properties.
     */
    vector<std::pair<string, vector<double>>> &getProperties();
};

#endif
