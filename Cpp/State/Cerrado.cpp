#include "Cerrado.h"
Cerrado::Cerrado() {
    cout << "Estado inicial: Cerrado" << endl;
}
void Cerrado::apretarBoton(Motor *m, EstadoControl *&e) {
    m->abrir();
    cout << "Estoy Cerrado. Cambio a Abierto." << endl;
    e = new Abierto(); // Assuming you have an Abierto state class to transition to
}