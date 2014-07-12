#ifndef _ESQUINA_H_
#define _ESQUINA_H_
#include <memory>
#include "Cuadro.h"
#include "Figura.h"

/** \brief Representa una esquina del tablero. Util para que las fichas no se muevan con estas y el rey sepa cuando gano.
 */
class Esquina: public Cuadro
{

public:

    Esquina(shared_ptr<Figura> f): figura(f), Cuadro() {};

protected:

    shared_ptr<Figura> figura;
};
#endif // _ESQUINA_H_
