#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : public Command{
public:
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~UploadCommand() override;
};

#endif
