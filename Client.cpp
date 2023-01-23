#ifndef VECTORS_SOCKETS_CLIENT_CPP
#define VECTORS_SOCKETS_CLIENT_CPP

#include "Client.h"

int Client::makeStringFromFile(int &length, string &sendData, const string &fileName, int indicator) {
    int flag;
    if (HandleIO::checkFile(fileName, indicator) == -1) {
        return -1;
    }
    ifstream file(fileName);
    string line;
    getline(file, line);
    if (indicator == 1) {
        length = HandleIO::lengthExtract(line);
    } else {
        sendData = "";
    }
    do {
        flag = HandleIO::checkDBLine(line, length, indicator);
        sendData += line + "\n";
    } while (getline(file, line) and flag != -1);
    sendData += "\r";
    file.close();
    return flag;
}

void Client::writeToFile(const string &receiveData, const string &fileName) {
    ofstream file(fileName);
    // use a 'stringstream' to parse the input string
    stringstream ss(receiveData);
    string line;
    while (getline(ss, line, '\n')) {
        // use another 'stringstream' to parse the line and extract the number and word
        stringstream lineStream(line);
        string number, word;
        getline(lineStream, number, ',');
        getline(lineStream, word, ',');

        // write the number and word to the CSV file
        file << number << "," << word << endl;
    }
    file.close();
}

void Client::InputOutput(int &serverSock, string &sendData, string &receiveData) {
    HandleIO::sendProtocol(serverSock, sendData);
    if (!HandleIO::receiveProtocol(serverSock, receiveData)) exit(0);
    cout << receiveData << endl;
}

void Client::Case1(int &serverSock, string &sendData, string &receiveData, string &fileName, int &flag, int &length,
                   int indicator) {
    Client::InputOutput(serverSock, sendData, receiveData);
    getline(cin, fileName);
    flag = makeStringFromFile(length, sendData, fileName, indicator);
    while (flag == -1) {
        sendData = "invalid file\nWrite a new path";
        cout << sendData << endl;
        sendData.clear();
        getline(cin, fileName);
        flag = makeStringFromFile(length, sendData, fileName, indicator);
    }
}

bool Client::isMissData(int &serverSock, string &sendData, string &receiveData, unsigned long &index) {
    HandleIO::sendProtocol(serverSock, sendData);
    if (!HandleIO::receiveProtocol(serverSock, receiveData)) exit(0);
    if (receiveData.find("please upload data") != string::npos ||
        receiveData.find("please classify the data") != string::npos) {
        cout << receiveData << endl;
        return true;
    }
    index = receiveData.find("Welcome");
    sendData = receiveData.substr(index, receiveData.size());
    receiveData = receiveData.substr(0, index);
    return false;
}

bool Client::createEmptyFile(const string &directory, const string &fileName) {
    string fullPath = directory + "/" + fileName;
    ifstream file(fullPath);
    if (!file.good()) {
        ofstream newFile(fullPath);
        if (newFile.is_open()) {
            newFile.close();
        } else {
            cerr << "Failed to create file: " << fullPath << endl;
            return false;
        }
    } else {
        cerr << "File Already Exist: " << fullPath << endl;
        return false;
    }
    return true;
}

/**
 * a main function for a client which receive input from the user and send it to the server for classification.
 * @param argc (int)
 * @param argv (char**)
 * @return int - 0 for success.
 */
int main(int argc, char *argv[]) {
    int i = 1;
    string fileName = "file_num_" + to_string(i) + ".csv";
    // cases vars:
    int length;
    string dirName;
    int flag;
    string menu;
    unsigned long index;

    string sendData;
    string receiveData;

    // arguments checks
    HandleIO::checkClientArguments(argc, argv);

    const char *ipAddress = SERVER_IP;
    const int port = stoi(S_PORT);
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0) {
        perror("Fail creating the socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ipAddress);
    sin.sin_port = htons(port);
    if (connect(serverSock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Fail connecting to server");
        close(serverSock);
        return 0;
    }
    if (!HandleIO::receiveProtocol(serverSock, receiveData)) exit(0);
    cout << receiveData << endl;
    while (true) {
        getline(cin, sendData);
        int choice = HandleIO::extractChoice(sendData);
        switch (choice) {
            case 1:
                Client::Case1(serverSock, sendData, receiveData, dirName, flag, length, 1);
                Client::Case1(serverSock, sendData, receiveData, dirName, flag, length, 2);
                Client::InputOutput(serverSock, sendData, receiveData);
                continue;
            case 2:
                Client::InputOutput(serverSock, sendData, receiveData);
                getline(cin, sendData);
                if (sendData.empty()) {
                    sendData = "-1";
                }
                Client::InputOutput(serverSock, sendData, receiveData);
                continue;
            case 3:
                Client::InputOutput(serverSock, sendData, receiveData);
                continue;
            case 4:
                if (Client::isMissData(serverSock, sendData, receiveData, index)) {
                    continue;
                }
                cout << receiveData << endl;
                getline(cin, receiveData);
                cout << sendData << endl;
                continue;
            case 5:
                if (Client::isMissData(serverSock, sendData, receiveData, index)) {
                    continue;
                }
                cout << "Please write a path name to create a new file there.\n";
                getline(cin, dirName);
                if (Client::createEmptyFile(dirName, fileName)) {
                    string temp = dirName += "/" + fileName;
                    Client::writeToFile(receiveData, temp);
                    i++;
                    fileName = "file_num_" + to_string(i) + ".csv";
                }
                cout << sendData << endl;
                continue;
            case 8:
                HandleIO::sendProtocol(serverSock, sendData);
                return 0;
            default:
                cout << "invalid input\n";
        }
    }
}

#endif