#pragma once
#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "IElemento.h"
class Archivo : public IElemento {
private:
    int tamanio;
public:
    Archivo(int id, int tamanio);
    int getId() const override;
    int calcularTamanio() const override;
};


#endif