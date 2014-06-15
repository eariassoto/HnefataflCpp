#ifndef _MATRIZDOBLE_H_
#define _MATRIZDOBLE_H_
#include "Matriz.h"
#include <map>
using namespace std;

template <class T, class U>
class MatrizDoble: public Matriz<pair<T, U> >
{
public:
    MatrizDoble(unsigned, unsigned);
    void swap_first(int, int, int, int);
};

template<class T, class U>
MatrizDoble<T, U>::MatrizDoble(unsigned filas, unsigned columnas): Matriz<pair<T, U> >(filas, columnas) {};

template<class T, class U>
void MatrizDoble<T, U>::swap_first(int n1, int m1, int n2, int m2)
{
    pair<int, int> e1(n1, m1), e2(n2, m2);
    pair<T,U> a = matriz[e1];
}

#endif // _MATRIZDOBLE_H_
