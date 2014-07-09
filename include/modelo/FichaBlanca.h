#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include "Ficha.h"
#include "FichaNegra.h"
#include "Esquina.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca(Figura* f):Ficha(f) {};
    virtual bool esEnemigo(Cuadro*);
    virtual bool esAliado(Cuadro*);
};
#endif // _FICHABLANCA_H_
