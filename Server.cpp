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

#define PORT argv[2]
#define FIN "-1"
#define S_BUFFER_SIZE 8192

using namespace std;

/**
 * a main function for the server which handles the data and classify vectors from clients.
 * @param argc (int)
 * @param argv (char**)
 * @return int - 0 for success.
 */
int main(int argc, char *argv[]) {
    const HandleIO handleIO;

    // arguments checks
    handleIO.checkServerArguments(argc, argv);

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
    if (listen(sock, 5) < 0) {
        perror("Fail defining the listening of the socket");
        close(sock);
        return 0;
    }

    DBCreator db = DBCreator(FILE_NAME);

    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    int validFlag;

    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Fail accepting client");
            continue;
        }

        while (true) {
            char buffer[S_BUFFER_SIZE] = {};
            int expected_data_len = sizeof(buffer);
            string data;
            long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                close(client_sock);
                break;
            } else if (read_bytes < 0) {
                perror("Fail reading data");
            }
            bool join = true;
            while (read_bytes == S_BUFFER_SIZE && buffer[S_BUFFER_SIZE - 1] != '\n') {
                data += buffer;
                unsigned long length = strlen(buffer);
                for (unsigned long i = 0; i < length; ++i) {
                    buffer[i] = '\0';
                }
                read_bytes = recv(client_sock, buffer, expected_data_len, 0);
                if (read_bytes < 0) {
                    perror("Fail reading data");
                    close(client_sock);
                    join = false;
                    break;
                }
            }
            if (!join) {
                break;
            }
            data += buffer;
            int approximation;
            string algorithm;
            vector<double> v;
            char *answer;
            validFlag = handleIO.dataExtract(data, v, db.getObjType().getLength(), algorithm, approximation);
            if (validFlag < 0) {
                answer = handleIO.convertStringToArray("invalid input");
            } else {
                Classified classifier = Classified(approximation, db, algorithm);
                answer = handleIO.convertStringToArray(classifier.findDistances(v));
            }

            long sent_bytes = send(client_sock, answer, strlen(answer), 0);
            if (sent_bytes < 0) {
                perror("Fail sending to client");
            }
        }
    }
    close(sock);
    return 0;
}

#endif

