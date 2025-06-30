#include "Deposito.h"

Deposito::Deposito(){
    cout << "Se ha creao un deposito" << endl;
}

void Deposito::notify(int id){
    cout << "Se ha pide stock del producto ID " << id << endl;
}

Deposito::~Deposito(){
    cout << "Se ha destruio un deposito" << endl;
}