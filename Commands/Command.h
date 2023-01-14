#ifndef CLASSIFIERVECTORS_COMMAND_H
#define CLASSIFIERVECTORS_COMMAND_H

#include <string>

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
     * a virtual function of destructor.
     */
    virtual ~Command();
};


#endif
