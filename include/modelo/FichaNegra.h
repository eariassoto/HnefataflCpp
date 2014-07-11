#ifndef FICHANEGRA_H_
#define FICHANEGRA_H_
#include <memory>
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Esquina.h"


class FichaNegra : public Ficha
{
public:
    FichaNegra(Figura* f):Ficha(f) {};
    vector< shared_ptr<Cuadro> > comer();
    bool                         esEnemigo(shared_ptr<Cuadro>);
    bool                         esAliado(shared_ptr<Cuadro>);
    shared_ptr<Cuadro>           esRey(shared_ptr<Cuadro>, int);
    bool                         esAliadoContraRey(shared_ptr<Cuadro>, int);

    virtual void tell()
    {
        cout << "soy negra" << endl;
    };
};
#endif // FICHANEGRA_H_
