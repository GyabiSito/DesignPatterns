#pragma once
#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "IFigura.h"
#include <iostream>

class Rectangulo : public IFigura{
    private:
        int base;
        int altura;
    public:
        Rectangulo(int, int);
        void dibujar() override;
        void mover() override;
        int getBase() const;
        void setBase(int);
        int getAltura() const;
        void setAltura(int);
        ~Rectangulo();
};

#endif