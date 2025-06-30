#pragma once
#ifndef DEPOSITO_H
#define DEPOSITO_H
#include "IObserver.h"
#include <iostream>
using namespace std;

class Deposito : public IObserver
{
public:
    Deposito();
    void notify(int) override;
    ~Deposito();
};

#endif