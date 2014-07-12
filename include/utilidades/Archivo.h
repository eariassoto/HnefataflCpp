#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

/** \brief Utilidades de entrada y salida de datos.
 */
class Archivo
{
public:
    Archivo(string);

    /** \brief Lee un archivo como caracteres.
     *
     * \return char*
     *
     */
    char*       leerArchivoCaracter();

    /** \brief Lee un caracter en una posicion n
     *
     * \param int
     * \return char
     *
     */
    char        leerCaracter(int);

    /** \brief Lee un entero en una posicion n.
     *
     * \param int
     * \return int
     *
     */
    int         leerEntero(int);

    /** \brief Lee un bloque de caracteres.
     *
     * \param int
     * \param int
     * \return char*
     *
     */
    char*       leerCaracteres(int, int);

    /** \brief Lee un bloque de enteros.
     *
     * \param int
     * \param int
     * \return vector<int>
     *
     */
    vector<int> leerEnteros(int, int);

    /** \brief Lee un archivo como enteros.
     *
     * \return vector<int>
     *
     */
    vector<int> leerArchivoEntero();

    int         getLargo();

    int         getLargoEntero();

    /** \brief Escribe un entero en un archivo
     *
     * \param ofstream&
     * \param int
     * \return void
     *
     */
    void escribirEntero(ofstream&, int);

    /** \brief Revisa si un archivo existe
     *
     * \param char* const
     * \return bool
     *
     */
    static bool archivoExiste(const char*);

    /** \brief Borra un archivo
     *
     * \param char* const
     * \return void
     *
     */
    void borrarArchivo(const char*);

protected:
    const string path;
};
#endif // ARCHIVO_H_
