#include "Archivo.h"


Archivo::Archivo(int id, int tamanio) : IElemento(id), tamanio(tamanio) {}

int Archivo::getId() const {
    return id;
}

int Archivo::calcularTamanio() const {
    return tamanio;
}