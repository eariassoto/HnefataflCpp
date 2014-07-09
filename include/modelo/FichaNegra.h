#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Rey.h"
#include "Esquina.h"

class FichaNegra : public Ficha
{
public:
    FichaNegra(Figura* f):Ficha(f) {};
    vector<Cuadro*> comer();
    virtual bool    esEnemigo(Cuadro*);
    virtual bool    esAliado(Cuadro*);
};
#endif // FICHANEGRA_H_
