#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include "Excepcion.h"

using namespace std;

class Cuadro
{
public:
    Cuadro() {cout << "construyo cuadro\n";};

    virtual Cuadro* mover(Cuadro*)
    {
        throw Excepcion("Esta ficha es un cuadro, no puede moverse");
    };
    virtual void comer()
    {
        throw Excepcion("Esta ficha es un cuadro, no puede comer");
    };
};
#endif // _CUADRO_H_
