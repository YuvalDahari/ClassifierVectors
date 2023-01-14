#include "CommandsMap.h"

CommandsMap::CommandsMap() {
    this->commands[1] = new UploadCommand;
    this->commands[2] = new AlgorithmSetting;
    this->commands[3] = new ClassifyCommend;
    this->commands[4] = new DisplayResults;
    this->commands[5] = new DownloadResults;
    this->commands[8] = new Exit;
}

const map<int, Command*> &CommandsMap::getCommands() const {
    return this->commands;
}

CommandsMap::~CommandsMap() {
    for (const pair<int, Command*>& command : this->commands) {
        delete(command.second);
    }
}