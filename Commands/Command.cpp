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

string Command::getMenu() {
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (const pair<const int, Command*> &command : this->commandsMap) {
        menu += command.second->getDescription();
    }
    return menu;
}

Command::~Command() = default;