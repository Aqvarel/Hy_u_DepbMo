#include "entrypoint.h"


void doOperation(enum Operation operation, struct AppContext* context,  struct AppParams* params) {
    switch(operation){
    case Convert:
        doConvert(context, params);
        break;
    case Valid:
        doValid(context, params);
        break;
    case Initialization:
        initialize(context);
        break;
    }
}
