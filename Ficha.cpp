#include "Ficha.h"

Ficha::Ficha():Cuadro(), ARR(0), DER(1), ABA(2), IZQ(3)
{
    //ctor
}

Cuadro* Ficha::mover(Cuadro* c)
{
    cout << "movi\n";
    return this;
}

