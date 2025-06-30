#pragma once
#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "IFigura.h"
#include <iostream>
class Triangulo : public IFigura {
    private:
        int base;
        int altura;

    public:
        Triangulo(int, int);
        void dibujar() override;
        void mover() override;
        int getBase() const;
        void setBase(int);
        int getAltura() const;
        void setAltura(int);
        ~Triangulo();
};

#endif