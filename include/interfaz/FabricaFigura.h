#ifndef FABRICAFIGURA_H_
#define FABRICAFIGURA_H_
#include "Excepcion.h"
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
class FabricaFigura
{
public:
    enum TipoFigura
    {
        CUADRADO,
        CIRCULO,
    };
    static Figura *crearFigura(TipoFigura tipoFigura, sf::Color c, int x, int y, int t, sf::RenderWindow& v)
    {
        switch (tipoFigura)
        {
        case CUADRADO:
            return new Cuadrado(c, x, y, t, v);
        case CIRCULO:
            return new Circulo(c, x, y, t, v);
        }
        throw Excepcion("tipo de figura invalida.");
    }
};
#endif // FABRICAFIGURA_H_

