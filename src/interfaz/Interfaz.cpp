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

void Interfaz::buscarPunto(int x, int y){
    vector<Figura*>::iterator it = figuras.begin();
    bool encontrado = false;
    int tamVen = ventana_.getSize().x;
    while(it!=figuras.end() && !encontrado){
        int* coord = (*it)->contiene(x,y);
        if(coord){
                cout << "lo encontre en " << coord[0] << ", " << coord[1] << endl;
            encontrado = true;
        }else{
        it++;
        }
        delete coord;
    }


}
