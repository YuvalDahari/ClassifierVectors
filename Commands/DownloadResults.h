#ifndef CLASSIFIERVECTORS_DOWNLOADRESULTS_H
#define CLASSIFIERVECTORS_DOWNLOADRESULTS_H

#include "Command.h"

/**
 * a class which manages the option to create a file of the classified results.
 */
class DownloadResults : public Command{
private:
    DBCreator DB;
public:
    /**
     * the function creates new DownloadResults, and initializes with unique description.
     */
    DownloadResults();

    /**
     * the function send all the classified vectors.
     */
    void execute() override;

    /**
     * the function sets new data base.
     * @param classified (DBCreator)
     */
    void setClassified(const DBCreator &classified);

    /**
     * default destructor.
     */
    ~DownloadResults() override;
};


#endif
