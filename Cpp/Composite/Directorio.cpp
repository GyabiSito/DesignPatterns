#include "Directorio.h"


Directorio::Directorio(int id, ICollection* elementos) : IElemento(id), hijos(elementos) {}


int Directorio::calcularTamanio() const{
    int total=0;
    IIterator* it = hijos->getIterator();
    while (it->hasCurrent()) {
        IElemento* elem = dynamic_cast<IElemento*>(it->getCurrent());
        if (elem) {
            total += elem->calcularTamanio();
        }
        it->next();
    }
    delete it;
    return total;
}

void Directorio::agregarElemento(IElemento* e) {
    hijos->add(e);
}

int Directorio::getId() const {
    return id;
}


Directorio::~Directorio() {
    delete hijos;
}

