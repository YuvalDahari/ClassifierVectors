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
#define FIN "-1"
#define C_BUFFER_SIZE 8192

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
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Fail creating the socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Fail connecting to server");
        close(sock);
        return 0;
    }

    while (true) {
        string string_data_addr;
        getline(cin, string_data_addr);
        if (string_data_addr == FIN) {
            break;
        }
        string_data_addr += "\n";
        const char *data_addr;
        string temp;
        while (string_data_addr.size() > C_BUFFER_SIZE) {
            temp = string_data_addr.substr(0, C_BUFFER_SIZE);
            data_addr = handleIO.convertStringToArray(temp);
            long sent_bytes = send(sock, data_addr, strlen(data_addr), 0);
            if (sent_bytes < 0) {
                perror("Fail sending to server");
            }
            string_data_addr = string_data_addr.substr(C_BUFFER_SIZE, string_data_addr.length() - 1);
        }
        data_addr = handleIO.convertStringToArray(string_data_addr);
        long sent_bytes = send(sock, data_addr, strlen(data_addr), 0);
        if (sent_bytes < 0) {
            perror("Fail sending to server");
        }
        char buffer[C_BUFFER_SIZE] = {};
        int expected_data_len = sizeof(buffer);
        string data;
        long read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            close(sock);
            break;
        } else if (read_bytes < 0) {
            perror("Fail reading data");
        }
        bool join = true;
        while (read_bytes == C_BUFFER_SIZE) {
            data += buffer;
            unsigned long length = strlen(buffer);
            for (unsigned long i = 0; i < length; ++i) {
                buffer[i] = '\0';
            }
            read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes < 0) {
                perror("Fail reading data");
                close(sock);
                join = false;
                break;
            }
        }
        if (!join) {
            break;
        }
        data += buffer;
        cout << data << endl;
    }

    close(sock);

    return 0;
}

#endif