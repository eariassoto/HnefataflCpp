#ifndef FIGURA_H_
#define FIGURA_H_
#include <SFML/Graphics.hpp>

class Figura{
public:
    Figura(sf::RenderWindow& v):ventana(v){};
    virtual void dibujar() = 0;
protected:
    sf::RenderWindow& ventana;
};
#endif // ELEMENTO_H_
