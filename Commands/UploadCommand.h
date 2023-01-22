#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"
#include "../Sprites/DBCreator.h"
#include "../Classified.h"
#include "ClassifyCommand.h"

class UploadCommand : public Command{
private:
    DBCreator DB;
    vector<vector<double>> unclassifiedVectors;
public:
    /**
     * constructor for creating a new specific command.
     */
    UploadCommand();
    /**
     * the function .
     */
    void execute() override;

    void startAnswer();

    void finishAnswer();

    void updateCommands();

    /**
     * default destructor.
     */
    ~UploadCommand() override;

    void finishFirstAnswer();
};

#endif
