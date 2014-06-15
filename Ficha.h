#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include "Cuadro.h"
#include "Excepcion.h"

using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha();
    virtual Cuadro* mover(Cuadro*);
    virtual void comer(){};

protected:
    const int ARR, DER, ABA, IZQ; //sigue orden agujas reloj
    vector<Cuadro*> cuadroPtr;
};

#endif // FICHA_H_
