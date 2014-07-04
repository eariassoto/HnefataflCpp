#include "Cuadro.h"


Cuadro::Cuadro(Figura* f):figura(f), cuadroArr(0), cuadroDer(0), cuadroAba(0), cuadroIzq(0){};

void Cuadro::setPunteros(Cuadro* arr, Cuadro* der, Cuadro* aba, Cuadro* izq)
{
    cuadroArr = arr;
    cuadroAba = aba;
    cuadroDer = der;
    cuadroIzq = izq;
}
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

void Cuadro::swap(Cuadro* c){
    Cuadro* aux;
    int j;
    for(int i = 0; i < 4; i++){
          j = ((i + 2) % 4);
        cout << "movi punteros " << i << endl;
        aux = this->getPtr(i); //guarde mi puntero temporal
        if(aux)
            aux->setPtr(j, c);
        if (c->getPtr(i))
            c->getPtr(i)->setPtr(j, this);
        this->setPtr(i, c->getPtr(i)); //apunte al del otro
        c->setPtr(i, aux); //el otroapunte al mio
    }
}

bool Cuadro::mover(Cuadro*)
{
    throw Excepcion("Esta ficha es un cuadro, no puede moverse");
};
void Cuadro::comer()
{
    throw Excepcion("Esta ficha es un cuadro, no puede comer");
};

