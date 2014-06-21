#ifndef SPRITE_H_
#define SPRITE_H_
#include <string>
#include "Excepcion.h"
#include "Figura.h"

using namespace std;

class Sprite: public Figura
{
public:
    Sprite(int x, int y, int t, string path, sf::RenderWindow& v): sprite(), imagen(), Figura(v)
    {
        if (!imagen.loadFromFile(path))
        {
            throw Excepcion("error al abrir la imagen");
        }
        sprite.setTexture(imagen);
        sprite.setTextureRect(sf::IntRect(0, 0, t, t));
        sprite.setPosition(x*t, y*t);
    };
    void dibujar(){
    ventana.draw(sprite);
    };
private:
    sf::Texture imagen;
    sf::Sprite sprite;
};
#endif // SPRITE_H_
