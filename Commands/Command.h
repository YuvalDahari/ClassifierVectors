#ifndef CLASSIFIERVECTORS_COMMAND_H
#define CLASSIFIERVECTORS_COMMAND_H

#include <string>
#include "../HandleIO.h"

using namespace std;

class Command {
protected:
    string description;
public:
    /**
    * a virtual function which executes different logics of every child.
    */
    virtual void execute() = 0;

    /**
     * the function returns the command's description.
     * @return string - the command description.
     */
    const string getDescription();

    /**
     * a virtual function of destructor.
     */
    virtual ~Command();
};


#endif
