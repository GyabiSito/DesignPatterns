#pragma once
#ifndef CIRCULO_H
#define CIRCULO_H
#include "IFigura.h"
#include <iostream>
using namespace std;
class Circulo : public IFigura {
    private:
        int radio;
        int diametro;
        
    public:
        Circulo(int);
        void dibujar() override;
        void mover() override;
        int getRadio() const;
        void setRadio(int);
        int getDiametro() const;
        void setDiametro(int d);
        ~Circulo();
};

#endif