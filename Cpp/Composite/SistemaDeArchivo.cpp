#include "SistemaDeArchivo.h"

SistemaDeArchivo * SistemaDeArchivo::instancia=nullptr;
SistemaDeArchivo::SistemaDeArchivo() {
    elementos = new OrderedDictionary();
}

SistemaDeArchivo * SistemaDeArchivo::getInstance(){
    if(instancia == nullptr){
        instancia = new SistemaDeArchivo();
    }
    return instancia;
}

void SistemaDeArchivo::crearArchivo(int idCarpeta, int idArchivo, int tamanio) {
    Archivo * archivo = new Archivo(idArchivo, tamanio);
    IKey * idCarpetaKey = new Integer(idCarpeta);
    IKey * idArchivoKey = new Integer(idArchivo);
    if (elementos->find(idCarpetaKey) == nullptr) {
        Directorio * carpeta = new Directorio(idCarpeta, new List());
        elementos->add(idCarpetaKey, carpeta);
    }else{
        Directorio * carpeta = dynamic_cast<Directorio *>(elementos->find(idCarpetaKey));
        if (carpeta != nullptr) {
            carpeta->agregarElemento(archivo);
        }
    }
}

int SistemaDeArchivo::calcularTamanio(int idElemento) {
    IKey * idElementoKey = new Integer(idElemento);
    IElemento * elemento = dynamic_cast<IElemento *>(elementos->find(idElementoKey));
    if (elemento != nullptr) {
        return elemento->calcularTamanio();
    }
    return 0;
}