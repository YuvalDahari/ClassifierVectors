#ifndef CLASSIFIERVECTORS_COMMAND_H
#define CLASSIFIERVECTORS_COMMAND_H

#include <string>
#include "../HandleIO.h"
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "../Classified.h"
using namespace std;

class Command {
protected:
    string description;
    int client_sock;
    const char *answer;
public:
    /**
    * a virtual function which executes different logics of every child.
    */
    virtual void execute() = 0;

    /**
     * the function returns the command's description.
     * @return string - the command description.
     */
    string getDescription();

    /**
     * the function set client for the command.
     * @param sock (int)
     */
    void setClient(int sock);

    void sendProtocol();

    void setInvalid();

    /**
     * a virtual function of destructor.
     */
    virtual ~Command();
};


#endif
