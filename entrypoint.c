#include "entrypoint.h"


void doOperation(enum Operation operation, struct AppContext* context) {
    switch(operation){
    case Convert:
        doConvert(context);
        break;
    case Valid:
        doValid(context);
        break;
    case Initialization:
        initialize(context);
        break;
    }
}
