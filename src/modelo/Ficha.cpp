#include "Ficha.h"

Ficha::Ficha(Figura* f):Cuadro(f) {}

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
        cout << "tengo que dar " << pasos << " pasos " << endl;
        moverFigura(pos, pasos);
        return true;//coord;
    }
    else
    {
        throw Excepcion("No se puede mover en esta posicion");
    }
}

bool Ficha::esCuadro(Cuadro* c)
{
    try{
    Cuadro* r = dynamic_cast<Ficha*>(c);
    return !r;
    }catch(exception& e){
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
        //figura->getCirc().setFillColor(sf::Color(255,0,0));
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
