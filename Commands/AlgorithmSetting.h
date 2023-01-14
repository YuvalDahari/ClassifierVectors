#ifndef CLASSIFIERVECTORS_ALGORITHMSETTING_H
#define CLASSIFIERVECTORS_ALGORITHMSETTING_H

#include "Command.h"

/**
 * a class which manages the option to set different arguments for classification.
 */
class AlgorithmSetting : public Command {
private:
    int approximation;
    string algorithm;

public:
    /**
     * constructor for creating a new specific command.
     */
    AlgorithmSetting();

    /**
     * the function call functions to get and check the user input and works according to the input.
     */
    void execute() override;

    /**
     * the function sets a new approximation.
     * @param defineApproximation (int)
     */
    void setApproximation(int defineApproximation);

    /**
    * the function sets a new algorithm.
    * @param algo (string)
    */
    void setAlgorithm(string algo);

    /**
     * default destructor.
     */
    ~AlgorithmSetting() override;
};

#endif
