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

    static void writeToFile(const string &receiveData, const string &fileName);

    static void InputOutput(int &serverSock, string &sendData, string &receiveData);

    static void Case1(int &serverSock, string &sendData, string &receiveData, string &fileName, int &flag,
                      int &length, int indicator);

    static bool isMissData(int &serverSock, string &sendData, string &receiveData, unsigned long &index);

    static bool createEmptyFile(const string &directory, const string &fileName);
};

#endif
