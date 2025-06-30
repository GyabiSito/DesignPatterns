#pragma once
#ifndef IELEMENTO_H
#define IELEMENTO_H

#include "ICollection/interfaces/ICollectible.h"
class IElemento : public ICollectible {
protected:
    int id;
public:
    IElemento(int id);
    virtual int getId() const=0;
    virtual int calcularTamanio() const = 0;
    virtual ~IElemento(){};
};

#endif