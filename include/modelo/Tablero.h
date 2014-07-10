#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
#include "Cuadro.h"

using namespace std;

class Tablero
{
public:
    Tablero(int);
    void    agregarFicha(int, int, Cuadro*);
    void    imprimir();
    bool    mover(int*, int*);
    Cuadro* getFicha(int, int);
    void    setFiguraVisible(Cuadro*, bool);
    void    comer(vector<Cuadro*>);

private:
    vector< vector<Cuadro*> > vmatriz;
    int                       dimension;
};
#endif // _TABLERO_H_
