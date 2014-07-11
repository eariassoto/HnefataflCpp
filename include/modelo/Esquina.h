#ifndef _ESQUINA_H_
#define _ESQUINA_H_
#include <memory>
#include "Cuadro.h"
#include "Figura.h"

class Esquina: public Cuadro
{
public:
    Esquina(shared_ptr<Figura> f): figura(f), Cuadro() {};

protected:
    shared_ptr<Figura> figura;
};
#endif // _ESQUINA_H_
