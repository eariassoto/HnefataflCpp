#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include "Ficha.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca(Cuadro* arr, Cuadro* der, Cuadro* aba, Cuadro* izq):Ficha(arr, der, aba, izq){};
    virtual void comer();
};
#endif // _FICHABLANCA_H_
