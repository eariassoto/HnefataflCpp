#include "FichaNegra.h"
#include <exception>
#include "FichaBlanca.h"
#include "Rey.h"

vector<Cuadro*> FichaNegra::comer()
{
    cout << "este rollo" << endl;
    int i = 0;
    vector<Cuadro*> v;
    while(i<4)
    {
        if(getPtr(i))
        {
            Cuadro * r = esRey(getPtr(i), i);
            if(r)
            {
                int j = 0;
                for(int i = 0; i < 4; i++)
                {
                    if(esAliadoContraRey(r->getPtr(i),i))
                        j++;
                }
                if(j==4)
                {
                    v.push_back(r);
                    return v;
                    i = 4; ///STAHP
                }
                else
                    i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    cout << "sali del rollo" << endl;
    return Ficha::comer();
};

bool FichaNegra::esEnemigo(Cuadro* c)
{

    Cuadro* r = dynamic_cast<Rey*>(c);
    if(r)
        return false;
    else
    {
        r = dynamic_cast<FichaBlanca*>(c);
        return r;
    }
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

Cuadro* FichaNegra::esRey(Cuadro* c, int i)
{
    Cuadro* r;
    if(c)
    {
        r = dynamic_cast<Rey*>(c);
        if(!r && c->getPtr(i))
        {
            r = dynamic_cast<Rey*>(c->getPtr(i));
        }
    }
    return r;
}

bool FichaNegra::esAliadoContraRey(Cuadro* c, int i)
{
    if(FichaNegra::esAliado(c))
    {
        return true;
    }
    else
    {
        Cuadro* f = dynamic_cast<FichaBlanca*>(c);
        if(f)
        {
            Cuadro* fN = dynamic_cast<FichaNegra*>(c->getPtr(i));
            return fN;
        }
    }
}





