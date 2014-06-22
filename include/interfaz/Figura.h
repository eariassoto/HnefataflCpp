#ifndef FIGURA_H_
#define FIGURA_H_
#include <SFML/Graphics.hpp>
#include "Excepcion.h"

class Figura
{
public:

    Figura(sf::RenderWindow& v):ventana(v)
    {
        visible = true;
    };

    virtual void                dibujar() = 0;
    virtual sf::RectangleShape& getRect() = 0;
    virtual sf::CircleShape&    getCirc() = 0;
    virtual void                setVisible(bool b)
    {
        visible = b;
    };

protected:
    sf::RenderWindow& ventana;
    bool visible;
};
#endif // ELEMENTO_H_
