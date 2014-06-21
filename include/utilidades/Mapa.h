#ifndef MAPA_H_
#define MAPA_H_
#include "Archivo.h"
#include <iostream>
class Mapa: public Archivo{
public:
    Mapa(string);
    int getDimension();
    enum TipoFicha{
        CUADRO = 0,
        BLANCA = 1,
        NEGRA = 2,
        REY = 3,
    };
private:
    int dimension;
    vector< pair< pair<int, int>, int > > coordenada;
    vector< pair< pair<int, int>, int > > armarPares(vector<int>);

};
#endif // MAPA_H_
