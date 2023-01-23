#include "CommandsMap.h"

CommandsMap::CommandsMap() = default;

const map<const int, Command*> &CommandsMap::getCommands() const {
    return this->commands;
}

string CommandsMap::getDescriptions() {
    string menu;
    for (const pair<const int, Command*> &command : this->commands) {
        menu += command.second->getDescription();
    }
    return menu;
}

void CommandsMap::initialize(){
    this->commands[1] = new UploadCommand;
    this->commands[2] = new AlgorithmSetting;
    this->commands[3] = new ClassifyCommand;
    this->commands[4] = new DisplayResults;
    this->commands[5] = new DownloadResults;
    this->commands[8] = new Exit;
}

CommandsMap::~CommandsMap() {
    for (const pair<const int, Command*> &command : this->commands) {
        delete(command.second);
    }
}

void CommandsMap::initializeCommands(int client_sock) {
    for (const pair<const int, Command*> &command : this->commands) {
        command.second->setCommandsMap(this->commands);
        command.second->setClient(client_sock);
    }
}
