#pragma once
#ifndef ESFERA_H
#define ESFERA_H
#include "I3DFigura.h"
class Esfera : public I3DFigura
{
private:
    double radio; // Radio de la esfera
public:
    Esfera(const string &, const string &, const string &, double, double);
    void dibujar() override;     // Método para dibujar la esfera
    void mover() override;       // Método para mover la esfera
    double getRadio() const;     // Método para obtener el radio de la esfera
    void setRadio(double radio); // Método para establecer el radio de la esfera
    ~Esfera();          // Destructor
};
#endif