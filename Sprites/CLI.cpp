#include "CLI.h"

void CLI::start() {
    CommandsMap commandsMap;
    commandsMap.initialize();
    commandsMap.initializeCommands(this->client_sock);
    string menu = commandsMap.getDescriptions();
    HandleIO::sendProtocol(this->client_sock, menu);
    while (true) {
        if (!HandleIO::receiveProtocol(this->client_sock, this->receive_data)) {
            return;
        }
        int command = HandleIO::checkDemand(this->indicators, this->receive_data, this->client_sock, menu);
        switch (command) {
            case 1:
                cout << "WTF" << endl;
                commandsMap.getCommands().at(stoi(this->receive_data))->execute();
                continue;
            case 0:
                continue;
            default:
                // if the user decide to exit, we execute the Exit's command and break the loop for ending the thread.
                commandsMap.getCommands().at(stoi(this->receive_data))->execute();
                return;
        }
    }
}

CLI::CLI(int clientSock) {
    this->client_sock = clientSock;
}
