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
    CommandsMap();

    /**
     * the function returns the map's algorithms.
     * @return map<string, Algo*> - the map's algorithms.
     */
    const map<const int, Command*> &getCommands() const;

    /**
     * the function returns the command's description.
     * @return string - the command description.
     */
    string getDescriptions();

    /**
     * the function initializes the maps to contain all the allows commands.
     */
    void initialize();

    /**
     * the function initializes all the commands in the map to specific client.
     * @param client_sock (int)
     */
    void initializeCommands(int client_sock);

    /**
     * destructor.
     */
    virtual ~CommandsMap();
};

#endif
