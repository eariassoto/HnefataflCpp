#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include "Cuadro.h"
#include "Excepcion.h"

using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha(Figura*);

    virtual bool mover(Cuadro*);
    virtual void comer() {};
    virtual bool esCuadro(Cuadro*);
    virtual void moverFigura(int, int);
};

#endif // FICHA_H_
