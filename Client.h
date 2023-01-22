#ifndef CLASSIFIERVECTORS_CLIENT_H
#define CLASSIFIERVECTORS_CLIENT_H

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

class Client {
public:
    static int makeStringFromFile(int &length, string &sendData, const string &fileName, int indicator);

    static int writeToFile(const string &receiveData, const string &fileName);

    static void InputOutput(int &server_sock, string &send_data, string &receive_data);

    static void Case1(int &server_sock, string &send_data, string &receive_data, string &fileName, int &flag,
                      int &length, int indicator);

    static bool isMissData(int &server_sock, string &send_data, string &receive_data, unsigned long &index);
};

#endif
