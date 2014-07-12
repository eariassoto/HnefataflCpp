#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include <memory>
#include "Cuadro.h"
#include "Figura.h"

using namespace std;

/** \brief Reune comportamientos generales de las fichas blancas y negras, como por ejemplo mover.
 */
class Ficha: public Cuadro
{

public:

    Ficha(shared_ptr<Figura>);

    /** \brief Verifica si un puntero corresponde a una posicion valida hacia donde la ficha se puede mover.
     *
     * \param shared_ptr<Cuadro>
     * \return virtual shared_ptr<Cuadro>
     *
     */
    virtual shared_ptr<Cuadro>           mover(shared_ptr<Cuadro>);

    /** \brief Busca si la ficha puede comerse a otras
     *
     * \return virtual vector< shared_ptr<Cuadro>>
     *
     */
    virtual vector< shared_ptr<Cuadro> > comer();

    /** \brief Verifica si un puntero es de tipo Cuadro
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    virtual bool                         esCuadro(shared_ptr<Cuadro>);

    /** \brief Mueve a la representacion grafica de la ficha
     *
     * \param int
     * \param int
     * \return virtual void
     *
     */
    virtual void                         moverFigura(int, int);

    virtual void                         setFiguraVisible(bool);

    /** \brief Verifica si un puntero corresponde a una ficha enemiga (Implementado por hijos)
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    virtual bool                         esEnemigo(shared_ptr<Cuadro>)=0;

    /** \brief Verifica si un puntero corresponde a una ficha aliada (Implementado por hijos)
     *
     * \param shared_ptr<Cuadro>
     * \return virtual bool
     *
     */
    virtual bool                         esAliado(shared_ptr<Cuadro>)=0;

protected:

    shared_ptr<Figura> figura; ///Contenedor de la representacion grafica.
};



#endif // FICHA_H_
