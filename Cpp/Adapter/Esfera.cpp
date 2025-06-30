#include "Esfera.h"

Esfera::Esfera(const string &nombre, const string &tipo, const string &material, double volumen, double radio)
    : I3DFigura(nombre, tipo, material, volumen), radio(radio)
{

}

void Esfera::dibujar()
{
    cout << "Dibujando una esfera de radio: " << getRadio() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

void Esfera::mover()
{
    cout << "Moviendo una esfera de radio: " << getRadio() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

double Esfera::getRadio() const
{
    return this->radio;
}
void Esfera::setRadio(double radio)
{
    this->radio = radio;
}
Esfera::~Esfera()
{
    // Destructor por defecto
    cout << "Destruyendo Esfera de radio: " << getRadio() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

