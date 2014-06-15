#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_
#include <SFML/Graphics.hpp>

class Elemento
{
public:
    Elemento(sf::Drawable& d):elemento(&d) {};
    void dibujar(sf::RenderWindow& ventana)
    {
        ventana.draw(*elemento);
    };
protected:
    sf::Drawable* elemento;
};
#endif // _ELEMENTO_H_
