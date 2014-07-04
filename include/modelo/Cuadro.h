#ifndef _CUADRO_H_
#define _CUADRO_H_
#include "Excepcion.h"
#include "Figura.h"

using namespace std;

class Cuadro
{
public:

    Cuadro(Figura*);

    virtual void    setPunteros(Cuadro*, Cuadro*, Cuadro*, Cuadro*);
    virtual Cuadro* getPtr(int);
    virtual void    setPtr(int, Cuadro*);
    virtual bool    mover(Cuadro*);
    virtual void    comer();
    virtual void    moverFigura(int, int)
    {
        throw Excepcion("Soy un cuadro, no tengo que mover");
    };
    virtual void agregarFiguraTrono(Figura*)
    {
        throw Excepcion("No soy rey, no tengo trono");
    };

    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3;

/// TODO protected:

    Figura *figura;
    Cuadro *cuadroArr, *cuadroDer, *cuadroAba, *cuadroIzq;
};
#endif // _CUADRO_H_
