#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "appcontext.h"
#include "logic.h"


enum Operation {
    Convert,
    Valid,
    Initialization
};




void doOperation(enum Operation operation,  struct AppContext* context);


#endif // ENTRYPOINT_H
