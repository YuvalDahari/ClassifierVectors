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

void Client::InputOutput(int &server_sock, string &send_data, string &receive_data) {
    HandleIO::sendProtocol(server_sock, send_data);
    HandleIO::receiveProtocol(server_sock, receive_data);
    cout << receive_data << "\n";
}

void Client::Case1(int &server_sock, string &send_data, string &receive_data, string &fileName, int &flag, int &length,
                   int indicator) {
    Client::InputOutput(server_sock, send_data, receive_data);
    getline(cin, fileName);
    flag = makeStringFromFile(length, send_data, fileName, indicator);
    while (flag == -1) {
        send_data = "invalid file\nWrite a new path";
        cout << send_data << endl;
        send_data.clear();
        getline(cin, fileName);
        flag = makeStringFromFile(length, send_data, fileName, indicator);
    }
}

bool Client::isMissData(int &server_sock, string &send_data, string &receive_data, unsigned long &index) {
    HandleIO::sendProtocol(server_sock, send_data);
    HandleIO::receiveProtocol(server_sock, receive_data);
    if (receive_data.find("please upload data") != string::npos ||
        receive_data.find("please classify the data") != string::npos) {
        cout << receive_data << endl;
        return true;
    }
    index = receive_data.find("Welcome");
    send_data = receive_data.substr(index, receive_data.size());
    receive_data = receive_data.substr(0, index - 1);
    return false;
}

bool Client::createEmptyFile(const string &fileName) {
    ifstream file(fileName, ios::in);
    if (!file.good()) {
        ofstream new_file(fileName);
        if (new_file.is_open()) {

            new_file.close();
        } else {
            cerr << "Failed to create file: " << fileName << endl;
            return false;
        }
    } else {
        cerr << "File Already Exist: " << fileName << endl;
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
    // cases vars:
    int length;
    string fileName;
    int flag;
    string menu;
    unsigned long index;

    string send_data;
    string receive_data;

    // arguments checks
    HandleIO::checkClientArguments(argc, argv);

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
    HandleIO::receiveProtocol(server_sock, receive_data);
    cout << receive_data << endl;
    while (true) {
        getline(cin, send_data);
        int choice = HandleIO::extractChoice(send_data);
        switch (choice) {
            case 1:
                Client::Case1(server_sock, send_data, receive_data, fileName, flag, length, 1);
                Client::Case1(server_sock, send_data, receive_data, fileName, flag, length, 2);
                Client::InputOutput(server_sock, send_data, receive_data);
                continue;
            case 2:
                Client::InputOutput(server_sock, send_data, receive_data);
                getline(cin, send_data);
                Client::InputOutput(server_sock, send_data, receive_data);
                continue;
            case 3:
                Client::InputOutput(server_sock, send_data, receive_data);
                continue;
            case 4:
                if (Client::isMissData(server_sock, send_data, receive_data, index)) {
                    continue;
                }
                cout << receive_data;
                getline(cin, receive_data);
                cout << send_data << endl;
                continue;
            case 5:
                if (Client::isMissData(server_sock, send_data, receive_data, index)) {
                    continue;
                }
                //todo: a path to the file.
                cout << "Please write a path name to create a new file there.\n";
                getline(cin, fileName);
                if(Client::createEmptyFile(fileName)) {
                    Client::writeToFile(receive_data, fileName);
                }
                continue;
            case 8:
                HandleIO::sendProtocol(server_sock, send_data);
                return 0;
            default:
                cout << "invalid input\n";
        }
    }
    return 0;
}

#endif