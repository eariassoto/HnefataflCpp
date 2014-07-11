#ifndef REY_H_
#define REY_H_
#include <memory>
#include "FichaBlanca.h"
#include "Cuadro.h"

class Rey : public FichaBlanca
{
public:
    Rey(shared_ptr<Figura> f, shared_ptr<Cuadro> t):FichaBlanca(f), trono(t), reserva(t) {};
    shared_ptr<Cuadro> mover(shared_ptr<Cuadro>);
    bool esCuadro(shared_ptr<Cuadro> c);

    //TODO define scope
    shared_ptr<Cuadro> trono, reserva;

};
#endif // REY_H_
