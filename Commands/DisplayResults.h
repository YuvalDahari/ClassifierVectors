#ifndef CLASSIFIERVECTORS_DISPLAYRESULTS_H
#define CLASSIFIERVECTORS_DISPLAYRESULTS_H

#include "Command.h"
#include "../Sprites/DBCreator.h"

/**
 * a class which manages the option to print the classified results.
 */
class DisplayResults : public Command{
    DBCreator DB;
public:
    /**
    * the function creates new DisplayResults, and initializes with unique description.
    */
    DisplayResults();

    /**
     * the function send all the classified vectors.
     */
    void execute() override;

    /**
     * the function sets new data base.
     * @param classified (DBCreator)
     */
    void setClassified(const DBCreator &classified);

    /**
     * default destructor.
     */
    ~DisplayResults() override;
};

#endif
