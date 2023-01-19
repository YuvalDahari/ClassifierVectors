#ifndef VECTORS_SOCKETS_CLIENT_CPP
#define VECTORS_SOCKETS_CLIENT_CPP

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "Sprites/DBCreator.h"
#include "Classified.h"

#define SERVER_IP argv[1]
#define S_PORT argv[2]

/**
 * a main function for a client which receive input from the user and send it to the server for classification.
 * @param argc (int)
 * @param argv (char**)
 * @return int - 0 for success.
 */
int main(int argc, char *argv[]) {
    const HandleIO handleIO;

    // arguments checks
    handleIO.checkClientArguments(argc, argv);

    const char *ip_address = SERVER_IP;
    const int port = stoi(S_PORT);
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Fail creating the socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(server_sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Fail connecting to server");
        close(server_sock);
        return 0;
    }

    string receive_data;

    HandleIO::receiveProtocol(server_sock, receive_data);
    cout << receive_data;

    while (true) {
        string send_data;
        getline(cin, send_data);
        int choice = HandleIO::extraxtChoice(send_data);
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 8:
            default:
                HandleIO::sendProtocol(server_sock, send_data);
        }
    }
    return 0;
}

#endif