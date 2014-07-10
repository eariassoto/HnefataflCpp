#ifndef _TRONO_H_
#define _TRONO_H_

#include "Cuadro.h"
#include "Figura.h"

class Trono: public Cuadro
{
public:
    Trono(Figura* f): figura(f), Cuadro()
    {
        figura->setVisible(false);
    };

    void setFiguraVisible(bool b)
    {
        figura->setVisible(b);
    };

protected:
    Figura* figura;
};
#endif // _TRONO_H_

