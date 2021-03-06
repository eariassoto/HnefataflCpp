#include "Interfaz.h"
#include "Circulo.h"
void Interfaz::dibujar()
{
    vector< shared_ptr<Figura> >::iterator it = figuras.begin();
    for(it; it != figuras.end(); it++)
    {
        (*it)->dibujar();
    }
}
void Interfaz::push_figura(shared_ptr<Figura> f)
{
    shared_ptr<Circulo> c = dynamic_pointer_cast<Circulo> (f);
    if(c)
        figuras.push_back(f);
    else
        figuras.insert(figuras.begin(), f);
}

Interfaz::Interfaz(sf::RenderWindow& v): ventana_(v)
{
}

int* Interfaz::buscarPunto(int x, int y)
{
    vector< shared_ptr<Figura> >::iterator it = figuras.begin();
    bool encontrado = false;
    int tamVen = ventana_.getSize().x;
    int* coord = new int[2];
    while(it!=figuras.end() && !encontrado)
    {
        coord = (*it)->contiene(x,y);
        if(coord)
        {
            encontrado = true;
        }
        else
        {
            it++;
        }
    }
    return coord;
}
