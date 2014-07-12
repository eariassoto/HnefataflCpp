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

/** \brief Clase util para crear instancias de distintas clases de una manera mas limpia.
 */
class FabricaFicha
{
public:

    enum TipoFicha ///Para identificar la figura que me piden
    {
        BLANCA,
        NEGRA,
        ESQUINA,
        REY
    };

    /** \brief Crea instancias de Cuadro
     *
     * \return shared_ptr<Cuadro>
     *
     */
    static shared_ptr<Cuadro> crearCuadro()
    {
        return shared_ptr<Cuadro>(new Cuadro());
    }

    /** \brief Crea nuevas instancias de las clases derivadas de Cuadro.
     *
     * \param tipoFicha TipoFicha
     * \param f shared_ptr<Figura>
     * \return shared_ptr<Cuadro>
     *
     */
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
