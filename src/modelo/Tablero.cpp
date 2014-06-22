#include "Tablero.h"
Tablero::Tablero(int t):dimension(t), matriz(t,t)
{
}


void Tablero::agregarFicha(int i, int j, Cuadro* c)
{
    matriz(i,j) = c;
    if(i > 0 && matriz(i-1,j))
    {
        matriz(i,j)->setPuntero(Cuadro::ARR, matriz(i-1, j)); //ARR
        matriz(i-1, j)->setPuntero(Cuadro::ABA, matriz(i,j));
    }

    if(j < (matriz.y()-1) && matriz(i, j+1))
    {
        matriz(i,j)->setPuntero(Cuadro::DER, matriz(i, j+1)); //DER
        matriz(i, j+1)->setPuntero(Cuadro::IZQ, matriz(i,j));
    }

    if(i < (matriz.x()-1) && matriz(i+1, j))
    {
        matriz(i,j)->setPuntero(Cuadro::ABA, matriz(i+1, j)); //ABA
        matriz(i+1, j)->setPuntero(Cuadro::ARR, matriz(i,j));
    }
    if(j > 0)
    {
        if(matriz(i,j-1))
        {
            matriz(i,j)->setPuntero(Cuadro::IZQ, matriz(i, j-1)); //IZQ
            matriz(i, j-1)->setPuntero(Cuadro::DER, matriz(i,j));
        }
    }
}

void Tablero::imprimir()
{
    for(int i = 0; i < dimension; i++)
        for(int j = 0; j < dimension; j++)
            cout << "Soy " << i << ", " << j << " " << matriz(i,j) << " ARR: " << matriz(i,j)->cuadroPtr[0] << " DER: " << matriz(i,j)->cuadroPtr[1] << " ABA: " << matriz(i,j)->cuadroPtr[2] << " IZQ: " << matriz(i,j)->cuadroPtr[3] << endl;
}

void Tablero::mover(int i1, int j1, int i2, int j2)
{
    vector<Cuadro*> aux = matriz(i1,j1)->getPunteros();
    matriz(i1, j1)->setNuevosPunteros(matriz(i2, j2)->getPunteros());
    matriz(i2, j2)->setNuevosPunteros(aux);
    matriz.swap(i1,j1,i2,j2);
}
