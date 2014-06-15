#ifndef _FICHABLANCA_H_
#define _FICHABLANCA_H_
#include "Ficha.h"

class FichaBlanca : public Ficha
{
public:
    FichaBlanca():Ficha(){};
    virtual void comer();
};
#endif // _FICHABLANCA_H_
