#ifndef _MATRIZ_H_
#define _MATRIZ_H_
#include <map>
#include "Excepcion.h"

using namespace std;

template<class T>
class Matriz
{
public:
    Matriz(unsigned, unsigned);
   // Matriz(Matriz const& m);               // Constructor que copia, hay que implementar

    virtual T& operator() (unsigned, unsigned);
    //T  operator() (unsigned, unsigned) const;
    //Matriz& operator= (Matriz const& m);   // Operador de asignacion
    virtual void swap(int, int, int, int);

protected:
    unsigned filas_, columnas_;
    map<pair<int, int>, T> matriz;
};

template<class T>
Matriz<T>::Matriz(unsigned filas, unsigned columnas)
    : filas_ (filas)
    , columnas_ (columnas)
{
    if (filas <= 0)
        throw Excepcion("El rango de las filas es negativo o cero. No se pudo crear la matriz.");
    else if (columnas <= 0)
        throw Excepcion("El rango de las columnas es negativo o cero. No se pudo crear la matriz.");

    for(int i = 0; i < filas_; i++)
        for(int j = 0; j < columnas_; j++)
        {
            pair<int, int> index(i, j);
            pair<pair<int, int>, T> contenido(index, 0);
            matriz.insert(contenido);
        }
}

template<class T>
T& Matriz<T>::operator() (unsigned fila, unsigned columna)
{
    if (fila <= 0 || fila >= filas_)
        throw Excepcion("El rango de la fila es negativo o cero. No se pudo acceder ");
    else if (columna <= 0 || columna >= columnas_)
        throw Excepcion("El rango de la columna es negativo o cero. No se pudo acceder al dato.");

    pair<int, int> buscar(fila, columna);
    return matriz[buscar];
}
/*
template<class T>
T Matriz<T>::operator() (unsigned fila, unsigned columna) const
{
    if (fila <= 0 || fila >= filas_)
        throw Excepcion("El rango de la fila es negativo o cero. No se pudo acceder ");
    else if (columna <= 0 || columna >= columnas_)
        throw Excepcion("El rango de la columna es negativo o cero. No se pudo acceder al dato.");

    pair<int, int> buscar(fila, columna);
    return matriz[buscar];
}
*/
template<class T>
void Matriz<T>::swap(int n1, int m1, int n2, int m2){
    pair<int, int> e1(n1, m1), e2(n2, m2);
    T aux;
    aux = matriz[e1];
    matriz[e1] = matriz[e2];
    matriz[e2] = aux;
}

#endif // _MATRIZ_H_
