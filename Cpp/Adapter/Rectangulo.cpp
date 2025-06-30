#include "Rectangulo.h"

/**
 *         Rectangulo(int, int);
 *         void dibujar() override;
 *         void mover() override;
 *         int getBase() const;
 *         void setBase(int);
 *         int getAltura() const;
 *         void setAltura(int);
 *         ~Rectangulo();
 */
Rectangulo::Rectangulo(int b, int a) : base(b), altura(a) {}

void Rectangulo::dibujar() {
    std::cout << "Dibujando un rectangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}
void Rectangulo::mover() {
    std::cout << "Moviendo el rectangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}
int Rectangulo::getBase() const {
    return this->base;
}
void Rectangulo::setBase(int b) {
    this->base = b;
}
int Rectangulo::getAltura() const {
    return this->altura;
}
void Rectangulo::setAltura(int a) {
    this->altura = a;
}

Rectangulo::~Rectangulo(){
    // Destructor por defecto
    std::cout << "Destruyendo Rectangulo de base: " << getBase() << " y altura: " << getAltura() << std::endl;
}

