#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include "Cuadro.h"
#include "Excepcion.h"

using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha(Cuadro*, Cuadro*, Cuadro*, Cuadro*);
    virtual int* mover(Cuadro*);
    virtual void comer(){};
	virtual bool esCuadro(Cuadro*);
};

#endif // FICHA_H_
