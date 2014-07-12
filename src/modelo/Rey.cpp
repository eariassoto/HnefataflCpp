#include "Rey.h"
#include "Esquina.h"
#include "Excepcion.h"

shared_ptr<Cuadro> Rey::mover(shared_ptr<Cuadro> c)
{
    int i = 0;
    bool encontrado = false;
    bool b = false;
    int pos = 0;
    cout << "entonrdsgfsdg" << endl;
    while(i < 4 && !encontrado)
    {
        shared_ptr<Cuadro> vecino = getPtr(i);
        b = false;
        while(!b && vecino && esCuadro(vecino))
        {
            if(vecino == c)
            {
                pos = i;
                encontrado = true;
            }
            b = true;
        }
        i++;
    }
   if(encontrado)
    {
        moverFigura(pos, 1);
        return c;
    }
    else
    {
        cout <<"no se puede mover aqui dice el rey" << endl;
        return 0;
    }
}

bool Rey::esCuadro(shared_ptr<Cuadro> c)
{
    try
    {
        shared_ptr<Cuadro> r = dynamic_pointer_cast<Ficha>(c);
        if(!r)
            return true;
        else
            return false;
    }
    catch(exception& e)
    {
        cout << e.what();
    }
}
