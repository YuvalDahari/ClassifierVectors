#ifndef CLASSIFIERVECTORS_COMMANDSMAP_H
#define CLASSIFIERVECTORS_COMMANDSMAP_H

#include <map>
#include <iostream>
#include "../Commands/Command.h"
#include "../Commands/UploadCommand.h"
#include "../Commands/AlgorithmSetting.h"
#include "../Commands/ClassifyCommand.h"
#include "../Commands/DisplayResults.h"
#include "../Commands/DownloadResults.h"
#include "../Commands/Exit.h"

using namespace std;

/**
 * a class which represents the commands' map.
 */
class CommandsMap {
private:
    map<const int, Command*> commands;

public:
    /**
     * default constructor.
     */
    CommandsMap() = default;

    /**
     * the function returns the map's algorithms.
     * @return map<string, Algo*> - the map's algorithms.
     */
    const map<const int, Command*> &getCommands() const;

    string getDescriptions();

    /**
     * destructor
     */
    virtual ~CommandsMap();

    /**
     * the function initializes the maps to contain all the allows commands.
     */
    void initialize();

    /**
     * the function initializes all the commands in the map to specific client.
     * @param client_sock (int)
     */
    void initializeCommands(int client_sock);
};

#endif
