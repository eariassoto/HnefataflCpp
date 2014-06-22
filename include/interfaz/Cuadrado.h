#ifndef CUADRADO_H_
#define CUADRADO_H_
#include <string>
#include "Figura.h"

class Cuadrado: public Figura
{
public:

    static sf::Color getColorCuadro(int coordX, int coordY)
    {
        if (coordX % 2 == 0)
        {
            if (coordY % 2 == 0)
                return sf::Color(0,54,107);
            else
                return sf::Color(0,148,255);
        }
        else
        {
            if (coordY % 2 == 0)
                return sf::Color(0,148,255);
            else
                return sf::Color(0,54,107);
        }
    }

    Cuadrado(sf::RectangleShape& r, sf::RenderWindow& v):rectangulo(r), Figura(v) {};

    Cuadrado(sf::Color c, int x, int y, int t, sf::RenderWindow& v):rectangulo(sf::Vector2f(t, t)), Figura(v)
    {
        rectangulo.setFillColor(c);
        rectangulo.setPosition(x*t, y*t);
    }

    void dibujar()
    {
        if(visible)
            ventana.draw(rectangulo);
    }

    sf::CircleShape& getCirc()
    {
        throw Excepcion("Soy un cuadro");
    };
    sf::RectangleShape& getRect()
    {
        return rectangulo;
    };

private:

    sf::RectangleShape rectangulo;
};
#endif // CUADRADO_H_
