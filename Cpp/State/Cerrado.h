#pragma once
#ifndef CERRADO_H
#define CERRADO_H
#include "EstadoControl.h"
#include "Abierto.h"
#include <iostream>
using namespace std;
class Cerrado : public EstadoControl {
    public:
    Cerrado();
    void apretarBoton(Motor *m, EstadoControl *&e) override;
};

#endif