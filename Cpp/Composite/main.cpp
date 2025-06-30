// 🗂️ Sistema de Archivos
// Conceptos: Composite full.

// Práctica:

// Interface Elemento con método getTamanioTotal().

// Archivo devuelve su tamaño, Directorio suma el de sus hijos.

// Uso de colecciones abstractas (ICollection, IIterator) → simulá cómo recorrerlas.
#include <iostream>
#include "IElemento.h"
#include "Archivo.h"
#include "Directorio.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h" // Asumiendo que List es una implementación de ICollection
using namespace std;

int main(){
    // Crear archivos
    IElemento * archivo1 = new Archivo(1, 100); // Archivo con ID 1 y tamaño 100
    IElemento * archivo2 = new Archivo(2, 200); // Archivo con ID
    IElemento * archivo3 = new Archivo(3, 300); // Archivo con ID 3 y tamaño 300
    // Crear un directorio y agregar los archivos
    // Asumiendo que ICollection es una colección que puede contener IElemento
    // y que List es una implementación de ICollection
    // Crear una colección de archivos


    ICollection* coleccion = new List();
    coleccion->add(archivo1);
    coleccion->add(archivo2);
    coleccion->add(archivo3);

    IElemento* directorio = new Directorio(10, coleccion); // Directorio con ID 10

    // Calcular el tamaño total del directorio
    cout << "Tamaño total del directorio: " << directorio->calcularTamanio() << endl;

    // Limpiar memoria
    delete directorio;
    delete archivo1;
    delete archivo2;
    delete archivo3;

    return 0;
}