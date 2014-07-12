#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Archivo
{
public:
    Archivo(string);
    char*       leerArchivoCaracter();
    char        leerCaracter(int);
    int         leerEntero(int);
    char*       leerCaracteres(int, int);
    vector<int> leerEnteros(int, int);
    vector<int> leerArchivoEntero();
    int         getLargo();
    int         getLargoEntero();

    void escribirEntero(ofstream&, int);
    static bool archivoExiste(const char*);
    void borrarArchivo(const char*);

protected:
    const string path;
};
#endif // ARCHIVO_H_
