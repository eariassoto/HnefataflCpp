#include "Cuadro.h"


Cuadro::Cuadro(Figura* f):figura(f), cuadroPtr(4) {};

void Cuadro::setPunteros(vector<Cuadro*> p)
{
    cuadroPtr = p;
}

vector<Cuadro*> Cuadro::getPunteros()
{
    return cuadroPtr;
}

void Cuadro::setPuntero(const int pos, Cuadro* ptr)
{
    if(pos < 0 || pos > 3)
        throw Excepcion("Rango fuera de limites en setPuntero");
    cuadroPtr[pos] = ptr;
}

void Cuadro::setNuevosPunteros(vector<Cuadro*> p)
{
    cuadroPtr = p;
    cuadroPtr[ARR]->setPuntero(ABA, this);
    cuadroPtr[DER]->setPuntero(IZQ, this);
    cuadroPtr[ABA]->setPuntero(ARR, this);
    cuadroPtr[IZQ]->setPuntero(DER, this);
}

bool Cuadro::mover(Cuadro*)
{
    throw Excepcion("Esta ficha es un cuadro, no puede moverse");
};
void Cuadro::comer()
{
    throw Excepcion("Esta ficha es un cuadro, no puede comer");
};

Cuadro* Cuadro::getVecino(int v)
{
    if(v < 0 || v > 3)
        throw Excepcion("Parametro de getVecino incorrecto");
    else
        return cuadroPtr.at(v);
}

