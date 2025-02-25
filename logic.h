#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"

enum ErrorsGood{
    error_first = -1,
    error_second = -2,
    good = 0
};

#define DEFAULT_VALUE 0

void doConvert(struct AppContext* context);
void doValid(struct AppContext* context);
void initialize(struct AppContext* context);

#endif // LOGIC_H
