#pragma once
#ifndef ISISTEMA_DE_ARCHIVO_H
#define ISISTEMA_DE_ARCHIVO_H
#include "ICollection/interfaces/ICollectible.h"
class ISistemaDeArchivo : ICollectible {
public:
    ISistemaDeArchivo();
    virtual void crearArchivo(int idCarpeta, int idArchivo, int tamanio) = 0;
    virtual int calcularTamanio(int idElemento) = 0;
    virtual ~ISistemaDeArchivo() {}
};


#endif