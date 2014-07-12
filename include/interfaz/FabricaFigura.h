#ifndef FABRICAFIGURA_H_
#define FABRICAFIGURA_H_
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"

/** \brief Clase util para crear instancias de distintas clases de una manera mas limpia.
 */
class FabricaFigura
{

public:

    enum TipoFigura ///Para identificar la figura que me piden
    {
        CUADRADO,
        CIRCULO,
    };

    /** \brief Crea nuevas instancias de las clases derivadas de figura.
     *
     * \param tipoFigura TipoFigura
     * \param c sf::Color
     * \param x int
     * \param y int
     * \param t int
     * \param v sf::RenderWindow&
     * \return shared_ptr<Figura>
     *
     */
    static shared_ptr<Figura> crearFigura(TipoFigura tipoFigura, sf::Color c, int x, int y, int t, sf::RenderWindow& v)
    {
        switch (tipoFigura)
        {
        case CUADRADO:
            return shared_ptr<Figura>(new Cuadrado(c, x, y, t, v));
        case CIRCULO:
            return shared_ptr<Figura>(new Circulo(c, x, y, t, v));
        }
    }
};
#endif // FABRICAFIGURA_H_
