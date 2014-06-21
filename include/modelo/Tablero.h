#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include "Matriz.h"
#include "Ficha.h"

using namespace std;

class Tablero
{
public:
    Tablero(int);
private:
    Matriz<Ficha*> matriz;

    void mover(int, int);
};
#endif // _TABLERO_H_
