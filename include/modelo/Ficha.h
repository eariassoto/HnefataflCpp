#ifndef FICHA_H_
#define FICHA_H_
#include <vector>
#include <exception>
#include "Cuadro.h"
#include "Excepcion.h"

using namespace std;

class Ficha: public Cuadro
{
public:
    Ficha(Figura*);

    virtual bool    mover(Cuadro*);
    virtual vector<Cuadro*> comer();
    virtual bool    esCuadro(Cuadro*);
    virtual void    moverFigura(int, int);
    virtual void    setFiguraVisible(bool);
    virtual bool    esEnemigo(Cuadro*)=0;
    virtual bool    esAliado(Cuadro*)=0;

protected:
    Figura *figura;
};



#endif // FICHA_H_
