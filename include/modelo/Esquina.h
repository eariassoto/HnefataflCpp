#ifndef _ESQUINA_H_
#define _ESQUINA_H_

#include "Cuadro.h"
#include "Figura.h"

class Esquina: public Cuadro
{
public:
    Esquina(Figura* f): figura(f), Cuadro(){};
    virtual void tell(){cout << "soy esquina" << endl;};

protected:
    Figura* figura;
};
#endif // _ESQUINA_H_
