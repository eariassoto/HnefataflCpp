#ifndef _CUADRO_H_
#define _CUADRO_H_
#include <vector>
#include "Excepcion.h"

using namespace std;

class Cuadro
{
public:
    Cuadro(Cuadro* arr, Cuadro* der, Cuadro* aba, Cuadro* izq): 
	ARR(0), DER(1), ABA(2), IZQ(3)
	{
		cuadroPtr.push_back(arr);
		cuadroPtr.push_back(der);
		cuadroPtr.push_back(aba);
		cuadroPtr.push_back(izq);
	};

    virtual int* mover(Cuadro*)
    {
        throw Excepcion("Esta ficha es un cuadro, no puede moverse");
    };
    virtual void comer()
    {
        throw Excepcion("Esta ficha es un cuadro, no puede comer");
    };
	
	virtual Cuadro* getVecino(int v){
		if(v < 0 || v > 3)
			throw Excepcion("Parametro de getVecino incorrecto");
		else
			return cuadroPtr.at(v);
	}
	
protected:
	const int ARR, DER, ABA, IZQ; //sigue orden agujas reloj
    vector<Cuadro*> cuadroPtr;
};
#endif // _CUADRO_H_
