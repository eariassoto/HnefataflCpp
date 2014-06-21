#include "Ficha.h"

Ficha::Ficha(Figura* f):Cuadro(f) {}

int* Ficha::mover(Cuadro* c)
{
    bool encontrado = false;
    int POS = 0;
    int pasos = 0;
    for(int i = 0; i < 4; i++)
    {
        Cuadro * vecino = cuadroPtr.at(i);
        pasos = 1;
        while(!encontrado && vecino != 0 && esCuadro(vecino))
        {
            if(vecino == c)
            {
                POS = i;
                encontrado = true;
            }
            else
            {
                pasos++;
                vecino = vecino->getVecino(i);
            }
        }
    }
    if(encontrado)
    {
        int * coord = new int(2);
        coord[0] = POS;
        coord[1] = pasos;
        return coord;
    }
    else
    {
        throw Excepcion("No se puede mover en esta posicion");
    }
}

bool Ficha::esCuadro(Cuadro* c)
{
    Cuadro* r = dynamic_cast<Ficha*>(c);
    return !r;
}
///todo probar el esCuadro() con las clases derivadas hijas
