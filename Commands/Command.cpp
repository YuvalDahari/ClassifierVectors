#include "Command.h"

const string Command::getDescription() {
    return this->description;
}

void Command::setClient(int sock) {
    Command::client_sock = sock;
}

void Command::sendProtocol() {
    long sent_bytes = send(this->client_sock, this->answer, strlen(this->answer), 0);
    if (sent_bytes < 0) {
        perror("Fail sending to client");
    }
}

Command::~Command() = default;