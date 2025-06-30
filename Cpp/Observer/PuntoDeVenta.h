#pragma once
#ifndef PUNTO_DE_VENTA_H
#define PUNTO_DE_VENTA_H
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/List.h"
#include "IObserver.h"
#include "Producto.h"
#include <iostream>
using namespace std;
class PuntoDeVenta
{
private:
    ICollection *productos;
    ICollection *observers;
    void notificarObservadores(int);

public:
    PuntoDeVenta(); // ← Agregado
    void venderProducto(int, int);
    void agregarProducto(Producto *);
    void agregarObserver(IObserver *);
    void eliminarObserver(IObserver *);
    ~PuntoDeVenta();
};

#endif