#pragma once
#ifndef PARALELEPIPEDO_H
#define PARALELEPIPEDO_H
#include "I3DFigura.h"
#include <iostream>
using namespace std;
class Paralelepipedo : public I3DFigura {
    private:
    double largo;   // Largo del paralelepípedo
    double ancho;   // Ancho del paralelepípedo
    double altura;  // Altura del paralelepípedo
    public:
    Paralelepipedo(const string &, const string &, const string &, double, double, double, double);
    void dibujar() override;       // Método para dibujar el paralelepípedo
    void mover() override;         // Método para mover el paralelepípedo
    double getLargo() const;       // Método para obtener el largo del paralelepípedo
    void setLargo(double);   // Método para establecer el largo del paralelepípedo
    double getAncho() const;       // Método para obtener el ancho del paralelepípedo
    void setAncho(double);   // Método para establecer el ancho del paralelepípedo
    double getAltura() const;      // Método para obtener la altura del paralelepípedo
    void setAltura(double); // Método para establecer la altura del paralelepípedo
    ~Paralelepipedo();    // Destructor

};

#endif