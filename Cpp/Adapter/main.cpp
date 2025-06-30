#include "editor.h"
#include <iostream>
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "I3DFigura.h"
#include "Esfera.h"
#include "Piramide.h"
#include "Paralelepipedo.h"

using namespace std;
int main() {
    cout << "Editor de Figuras" << endl;
    Editor editor;
    
    // Crear algunas figuras
    IFigura *circulo = new Circulo(5);
    circulo->setNombre("Mi Circulo");
    circulo->setTipo("Circulo");

    IFigura *rectangulo = new Rectangulo(4, 6);
    rectangulo->setNombre("Mi Rectangulo");
    rectangulo->setTipo("Rectangulo");

    IFigura *triangulo = new Triangulo(3, 4);
    triangulo->setNombre("Mi Triangulo");
    triangulo->setTipo("Triangulo");

    // Agregar figuras al editor
    editor.agregarFigura(circulo);
    editor.agregarFigura(rectangulo);
    editor.agregarFigura(triangulo);

    // Imprimir todas las figuras
    cout << "Figuras en el editor:" << endl;
    editor.imprimirFiguras();

    // Dibujar y mover las figuras
    cout << "\nDibujando figuras:" << endl;
    editor.dibujar();
    cout << "\n Moviendo Figuras:" << endl;
    editor.mover();


    editor.eliminarFigura(circulo);

    cout << "\nBuscando figura por nombre 'Mi Circulo':" << endl;
    IFigura *figuraEncontrada = editor.buscarFiguraPorNombre("Mi Circulo");
    if (figuraEncontrada) {
        figuraEncontrada->imprimir();
    } else {
        cout << "Figura no encontrada." << endl;
    }
    cout << "\nBuscando figura por tipo 'Rectangulo':" << endl;
    figuraEncontrada = editor.buscarFiguraPorTipo("Rectangulo");
    if (figuraEncontrada) {
        figuraEncontrada->imprimir();
    } else {
        cout << "Figura no encontrada." << endl;
    }
    // Imprimir figuras por tipo
    cout << "\nFiguras de tipo 'Circulo':" << endl;
    editor.imprimirFigurasPorTipo("Circulo");
    cout << "\nFiguras de tipo 'Rectangulo':" << endl;
    editor.imprimirFigurasPorTipo("Rectangulo");
    cout << "\nFiguras de tipo 'Triangulo':" << endl;
    editor.imprimirFigurasPorTipo("Triangulo");
    // Imprimir figuras por nombre
    cout << "\nFiguras con nombre 'Mi Circulo':" << endl;
    editor.imprimirFigurasPorNombre("Mi Circulo");
    cout << "\nFiguras con nombre 'Mi Rectangulo':" << endl;
    editor.imprimirFigurasPorNombre("Mi Rectangulo");
    cout << "\nFiguras con nombre 'Mi Triangulo':" << endl;
    editor.imprimirFigurasPorNombre("Mi Triangulo");
    // Limpiar el editor
    cout << "\nLimpiando el editor..." << endl;
    editor.eliminarFigura(rectangulo);
    // delete triangulo; Que el desctructor lo borra

    cout << "\n***************************Ahora los 3D.*******************************" << endl;
    // Crear algunas figuras 3D
    IFigura *esfera = new Esfera("Mi Esfera", "Esfera", "Plastico", 100.0, 5.0);
    IFigura *piramide = new Piramide("Mi Piramide", "Piramide", "Madera", 200.0, 10.0, 15.0);
    IFigura *paralelepipedo = new Paralelepipedo("Mi Paralelepipedo", "Paralelepipedo", "Metal", 300.0, 5.0, 10.0, 15.0);
    // Agregar figuras 3D al editor
    editor.agregarFigura(esfera);
    editor.agregarFigura(piramide);
    editor.agregarFigura(paralelepipedo);
    // Imprimir todas las figuras 3D

    cout << "\nFiguras 3D en el editor:" << endl;
    editor.imprimirFiguras();
    // Dibujar y mover las figuras 3D
    cout << "\nDibujando figuras 3D:" << endl;
    editor.dibujar();
    cout << "\nMoviendo figuras 3D:" << endl;
    editor.mover();
    // Buscar figura 3D por nombre
    cout << "\nBuscando figura 3D por nombre 'Mi Esfera':" << endl;
    figuraEncontrada = editor.buscarFiguraPorNombre("Mi Esfera");
    if (figuraEncontrada) {
        figuraEncontrada->imprimir();
    } else {
        cout << "Figura 3D no encontrada." << endl;
    }
    // Buscar figura 3D por tipo
    cout << "\nBuscando figura 3D por tipo 'Piramide':" << endl;
    figuraEncontrada = editor.buscarFiguraPorTipo("Piramide");
    if (figuraEncontrada) {
        figuraEncontrada->imprimir();
    } else {
        cout << "Figura 3D no encontrada." << endl;
    }
    // Imprimir figuras 3D por tipo
    cout << "\nFiguras 3D de tipo 'Esfera':" << endl;
    editor.imprimirFigurasPorTipo("Esfera");
    cout << "\nFiguras 3D de tipo 'Piramide':" << endl;
    editor.imprimirFigurasPorTipo("Piramide");
    cout << "\nFiguras 3D de tipo 'Paralelepipedo':" << endl;
    editor.imprimirFigurasPorTipo("Paralelepipedo");
    // Imprimir figuras 3D por nombre
    cout << "\nFiguras 3D con nombre 'Mi Esfera':" << endl;
    editor.imprimirFigurasPorNombre("Mi Esfera");

    cout << "\nFiguras 3D con nombre 'Mi Piramide':" << endl;
    editor.imprimirFigurasPorNombre("Mi Piramide");
    cout << "\nFiguras 3D con nombre 'Mi Paralelepipedo':" << endl;
    editor.imprimirFigurasPorNombre("Mi Paralelepipedo");
    //Ahora borrar esfera y buscarla
    cout << "\nBorrando figura 3D 'Mi Esfera'..." << endl;
    editor.eliminarFigura(esfera);
    cout << "\nBuscando figura 3D por nombre 'Mi Esfera' después de borrarla:" << endl;
    figuraEncontrada = editor.buscarFiguraPorNombre("Mi Esfera");
    if (figuraEncontrada) {
        figuraEncontrada->imprimir();
    } else {
        cout << "Figura 3D no encontrada." << endl;
    }
    // Limpiar el editor
    cout << "\nLimpiando el editor..." << endl;

    // editor.eliminarFigura(paralelepipedo);
    cout << "\nEditor eliminado." << endl;
    // Liberar memoria de las figuras restantes
    //Se elimina primero el triangulo, luego la piramide y por ultimo el paralelepipedo
    //Preguntar por el paralelepipedo, si se quiere eliminar
    // El sistema liberara a piramide y triangulo
    cout << "Programa finalizado." << endl;
    

    return 0;
}