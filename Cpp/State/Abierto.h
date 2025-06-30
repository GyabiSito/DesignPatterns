#pragma once
#ifndef ABIERTO_H
#define ABIERTO_H
#include "EstadoControl.h"
#include "Cerrado.h"
#include <iostream>
using namespace std;
class Abierto : public EstadoControl{
    public:
        void apretarBoton(Motor *m,EstadoControl *&e) override;

};

#endif