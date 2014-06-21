#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Figura.h"
#include "Cuadrado.h"

using namespace std;

class Interfaz
{
public:
    Interfaz(sf::RenderWindow&);
    void dibujar();
    void push_figura(Figura*);
    sf::RenderWindow& ventana_;
private:
    vector<Figura*> figuras;
//    /** \class Cuadro
//     * \brief Mantiene un arbol con un contenedor para las instancias de sf::RectangleShape que son los cuadros del tablero.
//
//     * \version 0.1
//     * \author Emmanuel Arias, Geovanny Zu;iga
//     *
//     */
//    class Cuadro
//    {
//    public:
//        Cuadro();
//        Cuadro(int, int, sf::RectangleShape);
//        ~Cuadro();
//
//        int                coordX;
//        int                coordY;
//        bool               usado;
//        Cuadro *           hijoIzq;
//        Cuadro *           hijoDer;
//        sf::RectangleShape rectangulo;
//
//        void     agregarCuadro(Cuadro *);
//        void     dibujarCuadros(sf::RenderWindow&);
//        Cuadro * buscarCuadro(int, int);
//        int *    buscarPixelEnCuadro(int, int);
//    };
//
//    int    iniciarPantallaInicio();
//    void   iniciarPantallaFinal();
//    bool   iniciarPantallaSesion();
//    void   iniciarPantallaTablero();
//    void   dibujarPantallaTablero();
//    void   dibujarPantallaSesion(bool);
//    void   setPosicionMouse(int, int);
//    bool   puedeMover(int, int);
//    int *  getCoordNodo(int, int);
//
//private:
//    int               cantCuadros;
//    int               mousex;
//    int               mousey;
   /// sf::RenderWindow& ventana;
//    sf::Font          fuente;
//    Cuadro *          raiz;
//
//    int *     calcularEsquinaCuadro(int, int);
//    int       calcularEscalaCirculo();
//    int *     calcularCoordEscala(int, int);
//    sf::Color getColorCuadro(int, int);
//    sf::Color getColorFicha(bool);
//    void      dibujarFicha(int, int, sf::Color);
//    void      dibujarFichas();
//    void      dibujarTexto(string, int, int);
//    void      dibujarPantallaInicio();
//    void      dibujarPantallaFinal();
//    std::string itos(int);
};

#endif


