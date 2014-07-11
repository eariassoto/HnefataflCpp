#include "Ficha.h"
#include "Excepcion.h"
#include "Esquina.h"
#include "Trono.h"

Ficha::Ficha(Figura* f):figura(f) {}

shared_ptr<Cuadro> Ficha::mover(shared_ptr<Cuadro> c)
{
    int i = 0;
    bool encontrado = false;
    int pos = 0;
    int pasos = 0;

    while(i < 4 && !encontrado)
    {
        shared_ptr<Cuadro> vecino = getPtr(i);
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
        return c;
    }
    else
    {
        cout <<"no se puede mover aqui" << endl;
        return 0;
    }
}

bool Ficha::esCuadro(shared_ptr<Cuadro> c)
{
    try
    {
        Cuadro* r = dynamic_cast<Ficha*>(c);
        if(r)
            return !r;
        else
        {
            r = dynamic_cast<Esquina*>(c);
            if(r)
                return !r;
            else
            {
                r = dynamic_cast<Trono*>(c);
                return !r;
            }
        }
    }
    catch(exception& e)
    {
        cout << e.what();
    }
}

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

vector< shared_ptr<Cuadro> > Ficha::comer()
{
    int i = 0;
    vector< shared_ptr<Cuadro> > v;
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
