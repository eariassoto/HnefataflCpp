#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <map>
#include "Ficha.h"

using namespace std;

class Tablero{
public:
    Tablero();
private:
    map<pair<int, int>, Ficha*> mapFichas;

    void mover(int, int);
};
#endif // _TABLERO_H_
