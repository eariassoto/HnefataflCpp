#include "Rey.h"
#include "Trono.h"
#include "Esquina.h"
#include "Excepcion.h"

Cuadro* Rey::mover(Cuadro* c)
{
    int i = 0;
    bool encontrado = false;
    bool b = false;
    int pos = 0;

    while(i < 4 && !encontrado)
    {
        Cuadro * vecino = getPtr(i);
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
            cout << "cambiotrono" << endl;
            Trono* t = dynamic_cast<Trono*>(trono);
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
            Cuadro * ret = reserva;
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

bool Rey::esCuadro(Cuadro* c)
{
    try
    {
        Cuadro* r = dynamic_cast<Ficha*>(c);
        if(r)
            return !r;
        else
        {
            r = dynamic_cast<Esquina*>(c);
            if(r)
                return !r;
            else
            {
                r = dynamic_cast<Trono*>(c);
                return !r;
            }
        }
    }
    catch(exception& e)
    {
        cout << e.what();
    }
}
