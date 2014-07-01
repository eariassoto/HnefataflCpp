#include "Jugador.h"

Jugador::Jugador(TipoFicha tF):tipoFicha(tF)
{
    seleccion = false;
    selX = -1;
    selY = -1;
};

bool Jugador::esFichaMia(Cuadro* c)
{
    switch(tipoFicha)
    {
    case BLANCA:
        return dynamic_cast<FichaBlanca*>(c);
    case NEGRA:
        return dynamic_cast<FichaNegra*>(c);
    }
}

void Jugador::seleccionar(int x, int y)
{
    seleccion = true;
    selX = x;
    selY = y;
}

int* Jugador::getSeleccion(){
    int* aux = new int[2];
    aux[0] = selX;
    aux[1] = selY;
    return aux;
}
