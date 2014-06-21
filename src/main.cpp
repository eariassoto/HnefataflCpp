#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "Matriz.h"
#include "MatrizDoble.h"
#include "Excepcion.h"
#include "Cuadro.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Interfaz.h"
#include "Circulo.h"
#include "Archivo.h"

using namespace std;

int main()
{

    sf::RenderWindow ventanaPrincipal(sf::VideoMode(600,600), "Hnefatafl");
    unique_ptr<Interfaz> interfaz(new Interfaz(ventanaPrincipal));

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(sf::Vector2f(200,20));

    int tamVentana = ventanaPrincipal.getSize().x;
    int tamCuadro = (int)(tamVentana / 10);
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            Cuadrado * figura = new Cuadrado(i, j, tamCuadro, ventanaPrincipal);
            interfaz->push_figura(figura);
            Circulo  * c = new Circulo(sf::Color(255,255,255), i, j, tamCuadro, ventanaPrincipal);
            interfaz->push_figura(c);
        }

    }
<<<<<<< HEAD
    string pat = "map/hola.bin";
    Archivo * a = new Archivo(pat);
=======

    try{
        string str = "img/blanca.png";
        Sprite * s = new Sprite(0, 0, 75, str, ventanaPrincipal);
        interfaz->push_figura(s);

    }catch(Excepcion e){
        cout << e.what() << endl;
    }
>>>>>>> 2b53a365b6e8e6fb1499d6651b0087f1c2b14783

    while (ventanaPrincipal.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (ventanaPrincipal.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                ventanaPrincipal.close();
        }

        // clear the window with black color
        ventanaPrincipal.clear(sf::Color::Black);

        // draw everything here...
        interfaz->dibujar();

        // end the current frame
        ventanaPrincipal.display();
    }

    return 0;
}
