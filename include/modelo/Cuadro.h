#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include <iostream>

using namespace std;

class Cuadro
{
public:

    Cuadro();

    //cosas que tiran excepciones, mera prevencion
    virtual Cuadro*         mover(Cuadro*);
    virtual vector<Cuadro*> comer();

    virtual Cuadro*         getPtr(int);
    virtual void            setPtr(int, Cuadro*);
    virtual void            swap(Cuadro*);
    virtual void tell(){cout << "soy cuadro" << endl;};

    static const int ARR = 0, DER = 1, ABA = 2, IZQ = 3;

protected:
    Cuadro *cuadroArr, *cuadroDer, *cuadroAba, *cuadroIzq;
};
#endif // _CUADRO_H_
