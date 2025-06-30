#pragma once
#ifndef CONTROLADOR2_H
#define CONTROLADOR2_H
#include "ISistema2.h"

class Controlador2 : public ISistema2
{
    public:
    void oper3() override;
    void oper4() override;
};


#endif