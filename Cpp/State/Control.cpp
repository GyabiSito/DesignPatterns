#include "control.h"


Control::Control() {
    m = new Motor();

    e = new Cerrado(); // Initial state
}
Control::~Control() {
    delete m;
    delete e;
}
void Control::apretarBoton() {
    e->apretarBoton(m, e);
}
void Control::setEstado(EstadoControl *estado) {
    delete e; 
    e = estado;
}

EstadoControl* Control::getEstado() {
    return e;
}

void Control::setMotor(Motor *motor) {
    delete m; 
    m = motor;
}

Motor* Control::getMotor() {
    return m;
}