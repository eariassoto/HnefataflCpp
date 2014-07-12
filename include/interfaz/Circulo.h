#ifndef CIRCULO_H_
#define CIRCULO_H_
#include <string>
#include "Figura.h"
#include "Excepcion.h"

/** \brief En la interfaz, representa una ficha del tablero.
 */
class Circulo: public Figura
{

public:

    Circulo(sf::Color c, int x, int y, int t, sf::RenderWindow& v):circulo(t/2), Figura(v)
    {
        circulo.setFillColor(c);
        circulo.setPosition(y*t, x*t);
    }

    /** \brief Dibuja en la referencia de ventana que tiene los elementos graficos.
     *
     * \return void
     *
     */
    void dibujar()
    {
        if(visible)
            ventana.draw(circulo);
    }

    sf::RectangleShape& getRect()
    {
        throw Excepcion("Soy un circulo");
    };

    sf::CircleShape& getCirc()
    {
        return circulo;
    };

private:
    sf::CircleShape circulo;
};
#endif // CIRCULO_H_
