#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Cuadro.h"

class Jugador
{
public:
    enum TipoFicha
    {
        BLANCA, NEGRA
    };

    Jugador(TipoFicha);
    int x, y;

    bool esFichaMia(shared_ptr<Cuadro>);
    void seleccionar(int, int);
    int* getSeleccion();
    bool seleccion;

private:
    TipoFicha tipoFicha;
    int selX, selY;
};

#endif // JUGADOR_H_
