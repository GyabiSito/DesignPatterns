#include "PuntoDeVenta.h"

PuntoDeVenta::PuntoDeVenta() {
    productos = new List();   // ← IMPORTANTE
    observers = new List();   // ← IMPORTANTE
}
void PuntoDeVenta::venderProducto(int id, int cant)
{
    // Buscar el producto con ESA id y ESA cantidad y venderlo, luego notificar
    IIterator *it = productos->getIterator();
    if(it==NULL){
        cout << "No hay productos en el punto de venta" << endl;
        return;
    }
    while (it->hasCurrent())
    {
        Producto *p = (Producto *)it->getCurrent();
        if(p == NULL){
            cout << "Producto nulo encontrado, continuando..." << endl;
            it->next();
            continue;
        }
        if (p->getId() == id)
        {
            if ((p->getStock() - cant) <= 0)
            {
                //*************************Esto se puede separar pero me da paja */
                // Iterar por cada observer y notificar
                IIterator *it2 = observers->getIterator();
                while (it2->hasCurrent())
                {
                    IObserver *o = (IObserver *)it2->getCurrent();
                    o->notify(id);
                    it2->next();
                }
                delete it2;
                return;
                //*************************Esto se puede separar pero me da paja */
            }
            else
            {
                cout << "Se ha quitao " << cant << "Del producto con id" << id << endl;
                p->setStock(p->getStock() - cant);
            }
        }
        it->next();
    }
    delete it;
}

void PuntoDeVenta::agregarObserver(IObserver *o)
{
    cout << "Se ha agregado un observer" << endl;
    observers->add(o);
}
void PuntoDeVenta::eliminarObserver(IObserver *o)
{
    observers->remove(o);
}

void PuntoDeVenta::agregarProducto(Producto *p)
{
    cout << "Se ha agregado un producto al punto de venta" << endl;
    productos->add(p);
}
PuntoDeVenta::~PuntoDeVenta(){
    cout << "Destruyendo PuntoDeVenta y sus colecciones..." << endl;
    delete productos;   // Limpia la colección de productos
    delete observers;   // Limpia la colección de observadores
    cout << "PuntoDeVenta destruido." << endl;
}