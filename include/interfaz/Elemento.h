#ifndef ELEMENTO_H_
#define ELEMENTO_H_
#include <SFML/Graphics.hpp>

class Elemento{
public:
    Elemento(sf::Drawable&, sf::RenderWindow&);
    sf::Drawable& figura;
    sf::RenderWindow& ventana;
    void dibujar();
};
#endif // ELEMENTO_H_
