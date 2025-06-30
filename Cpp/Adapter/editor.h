#pragma once
#ifndef EDITOR_H
#define EDITOR_H
#include <iostream>
#include "IFigura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "./ICollection/interfaces/ICollectible.h"
#include "./ICollection/interfaces/ICollection.h"
#include "./ICollection/interfaces/IDictionary.h"
#include "./ICollection/interfaces/IIterator.h"
#include "./ICollection/interfaces/IKey.h"
#include "./ICollection/interfaces/OrderedKey.h"
#include "./ICollection/interfaces/StringKey.h"
#include "./ICollection/collections/List.h"
#include "./ICollection/collections/OrderedDictionary.h"
#include "string.h"
using namespace std;
class Editor : public IFigura
{
private:
    ICollection *figuras;          // Colección de figuras
    IDictionary *figurasPorNombre; // Diccionario de figuras por nombre
    IDictionary *figurasPorTipo;   // Diccionario de figuras por tipo

public:
    Editor(); // Constructor que inicializa las colecciones
    void agregarFigura(IFigura *);
    void eliminarFigura(IFigura *);

    void dibujar() override;
    void mover() override;
    
    IFigura *buscarFiguraPorNombre(const string);
    IFigura *buscarFiguraPorTipo(const string);

    ICollection *getFiguras() const;
    IDictionary *getFigurasPorNombre() const;
    IDictionary *getFigurasPorTipo() const;

    void setFiguras(ICollection *);
    void setFigurasPorNombre(IDictionary *);
    void setFigurasPorTipo(IDictionary *);

    void imprimirFiguras();
    void imprimirFigurasPorTipo(const string);
    void imprimirFigurasPorNombre(const string);
    ~Editor() override;
    
};
#endif