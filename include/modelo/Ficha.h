#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include <exception>
#include "Cuadro.h"
#include "Excepcion.h"

using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha(Figura*);

    virtual bool    mover(Cuadro*);
    virtual Cuadro* comer();
    virtual bool    esCuadro(Cuadro*);
    virtual void    moverFigura(int, int);

    //TODO protected
    Figura *figura;
};



#endif // FICHA_H_
