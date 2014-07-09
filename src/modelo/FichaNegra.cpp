#include "FichaNegra.h"

vector<Cuadro*> FichaNegra::comer()
{
    int i = 0;
    vector<Cuadro*> v;
    while(i<4)
    {
        if(esEnemigo(getPtr(i)))
            if(esAliado(getPtr(i)->getPtr(i)))
            {
                v.push_back(getPtr(i));
            }
        i++;
    }
    return v;
    return Ficha::comer();
};

bool FichaNegra::esEnemigo(Cuadro* c)
{
    Cuadro* r = dynamic_cast<FichaBlanca*>(c);
    return r;
}

bool FichaNegra::esAliado(Cuadro* c)
{
    if(c == 0)
        return true;
    else
    {
        Cuadro* r = dynamic_cast<FichaNegra*>(c);
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





