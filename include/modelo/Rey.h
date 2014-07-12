#ifndef REY_H_
#define REY_H_
#include <memory>
#include "FichaBlanca.h"
#include "Cuadro.h"

class Rey : public FichaBlanca
{
public:
    Rey(shared_ptr<Figura> f):FichaBlanca(f){};
    shared_ptr<Cuadro> mover(shared_ptr<Cuadro>);
    bool esCuadro(shared_ptr<Cuadro> c);

};
#endif // REY_H_
