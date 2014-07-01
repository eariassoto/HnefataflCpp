#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include "Excepcion.h"
#include "Figura.h"

using namespace std;

class Cuadro
{
public:

    Cuadro(Figura*);

    virtual void            setPunteros(vector<Cuadro*>);
    virtual vector<Cuadro*> getPunteros();
    virtual void            setPuntero(const int, Cuadro*);
    virtual void            setNuevosPunteros(vector<Cuadro*>);
    virtual bool            mover(Cuadro*);
    virtual void            comer();
    virtual Cuadro*         getVecino(int);
    virtual void            moverFigura(int, int)
    {
        throw Excepcion("Soy un cuadro, no tengo que mover");
    };
    virtual void            agregarFiguraTrono(Figura*)
    {
        throw Excepcion("No soy rey, no tengo trono");
    };

    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3; //sigue orden agujas reloj

/// TODO protected:

    Figura* figura;
    vector<Cuadro*> cuadroPtr;
};
#endif // _CUADRO_H_
