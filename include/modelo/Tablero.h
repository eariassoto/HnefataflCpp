#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <vector>
#include "Matriz.h"
#include "Cuadro.h"

using namespace std;

class Tablero
{
public:
    Tablero(int);
    void agregarFicha(int, int, Cuadro*);

private:
    Matriz<Cuadro*> matriz;
};
#endif // _TABLERO_H_
