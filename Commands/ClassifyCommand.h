#ifndef CLASSIFIERVECTORS_CLASSIFYCOMMAND_H
#define CLASSIFIERVECTORS_CLASSIFYCOMMAND_H

#include "Command.h"

class ClassifyCommand : public Command{
public:
    /**
    * constructor for creating a new specific command.
     */
    ClassifyCommand();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~ClassifyCommand() override;
};

#endif
