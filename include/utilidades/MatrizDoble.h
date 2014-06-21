#ifndef _MATRIZDOBLE_H_
#define _MATRIZDOBLE_H_
#include "Matriz.h"
#include <map>
using namespace std;

template <class U, class V>
class MatrizDoble: public Matriz<pair<U, V> >
{
public:
    MatrizDoble(unsigned, unsigned);
    void swap_first(int, int, int, int);
    void swap_second(int, int, int, int);
};

template<class U, class V>
MatrizDoble<U, V>::MatrizDoble(unsigned filas, unsigned columnas): Matriz< pair<U, V> >(filas, columnas) {};

template<class U, class V>
void MatrizDoble<U, V>::swap_first(int n1, int m1, int n2, int m2)
{
    pair<int, int> e1(n1, m1), e2(n2, m2);
    U aux = Matriz< pair<U,V> >::matriz[e1].first;
    Matriz< pair<U,V> >::matriz[e1].first =  Matriz< pair<U,V> >::matriz[e2].first;
    Matriz< pair<U,V> >::matriz[e2].first = aux;
}

template<class U, class V>
void MatrizDoble<U, V>::swap_second(int n1, int m1, int n2, int m2)
{
    pair<int, int> e1(n1, m1), e2(n2, m2);
    V aux = Matriz< pair<U,V> >::matriz[e1].second;
    Matriz< pair<U,V> >::matriz[e1].second =  Matriz< pair<U,V> >::matriz[e2].second;
    Matriz< pair<U,V> >::matriz[e2].second = aux;
}

#endif // _MATRIZDOBLE_H_
