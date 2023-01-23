#include "CLI.h"

void CLI::start() {
    CommandsMap commandsMap;
    commandsMap.initialize();
    commandsMap.initializeCommands(this->clientSock);
    string menu = commandsMap.getDescriptions();
    HandleIO::sendProtocol(this->clientSock, menu);
    while (true) {
        if (!HandleIO::receiveProtocol(this->clientSock, this->receiveData)) {
            return;
        }
        int command = HandleIO::checkDemand(this->indicators, this->receiveData, this->clientSock, menu);
        switch (command) {
            case 1:
                commandsMap.getCommands().at(stoi(this->receiveData))->execute();
                continue;
            case 0:
                continue;
            default:
                // if the user decide to exit, we execute the Exit's command and break the loop for ending the thread.
                commandsMap.getCommands().at(stoi(this->receiveData))->execute();
                return;
        }
    }
}

CLI::CLI(int clientSock) {
    this->clientSock = clientSock;
}
