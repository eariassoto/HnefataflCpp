#include "Mapa.h"
Mapa::Mapa(string p):Archivo(p)
{
    cout << "el tamano es " << getLargoEntero()<<endl;
    dimension = leerEntero(0);
    vector<int> c = leerEnteros(1, getLargoEntero()-1);
    armarPares(c);

}

vector< pair< pair<int, int>, int > > Mapa::armarPares(vector<int> v)
{
    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.begin()+1;
    vector<int>::iterator it3 = v.begin()+2;
    cout << "el tamano de la vara es " << v.size() << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << *it1 << ", " << *it2 << ", " << *it3 << endl;
        next(it1, 3);
        next(it2, 3);
        next(it3, 3);
    }
}
