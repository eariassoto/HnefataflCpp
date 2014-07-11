#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Figura.h"
#include <memory>

using namespace std;

class Interfaz
{
public:
    Interfaz(sf::RenderWindow&);

    void              dibujar();
    void              push_figura(Figura*);
    int* buscarPunto(int, int);
    sf::RenderWindow& ventana_;

private:
    vector<Figura*> figuras;
};

#endif


