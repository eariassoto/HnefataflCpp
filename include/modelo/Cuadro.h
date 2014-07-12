#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

/** \brief Clase base de las fichas del tablero, tiene las operaciones basicas de intercambios de punteros y declaraciones virtuales vacias.
 */
class Cuadro: public enable_shared_from_this<Cuadro>
{
public:

    Cuadro();

    ///Implementaciones vacias.
    virtual shared_ptr<Cuadro>              mover(shared_ptr<Cuadro>);
    virtual vector< shared_ptr<Cuadro> >    comer();

    shared_ptr<Cuadro>                      getPtr(int);
    void                                    setPtr(int, shared_ptr<Cuadro>);

    /** \brief Inteercambia debidamente los punteros entre dos objetos.
     *
     * \param shared_ptr<Cuadro>
     * \return virtual void
     *
     */
    void                                    swap(shared_ptr<Cuadro>);

    /// Constantes
    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3;

protected:

    shared_ptr<Cuadro> cuadroArr, cuadroDer, cuadroAba, cuadroIzq; ///Punteros hacia los vecinos en el tablero.
};
#endif // _CUADRO_H_
