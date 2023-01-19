#ifndef CLASSIFIERVECTORS_CLASSIFYCOMMAND_H
#define CLASSIFIERVECTORS_CLASSIFYCOMMAND_H

#include "Command.h"
#include "../Classified.h"

class ClassifyCommand : public Command{
private:
    Classified classifier;
    DBCreator classified;
    vector<vector<double>> unclassified;
public:
    const Classified &getClassifier() const;

    void setClassifier(const Classified &classifier);

    const DBCreator &getClassified() const;

    void setClassified(const DBCreator &classified);

    const vector<vector<double>> &getUnclassified() const;

    void setUnclassified(const vector<vector<double>> &unclassified);
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
};

#endif
