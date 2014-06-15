#ifndef _VENTANA_H_
#define _VENTANA_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>
#include "Elemento.h"

using namespace std;

class Ventana{
public:
    Ventana(sf::RenderWindow&);
    Ventana* push(Elemento&);
    Ventana* dibujar();
private:
    sf::RenderWindow& ventana;
    vector<Elemento> elementos;
};
#endif // _VENTANA_H_
