#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"

#define SizeBaseText 20
#define SizeCurent 35
#define BinSystem 2
#define OctSystem 8
#define DecSystem 10
#define HexSystem 16

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
