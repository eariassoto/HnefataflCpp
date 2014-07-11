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
    string pat = "map/mapa2.bin";
    unique_ptr<Mapa> mapa(new Mapa(pat));
    int dimension = mapa->getDimension();
    int tamVentana = (600/dimension)*dimension;
    int tamCuadro = (int)(tamVentana / dimension);

    sf::RenderWindow ventanaPrincipal(sf::VideoMode(tamVentana,tamVentana), "Hnefatafl");
    unique_ptr<Interfaz> interfaz(new Interfaz(ventanaPrincipal));
    unique_ptr<Tablero> tablero(new Tablero(dimension));

    shared_ptr<Jugador> jugador1(new Jugador(Jugador::TipoFicha::BLANCA));
    shared_ptr<Jugador> jugador2(new Jugador(Jugador::TipoFicha::NEGRA));
    shared_ptr<Jugador> jugador = jugador1;


    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            shared_ptr<Figura> figura(FabricaFigura::crearCuadrado(Cuadrado::getColorCuadro(i,j), i, j, tamCuadro, ventanaPrincipal));
            interfaz->push_figura(figura);
            shared_ptr<Cuadro> cuadro;
            Mapa::TipoFicha tF = mapa->buscar(i,j);
            switch(tF)
            {
            case Mapa::TipoFicha::ESQUINA:
            {
                figura = FabricaFigura::crearCirculo(sf::Color(0,255,0), i, j, tamCuadro, ventanaPrincipal, " E", true);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::ESQUINA, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::CUADRO:
            {
                cuadro = FabricaFicha::crearCuadro();
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::BLANCA:
            {
                figura = FabricaFigura::crearCirculo(sf::Color(255,255,255), i, j, tamCuadro, ventanaPrincipal, "J1", false);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::BLANCA, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::NEGRA:
            {
                figura = FabricaFigura::crearCirculo(sf::Color(0,0,0), i, j, tamCuadro, ventanaPrincipal, "J2", false);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::NEGRA, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            case Mapa::TipoFicha::REY:
            {
                ///creo el trono
                figura = FabricaFigura::crearCirculo(sf::Color(255,0,0), i, j, tamCuadro, ventanaPrincipal, " T", false);
                interfaz->push_figura(figura);
                shared_ptr<Cuadro> trono = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::TRONO, figura);

                ///creo el rey
                figura = FabricaFigura::crearCirculo(sf::Color(255,255,0), i, j, tamCuadro, ventanaPrincipal, " R", false);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearRey(figura, trono);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            default:
                break;
            }

        }
    }
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
                    try
                    {
                        int* coord = interfaz->buscarPunto(event.mouseButton.x, event.mouseButton.y);

                        if(jugador->esFichaMia(tablero->getFicha(coord[0], coord[1])))
                        {
                            jugador->seleccionar(coord[0], coord[1]);
                            shared_ptr<Ficha> cu = dynamic_pointer_cast<Ficha>(tablero->getFicha(coord[0], coord[1]));
                            cu->setTextoVisible(true);
                        }
                        else
                        {
                            bool movimiento = false;
                            if(jugador->seleccion)
                            movimiento = tablero->mover(jugador->getSeleccion(), coord);
                            if(movimiento)
                            {
                                if(jugador == jugador1)
                                    jugador = jugador2;
                                else
                                    jugador = jugador1;
                            }
                        }
                        delete coord;

                    }
                    catch(Excepcion e) {}
                }
            }
        }

        ventanaPrincipal.clear(sf::Color::Black);
        interfaz->dibujar();
        ventanaPrincipal.display();
    }

    return 0;
}
