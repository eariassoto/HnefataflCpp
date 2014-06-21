#ifndef CUADRADO_H_
#define CUADRADO_H_
#include "Figura.h"
class Cuadrado: public Figura{
public:
    Cuadrado(sf::RectangleShape& r, sf::RenderWindow& v):rectangulo(r), Figura(v){};
    Cuadrado(int x, int y, int t, sf::RenderWindow& v):rectangulo(sf::Vector2f(t, t)), Figura(v){
        rectangulo.setFillColor(sf::Color(255,0,0));
        rectangulo.setPosition(x, y);
    }

    void dibujar(){
        ventana.draw(rectangulo);
    }
private:
    sf::RectangleShape rectangulo;
};
#endif // CUADRADO_H_
