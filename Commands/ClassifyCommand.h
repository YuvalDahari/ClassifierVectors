#ifndef CLASSIFIERVECTORS_CLASSIFYCOMMAND_H
#define CLASSIFIERVECTORS_CLASSIFYCOMMAND_H

#include "Command.h"
#include "../Classified.h"
#include "DisplayResults.h"
#include "DownloadResults.h"

class ClassifyCommand : public Command{
private:
    Classified classifier;
    DBCreator DB;
    vector<vector<double>> unclassifiedVectors;
public:
    Classified getClassifier() const;

    void updateCommands();

    void setUnclassified(const vector<vector<double>> &vector);
    /**
    * constructor for creating a new specific command.
     */
    ClassifyCommand();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~ClassifyCommand() override;

    void finish();

    void setClassifier(const Classified &classified);

    void setDb(const DBCreator &db);
};

#endif
