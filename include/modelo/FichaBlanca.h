#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include "Ficha.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca(Figura* f):Ficha(f) {};
    virtual bool esEnemigo(Cuadro*);
    virtual bool esAliado(Cuadro*);
    virtual void tell()
    {
        cout << "soy blanca" << endl;
    };
};
#endif // _FICHABLANCA_H_
