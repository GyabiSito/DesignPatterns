#include "Producto.h"

Producto::Producto(){}
Producto::Producto(int id, int stock){
    this->id=id;
    this->stock=stock;
}
void Producto::setStock(int stock){
    this->stock=stock;
}
int Producto::getStock(){
    return this->stock;
}
void Producto::setId(int id){
    this->id=id;
}
int Producto::getId(){
    return this->id;
}
Producto::~Producto(){
    
}