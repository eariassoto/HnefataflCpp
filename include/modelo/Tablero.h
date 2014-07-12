#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
#include <memory>
#include "Cuadro.h"

using namespace std;

/** \brief Controla y maneja la matriz de fichas y las operaciones sobre estas.
 */
class Tablero
{
public:

    Tablero(int);

    /** \brief Agrega punteros a la matriz
     *
     * \param int
     * \param int
     * \param shared_ptr<Cuadro>
     * \return void
     *
     */
    void               agregarFicha(int, int, shared_ptr<Cuadro>);

    void               imprimir();

    /** \brief Envia una ficha a mover.
     *
     * \param int*
     * \param int*
     * \return bool
     *
     */
    bool               mover(int*, int*);

    shared_ptr<Cuadro> getFicha(int, int);

    void               setFiguraVisible(shared_ptr<Cuadro>, bool);

    /** \brief Evalua los resultados del comer de una ficha.
     *
     * \param > vector<shared_ptr<Cuadro>
     * \return void
     *
     */
    void               comer(vector<shared_ptr<Cuadro> >);

    int                getDimension();

    int                finJuego;

private:
    vector< vector<shared_ptr<Cuadro> > > vmatriz; ///Matriz de punteros.
    int                                   dimension;

};
#endif // _TABLERO_H_
