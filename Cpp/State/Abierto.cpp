#include "Abierto.h"

void Abierto::apretarBoton(Motor *m, EstadoControl *&e) {
    m->cerrar();
    cout << "Estoy Abierto. Cambio a Cerrado" << endl;
    e = new Cerrado(); 
}