#ifndef CLASSIFIERVECTORS_SERVER_H
#define CLASSIFIERVECTORS_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include "Sprites/DBCreator.h"
#include "Classified.h"
#include "Sprites/CLI.h"

#define PORT argv[1]
#define FIX_LISTEN 5
#define FAIL 0

/**
 * a class which manages the server's logic.
 */
class Server {
public:
    /**
     * the function activate thread to handle a client.
     * @param clientSock (int)
     */
    static void handleClient(int clientSock);
};

#endif
