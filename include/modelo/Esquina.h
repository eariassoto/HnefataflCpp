#ifndef _ESQUINA_H_
#define _ESQUINA_H_
#include "Cuadro.h"
class Esquina: public Cuadro
{

public:

    Esquina(Figura*);

protected:
    Figura* figura;
};
#endif // _ESQUINA_H_
