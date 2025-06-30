#pragma once
#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "IObserver.h"
#include <iostream>
using namespace std;
class Proveedor : public IObserver{
    public:
    Proveedor();    
    void notify(int);
    ~Proveedor();

};

#endif