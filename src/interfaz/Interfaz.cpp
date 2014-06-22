#include "Interfaz.h"
void Interfaz::dibujar()
{
    vector<Figura*>::iterator it = figuras.begin();
    for(it; it != figuras.end(); it++)
    {
        (*it)->dibujar();
    }
}
void Interfaz::push_figura(Figura* f)
{
    Circulo * c = dynamic_cast<Circulo *> (f);
    if(c)
        figuras.push_back(f);
    else
        figuras.insert(figuras.begin(), f);
}

Interfaz::Interfaz(sf::RenderWindow& v): ventana_(v)
{
}
