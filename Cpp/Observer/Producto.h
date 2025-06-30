#pragma once
#ifndef PRODUCTO_H  
#define PRODUCTO_H
#include "ICollection/interfaces/ICollectible.h"
class Producto : public ICollectible{
    private:
        int stock;
        int id;
    public:
        Producto();
        Producto(int,int);
        void setStock(int);
        int getStock();
        void setId(int);
        int getId();
        ~Producto();
};

#endif