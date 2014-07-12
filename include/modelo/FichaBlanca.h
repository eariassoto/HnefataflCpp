#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include <memory>
#include "Ficha.h"

/** \brief Reune los comportamientos de las fichas blancas.
 */
class FichaBlanca : public Ficha
{

public:

    FichaBlanca(shared_ptr<Figura> f):Ficha(f) {};

    /** \brief Verifica si un puntero corresponde a una ficha enemiga
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    virtual bool esEnemigo(shared_ptr<Cuadro>);

    /** \brief Verifica si un puntero corresponde a una ficha aliada o algo que sirva para ayudarse a comer
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    virtual bool esAliado(shared_ptr<Cuadro>);

};
#endif // _FICHABLANCA_H_
