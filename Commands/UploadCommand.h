#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"
#include "../Sprites/DBCreator.h"
#include "../Sprites/Classifier.h"
#include "ClassifyCommand.h"
#include "AlgorithmSetting.h"

/**
 * a class which manages the uploads of the classified and unclassified files.
 */
class UploadCommand : public Command{
private:
    DBCreator DB;
    vector<vector<double>> unclassifiedVectors;
public:
    /**
     * the function creates new UploadCommand, and initializes with unique description.
     */
    UploadCommand();

    /**
     * the function load the data from the client and creates data base according to the classified data, and then
     * creates a vector according to the unclassified data.
     */
    void execute() override;

    /**
     * the function send the first massage to the client.
     */
    void startAnswer();

    /**
     * the function notifies the user that the upload was complete (part 1).
     */
    void finishAnswer();

    /**
     * the function notifies the user that the upload was complete (part 2).
     */
    void finishFirstAnswer();

    /**
     * the function updates all the commands which holding a data base member.
     */
    void updateCommands();

    /**
     * default destructor.
     */
    ~UploadCommand() override;
};

#endif
