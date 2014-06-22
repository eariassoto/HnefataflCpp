#ifndef MAPA_H_
#define MAPA_H_
#include "Archivo.h"
#include <iostream>
#include <map>
#include <stdexcept>

class Mapa: public Archivo
{
public:
    Mapa(string);
    int getDimension();
    enum TipoFicha
    {
        CUADRO = 0,
        BLANCA = 1,
        NEGRA = 2,
        REY = 3,
        ESQUINA = 4
    };

    TipoFicha buscar(int, int);

private:
    int                        dimension;
    map< pair<int, int>, int > coordenada;
    void                       armarPares(vector<int>);

};
#endif // MAPA_H_
