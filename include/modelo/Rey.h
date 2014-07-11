#ifndef REY_H_
#define REY_H_
#include "FichaBlanca.h"
#include "Cuadro.h"

class Rey : public FichaBlanca
{
public:
    Rey(Figura* f, Cuadro * t):FichaBlanca(f), trono(t), reserva(t) {};
    Cuadro* mover(Cuadro*);
    bool esCuadro(Cuadro* c);

    //TODO define scope
    void tell()
    {
        cout << "soy rey"<< endl;
        getPtr(0)->tell();
        getPtr(1)->tell();
        getPtr(2)->tell();
        getPtr(3)->tell();
    };
    Cuadro *trono, *reserva;

};
#endif // REY_H_
