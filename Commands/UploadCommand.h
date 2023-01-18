#ifndef CLASSIFIERVECTORS_UPLOADCOMMAND_H
#define CLASSIFIERVECTORS_UPLOADCOMMAND_H

#include "Command.h"
#include "../Sprites/DBCreator.h"
#include "../Classified.h"

class UploadCommand : public Command{
private:
    DBCreator classified;
public:
    const DBCreator &getClassified() const;

    const vector<vector<double>> &getUnclassified() const;

private:
    vector<vector<double>> unclassified;
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

    void setClassified(const DBCreator &classified);

    void setUnclassified(const vector<vector<double>> &unclassified);
};

#endif
