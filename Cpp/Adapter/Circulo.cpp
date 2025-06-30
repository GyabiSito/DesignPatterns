#include "Circulo.h"

/**
 *         Circulo(int);
        void dibujar() override;
        void mover() override;
        int getRadio();
        void setRadio(int);
        ~Circulo();
 */

Circulo::Circulo(int r) : radio(r), diametro(r * 2)
{
    // Constructor que inicializa el radio y calcula el diametro
}

void Circulo::dibujar()
{
    cout << "Dibujando un circulo de radio: " << getRadio() << endl;
}

void Circulo::mover()
{
    cout << "Moviendo el circulo de radio: " << getRadio() << endl;
}

int Circulo::getRadio() const
{
    return this->radio;
}

void Circulo::setRadio(int r)
{
    this->radio = r;
}
int Circulo::getDiametro() const
{
    return this->radio * 2;
}

void Circulo::setDiametro(int d)
{
    this->radio = d / 2;
}

Circulo::~Circulo(){
    // Destructor por defecto
    cout << "Destruyendo Circulo de radio: " << endl;
}