#ifndef VECTORS_SOCKETS_SERVER_CPP
#define VECTORS_SOCKETS_SERVER_CPP

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Sprites/DBCreator.h"
#include "Classified.h"
#include "Sprites/CLI.h"

#define PORT argv[1]
#define FIX_LISTEN 5

using namespace std;

/**
 * a main function for the server which handles the data and classify vectors from clients.
 * @param argc (int)
 * @param argv (char**)
 * @return int - 0 for success.
 */
int main(int argc, char *argv[]) {
    // arguments checks
    HandleIO::checkServerArguments(argc, argv);

    const int port = stoi(PORT);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Fail creating the socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Fail binding the socket");
        close(sock);
        return 0;
    }
    if (listen(sock, FIX_LISTEN) < 0) {
        perror("Fail defining the listening of the socket");
        close(sock);
        return 0;
    }

    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);

    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Fail accepting client");
        }
        CLI cli = CLI(client_sock);
        cli.start();
    }
    close(sock);
    return 0;
}

#endif

