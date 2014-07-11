#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include <memory>
#include "Cuadro.h"
#include "Figura.h"


using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha(Figura*);

    virtual shared_ptr<Cuadro>           mover(shared_ptr<Cuadro>);
    virtual vector< shared_ptr<Cuadro> > comer();
    virtual bool                         esCuadro(shared_ptr<Cuadro>);
    virtual void                         moverFigura(int, int);
    virtual void                         setFiguraVisible(bool);
    virtual bool                         esEnemigo(shared_ptr<Cuadro>)=0;
    virtual bool                         esAliado(shared_ptr<Cuadro>)=0;

protected:
    Figura *figura;
};



#endif // FICHA_H_
