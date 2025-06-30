#pragma once
#ifndef IFigura_h
#define IFigura_h

#include <iostream>
#include <string.h>
#include "./ICollection/interfaces/ICollectible.h"
using namespace std;

class IFigura : public ICollectible
{
private:
    string nombre;
    string tipo;

public:
    IFigura() = default; // Constructor por defecto
    IFigura(const string &, const string &);
    virtual void dibujar() = 0;
    virtual void mover() = 0;
    virtual string getNombre() const;
    virtual string getTipo() const;
    virtual void setNombre(const string&);
    virtual void setTipo(const string&);
    virtual void imprimir() const;
    virtual ~IFigura();
};
#endif