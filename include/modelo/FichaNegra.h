#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include "Ficha.h"
class FichaNegra : public Ficha
{
public:
    FichaNegra(Cuadro* arr, Cuadro* der, Cuadro* aba, Cuadro* izq):Ficha(arr, der, aba, izq) {};
    void comer();
};
#endif // FICHANEGRA_H_
