#ifndef CLASSIFIERVECTORS_CLIENT_H
#define CLASSIFIERVECTORS_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include "Sprites/DBCreator.h"
#include "Classified.h"

#define S_PORT argv[1]

/**
 * a class which manages the client's logic.
 */
class Client {
public:
    /**
     * the function reads file and makes a string out of it.
     * @param length (int)
     * @param sendData (string)
     * @param fileName (string)
     * @param indicator (int)
     * @return int - 1 if the file is valid, end -1 if it is not.
     */
    static int makeStringFromFile(int &length, string &sendData, const string &fileName, int indicator);

    /**
     * the function writes given string to file.
     * @param receiveData (string)
     * @param fileName (string)
     */
    static void writeToFile(const string &receiveData, const string &fileName);

    /**
     * the function sends message for the server, then if there is an answer prints it.
     * @param serverSock (int)
     * @param sendData (string)
     * @param receiveData (string)
     */
    static void inputOutput(int &serverSock, string &sendData, string &receiveData);

    /**
     * the function manages the logics of case 1.
     * @param serverSock (int)
     * @param sendData (string)
     * @param receiveData (string)
     * @param flag (int)
     * @param length (int)
     * @param indicator (int)
     */
    static void case1(int &serverSock, string &sendData, string &receiveData, int &flag, int &length, int indicator);

    /**
     * the function checks if there is already a classified data.
     * @param serverSock (int)
     * @param menu (string)
     * @param sendData (string)
     * @param receiveData (string)
     * @param index (unsigned long)
     * @return bool - true if the data already has been classified, and false otherwise.
     */
    static bool isMissData(int &serverSock, string &menu, string &sendData, string &receiveData, unsigned long &index);

    /**
     * the function creates an empty file.
     * @param directory (string)
     * @param fileName (string)
     * @return bool - true if it works, and false otherwise.
     */
    static bool createEmptyFile(const string& directory, const string& fileName);

    /**
     * the function manages the logic of the file's creations.
     * @param receiveData (string)
     * @param i (int)
     */
    static void handleFile(string &receiveData, int &i);

    /**
     * the function activates a thread to write into file.
     * @param receiveData (string)
     * @param temp (string)
     */
    static void threadRun(string receiveData, string temp);

    /**
     * the function manages the logics of case 5.
     * @param serverSock (int)
     * @param menu (string)
     * @param sendData (string)
     * @param receiveData (string)
     * @param index (unsigned long)
     * @param i (int)
     */
    static void case5(int serverSock, string &menu, string &sendData, string &receiveData, unsigned long index, int &i);
};

#endif
