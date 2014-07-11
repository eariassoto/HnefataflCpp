#include "Tablero.h"
#include <iostream>
#include <algorithm>
#include "FabricaFicha.h"

Tablero::Tablero(int t):dimension(t), vmatriz(t, vector<Cuadro*>(t))
{

}


void Tablero::agregarFicha(int i, int j, Cuadro* c)
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
        Cuadro* cambio = vmatriz[f[0]][f[1]]->mover(vmatriz[g[0]][g[1]]);
        if(cambio)
        {
            vmatriz[g[0]][g[1]] = cambio;
            vmatriz[f[0]][f[1]]->swap(vmatriz[g[0]][g[1]]);
            swap(vmatriz[f[0]][f[1]], vmatriz[g[0]][g[1]]);
            comer(vmatriz[g[0]][g[1]]->comer());
            return true;
        }
        else{
            return false;
        }

    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
        return false;
    }
}

Cuadro* Tablero::getFicha(int x, int y)
{
    return vmatriz[x][y];
}

void Tablero::setFiguraVisible(Cuadro * c, bool b)
{
    Ficha * f = dynamic_cast<Ficha*> (c);
    f->setFiguraVisible(b);
}

void Tablero::comer(vector<Cuadro*> respComer)
{
    cout << "enre a comer" << endl;
    if(!respComer.empty())
    {
        Cuadro * r = dynamic_cast<Rey*> (respComer[0]);
        if(r)
            cout << "tengo que comer al rey" << endl;
        else
        {
            cout << "como " << respComer[0] << endl;
            for(vector<Cuadro*>::iterator it = respComer.begin(); it != respComer.end(); it++)
            {
                setFiguraVisible(*it, false);
                for(vector<Cuadro*>::size_type i = 0; i != vmatriz.size(); i++)
                    for(vector<Cuadro*>::size_type j = 0; j != vmatriz[0].size(); j++)
                    {
                        if(vmatriz[i][j] == *it)
                        {
                            Cuadro* reemplazo = FabricaFicha::crearCuadro();
                            vmatriz[i][j]->swap(reemplazo);
                            vmatriz[i][j] = reemplazo;
                        }
                    }
            }
        }
    }
}
