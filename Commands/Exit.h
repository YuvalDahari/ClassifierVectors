#ifndef CLASSIFIERVECTORS_EXIT_H
#define CLASSIFIERVECTORS_EXIT_H

#include "Command.h"

/**
 * a class which manages the option to stop the program.
 */
class Exit : public Command{
public:
    /**
     * the function creates new Exit, and initializes with unique description.
     */
    Exit();

    /**
     * the function close the client connection.
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~Exit() override;
};

#endif
