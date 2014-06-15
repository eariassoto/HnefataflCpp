#include <iostream>
#include <utility>
#include "Matriz.h"
#include "Excepcion.h"
#include "Cuadro.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Interfaz.h"

using namespace std;

int main()
{
    try
    {
        Matriz<double> m(10,10);
        m(5,8) = 106.15;
        cout << m(5,8) << endl;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }

    try
    {
        Cuadro * c = new Cuadro();
        c->mover(c)->comer();
        delete c;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }

    try
    {
        FichaBlanca * f = new FichaBlanca();
        f->mover(f)->comer();
        delete f;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }

    Interfaz * i = new Interfaz();
   /* Interfaz * j = new Interfaz();
    cout << "puntero de i " << i << endl;
    cout << "puntero de j " << j << endl;
    cout << "dir de i " << &i << endl;
    cout << "dir de j " << &j << endl;
    swap(i,j);
    cout << "puntero de i " << i << endl;
    cout << "puntero de j " << j << endl;
    cout << "dir de i " << &i << endl;
    cout << "dir de j " << &j << endl;*/

    return 0;
}
