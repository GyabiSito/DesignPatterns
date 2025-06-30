#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "Deposito.h"
#include "Proveedor.h"
#include "Producto.h"
#include "PuntoDeVenta.h"

int main(){
    PuntoDeVenta* pdv = new PuntoDeVenta();
    Deposito* deposito = new Deposito();
    Proveedor* proveedor = new Proveedor();

    // Registramos los observadores
    pdv->agregarObserver(deposito);
    pdv->agregarObserver(proveedor);

    // Creamos un producto y lo agregamos al punto de venta
    cout << "Agregando producto al punto de venta..." << endl;
    Producto* producto = new Producto(1, 100); // ID 1, stock
    pdv->agregarProducto(producto);
    int id = producto->getId();
    int mucho = 150; // Cantidad a vender
    cout << "Vender producto con ID: " << id << " y cantidad: " << mucho << endl;
    pdv->venderProducto(id, mucho);

    // Cleanup
    delete pdv;
    delete deposito;
    delete proveedor;
}