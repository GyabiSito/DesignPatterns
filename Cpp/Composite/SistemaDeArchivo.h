#pragma once
#ifndef SISTEMA_DE_ARCHIVO_H
#define SISTEMA_DE_ARCHIVO_H
#include "ISistemaDeArchivo.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Archivo.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/Integer.h"
#include "Directorio.h"
#include "IElemento.h"
#include "ICollection/interfaces/ICollectible.h"
class SistemaDeArchivo : public ISistemaDeArchivo {
private:
    static SistemaDeArchivo* instancia;
    IDictionary* elementos; // clave: int (id), valor: Elemento*
    SistemaDeArchivo(); // constructor privado
public:
    static SistemaDeArchivo* getInstance();
    void crearArchivo(int idCarpeta, int idArchivo, int tamanio) override;
    int calcularTamanio(int idElemento) override;
};


#endif