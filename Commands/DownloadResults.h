#ifndef CLASSIFIERVECTORS_DOWNLOADRESULTS_H
#define CLASSIFIERVECTORS_DOWNLOADRESULTS_H


#include "Command.h"

class DownloadResults : public Command{
private:
    Classified classified;
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

    void setClassified(const Classified &classified);
};


#endif
