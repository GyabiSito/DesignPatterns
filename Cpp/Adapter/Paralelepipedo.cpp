#include "Paralelepipedo.h"

Paralelepipedo::Paralelepipedo(const string &nombre, const string &tipo, const string &material, double volumen, double largo, double ancho, double altura)
    : I3DFigura(nombre, tipo, material, volumen), largo(largo), ancho(ancho), altura(altura) {}

void Paralelepipedo::dibujar()
{
    cout << "Dibujando un paralelepípedo de largo: " << getLargo() << ", ancho: " << getAncho()
         << ", altura: " << getAltura() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

void Paralelepipedo::mover()
{
    cout << "Moviendo un paralelepípedo de largo: " << getLargo() << ", ancho: " << getAncho()
         << ", altura: " << getAltura() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

double Paralelepipedo::getLargo() const
{
    return this->largo;
}

void Paralelepipedo::setLargo(double largo)
{
    this->largo = largo;
}

double Paralelepipedo::getAncho() const
{
    return this->ancho;
}

void Paralelepipedo::setAncho(double ancho)
{
    this->ancho = ancho;
}

double Paralelepipedo::getAltura() const
{
    return this->altura;
}

void Paralelepipedo::setAltura(double altura)
{
    this->altura = altura;
}

Paralelepipedo::~Paralelepipedo()
{
    // Destructor por defecto
    cout << "Destruyendo Paralelepípedo de largo: " << getLargo() << ", ancho: " << getAncho()
         << ", altura: " << getAltura() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}
