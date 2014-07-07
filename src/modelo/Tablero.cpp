#include "Tablero.h"
#include <algorithm>
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
<<<<<<< HEAD
        if(vmatriz[f[0]][f[1]]->mover(vmatriz[g[0]][g[1]]))
        {
            vmatriz[f[0]][f[1]]->swap(vmatriz[g[0]][g[1]]);
            swap(vmatriz[f[0]][f[1]], vmatriz[g[0]][g[1]]);
            Cuadro* respComer = vmatriz[g[0]][g[1]]->comer();
            if(respComer){
                cout << "hay que comer" << endl;
                Ficha * f = dynamic_cast<Ficha*> (respComer);
                f->figura->setVisible(false);
            }
        }
=======
        vmatriz[f[0]][f[1]]->mover(vmatriz[g[0]][g[1]]);
        vmatriz[f[0]][f[1]]->swap(vmatriz[g[0]][g[1]]);
        cout << vmatriz[f[0]][f[1]] << " " << vmatriz[g[0]][g[1]] << endl;
        swap(vmatriz[f[0]][f[1]], vmatriz[g[0]][g[1]]);
        cout << vmatriz[f[0]][f[1]] << " " << vmatriz[g[0]][g[1]] << endl;
       // cout << matriz(f[0], f[1]) << " " << matriz(g[0], g[1]) << endl;
      //  matriz(f[0], f[1])->swap(matriz(g[0], g[1]));
      //  cout << matriz(f[0], f[1]) << " " << matriz(g[0], g[1]) << endl;
>>>>>>> 8f6aa708310613660b0f4af8a4e67329a66c11e7
        return true;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }
}

Cuadro* Tablero::getFicha(int x, int y)
{
    return vmatriz[x][y];
}
