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

#define S_PORT argv[1]

int makeStringFromFile(int &length, string &sendData, const string &fileName, int indicator) {
    int flag;
    if (HandleIO::checkFile(fileName, 1) == -1) {
        return -1;
    }
    ifstream file(fileName);
    string line;
    getline(file, line);
    length = HandleIO::lengthExtract(line);
    sendData = to_string(length) + "\n";
    do {
        flag = HandleIO::checkDBLine(line, length, indicator);
        sendData += line + "\n";
    } while (getline(file, line) and flag != -1);
    sendData += "\r\n\r";
    return flag;
}

int writeToFile(const string& receiveData, const string &fileName) {
    if (HandleIO::checkFile(fileName, 2) == -1) {
        return -1;
    }
    ofstream file(fileName);

    // Use a stringstream to parse the input string
    stringstream ss(receiveData);
    string line;
    while (std::getline(ss, line, '\n')) {
        // Use another stringstream to parse the line and extract the number and word
        stringstream lineStream(line);
        string number, word;
        getline(lineStream, number, ',');
        getline(lineStream, word, ',');

        // Write the number and word to the CSV file
        file << number << "," << word << std::endl;
    }
    file.close();
    return 1;
}


/**
 * a main function for a client which receive input from the user and send it to the server for classification.
 * @param argc (int)
 * @param argv (char**)
 * @return int - 0 for success.
 */
int main(int argc, char *argv[]) {
    // cases vars:
    int length;
    string fileName;
    int flag;
    string menu;
    int index;



    const HandleIO handleIO;
    string send_data;
    string receive_data;

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


    while (true) {
        HandleIO::receiveProtocol(server_sock, receive_data);
        cout << receive_data;
        getline(cin, send_data);
        int choice = HandleIO::extractChoice(send_data);
        switch (choice) {
            case 1:
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                cout << receive_data;
                getline(cin, fileName);
                flag = makeStringFromFile(length, send_data, fileName, 1);
                while (flag == -1) {
                    send_data = "invalid file\nWrite a new path\n";
                    cout << send_data;
                    flag = makeStringFromFile(length, send_data, fileName, 1);
                }
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                //duplicate code, need to rewrite when finished.
                cout << receive_data;
                getline(cin, fileName);
                flag = makeStringFromFile(length, send_data, fileName, 2);
                while (flag == -1) {
                    send_data = "invalid file\nWrite a new path\n";
                    cout << send_data;
                    flag = makeStringFromFile(length, send_data, fileName, 2);
                }
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                cout << receive_data;
                continue;
            case 2:
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                cout << receive_data;
                getline(cin, send_data);
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                cout << receive_data;
                continue;
            case 3:
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                cout << receive_data;
                continue;
            case 4:
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                index = receive_data.find("Welcome");
                menu = receive_data.substr(index, receive_data.length()- 4);
                receive_data = receive_data.substr(0, index - 1);
                cout << receive_data;
                getline(cin, fileName);
                cout << menu;
                continue;
            case 5:
                HandleIO::sendProtocol(server_sock, send_data);
                HandleIO::receiveProtocol(server_sock, receive_data);
                index = receive_data.find("Welcome");
                menu = receive_data.substr(index, receive_data.length()- 4);
                receive_data = receive_data.substr(0, index - 1);
                getline(cin, fileName);
                flag = writeToFile(receive_data, fileName);
                while (flag == -1) {
                    send_data = "invalid file\nWrite a new path\n";
                    cout << send_data;
                    flag = writeToFile(receive_data, fileName);
                }
                continue;
            case 8:
                HandleIO::sendProtocol(server_sock, send_data);
                return 0;
            default:
                cout << "Invalid input\n"
        }
    }
    return 0;
}

#endif