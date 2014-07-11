#include "Jugador.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"

Jugador::Jugador(TipoFicha tF):tipoFicha(tF)
{
    seleccion = false;
    selX = -1;
    selY = -1;
};

bool Jugador::esFichaMia(shared_ptr<Cuadro> c)
{
    switch(tipoFicha)
    {
    case BLANCA:
    {
        shared_ptr<Cuadro> f = dynamic_pointer_cast<FichaBlanca>(c);
        if(f)
            return true;
        else
            return false;
    }
    break;
    case NEGRA:
    {
        shared_ptr<Cuadro> f = dynamic_pointer_cast<FichaNegra>(c);
        if(f)
            return true;
        else
            return false;
    }
    break;
    }
}

void Jugador::seleccionar(int x, int y)
{
    seleccion = true;
    selX = x;
    selY = y;
}

int* Jugador::getSeleccion()
{
    int* aux = new int[2];
    aux[0] = selX;
    aux[1] = selY;
    return aux;
}
