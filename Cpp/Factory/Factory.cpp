#include "Factory.h"

Factory* Factory::instancia = nullptr;

Factory::Factory() {}

Factory* Factory::getInstancia() {
    if (instancia == nullptr)
        instancia = new Factory();
    return instancia;
}

ISistema1* Factory::getISistema1() {
    return &Controlador1::getInstancia();
}

ISistema2* Factory::getISistema2() {
    // si Controlador2 no es singleton, crea una instancia nueva
    return new Controlador2(); 
}
