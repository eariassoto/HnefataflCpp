#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include <memory>
#include "Ficha.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca(shared_ptr<Figura> f):Ficha(f) {};
    virtual bool esEnemigo(shared_ptr<Cuadro>);
    virtual bool esAliado(shared_ptr<Cuadro>);

};
#endif // _FICHABLANCA_H_
