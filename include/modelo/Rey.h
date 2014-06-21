#ifndef REY_H_
#define REY_H_
#include "FichaBlanca.h"
class Rey : public FichaBlanca
{
public:
    Rey(Cuadro* arr, Cuadro* der, Cuadro* aba, Cuadro* izq):FichaBlanca(arr, der, aba, izq) {};
    void comer();
};
#endif // REY_H_
