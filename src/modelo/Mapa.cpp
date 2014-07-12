#include "Mapa.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Rey.h"
#include "Esquina.h"

Mapa::Mapa(string m, string j): Archivo(m), pathJuego(j)
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

void Mapa::guardarMapa(shared_ptr<Tablero> tablero)
{
    borrarMapa();
    ofstream salida (pathJuego, ios::out | ios::binary);
    escribirEntero(salida, tablero->getDimension());
    for(int i = 0; i < tablero->getDimension(); i++)
        for(int j = 0; j < tablero->getDimension(); j++)
        {
            shared_ptr<Rey> rey = dynamic_pointer_cast<Rey>(tablero->getFicha(i, j));
            if(rey)
            {
                escribirEntero(salida, i);
                escribirEntero(salida, j);
                escribirEntero(salida, REY);
            }
            else
            {
                shared_ptr<FichaNegra> fN = dynamic_pointer_cast<FichaNegra>(tablero->getFicha(i, j));
                if(fN)
                {
                    escribirEntero(salida, i);
                    escribirEntero(salida, j);
                    escribirEntero(salida, NEGRA);
                }
                else
                {
                    shared_ptr<FichaBlanca> fB = dynamic_pointer_cast<FichaBlanca>(tablero->getFicha(i, j));
                    if(fB)
                    {
                        escribirEntero(salida, i);
                        escribirEntero(salida, j);
                        escribirEntero(salida, BLANCA);
                    }
                    else
                    {
                        shared_ptr<Esquina> es = dynamic_pointer_cast<Esquina>(tablero->getFicha(i, j));
                        if(es)
                        {
                            escribirEntero(salida, i);
                            escribirEntero(salida, j);
                            escribirEntero(salida, ESQUINA);
                        }
                    }
                }
            }
        }
        salida.close();
}

void Mapa::borrarMapa(){
    borrarArchivo(pathJuego.c_str());
}
