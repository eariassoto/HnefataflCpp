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
    void    agregarFicha(int, int, Cuadro*);
    void    imprimir();
    void    mover(int, int, int, int);
    Cuadro* getFicha(int, int);

//private:
    Matriz<Cuadro*> matriz;
    int             dimension;
};
#endif // _TABLERO_H_
