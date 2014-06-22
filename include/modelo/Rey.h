#ifndef REY_H_
#define REY_H_
#include "FichaBlanca.h"
class Rey : public FichaBlanca
{
public:
    Rey(Figura* f):FichaBlanca(f) {};
    void comer();
    void agregarFiguraTrono(Figura*);
private:
    Figura* trono;
};
#endif // REY_H_
