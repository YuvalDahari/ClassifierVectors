#include "Command.h"

const string Command::getDescription() {
    return this->description;
}

void Command::setClient(int sock) {
    Command::client_sock = sock;
}

Command::~Command() = default;