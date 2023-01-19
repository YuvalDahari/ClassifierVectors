#ifndef CLASSIFIERVECTORS_DISPLAYRESULTS_H
#define CLASSIFIERVECTORS_DISPLAYRESULTS_H

#include "Command.h"
#include "../Sprites/DBCreator.h"

class DisplayResults : public Command{
    DBCreator DB;
public:
    void setClassified(const DBCreator &classified);

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
