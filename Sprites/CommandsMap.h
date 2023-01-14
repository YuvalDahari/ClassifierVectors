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
 * a class which represents the map's commands.
 */
class CommandsMap {
private:
    map<const int, Command*> commands;

public:
    /**
     * the function creates a map of all the allows commands.
     */
    CommandsMap();

    /**
     * the function returns the map's algorithms.
     * @return map<string, Algo*> - the map's algorithms.
     */
    const map<const int, Command*> &getCommands() const;

    /**
     * the function prints all the valid commands.
     */
    void printMap();

    /**
     * destructor
     */
    virtual ~CommandsMap();
};

#endif
