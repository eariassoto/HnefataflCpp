#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include <memory>
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Esquina.h"


/** \brief Reune los comportamientos de las fichas negras.
 */
class FichaNegra : public Ficha
{

public:

    FichaNegra(shared_ptr<Figura> f):Ficha(f) {};

    /** \brief Nueva definicion de comer ya que hay que considerar el caso del rey
     *
     * \return vector< shared_ptr<Cuadro>>
     *
     */
    vector< shared_ptr<Cuadro> > comer();

    /** \brief Verifica si un puntero corresponde a una ficha enemiga
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    bool                         esEnemigo(shared_ptr<Cuadro>);

    /** \brief Verifica si un puntero corresponde a una ficha aliada o algo que sirva para ayudarse a comer
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    bool                         esAliado(shared_ptr<Cuadro>);

    /** \brief Verifica si un puntero corresponde al rey
     *
     * \param shared_ptr<Cuadro>
     * \param int
     * \return shared_ptr<Cuadro>
     *
     */
    shared_ptr<Cuadro>           esRey(shared_ptr<Cuadro>, int);

    /** \brief Agrega y verifica otras reglas para poder comer al rey
     *
     * \param shared_ptr<Cuadro>
     * \param int
     * \return bool
     *
     */
    bool                         esAliadoContraRey(shared_ptr<Cuadro>, int);
};
#endif // FICHANEGRA_H_
