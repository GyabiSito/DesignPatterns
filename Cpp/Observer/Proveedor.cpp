#include "Proveedor.h"

Proveedor::Proveedor(){
    cout << "Se ha creado un proveedor" << endl;
}

void Proveedor::notify(int id){
    cout << "El proveedor debe probeer stock al producto ID" << id << endl;
}

Proveedor::~Proveedor(){
    cout << "Se ha destruio un provedor" << endl;
}