#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Cuadro: public enable_shared_from_this<Cuadro>
{
public:

    Cuadro();

    //cosas que tiran excepciones, mera prevencion
    virtual shared_ptr<Cuadro>              mover(shared_ptr<Cuadro>);
    virtual vector< shared_ptr<Cuadro> >    comer();

    virtual shared_ptr<Cuadro>              getPtr(int);
    virtual void                            setPtr(int, shared_ptr<Cuadro>);
    virtual void                            swap(shared_ptr<Cuadro>);

    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3;

//protected:
    shared_ptr<Cuadro> cuadroArr, cuadroDer, cuadroAba, cuadroIzq;
};
#endif // _CUADRO_H_
