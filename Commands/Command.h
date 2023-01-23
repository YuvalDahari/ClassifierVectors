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
#include "../HandleIO.h"

#define COMMAND2 2
#define COMMAND3 3
#define COMMAND4 4
#define COMMAND5 5

using namespace std;

class Command {
protected:
    string description;
    int client_sock;
    string send_data;
    string receive_data;
    map<const int, Command*> commandsMap;
public:
    /**
    * a virtual function which executes different logics of every child.
    */
    virtual void execute() = 0;

    void setCommandsMap(const map<const int, Command *> &commandsMap);

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

    /**
     * a virtual function of destructor.
     */
    virtual ~Command();

    string getMenu();
};


#endif
