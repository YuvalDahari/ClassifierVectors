#ifndef CLASSIFIERVECTORS_DISPLAYRESULTS_H
#define CLASSIFIERVECTORS_DISPLAYRESULTS_H

#include "Command.h"

class DisplayResults : public Command{
public:
    /**
    * constructor for creating a new specific command.
     */
    DisplayResults();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~DisplayResults() override;
};

#endif
