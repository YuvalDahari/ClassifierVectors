#include "Exit.h"

Exit::Exit() {
    this->description = "8. exit";
}

void Exit::execute() {
    close(this->client_sock);
}

Exit::~Exit() = default;