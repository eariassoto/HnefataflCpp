#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Cuadro.h"

/** \brief Contiene informacion sobre un jugador
 */
class Jugador
{
public:

    enum TipoFicha ///Identifica con que ficha esta jugando
    {
        BLANCA, NEGRA
    };

    Jugador(TipoFicha);


    /** \brief Verifica si un puntero corresponde a una de sus fichas
     *
     * \param shared_ptr<Cuadro>
     * \return bool
     *
     */
    bool esFichaMia(shared_ptr<Cuadro>);

    /** \brief Mantiene la seleccion de ficha del usuario.
     *
     * \param int
     * \param int
     * \return void
     *
     */
    void seleccionar(int, int);

    int* getSeleccion();

    bool seleccion;

private:

    TipoFicha tipoFicha;
    int selX, selY;
    int x, y;
};

#endif // JUGADOR_H_
