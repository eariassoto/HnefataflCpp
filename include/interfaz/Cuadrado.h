#ifndef CUADRADO_H_
#define CUADRADO_H_
#include <string>
#include "Figura.h"

/** \brief En la interfaz grafica representa un cuadro del tablero.
 */
class Cuadrado: public Figura
{

public:

    /** \brief Calcula el color de un cuadro, es estatico puesto que se llama para la fabrica de figuras
     *
     * \param coordX int
     * \param coordY int
     * \return sf::Color
     *
     */
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

    Cuadrado(sf::Color c, int x, int y, int t, sf::RenderWindow& v):rectangulo(sf::Vector2f(t, t)), Figura(v)
    {
        rectangulo.setFillColor(c);
        rectangulo.setPosition(y*t, x*t);
    }

    /** \brief Dibuja en la referencia de ventana que tiene los elementos graficos.
         *
         * \return void
         *
         */
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

    /** \brief Calcula si en su cuadro esta el punto indicado por los parametros, estos son pixeles obtenidos de la ventana.
     *
     * \param x int
     * \param y int
     * \return int*
     *
     */
    int* contiene(int x, int y)
    {
        if(rectangulo.getGlobalBounds().contains(x, y))
        {
            int* coord = new int[2];
            if(rectangulo.getGlobalBounds().top == 0)
                coord[0] = 0;
            else
                coord[0] = rectangulo.getGlobalBounds().top / rectangulo.getGlobalBounds().width;
            if(rectangulo.getGlobalBounds().left == 0)
                coord[1] = 0;
            else
                coord[1] = rectangulo.getGlobalBounds().left / rectangulo.getGlobalBounds().height;
            return coord;
        }
        else
        {
            return 0;
        }
    }

private:

    sf::RectangleShape rectangulo;
};
#endif // CUADRADO_H_
