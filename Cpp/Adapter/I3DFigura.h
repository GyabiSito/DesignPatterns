#pragma once
#ifndef I3DFIGURA_H
#define I3DFIGURA_H

#include "IFigura.h"
#include <iostream>
#include <string>
#include "./ICollection/interfaces/ICollectible.h"
using namespace std;
class I3DFigura : public IFigura
{
private:
    string material; // Material de la figura 3D
    double volumen;  // Volumen de la figura 3D
public:
    I3DFigura() = default; // Constructor por defecto
    I3DFigura(const string &, const string &, const string &, double);
    virtual void dibujar() = 0; // Método para dibujar la figura 3D
    virtual void mover() = 0;   // Método para mover la figura 3D
    virtual string getMaterial() const;
    virtual void setMaterial(const string &);
    virtual double getVolumen() const;
    virtual void setVolumen(double);
    virtual ~I3DFigura(); // Destructor por defecto
};
#endif