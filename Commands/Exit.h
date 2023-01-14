#ifndef CLASSIFIERVECTORS_EXIT_H
#define CLASSIFIERVECTORS_EXIT_H

#include "Command.h"

class Exit : public Command{
public:
    /**
    * constructor for creating a new specific command.
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
