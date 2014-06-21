#include "Elemento.h"
Elemento::Elemento(sf::Drawable& f, sf::RenderWindow& v):figura(f), ventana(v){}

void Elemento::dibujar(){
    ventana.draw(figura);
}
