#include "Tablero.h"
Tablero::Tablero(int t):matriz(t,t)
{
}


void Tablero::agregarFicha(int i, int j, Cuadro* c)
{
    matriz(i,j) == c;
    vector<Cuadro*> ptr;
    if(i > 0 && matriz(i-1,j))
    {
        ptr.push_back(matriz(i-1, j)); //ARR
        matriz(i-1, j)->setPuntero(Cuadro::ABA, matriz(i,j));
    }

    if(j < (matriz.y()-1))
    {
        ptr.push_back(matriz(i, j+1)); //DER
        matriz(i, j+1)->setPuntero(Cuadro::IZQ, matriz(i,j));
    }

    if(i < (matriz.x()-1))
    {
        ptr.push_back(matriz(i+1, j)); //ABA
        matriz(i+1, j)->setPuntero(Cuadro::ARR, matriz(i,j));
    }

    if(j > 0 && matriz(i,j-1))
    {
        ptr.push_back(matriz(i, j-1)); //IZQ
        matriz(i, j-1)->setPuntero(Cuadro::DER, matriz(i,j));
    }

}
