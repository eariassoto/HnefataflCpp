#ifndef FABRICAFIGURA_H_
#define FABRICAFIGURA_H_
#include "Excepcion.h"
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
class FabricaFigura
{
public:

    static shared_ptr<Figura> crearCirculo(sf::Color c, int x, int y, int t, sf::RenderWindow& v)
    {
        return shared_ptr<Figura>(new Circulo(c, x, y, t, v));
    }

    static shared_ptr<Figura> crearCuadrado(sf::Color c, int x, int y, int t, sf::RenderWindow& v)
    {
        return shared_ptr<Figura>(new Cuadrado(c, x, y, t, v));
    }
};
#endif // FABRICAFIGURA_H_

