#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"
#include "../Sprites/DBCreator.h"
#include "../Classified.h"

class UploadCommand : public Command{
private:
    DBCreator classified;
    vector<vector<double>> unclassified;
public:
    const DBCreator &getClassified() const;

    const vector<vector<double>> &getUnclassified() const;

    /**
     * constructor for creating a new specific command.
     */
    UploadCommand();
    /**
     * the function .
     */
    void execute() override;

    void startAnswer();

    void secondAnswer();

    void finishAnswer();

    /**
     * default destructor.
     */
    ~UploadCommand() override;
};

#endif
