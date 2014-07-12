#ifndef REY_H_
#define REY_H_
#include <memory>
#include "FichaBlanca.h"
#include "Cuadro.h"

/** \brief Contiene los comportamientos especificos del rey
 */
class Rey : public FichaBlanca
{
public:
    Rey(shared_ptr<Figura> f):FichaBlanca(f) {};

    /** \brief Cambia las reglas del mover de Ficha.
     *
     * \param shared_ptr<Cuadro>
     * \return shared_ptr<Cuadro>
     *
     */
    shared_ptr<Cuadro> mover(shared_ptr<Cuadro>);

    /** \brief Cambia las reglas ya que el rey si se puede mover hacia una esquina
     *
     * \param c shared_ptr<Cuadro>
     * \return bool
     *
     */
    bool esCuadro(shared_ptr<Cuadro> c);

};
#endif // REY_H_
