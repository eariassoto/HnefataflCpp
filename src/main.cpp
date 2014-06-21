#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "Matriz.h"
#include "MatrizDoble.h"
#include "Excepcion.h"
#include "Cuadro.h"
#include "Sprite.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "Interfaz.h"

using namespace std;

int main()
{
    try
    {
        Matriz<double> m(10,10);
        m(5,8) = 106.15;
        m(1,1) = 333.3;
        cout << m(5,8) << endl;
        cout << m(1,1) << endl;
        m.swap(5,8,1,1);
        cout << m(5,8) << endl;
        cout << m(1,1) << endl;
        cout << endl << endl;
        MatrizDoble<int, char> md(5, 5);
        pair<int, char> a(1, 'b'), b(2,'c');
        md(1,1) = a;
        md(0,0) = b;
        cout << md(1,1).first << ", " << md(1,1).second << endl;
        cout << md(0,0).first << ", " << md(0,0).second << endl;
        md.swap(1,1,0,0);
        cout << md(1,1).first << ", " << md(1,1).second << endl;
        cout << md(0,0).first << ", " << md(0,0).second << endl;
        md.swap_first(1,1,0,0);
        cout << md(1,1).first << ", " << md(1,1).second << endl;
        cout << md(0,0).first << ", " << md(0,0).second << endl;
        md.swap_second(1,1,0,0);
        cout << md(1,1).first << ", " << md(1,1).second << endl;
        cout << md(0,0).first << ", " << md(0,0).second << endl;
    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }

    try
    {
        Cuadro * c0 = new Cuadro(0,0,0,0);
        Cuadro * c1 = new Cuadro(0,0,0,0);
        Cuadro * c2 = new Cuadro(0,0,0,0);
        Cuadro * c3 = new Cuadro(0,0,0,0);
        Cuadro * x = new Cuadro(0,0,0,0);

        Ficha * f = new Ficha(c0, c1, c2, c3);
        int * i = f->mover(c1);
        cout << "mover responde " << i[0] << ", " << i[1] << endl;

    }
    catch(Excepcion e)
    {
        cout << e.what() << endl;
    }

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
        }

    }

    try{
        string str = "img/blanca.png";
        Sprite * s = new Sprite(0, 0, 100, str, ventanaPrincipal);

    }catch(Excepcion e){
        cout << e.what() << endl;
    }

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
