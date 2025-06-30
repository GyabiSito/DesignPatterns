#include "Triangulo.h"

Triangulo::Triangulo(int b, int a) : base(b), altura(a) {}

void Triangulo::dibujar()
{
    std::cout << "Dibujando un triangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}
void Triangulo::mover()
{
    std::cout << "Moviendo el triangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}
int Triangulo::getBase() const
{
    return this->base;
}
void Triangulo::setBase(int b)
{
    this->base = b;
}
int Triangulo::getAltura() const
{
    return this->altura;
}
void Triangulo::setAltura(int a)
{
    this->altura = a;
}

Triangulo::~Triangulo()
{
    // Destructor por defecto
    std::cout << "Destruyendo Triangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}