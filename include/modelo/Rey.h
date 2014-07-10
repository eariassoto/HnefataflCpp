#ifndef REY_H_
#define REY_H_
#include "FichaBlanca.h"
#include "Cuadro.h"

class Rey : public FichaBlanca
{
public:
    Rey(Figura* f, Cuadro * t):FichaBlanca(f), trono(t){};
    bool mover(Cuadro*);

    //TODO define scope
    Cuadro* trono;

};
#endif // REY_H_
