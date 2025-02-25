#ifndef APPCONTEXT_H
#define APPCONTEXT_H
#include <stdlib.h>


struct AppContext {
    char answer[64];
    const char* input;
    int fromBase;
    int toBase;
    int flag;
};

#endif // APPCONTEXT_H
