#ifndef APPCONTEXT_H
#define APPCONTEXT_H
#include <stdlib.h>



struct AppContext {
    char answer[33];
    char input[100];
    int fromBase;
    int toBase;
    int flag;
};

#endif // APPCONTEXT_H
