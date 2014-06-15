#ifndef _EXCEPCION_H_
#define _EXCEPCION_H_
#include <iostream>
#include <string>

using namespace std;

class Excepcion: public exception{
public:

    explicit Excepcion(const char* m): msg(m){}

    virtual ~Excepcion() throw (){}

    virtual const char* what() const throw (){
       return msg.c_str();
    }

protected:
    string msg;
};
#endif // _EXCEPCION_H_
