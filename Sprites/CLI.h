#ifndef CLASSIFIERVECTORS_CLI_H
#define CLASSIFIERVECTORS_CLI_H

#include "CommandsMap.h"

class CLI {
private:
    string sendData;
    string receiveData;
    int clientSock;
    bool indicators[5] = {false, false, false, false, false};
public:
    explicit CLI(int clientSock);

    void start();
};

#endif
