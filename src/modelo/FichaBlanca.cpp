#include "FichaBlanca.h"

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
            r = dynamic_cast<Esquina*>(c);
            if(r)
                return true;
            else
                return false;
        }
    }
}




