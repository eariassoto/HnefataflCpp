#include "Tablero.h"
Tablero::Tablero(int t):dimension(t), matriz(t,t)
{
}


void Tablero::agregarFicha(int i, int j, Cuadro* c)
{
    matriz(i,j) = c;
    if(i > 0 && matriz(i-1,j))
    {
        matriz(i,j)->setPtr(Cuadro::ARR, matriz(i-1, j)); //ARR
        matriz(i-1, j)->setPtr(Cuadro::ABA, matriz(i,j));
    }

    if(j < (matriz.y()-1) && matriz(i, j+1))
    {
        matriz(i,j)->setPtr(Cuadro::DER, matriz(i, j+1)); //DER
        matriz(i, j+1)->setPtr(Cuadro::IZQ, matriz(i,j));
    }

    if(i < (matriz.x()-1) && matriz(i+1, j))
    {
        matriz(i,j)->setPtr(Cuadro::ABA, matriz(i+1, j)); //ABA
        matriz(i+1, j)->setPtr(Cuadro::ARR, matriz(i,j));
    }
    if(j > 0)
    {
        if(matriz(i,j-1))
        {
            matriz(i,j)->setPtr(Cuadro::IZQ, matriz(i, j-1)); //IZQ
            matriz(i, j-1)->setPtr(Cuadro::DER, matriz(i,j));
        }
    }
}

void Tablero::imprimir()
{
    for(int i = 0; i < dimension; i++)
        for(int j = 0; j < dimension; j++)
            cout << "Soy " << i << ", " << j << " " << matriz(i,j) << " ARR: " << matriz(i,j)->getPtr(0) << " DER: " << matriz(i,j)->getPtr(1) << " ABA: " << matriz(i,j)->getPtr(2) << " IZQ: " << matriz(i,j)->getPtr(3) << endl;
}

bool Tablero::mover(int* f, int* g)
{
    try
    {
        matriz(f[0], f[1])->mover(matriz(g[0], g[1]));
        matriz(f[0], f[1])->mover(matriz(g[0], g[1]));
        return true;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }
}

Cuadro* Tablero::getFicha(int x, int y)
{
    return matriz(x,y);
}
