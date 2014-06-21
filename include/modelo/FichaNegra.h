#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include "Ficha.h"
class FichaNegra : public Ficha
{
public:
    FichaNegra(Figura* f):Ficha(f) {};
    void comer();
};
#endif // FICHANEGRA_H_
