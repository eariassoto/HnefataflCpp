#include "Rey.h"

void Rey::comer()
{
    cout << "comi\n";
};

void Rey::agregarFiguraTrono(Figura* f)
{
    trono = f;
    trono->setVisible(false);
}


