#include "Archivo.h"
Archivo::Archivo(string p):path(p)
{

    vector<int> a = leerEnteros(0,2);
    cout << "largo de lo que lei es" << a.size() << endl;
    vector<int>::iterator v = a.begin();
    for(v; v!=a.end(); v++){
        cout<< "lei " << *v << endl;
    }

}
char* Archivo::leerArchivoCaracter(){
    return leerCaracteres(0, getLargo());
}

vector<int> Archivo::leerArchivoEntero(){
    return leerEnteros(0, getLargoEntero());
}

char* Archivo::leerCaracteres(int b, int e)
{
    int tam = (e-b)+1;
    char * bloque = new char[tam]();
    ifstream input (path, ios::in|ios::binary);
    input.seekg (b);
    input.read (bloque, tam);
    input.close();
    return bloque;
}

vector<int> Archivo::leerEnteros(int b, int e){
    int tam = (e-b)+1;
    vector<int> num(tam);
    ifstream input (path, ios::in|ios::binary);
    input.seekg (b*sizeof(int));
    input.read ((char*)&num[0], num.size()*sizeof(num[0]));
    input.close();
    return num;
}

char Archivo::leerCaracter(int n)
{
    char * c = new char[1]();
    ifstream file (path, ios::in|ios::binary);
    file.seekg (n);
    file.read(c,1);
    file.close();
    return c[0];
}

int Archivo::getLargo()
{
    ifstream input (path, ios::in|ios::binary|ios::ate);
    int l = input.tellg();
    input.close();
    return l;
}

int Archivo::getLargoEntero(){
    return getLargo() / sizeof(int);
}
