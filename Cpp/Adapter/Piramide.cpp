#include "Piramide.h"

Piramide::Piramide(const string &nombre, const string &tipo, const string &material, double volumen, double base, double altura)
    : I3DFigura(nombre, tipo, material, volumen), base(base), altura(altura) {}

void Piramide::dibujar()
{
    cout << "Dibujando una pirámide de base: " << getBase() << ", altura: " << getAltura()
         << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

void Piramide::mover()
{
    cout << "Moviendo una pirámide de base: " << getBase() << ", altura: " << getAltura()
         << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

double Piramide::getBase() const
{
    return this->base;
}
void Piramide::setBase(double base)
{
    this->base = base;
}
double Piramide::getAltura() const
{
    return this->altura;
}
void Piramide::setAltura(double altura)
{
    this->altura = altura;
}
Piramide::~Piramide()
{
    // Destructor por defecto
    cout << "Destruyendo Pirámide de base: " << getBase() << ", altura: " << getAltura()
         << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}