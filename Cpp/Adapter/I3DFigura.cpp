#include "I3DFigura.h"

I3DFigura::I3DFigura(const string &nombre, const string &tipo, const string &material, double volumen) : IFigura(nombre, tipo), material(material), volumen(volumen) {}

string I3DFigura::getMaterial() const
{
    return this->material;
}
void I3DFigura::setMaterial(const string &material)
{
    this->material = material;
}
double I3DFigura::getVolumen() const
{
    return this->volumen;
}
void I3DFigura::setVolumen(double volumen)
{
    this->volumen = volumen;
}
void I3DFigura::dibujar()
{
    cout << "Dibujando figura 3D de tipo: " << getTipo() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}
void I3DFigura::mover()
{
    cout << "Moviendo figura 3D de tipo: " << getTipo() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}

I3DFigura::~I3DFigura()
{
    // Destructor por defecto
    cout << "Destruyendo figura 3D de tipo: " << getTipo() << ", material: " << getMaterial() << ", volumen: " << getVolumen() << endl;
}