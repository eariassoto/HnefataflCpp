#ifndef REY_H_
#define REY_H_
#include "FichaBlanca.h"
class Rey : public FichaBlanca
{
public:
    Rey(Figura* f):FichaBlanca(f) {};
    void comer();
};
#endif // REY_H_
