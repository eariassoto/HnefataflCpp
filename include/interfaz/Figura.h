#ifndef FIGURA_H_
#define FIGURA_H_
#include <SFML/Graphics.hpp>
#include "Excepcion.h"

/** \brief Clase base para los elemetos graficos de la ventana
 */
class Figura
{
public:

    Figura(sf::RenderWindow& v):ventana(v)
    {
        visible = true;

    };

    ///Procedimientos vacios definidos por sus hijos.
    virtual void                dibujar() = 0;
    virtual sf::RectangleShape& getRect() = 0;
    virtual sf::CircleShape&    getCirc() = 0;

    virtual void                setVisible(bool b)
    {
        visible = b;
    };

    virtual int*                contiene(int, int)
    {
        throw Excepcion("no busco, soy ficha");
    };

protected:
    sf::RenderWindow& ventana;
    bool visible;
};
#endif // ELEMENTO_H_
