#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Figura.h"
#include <memory>

using namespace std;

/** \brief Coordina la representacion grafica del juego. Mantiene un vector de elementos graficos asociados a una ventana
 */
class Interfaz
{
public:

    Interfaz(sf::RenderWindow&);

    /** \brief Dibuja los elementos en la ventana
     *
     * \return void
     *
     */
    void dibujar();

    /** \brief Agrega elementos al vector.
     *
     * \param shared_ptr<Figura>
     * \return void
     *
     */
    void push_figura(shared_ptr<Figura>);

    /** \brief Busca un punto en la ventana.
     *
     * \param int
     * \param int
     * \return int*
     *
     */
    int* buscarPunto(int, int);

    sf::RenderWindow& ventana_;

private:
    vector< shared_ptr<Figura> > figuras; ///vector de figuras
};

#endif


