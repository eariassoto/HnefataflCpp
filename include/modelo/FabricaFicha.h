#ifndef FABRICAFICHA_H_
#define FABRICAFICHA_H_
#include "Excepcion.h"
#include "Figura.h"
#include "Cuadro.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Rey.h"
class FabricaFicha
{
public:

    enum TipoFicha
    {
        CUADRO,
        BLANCA,
        NEGRA,
        REY
    };
    static Cuadro* crearFicha(TipoFicha tipoFicha, Figura* f)
    {
        switch (tipoFicha)
        {
        case CUADRO:
            return new Cuadro(f);
        case BLANCA:
            return new FichaBlanca(f);
        case NEGRA:
            return new FichaNegra(f);
        case REY:
            return new Rey(f);
        }
        throw Excepcion("tipo de ficha invalida.");
    }
};
#endif // FABRICAFICHA_H_
