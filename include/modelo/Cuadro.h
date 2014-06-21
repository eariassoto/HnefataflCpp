#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include "Excepcion.h"
#include "Figura.h"

using namespace std;

class Cuadro
{
public:
    Cuadro(Figura* f):figura(f), cuadroPtr(4)
    {
    };

    virtual void setPunteros(vector<Cuadro*> p)
    {
        vector<Cuadro*>::iterator it = cuadroPtr.begin();
        vector<Cuadro*>::iterator it1 = p.begin();
        for(it; it!=cuadroPtr.end(); it++)
        {
            *it = *it1;
            it1++;
        }
    }

    virtual void setPuntero(const int pos, Cuadro* ptr)
    {
        if(pos < 0 || pos > 3)
            throw Excepcion("Rango fuera de limites en setPuntero");
        cuadroPtr[pos] = ptr;
    }

    virtual int* mover(Cuadro*)
    {
        throw Excepcion("Esta ficha es un cuadro, no puede moverse");
    };
    virtual void comer()
    {
        throw Excepcion("Esta ficha es un cuadro, no puede comer");
    };

    virtual Cuadro* getVecino(int v)
    {
        if(v < 0 || v > 3)
            throw Excepcion("Parametro de getVecino incorrecto");
        else
            return cuadroPtr.at(v);
    }
    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3; //sigue orden agujas reloj
protected:
    vector<Cuadro*> cuadroPtr;
    Figura* figura;
};
#endif // _CUADRO_H_
