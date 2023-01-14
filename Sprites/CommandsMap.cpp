#include "CommandsMap.h"

CommandsMap::CommandsMap() {
    this->commands[1] = new UploadCommand;
    this->commands[2] = new AlgorithmSetting;
    this->commands[3] = new ClassifyCommand;
    this->commands[4] = new DisplayResults;
    this->commands[5] = new DownloadResults;
    this->commands[8] = new Exit;
}

const map<const int, Command*> &CommandsMap::getCommands() const {
    return this->commands;
}

void CommandsMap::printMap() {
    string menu;
    for (const pair<const int, Command*> &command : this->commands) {
        menu += command.second->getDescription();
    }
    cout << menu;
}

CommandsMap::~CommandsMap() {
    for (const pair<const int, Command*> &command : this->commands) {
        delete(command.second);
    }
}