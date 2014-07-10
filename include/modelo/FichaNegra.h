#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Esquina.h"


class FichaNegra : public Ficha
{
public:
    FichaNegra(Figura* f):Ficha(f) {};
    vector<Cuadro*> comer();
    bool            esEnemigo(Cuadro*);
    bool            esAliado(Cuadro*);
    Cuadro*         esRey(Cuadro*, int);
    bool            esAliadoContraRey(Cuadro*, int);
    virtual void tell(){cout << "soy negra" << endl;};
};
#endif // FICHANEGRA_H_
