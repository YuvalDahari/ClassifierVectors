#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"
#include "../Sprites/DBCreator.h"
#include "../Classified.h"

class UploadCommand : public Command{
private:
    DBCreator classified;
    DBCreator unclassified;
public:
    /**
     * constructor for creating a new specific command.
     */
    UploadCommand();
    /**
     * the function .
     */
    void execute() override;

    void setStartAnswer();

    void setFinishAnswer();

    /**
     * default destructor.
     */
    ~UploadCommand() override;

    void setSecondAnswer();
};

#endif
