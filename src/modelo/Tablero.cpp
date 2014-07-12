#include "Tablero.h"
#include <iostream>
#include <algorithm>
#include "FabricaFicha.h"

Tablero::Tablero(int t):dimension(t), vmatriz(t, vector< shared_ptr<Cuadro> >(t))
{
     finJuego = 0;
}


void Tablero::agregarFicha(int i, int j, shared_ptr<Cuadro> c)
{
    vmatriz[i][j] = c;
    if(i > 0 && vmatriz[i-1][j])
    {
        vmatriz[i][j]->setPtr(Cuadro::ARR, vmatriz[i-1][j]); //ARR
        vmatriz[i-1][j]->setPtr(Cuadro::ABA, vmatriz[i][j]);
    }

    if(j < (vmatriz[0].size()-1) && vmatriz[i][j+1])
    {
        vmatriz[i][j]->setPtr(Cuadro::DER, vmatriz[i][j+1]); //DER
        vmatriz[i][j+1]->setPtr(Cuadro::IZQ, vmatriz[i][j]);
    }

    if(i < (vmatriz.size()-1) && vmatriz[i+1][j])
    {
        vmatriz[i][j]->setPtr(Cuadro::ABA, vmatriz[i+1][j]); //ABA
        vmatriz[i+1][j]->setPtr(Cuadro::ARR, vmatriz[i][j]);
    }
    if(j > 0 && vmatriz[i][j-1])
    {
        vmatriz[i][j]->setPtr(Cuadro::IZQ, vmatriz[i][j-1]); //IZQ
        vmatriz[i][j-1]->setPtr(Cuadro::DER, vmatriz[i][j]);
    }
}

bool Tablero::mover(int* f, int* g)
{
    try
    {
        shared_ptr<Cuadro> cambio = vmatriz[f[0]][f[1]]->mover(vmatriz[g[0]][g[1]]);
        if(cambio)
        {
            vmatriz[g[0]][g[1]] = cambio;
            vmatriz[f[0]][f[1]]->swap(vmatriz[g[0]][g[1]]);
            swap(vmatriz[f[0]][f[1]], vmatriz[g[0]][g[1]]);

            shared_ptr<Esquina> es = dynamic_pointer_cast<Esquina>(vmatriz[f[0]][f[1]]);
            if(es)
                finJuego = 2;
            else
                comer(vmatriz[g[0]][g[1]]->comer());
            return true;
        }
        else
        {
            return false;
        }
    delete g;
    }
    catch(Excepcion e)
    {
        delete g;
        return false;
    }
}

shared_ptr<Cuadro> Tablero::getFicha(int x, int y)
{
    return vmatriz[x][y];
}

void Tablero::setFiguraVisible(shared_ptr<Cuadro> c, bool b)
{
    shared_ptr<Ficha> f = dynamic_pointer_cast<Ficha> (c);
    f->setFiguraVisible(b);
}

void Tablero::comer(vector< shared_ptr<Cuadro> > respComer)
{
    if(!respComer.empty())
    {
        shared_ptr<Cuadro> r = dynamic_pointer_cast<Rey> (respComer[0]);
        if(r){
            cout << "reycomido" << endl;
            finJuego = 1;
            }
        else
        {
            for(vector< shared_ptr<Cuadro> >::iterator it = respComer.begin(); it != respComer.end(); it++)
            {
                setFiguraVisible(*it, false);
                for(vector< shared_ptr<Cuadro> >::size_type i = 0; i != vmatriz.size(); i++)
                    for(vector< shared_ptr<Cuadro> >::size_type j = 0; j != vmatriz[0].size(); j++)
                    {
                        if(vmatriz[i][j] == *it)
                        {
                            shared_ptr<Cuadro> reemplazo = FabricaFicha::crearCuadro();
                            vmatriz[i][j]->swap(reemplazo);
                            vmatriz[i][j] = reemplazo;
                        }
                    }
            }
        }
    }
}

int Tablero::getDimension(){
        return dimension;
}
