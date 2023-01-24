#ifndef CLASSIFIERVECTORS_CLASSIFYCOMMAND_H
#define CLASSIFIERVECTORS_CLASSIFYCOMMAND_H

#include "Command.h"
#include "../Classified.h"
#include "DisplayResults.h"
#include "DownloadResults.h"

/**
 * a class which manages the option to classify given data base.
 */
class ClassifyCommand : public Command{
private:
    Classified classifier;
    DBCreator DB;
    vector<vector<double>> unclassifiedVectors;
public:
    /**
     * the function creates new ClassifyCommand, and initializes with unique description.
    */
    ClassifyCommand();

    /**
     * the function classify the class's unclassified vector.
     */
    void execute() override;

    /**
     * the function return the classifier of the class.
     * @return Classified - the classifier of the class.
     */
    Classified getClassifier() const;

    /**
     * the function sets new vector of unclassified vectors.
     * @param vector (vector<vector<double>>)
     */
    void setUnclassified(const vector<vector<double>> &vector);

    /**
     * the function sets new classifier.
     * @param classified (Classified)
     */
    void setClassifier(const Classified &classified);

    /**
     * the function sets new data base.
     * @param db (DBCreator)
     */
    void setDb(const DBCreator &db);

    /**
     * the function updates all the commands which holding a data base member.
     */
    void updateCommands();

    /**
     * the function notifies the user that the classification is done.
     */
    void finish();

    /**
     * default destructor.
     */
    ~ClassifyCommand() override;
};

#endif
