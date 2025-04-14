#ifndef APPCONTEXT_H
#define APPCONTEXT_H
#include <stdlib.h>

#define AnswerSize 33
#define InputSize 100

struct AppContext {
    char answer[AnswerSize];
    char input[InputSize];
    int fromBase;
    int toBase;
    int flag;
};

#endif // APPCONTEXT_H
