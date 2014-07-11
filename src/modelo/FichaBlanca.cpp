#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Esquina.h"

bool FichaBlanca::esEnemigo(shared_ptr<Cuadro> c)
{
    shared_ptr<Cuadro> r = dynamic_pointer_cast<FichaNegra>(c);
    if(r)
        return true;
    else
        return false;
}

bool FichaBlanca::esAliado(shared_ptr<Cuadro> c)
{
    if(c == 0)
        return true;
    else
    {
        shared_ptr<Cuadro> r = dynamic_pointer_cast<FichaBlanca>(c);
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




