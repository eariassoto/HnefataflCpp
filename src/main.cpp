#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <string>
#include "Excepcion.h"
#include "Interfaz.h"
#include "Tablero.h"
#include "FabricaFicha.h"
#include "FabricaFigura.h"
#include "Mapa.h"
#include "Archivo.h"
#include "Jugador.h"

using namespace std;

///Prototipos

/** \brief Guarda la partido
 *
 */
void guardarJuego(shared_ptr<Mapa>, shared_ptr<Tablero>);

/** \brief Busca cuantos mapas hay disponibles.
 */
vector<string> buscarMapas();

/** \brief Pide al usuario que escoga un tipo de mapa o bien una partida anterior
 */
string escogerMapa(string);

/** \brief Carga el tablero desde el mapa.
 */
void iniciarTablero(shared_ptr<Mapa>, shared_ptr<Tablero>, shared_ptr<Interfaz>, sf::RenderWindow&, int, int);

int main()
{
    string pathJuego = "map/juegoGuardado.bin";
    shared_ptr<Mapa> mapa(new Mapa(escogerMapa(pathJuego), pathJuego));
    int dimension = mapa->getDimension();
    int tamVentana = (600/dimension)*dimension;
    int tamCuadro = (int)(tamVentana / dimension);

    ///Inicializacion de instancias
    sf::RenderWindow ventanaPrincipal(sf::VideoMode(tamVentana,tamVentana), "Hnefatafl");
    shared_ptr<Interfaz> interfaz(new Interfaz(ventanaPrincipal));
    shared_ptr<Tablero> tablero(new Tablero(dimension));

    shared_ptr<Jugador> jugador1(new Jugador(Jugador::TipoFicha::BLANCA));
    shared_ptr<Jugador> jugador2(new Jugador(Jugador::TipoFicha::NEGRA));
    shared_ptr<Jugador> jugador = jugador1;

    iniciarTablero(mapa, tablero, interfaz, ventanaPrincipal, dimension, tamCuadro);

    bool fin = false, clic = false, cambioTurno = true;
    int mousex = -1, mousey = -1;

    ///pequeño encabezado
    cout << "Bienvenido. Las fichas blancas y el rey son del jugador 1, las negras del jugador 2." << endl << "El objetivo del juego es que el Rey llega a una esquina (en verde) o que los negros capturen al rey." << endl << "Gana quien logre el objetivo primero." << endl << "Las otras reglas ya las sabe profe. gl hf" << endl;

    while (!fin && ventanaPrincipal.isOpen()) ///loop principal del juego
    {
        sf::Event event;
        while (ventanaPrincipal.pollEvent(event))
        {
            ///poll de eventos
            switch(event.type)
            {
            case sf::Event::Closed:
                ///usuario cerro el juego
                guardarJuego(mapa, tablero);
                ventanaPrincipal.close();
                break;
            case sf::Event::MouseButtonPressed:
                ///usuario hizo clic
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int* coord = interfaz->buscarPunto(event.mouseButton.x, event.mouseButton.y);
                    mousex = coord[0];
                    mousey = coord[1];
                    delete coord;
                    clic = true;
                }
            }
            ///verificaciones del juego
            try
            {
                if(cambioTurno)
                {
                    cout << "Turno del ";
                    if(jugador == jugador1)
                    {
                        cout << "jugador1." << endl;
                    }
                    else
                    {
                        cout << "jugador2." << endl;
                    }
                    cambioTurno = false;
                }
                if(clic)
                {
                    if(jugador->esFichaMia(tablero->getFicha(mousex, mousey)))
                    {
                        cout << "Seleccionada la ficha " << mousex << ", " << mousey << endl;
                        jugador->seleccionar(mousex, mousey);
                    }
                    else
                    {
                        if(jugador->seleccion)
                        {
                            int * coord = new int[2];
                            coord[0] = mousex;
                            coord[1] = mousey;
                            bool movimiento = tablero->mover(jugador->getSeleccion(), coord);
                            if(movimiento)
                            {
                                if(jugador == jugador1)
                                    jugador = jugador2;
                                else
                                    jugador = jugador1;
                                cambioTurno = true;
                            }
                            else
                            {
                                cout << "No se pudo mover en esta posicion. Intentalo de nuevo." << endl;
                            }
                            jugador->seleccion =  false;
                        }
                    }
                    clic = false;
                }
            }
            catch(Excepcion e) {}

            /// verificaciones de fin de juego
            if(tablero->finJuego == 1)
            {
                cout << "Los negros han ganado. El rey ha sido capturado" << endl;
                fin = true;
            }
            else if(tablero->finJuego == 2)
            {
                cout << "Los blancos han ganado. El rey ha logrado llegar a la torre." << endl;
                fin = true;
            }
        }

        ventanaPrincipal.clear(sf::Color::Black);
        interfaz->dibujar();
        ventanaPrincipal.display();
    }

    return 0;
}

void guardarJuego(shared_ptr<Mapa> mapa, shared_ptr<Tablero> tablero)
{
    char decision;
    cout << "Deseas guardar la partida: (s/n) ";
    cin >> decision;
    switch(decision)
    {
    case 's':
        mapa->guardarMapa(tablero);
        cout << "Juego guardado." << endl;
        break;
    case 'n':
        mapa->borrarMapa();
        cout << "El juego no se ha guardado." << endl;
        break;
    }
}

template <typename T>
string itos (T n)
{
    ostringstream ss;
    ss << n;
    return ss.str();
}

vector<string> buscarMapas()
{
    vector<string> mapa;
    bool fin = false;
    int in = 1;
    string path;
    while(!fin)
    {
        path = "map/mapa" + itos(in) + ".bin";
        if(Archivo::archivoExiste(path.c_str()))
        {
            mapa.push_back(path);
            in++;
        }
        else
        {
            fin = true;
        }
    }
    return mapa;
}

string escogerMapa(string j)
{
    if(Archivo::archivoExiste(j.c_str()))
    {
        char decision;
        cout << "Deseas continuar con la partida (s/n): ";
        cin >> decision;
        if(decision == 's')
            return j;
    }
    vector<string> mapas = buscarMapas();
    int index;
    cout << "Elige un mapa, ingresa un numero del " << 1 << " al " << mapas.size() << ": ";
    cin >> index;
    return mapas[index-1];
}

void iniciarTablero(shared_ptr<Mapa> mapa, shared_ptr<Tablero> tablero, shared_ptr<Interfaz> interfaz, sf::RenderWindow& ventanaPrincipal, int dimension, int tamCuadro)
{
    shared_ptr<Cuadro> trono, rey;
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            shared_ptr<Figura> figura(FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CUADRADO, Cuadrado::getColorCuadro(i,j), i, j, tamCuadro, ventanaPrincipal));
            interfaz->push_figura(figura);
            shared_ptr<Cuadro> cuadro;
            Mapa::TipoFicha tF = mapa->buscar(i,j);
            switch(tF)
            {
            case Mapa::TipoFicha::ESQUINA:
            {
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(0,255,0), i, j, tamCuadro, ventanaPrincipal);
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
                ///creo el rey
                figura = FabricaFigura::crearFigura(FabricaFigura::TipoFigura::CIRCULO, sf::Color(255,255,0), i, j, tamCuadro, ventanaPrincipal);
                interfaz->push_figura(figura);
                cuadro = FabricaFicha::crearFicha(FabricaFicha::TipoFicha::REY, figura);
                tablero->agregarFicha(i,j, cuadro);
            }
            break;
            default:
                break;
            }

        }
    }
}


