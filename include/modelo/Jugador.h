#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <memory>
#include "Cuadro.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"

class Jugador
{
public:
    enum TipoFicha
    {
        BLANCA, NEGRA
    };

    Jugador(TipoFicha);
    int x, y;

    bool esFichaMia(Cuadro*);
    void seleccionar(int, int);
    int* getSeleccion();

    bool seleccion;

private:
    TipoFicha tipoFicha;
    int selX, selY;
};

#endif // JUGADOR_H_
