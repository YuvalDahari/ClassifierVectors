#include "Command.h"

string Command::getDescription() {
    return this->description;
}

void Command::setClient(int sock) {
    Command::client_sock = sock;
}

void Command::sendProtocol() {
    this->send_data += "\n\r\n\r";
    string segment;
    const char *data;
    while (this->send_data.size() > BUFFER_SIZE) {
        segment = this->send_data.substr(0, BUFFER_SIZE);
        data = HandleIO::convertStringToArray(segment);
        long sent_bytes = send(this->client_sock, data, strlen(data), 0);
        if (sent_bytes < 0) {
            perror("Fail sending to server");
        }
        this->send_data = this->send_data.substr(BUFFER_SIZE, this->send_data.length() - 1);
    }
    data = HandleIO::convertStringToArray(this->send_data);
    long sent_bytes = send(this->client_sock, data, strlen(data), 0);
    if (sent_bytes < 0) {
        perror("Fail sending to client");
    }
}

void Command::receiveProtocol() {
    this->receive_data = "";
    char buffer[BUFFER_SIZE] = {};
    int expected_data_len = sizeof(buffer);
    long read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    while (read_bytes == BUFFER_SIZE && buffer[BUFFER_SIZE - 1] != '\r') {
        this->receive_data += buffer;
        unsigned long length = strlen(buffer);
        for (unsigned long i = 0; i < length; ++i) {
            buffer[i] = '\0';
        }
        read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes < 0) {
            perror("Fail reading data");
            close(client_sock);
            break;
        }
    }
    this->receive_data += buffer;
}

void Command::setInvalid() {
    this->send_data = "invalid input\n";
}

Command::~Command() = default;