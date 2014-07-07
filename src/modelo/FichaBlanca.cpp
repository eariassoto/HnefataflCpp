#include "FichaBlanca.h"

Cuadro* FichaBlanca::comer()
{
    int i = 0;
    while(i<4)
    {
        if(esEnemigo(getPtr(i)))
            if(esAliado(getPtr(i)->getPtr(i)))
            {
                return getPtr(i);
            }
        i++;
    }
    return 0;
};

bool FichaBlanca::esEnemigo(Cuadro* c)
{
    Cuadro* r = dynamic_cast<FichaNegra*>(c);
    return r;
}

bool FichaBlanca::esAliado(Cuadro* c)
{
    if(c == 0)
        return true;
    else
    {
        Cuadro* r = dynamic_cast<FichaBlanca*>(c);
        if(r)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

