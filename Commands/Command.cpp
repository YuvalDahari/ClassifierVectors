#include "Command.h"

string Command::getDescription() {
    return this->description;
}

void Command::setClient(int sock) {
    Command::client_sock = sock;
}

void Command::setCommandsMap(const map<const int, Command *> &commands) {
    Command::commandsMap = commands;
}

Command::~Command() = default;