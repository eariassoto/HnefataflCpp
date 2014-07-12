#ifndef MAPA_H_
#define MAPA_H_
#include <map>
#include <string>
#include <memory>
#include "Tablero.h"
#include "Archivo.h"

/** \brief Se encarga de la salida y entrada de datos del mapa del tablero
 */
class Mapa: public Archivo
{
public:

    Mapa(string, string);
    enum TipoFicha ///Identifica las fichas que esta leyendo
    {
        CUADRO = 0,
        BLANCA = 1,
        NEGRA = 2,
        REY = 3,
        ESQUINA = 4,
    };

    int getDimension();


    /** \brief Determina el tipo de ficha que se le indica
     *
     * \param int
     * \param int
     * \return TipoFicha
     *
     */
    TipoFicha buscar(int, int);

    /** \brief Guarda la partido
     *
     * \param shared_ptr<Tablero>
     * \return void
     *
     */
    void guardarMapa(shared_ptr<Tablero>);

    /** \brief Borra una partida.
     *
     * \return void
     *
     */
    void borrarMapa();

private:
    int                        dimension;
    map< pair<int, int>, int > coordenada; /// Aqui guarda lo que lee del archivo.
    void                       armarPares(vector<int>);
    string                     pathJuego;

};
#endif // MAPA_H_
