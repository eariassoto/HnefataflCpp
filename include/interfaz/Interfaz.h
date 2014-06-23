#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"

using namespace std;

class Interfaz
{
public:
    Interfaz(sf::RenderWindow&);

    void              dibujar();
    void              push_figura(Figura*);
    void buscarPunto(int, int);
    sf::RenderWindow& ventana_;

private:
    vector<Figura*> figuras;
};

#endif


