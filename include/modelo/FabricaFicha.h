#ifndef FABRICAFICHA_H_
#define FABRICAFICHA_H_
#include "Excepcion.h"
#include "Figura.h"
#include "Cuadro.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Rey.h"
#include "Esquina.h"
class FabricaFicha
{
public:

    enum TipoFicha
    {
        BLANCA,
        NEGRA,
        REY,
        ESQUINA
    };

    static Cuadro* crearCuadro()
    {
        return new Cuadro();
    }

    static Cuadro* crearFicha(TipoFicha tipoFicha, Figura* f)
    {
        switch (tipoFicha)
        {
        case BLANCA:
            return new FichaBlanca(f);
        case NEGRA:
            return new FichaNegra(f);
        case REY:
            return new Rey(f);
        case ESQUINA:
            return new Esquina(f);
        }
        throw Excepcion("tipo de ficha invalida.");
    }
};
#endif // FABRICAFICHA_H_
