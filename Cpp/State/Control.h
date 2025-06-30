#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include "EstadoControl.h"
#include "motor.h"
#include "Cerrado.h"
#include "Abierto.h"
class Control{
    private:
        Motor *m;
        EstadoControl *e;
    public:
        Control();
        ~Control();
        void apretarBoton();
        void setEstado(EstadoControl *estado);
        EstadoControl* getEstado();
        void setMotor(Motor *m);
        Motor * getMotor();
};

#endif