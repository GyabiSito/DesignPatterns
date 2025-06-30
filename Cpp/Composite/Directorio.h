#pragma once
#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "IElemento.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h" 

class Directorio : public IElemento
{
private:
    ICollection *hijos; // Elementos (Archivos o Directorios)
public:
    Directorio(int id,ICollection *elementos);
    int getId() const override;
    void agregarElemento(IElemento *e);
    int calcularTamanio() const override;
    ~Directorio();
};

#endif