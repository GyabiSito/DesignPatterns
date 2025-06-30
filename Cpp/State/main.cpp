
#include <iostream>
#include "Control.h"
#include "motor.h"
#include "Abierto.h"
#include "Cerrado.h"
#include "EstadoControl.h"

using namespace std;

int main(){
    Control* control = new Control();     // ✅ Crear instancia
    Motor *motor = control->getMotor();   // ✅ Ya puedes usarlo

    control->apretarBoton(); // Cambia a Abierto

    
    control->apretarBoton(); // Cambia a Cerrado

    
    return 0;
}