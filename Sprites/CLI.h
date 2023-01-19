#ifndef CLASSIFIERVECTORS_CLI_H
#define CLASSIFIERVECTORS_CLI_H

#include "CommandsMap.h"
#define WRONG_OPTION "invalid input"

class CLI {
private:
    string send_data;
    string receive_data;
    int client_sock;
    bool indicators[5] = {false, false, false, false, false};
public:
    void start();
};

#endif
