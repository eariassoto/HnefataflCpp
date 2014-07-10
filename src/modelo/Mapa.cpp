#include "Mapa.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Mapa::Mapa(string p): Archivo(p)
{
    dimension = leerEntero(0);
    vector<int> c = leerEnteros(1, getLargoEntero()-1);
    armarPares(c);

}

void Mapa::armarPares(vector<int> v)
{
    for(int i = 0; i < v.size(); i= i+3)
    {
        pair<int, int> c(v[i], v[i+1]);
        pair<pair<int, int>, int> coord(c, v[i+2]);
        coordenada.insert(coord);
    }
}

Mapa::TipoFicha Mapa::buscar(int i, int j)
{
    try
    {
        int f = coordenada.at(make_pair(i, j));
        switch(f)
        {
        case 1:
            return BLANCA;
        case 2:
            return NEGRA;
        case 3:
            return REY;
        case 4:
            return ESQUINA;
        }
    }
    catch(const out_of_range& oor)
    {
        return CUADRO;
    }
}

int Mapa::getDimension()
{
    return dimension;
}
