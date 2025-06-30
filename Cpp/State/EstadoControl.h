#pragma once
#ifndef ESTADO_CONTROL_H
#define ESTADO_CONTROL_H
#include "motor.h"

class EstadoControl
{

public:
    virtual void apretarBoton(Motor *m, EstadoControl *&e) = 0;
    virtual ~EstadoControl() {}
};
#endif