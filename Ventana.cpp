#include "Ventana.h"
Ventana::Ventana(sf::RenderWindow& v):ventana(v)
{

}

Ventana* Ventana::push(Elemento& e)
{
    elementos.push_back(e);
    return this;
}

Ventana* Ventana::dibujar()
{
    vector<Elemento>::iterator it = elementos.begin();
    for(it; it!=elementos.end(); it++)
        (*it).dibujar(ventana);
    return this;
}
