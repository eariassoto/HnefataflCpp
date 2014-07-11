#ifndef CIRCULO_H_
#define CIRCULO_H_
#include <string>
#include "Figura.h"
#include "Excepcion.h"

class Circulo: public Figura
{
public:

    Circulo(sf::Color c, int x, int y, int t, sf::RenderWindow& v, string s, bool b):circulo(t/2), textoVisible(b), Figura(v)
    {
        circulo.setFillColor(c);
        circulo.setPosition(y*t, x*t);
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "dayum" << endl;
        }
        texto.setFont(font);
        texto.setString(s);
        texto.setCharacterSize(44);
        texto.setColor(sf::Color::Red);
        texto.setPosition(y*t, x*t);
    }

    void dibujar()
    {
        if(visible)
            ventana.draw(circulo);

        if(textoVisible)
            ventana.draw(texto);
    }

    sf::RectangleShape& getRect()
    {
        throw Excepcion("Soy un circulo");
    };

    sf::CircleShape& getCirc()
    {
        return circulo;
    };

    sf::Text& getText()
    {
        return texto;
    };

    void setTextoVisible(bool b){
        textoVisible = b;
    }

private:

    sf::CircleShape circulo;
    sf::Font font;
    sf::Text texto;
    bool textoVisible;
};
#endif // CIRCULO_H_
