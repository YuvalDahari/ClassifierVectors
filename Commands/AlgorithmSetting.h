#ifndef CLASSIFIERVECTORS_ALGORITHMSETTING_H
#define CLASSIFIERVECTORS_ALGORITHMSETTING_H

#include "Command.h"

class AlgorithmSetting : public Command{
public:
    /**
     * constructor for creating a new specific command.
     */
    AlgorithmSetting();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~AlgorithmSetting() override;
};

#endif
