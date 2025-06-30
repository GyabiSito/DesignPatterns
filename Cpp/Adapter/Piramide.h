#pragma once
#ifndef PIRAMIDE_H
#define PIRAMIDE_H
#include "I3DFigura.h"
#include <iostream>
class Piramide : public I3DFigura
{

private:
    double base;   // Base de la pirámide
    double altura; // Altura de la pirámide
public:
    Piramide(const string &nombre, const string &tipo, const string &material, double volumen, double base, double altura);
    void dibujar() override;       // Método para dibujar la pirámide
    void mover() override;         // Método para mover la pirámide
    double getBase() const;        // Método para obtener la base de la pirámide
    void setBase(double base);     // Método para establecer la base de la pirámide
    double getAltura() const;      // Método para obtener la altura de la pirámide
    void setAltura(double altura); // Método para establecer la altura de la pirámide
    ~Piramide();          // Destructor
};

#endif