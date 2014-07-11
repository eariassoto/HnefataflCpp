#include "Cuadro.h"
#include "Excepcion.h"

Cuadro::Cuadro():cuadroArr(0), cuadroDer(0), cuadroAba(0), cuadroIzq(0) {};

Cuadro* Cuadro::getPtr(int i)
{
    switch(i)
    {
    case 0:
        return cuadroArr;
    case 1:
        return cuadroDer;
    case 2:
        return cuadroAba;
    case 3:
        return cuadroIzq;
    }
}

void Cuadro::setPtr(int pos, Cuadro* ptr)
{
    switch(pos)
    {
    case 0:
        cuadroArr = ptr;
        break;
    case 1:
        cuadroDer = ptr;
        break;
    case 2:
        cuadroAba = ptr;
        break;
    case 3:
        cuadroIzq = ptr;
        break;
    default:
        throw Excepcion("rango fuera filas");
    }
}

void Cuadro::swap(Cuadro* c)
{
    Cuadro* aux;
    int j;
    for(int i = 0; i < 4; i++)
    {
        cout << "comienza swap " << i << endl;
        aux = c->getPtr(i);
        j = ((i + 2) % 4);
        if(getPtr(i))
        {
            if(getPtr(i) != c)
                getPtr(i)->setPtr(j, c);
            if(aux)
            {
                c->setPtr(i, getPtr(i)); //el otroapunte al mio
                if(c->getPtr(i) == c)
                    c->setPtr(i, this);
            }
        }
        if (aux)
        {
            if(aux != this)
                aux->setPtr(j, this);
            if(getPtr(i))
            {
                setPtr(i, aux); //apunte al del otro
                if(getPtr(i) == this)
                    setPtr(i, c);
            }
        }
    }
}

Cuadro* Cuadro::mover(Cuadro*)
{
    throw Excepcion("Esta ficha es un cuadro, no puede moverse");
};

vector<Cuadro*> Cuadro::comer()
{
    throw Excepcion("Esta ficha es un cuadro, no puede comer");
};

