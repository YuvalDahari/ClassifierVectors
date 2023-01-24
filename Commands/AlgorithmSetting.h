#ifndef CLASSIFIERVECTORS_ALGORITHMSETTING_H
#define CLASSIFIERVECTORS_ALGORITHMSETTING_H

#include "Command.h"
#include "ClassifyCommand.h"

#define DEFAULT_APPROXIMATION 5
#define DEFAULT_ALGORITHM "AUC"

/**
 * a class which manages the option to set different arguments for classification.
 */
class AlgorithmSetting : public Command {
private:
    int approximation;
    string algorithm;
public:
    /**
     * the function creates new AlgorithmSetting, and initializes it with default arguments and it's unique description.
     */
    AlgorithmSetting();

    /**
     * the function calls functions to get and check the user input and works according to the input.
     */
    void execute() override;

    /**
     * the function return the current approximation.
     * @return int - current approximation.
     */
    int getApproximation() const;

    /**
     * the function return the current algorithm's key.
     * @return string - current algorithm's key.
     */
    const string &getAlgorithm() const;

    /**
    * the function manages the update of the class's values.
    * @param index (int)
    * @param settings (string)
    */
    void setFields(int index, const string &settings);

    /**
     * the function sets new approximation.
     * @param defineApproximation (int)
     */
    void setApproximation(int defineApproximation);

    /**
    * the function sets new algorithm.
    * @param algo (string)
    */
    void setAlgorithm(string algo);

    /**
     * the function send the current values of the approximation and given algorithm.
     */
    void currentValues();

    /**
     * the function checks the input and change the class's values if it's valid, else it's send a message according to
     * the invalid input's type.
     * @param indicator (int)
     */
    void invalidInput(int indicator);

    /**
     * default destructor.
     */
    ~AlgorithmSetting() override;
};

#endif
