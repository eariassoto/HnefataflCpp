#include "Ficha.h"
#include "Excepcion.h"
#include "Esquina.h"

Ficha::Ficha(Figura* f):figura(f) {}

bool Ficha::mover(Cuadro* c)
{
    int i = 0;
    bool encontrado = false;
    int pos = 0;
    int pasos = 0;

    while(i < 4 && !encontrado)
    {
        Cuadro * vecino = getPtr(i);
        pasos = 1;
        while(!encontrado && vecino && esCuadro(vecino))
        {
            if(vecino == c)
            {
                pos = i;
                encontrado = true;
            }
            else
            {
                pasos++;
                vecino = vecino->getPtr(i);
            }
        }
        i++;
    }
    if(encontrado)
    {
        moverFigura(pos, pasos);
        return true;
    }
    else
    {
        throw Excepcion("No se puede mover en esta posicion");
    }
}

bool Ficha::esCuadro(Cuadro* c)
{
    try
    {
        Cuadro* r = dynamic_cast<Ficha*>(c);
        if(r)
            return !r;
        else{
            r = dynamic_cast<Esquina*>(c);
            return !r;
        }
    }
    catch(exception& e)
    {
        cout << e.what();
    }

}
///todo probar el esCuadro() con las clases derivadas hijas

void Ficha::moverFigura(int pos, int n)
{
    int mag = 0;
    if(pos == DER || pos == IZQ)
    {
        if(pos == DER)
            mag = 2;
        else
            mag = -2;
        figura->getCirc().move((mag*n*figura->getCirc().getRadius()),0);
    }
    else
    {
        if(pos == ABA)
            mag = 2;
        else
            mag = -2;
        figura->getCirc().move(0,(mag*n*figura->getCirc().getRadius()));
    }
}

vector<Cuadro*> Ficha::comer()
{
    int i = 0;
    vector<Cuadro*> v;
    while(i<4)
    {
        if(esEnemigo(getPtr(i)))
            if(esAliado(getPtr(i)->getPtr(i)))
            {
                v.push_back(getPtr(i));
            }
        i++;
    }
    return v;
};

void Ficha::setFiguraVisible(bool b)
{
    figura->setVisible(b);
}
