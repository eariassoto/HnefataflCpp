#include "Cuadro.h"
#include "Excepcion.h"

Cuadro::Cuadro():cuadroArr(0), cuadroDer(0), cuadroAba(0), cuadroIzq(0) {};

shared_ptr<Cuadro> Cuadro::getPtr(int i)
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

void Cuadro::setPtr(int pos, shared_ptr<Cuadro> ptr)
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

void Cuadro::swap(shared_ptr<Cuadro> c)
{
    shared_ptr<Cuadro> aux;
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
                    c->setPtr(i, shared_from_this());
            }
        }
        if (aux)
        {
            if(aux != shared_from_this())
                aux->setPtr(j, shared_from_this());
            if(getPtr(i))
            {
                setPtr(i, aux); //apunte al del otro
                if(getPtr(i) == shared_from_this())
                    setPtr(i, c);
            }
        }
    }
}

shared_ptr<Cuadro> Cuadro::mover(shared_ptr<Cuadro>)
{
    throw Excepcion("Esta ficha es un cuadro, no puede moverse");
};

vector< shared_ptr<Cuadro> > Cuadro::comer()
{
    throw Excepcion("Esta ficha es un cuadro, no puede comer");
};

