#include "IFigura.h"
using namespace std;

// Constructor por defecto eliminado porque IFigura probablemente es abstracta

IFigura::IFigura(const string &nombre, const string &tipo) : nombre(nombre), tipo(tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
}

string IFigura::getNombre() const
{
    return this->nombre;
}
void IFigura::setNombre(const string &nombre)
{
    this->nombre = nombre;
}
string IFigura::getTipo() const
{
    return this->tipo;
}
void IFigura::setTipo(const string &tipo)
{
    this->tipo = tipo;
}
void IFigura::imprimir() const
{
    cout << "Nombre: " << getNombre() << ", Tipo: " << getTipo() << endl;
}

IFigura::~IFigura(){
    // Destructor por defecto
    cout << "Destruyendo figura de tipo: " << getTipo() << ", nombre: " << getNombre() << endl;
}