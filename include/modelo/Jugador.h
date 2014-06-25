#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <memory>
#include "Cuadro.h"

class Jugador
{
public:
    enum TipoFicha{
    BLANCA, NEGRA
    };

    Jugador(TipoFicha tF):tipoFicha(tF){};
    int x, y;

    bool esFichaMia(Cuadro* c){
        switch(tipoFicha){
    case BLANCA:
        return dynamic_cast<FichaBlanca*>(c);
    case NEGRA:
        return dynamic_cast<FichaNegra*>(c);
        }
    }
private:
    TipoFicha tipoFicha;

};

#endif // JUGADOR_H_
