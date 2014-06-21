#ifndef CIRCULO_H_
#define CIRCULO_H_
#include <string>
#include "Figura.h"
#include "Excepcion.h"

class Circulo: public Figura
{
public:
    Circulo(sf::CircleShape& c, sf::RenderWindow& v):circulo(c), Figura(v) {};

    Circulo(sf::Color c, int x, int y, int t, sf::RenderWindow& v):circulo(t/2), Figura(v)
    {
        circulo.setFillColor(c);
        circulo.setPosition(x*t, y*t);
    }

    void dibujar()
    {
        ventana.draw(circulo);
    }
private:
    sf::CircleShape circulo;
};
#endif // CIRCULO_H_
