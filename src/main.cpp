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
#include "Jugador.h"

using namespace std;

int main()
{
    string pat = "map/mapa1.bin";
    unique_ptr<Mapa> mapa(new Mapa(pat));
    int dimension = mapa->getDimension();
    int tamVentana = (600/dimension)*dimension;
    int tamCuadro = (int)(tamVentana / dimension);

    sf::RenderWindow ventanaPrincipal(sf::VideoMode(tamVentana,tamVentana), "Hnefatafl");
    unique_ptr<Interfaz> interfaz(new Interfaz(ventanaPrincipal));
    unique_ptr<Tablero> tablero(new Tablero(dimension));

    unique_ptr<Jugador> jugador1(new Jugador(Jugador::TipoFicha::BLANCA));
    unique_ptr<Jugador> jugador2(new Jugador(Jugador::TipoFicha::NEGRA));

    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            Figura * figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CUADRADO, Cuadrado::getColorCuadro(i,j), i, j, tamCuadro, ventanaPrincipal);
            interfaz->push_figura(figura);
            Cuadro* cuadro;
            Mapa::TipoFicha tF = mapa->buscar(i,j);
            switch(tF)
            {
            case Mapa::TipoFicha::ESQUINA:
            {
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(0,255,0), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
            }
            break;
            case Mapa::TipoFicha::CUADRO:
            {
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::CUADRO, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::BLANCA:
            {
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(255,255,255), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::BLANCA, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::NEGRA:
            {
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(0,0,0), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::NEGRA, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::REY:
            {
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(255,255,0), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::REY, figura);
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(255,0,0), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
                cuadro->agregarFiguraTrono(figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            }

        }
    }

    /// tablero->matriz(5,5)->figura->getCirc().move(10,10); ESTO SIRVE :D (poner private lo de tablero)
    /* tablero->imprimir();
     tablero->mover(1,1,4,2);
     cout << endl << endl;
     tablero->imprimir();*/
    //  tablero->matriz(5,5)->moverFigura(0, 3);

    while (ventanaPrincipal.isOpen())
    {
        sf::Event event;
        while (ventanaPrincipal.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                ventanaPrincipal.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int* coord = interfaz->buscarPunto(event.mouseButton.x, event.mouseButton.y);
                    if(!jugador1->seleccion)
                    {
                        if(jugador1->esFichaMia(tablero->getFicha(coord[0], coord[1])))
                        {
                            cout << "seleccione " << coord[0] << ", " << coord[1] << endl;
                            jugador1->seleccionar(coord[0], coord[1]);
                        }
                    }
                    else
                    {
                        cout << "mande a mover a la seleccion en " << coord[0] << ", " << coord[1] << endl;
                        tablero->mover(jugador1->getSeleccion(), coord);
                        jugador1->seleccion = false; //linea fea TODO
                    }
                    delete coord;
                }

            }

        }

        ventanaPrincipal.clear(sf::Color::Black);

        // draw everything here...
        interfaz->dibujar();

        // end the current frame
        ventanaPrincipal.display();
    }

    return 0;
}
