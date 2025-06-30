#pragma once
#ifndef CONTROLADOR1_H
#define CONTROLADOR1_H
#include "ISistema1.h"

class Controlador1 : public ISistema1 {
private:
    Controlador1(); // privado

public:
    static Controlador1& getInstancia(); // retorna una instancia estática
    void oper1() override;
    void oper2() override;
};



#endif