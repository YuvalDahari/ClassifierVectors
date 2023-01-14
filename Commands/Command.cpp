#include "Command.h"

const string Command::getDescription() {
    return this->description;
}

Command::~Command() = default;