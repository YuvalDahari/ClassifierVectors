#ifndef CLASSIFIERVECTORS_DOWNLOADRESULTS_H
#define CLASSIFIERVECTORS_DOWNLOADRESULTS_H


#include "Command.h"

class DownloadResults : public Command{
private:
    DBCreator classified;
public:
    /**
    * constructor for creating a new specific command.
     */
    DownloadResults();
    /**
     * the function .
     */
    void execute() override;

    /**
     * default destructor.
     */
    ~DownloadResults() override;

    void setClassified(const DBCreator &classified);
};


#endif
