#include "Rey.h"

bool Rey::mover(Cuadro* c)
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
        return true;//coord;
    }
    else
    {
        throw Excepcion("No se puede mover en esta posicion");
    }
}


