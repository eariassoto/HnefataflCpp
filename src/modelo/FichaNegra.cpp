#include "FichaNegra.h"
#include <exception>
#include "FichaBlanca.h"
#include "Rey.h"

vector< shared_ptr<Cuadro> > FichaNegra::comer()
{
    int i = 0;
    vector< shared_ptr<Cuadro> > v;
    while(i<4)
    {
        if(getPtr(i))
        {
            shared_ptr<Cuadro> r = esRey(getPtr(i), i);
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
    return Ficha::comer();
};

bool FichaNegra::esEnemigo(shared_ptr<Cuadro> c)
{

    shared_ptr<Cuadro> r = dynamic_pointer_cast<Rey>(c);
    if(r)
        return false;
    else
    {
        r = dynamic_pointer_cast<FichaBlanca>(c);
        if(r)
            return true;
        else
            return false;
    }
}

bool FichaNegra::esAliado(shared_ptr<Cuadro> c)
{
    if(c == 0)
        return true;
    else
    {
        shared_ptr<Cuadro> r = dynamic_pointer_cast<FichaNegra>(c);
        if(r)
        {
            return true;
        }
        else
        {
            r = dynamic_pointer_cast<Esquina>(c);
            if(r)
                return true;
            else
                return false;
        }
    }
}

shared_ptr<Cuadro> FichaNegra::esRey(shared_ptr<Cuadro> c, int i)
{
    shared_ptr<Cuadro> r;
    if(c)
    {
        r = dynamic_pointer_cast<Rey>(c);
        if(!r && c->getPtr(i))
        {
            r = dynamic_pointer_cast<Rey>(c->getPtr(i));
        }
    }
    return r;
}

bool FichaNegra::esAliadoContraRey(shared_ptr<Cuadro> c, int i)
{
    if(FichaNegra::esAliado(c))
    {
        return true;
    }
    else
    {
        shared_ptr<Cuadro> f = dynamic_pointer_cast<FichaBlanca>(c);
        if(f)
        {
            shared_ptr<Cuadro> fN = dynamic_pointer_cast<FichaNegra>(c->getPtr(i));
            if(fN)
                return true;
            else
                return false;
        }
    }
}





