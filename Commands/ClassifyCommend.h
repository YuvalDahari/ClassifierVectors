#ifndef CLASSIFIERVECTORS_CLASSIFYCOMMEND_H
#define CLASSIFIERVECTORS_CLASSIFYCOMMEND_H

#include "Command.h"

class ClassifyCommend : public Command{
public:
    /**
    * constructor for creating a new specific command.
     */
    ClassifyCommend();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~ClassifyCommend() override;
};

#endif
