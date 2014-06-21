#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "Excepcion.h"
#include "Interfaz.h"
#include "Tablero.h"
#include "FabricaFicha.h"
#include "FabricaFigura.h"
#include "Mapa.h"

using namespace std;

int main()
{
    sf::RenderWindow ventanaPrincipal(sf::VideoMode(600,600), "Hnefatafl");
    unique_ptr<Interfaz> interfaz(new Interfaz(ventanaPrincipal));

    int tamVentana = ventanaPrincipal.getSize().x;
    int tamCuadro = (int)(tamVentana / 10);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << i << ", " << j << "  ";
            Figura * figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CUADRADO, Cuadrado::getColorCuadro(i,j), i, j, tamCuadro, ventanaPrincipal);
            interfaz->push_figura(figura);
            Figura  * figura2 = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(255,255,255), i, j, tamCuadro, ventanaPrincipal);
            interfaz->push_figura(figura2);
        }
        cout << endl;
    }
    string pat = "map/mapa.bin";
    Mapa* m = new Mapa(pat);
    Tablero *t = new Tablero(4);

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
