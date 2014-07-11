#include "Rey.h"
#include "Trono.h"
#include "Esquina.h"
#include "Excepcion.h"

shared_ptr<Cuadro> Rey::mover(shared_ptr<Cuadro> c)
{
    int i = 0;
    bool encontrado = false;
    bool b = false;
    int pos = 0;

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
        if(trono == reserva)
        {
            shared_ptr<Trono> t = dynamic_pointer_cast<Trono>(trono);
            t->setFiguraVisible(true);

            reserva = c;
            for(int i = 0; i < 4; i++)
            {
                trono->setPtr(i, c->getPtr(i));
            }
            return trono;
        }
        else if(trono == c)
        {
            shared_ptr<Trono> t = dynamic_pointer_cast<Trono>(trono);
            t->setFiguraVisible(false);

            shared_ptr<Cuadro> ret = reserva;
            for(int i = 0; i < 4; i++)
            {
                reserva->setPtr(i, c->getPtr(i));
            }
            reserva = c;
            return ret;
        }
        else
        {
            return c;
        }
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
