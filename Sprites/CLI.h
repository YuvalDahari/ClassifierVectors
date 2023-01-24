#ifndef CLASSIFIERVECTORS_CLI_H
#define CLASSIFIERVECTORS_CLI_H

#include <thread>
#include "CommandsMap.h"

/**
 * a class which manages every singular client's logic.
 */
class CLI {
private:
    string sendData;
    string receiveData;
    int clientSock;
    bool indicators[5] = {false, false, false, false, false};
public:
    /**
     * the function creates a new CLI.
     * @param clientSock (int)
     */
    explicit CLI(int clientSock);

    /**
     * the function activates the classify program.
     */
    void start();
};

#endif
