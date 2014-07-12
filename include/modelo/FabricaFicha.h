#ifndef FABRICAFICHA_H_
#define FABRICAFICHA_H_
#include "Excepcion.h"
#include "Figura.h"
#include "Cuadro.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Esquina.h"
#include "Rey.h"

class FabricaFicha
{
public:

    enum TipoFicha
    {
        BLANCA,
        NEGRA,
        ESQUINA,
        REY
    };

    static shared_ptr<Cuadro> crearCuadro()
    {
        return shared_ptr<Cuadro>(new Cuadro());
    }

    static shared_ptr<Cuadro> crearFicha(TipoFicha tipoFicha, shared_ptr<Figura> f)
    {
        switch (tipoFicha)
        {
        case BLANCA:
            return shared_ptr<Cuadro>(new FichaBlanca(f));
        case NEGRA:
            return shared_ptr<Cuadro>(new FichaNegra(f));
        case ESQUINA:
            return shared_ptr<Cuadro>(new Esquina(f));
        case REY:
            return shared_ptr<Cuadro>(new Rey(f));
        }
        throw Excepcion("tipo de ficha invalida.");
    }
};
#endif // FABRICAFICHA_H_
