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

bool Tablero::mover(int* f, int* g)
{
    try
    {
        cout << "ficha dice: " << matriz(f[0], f[1])->mover(matriz(g[0], g[1])) << endl;
        return true;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }
    // vector<Cuadro*> aux = matriz(i1,j1)->getPunteros();
    /// matriz(i1, j1)->setNuevosPunteros(matriz(i2, j2)->getPunteros());
    //matriz(i2, j2)->setNuevosPunteros(aux);
    // matriz.swap(i1,j1,i2,j2);
}

Cuadro* Tablero::getFicha(int x, int y)
{
    return matriz(x,y);
}
