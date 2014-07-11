#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include <memory>
#include "Ficha.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca(Figura* f):Ficha(f) {};
    virtual bool esEnemigo(shared_ptr<Cuadro>);
    virtual bool esAliado(shared_ptr<Cuadro>);
    virtual void tell()
    {
        cout << "soy blanca" << endl;
    };
};
#endif // _FICHABLANCA_H_
