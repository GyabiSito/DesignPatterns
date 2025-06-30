#pragma once
#ifndef FACTORY_H
#define FACTORY_H

#include "ISistema1.h"
#include "ISistema2.h"
#include "Controlador1.h"
#include "Controlador2.h"

class Factory {
private:
    static Factory* instancia;
    Factory(); // constructor privado

public:
    static Factory* getInstancia(); // método de acceso singleton

    ISistema1* getISistema1();
    ISistema2* getISistema2();
};

#endif
