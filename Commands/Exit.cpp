#include "Exit.h"

Exit::Exit() {
    this->description = DESCRIPTION_8;
}

void Exit::execute() {
    close(this->client_sock);
}

Exit::~Exit() = default;