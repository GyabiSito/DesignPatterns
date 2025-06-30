#include "editor.h"

Editor::Editor() : IFigura("Editor", "Contenedor")
{
    figuras = new List();
    figurasPorNombre = new OrderedDictionary();
    figurasPorTipo = new OrderedDictionary();
}

/**
 *     void agregarFigura(IFigura *);
    void eliminarFigura(IFigura *);

    void dibujar() override;
    void mover() override;

    IFigura *buscarFiguraPorNombre(const string);
    IFigura *buscarFiguraPorTipo(const string);

    ICollection *getFiguras() const;
    IDictionary *getFigurasPorNombre() const;
    IDictionary *getFigurasPorTipo() const;

    void setFiguras(ICollection *);
    void setFigurasPorNombre(IDictionary *);
    void setFigurasPorTipo(IDictionary *);

    void imprimirFiguras();
    void imprimirFigurasPorTipo(const string);
    void imprimirFigurasPorNombre(const string);
 */
void Editor::eliminarFigura(IFigura *figura)
{
    if (figura == nullptr)
    {
        std::cerr << "Error: Figura no puede ser nula." << std::endl;
        return;
    }

    // Quitar de la colección general
    figuras->remove(figura);

    // Quitar de diccionario por nombre
    string nombre = figura->getNombre();
    StringKey *keyNombre = new StringKey(nombre);
    List *listaNombre = dynamic_cast<List *>(figurasPorNombre->find(keyNombre));
    if (listaNombre)
    {
        listaNombre->remove(figura);
        if (listaNombre->isEmpty())
        {
            figurasPorNombre->remove(keyNombre); // El diccionario debe liberar la lista
        }
    }
    delete keyNombre;

    // Quitar de diccionario por tipo
    string tipo = figura->getTipo();
    StringKey *keyTipo = new StringKey(tipo);
    List *listaTipo = dynamic_cast<List *>(figurasPorTipo->find(keyTipo));
    if (listaTipo)
    {
        listaTipo->remove(figura);
        if (listaTipo->isEmpty())
        {
            figurasPorTipo->remove(keyTipo); // El diccionario libera la lista
        }
    }
    delete keyTipo;

    // Finalmente, liberar figura
    delete figura;
}

void Editor::agregarFigura(IFigura *figura)
{
    if (figura == nullptr)
    {
        std::cerr << "Error: Figura no puede ser nula." << std::endl;
        return;
    }
    if (figura->getNombre().empty() || figura->getTipo().empty())
    {
        std::cerr << "[ADVERTENCIA] Figura con datos vacíos: nombre o tipo." << std::endl;
    }
    figuras->add(figura);
    string nombre = figura->getNombre();
    // Use a concrete subclass of OrderedKey, e.g., StringOrderedKey
    figurasPorNombre->add(new StringKey(nombre), figura);

    string tipo = figura->getTipo();
    figurasPorTipo->add(new StringKey(tipo), figura);
}

void Editor::dibujar()
{
    IIterator *it = figuras->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura != nullptr)
        {
            figura->dibujar();
        }
        else
        {
            std::cerr << "Error: Figura no es del tipo IFigura." << std::endl;
        }
        it->next();
    }
    delete it;
}
void Editor::mover()
{
    IIterator *it = figuras->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura)
        {
            figura->mover();
        }
        else
        {
            std::cerr << "Error: Figura no es del tipo IFigura." << std::endl;
        }
        it->next();
    }
}

IFigura* Editor::buscarFiguraPorNombre(const string nombre)
{
    if (figurasPorNombre == nullptr)
    {
        std::cerr << "Error: Diccionario de figuras por nombre no inicializado." << std::endl;
        return nullptr;
    }

    IKey* key = new StringKey(nombre);
    List* listaFiguras = dynamic_cast<List*>(figurasPorNombre->find(key));
    delete key;

    if (listaFiguras == nullptr)
    {
        std::cerr << "Figura con nombre '" << nombre << "' no encontrada." << std::endl;
        return nullptr;
    }

    IIterator* it = listaFiguras->getIterator();
    IFigura* figura = nullptr;
    while (it->hasCurrent())
    {
        figura = dynamic_cast<IFigura*>(it->getCurrent());
        if (figura != nullptr)
        {
            break;  // Encontré figura válida, la retorno
        }
        it->next();
    }
    delete it;

    if (figura == nullptr)
    {
        std::cerr << "No hay figuras válidas con nombre '" << nombre << "' en la lista." << std::endl;
    }
    return figura;
}


IFigura *Editor::buscarFiguraPorTipo(const string tipo)
{
    if (figurasPorTipo == nullptr)
    {
        std::cerr << "Error: Diccionario de figuras por tipo no inicializado." << std::endl;
        return nullptr;
    }

    IKey *key = new StringKey(tipo);
    IFigura *figura = dynamic_cast<IFigura *>(figurasPorTipo->find(key));
    delete key; // Liberar memoria del key

    if (figura == nullptr)
    {
        std::cerr << "Figura con tipo '" << tipo << "' no encontrada." << std::endl;
    }
    return figura;
}

ICollection *Editor::getFiguras() const
{
    return figuras;
}

IDictionary *Editor::getFigurasPorNombre() const
{
    return figurasPorNombre;
}

IDictionary *Editor::getFigurasPorTipo() const
{
    return figurasPorTipo;
}

void Editor::setFiguras(ICollection *newFiguras)
{
    if (figuras != nullptr)
    {
        delete figuras; // Liberar memoria de la colección anterior
    }
    figuras = newFiguras;
}

void Editor::setFigurasPorNombre(IDictionary *newFigurasPorNombre)
{
    if (figurasPorNombre != nullptr)
    {
        delete figurasPorNombre; // Liberar memoria del diccionario anterior
    }
    figurasPorNombre = newFigurasPorNombre;
}

void Editor::setFigurasPorTipo(IDictionary *newFigurasPorTipo)
{
    if (figurasPorTipo != nullptr)
    {
        delete figurasPorTipo; // Liberar memoria del diccionario anterior
    }
    figurasPorTipo = newFigurasPorTipo;
}

void Editor::imprimirFiguras()
{
    if (figuras->isEmpty())
    {
        cout << "No hay figuras en el editor." << endl;
        return;
    }

    IIterator *it = figuras->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura)
        {
            figura->imprimir();
        }
        else
        {
            cerr << "Error: Figura no es del tipo IFigura." << endl;
        }
        it->next();
    }
    delete it;
}

void Editor::imprimirFigurasPorTipo(const string tipo)
{
    IKey *key = new StringKey(tipo);
    List *lista = dynamic_cast<List *>(figurasPorTipo->find(key));
    delete key;

    if (!lista)
    {
        cout << "No hay figuras de tipo '" << tipo << "'." << endl;
        return;
    }

    IIterator *it = lista->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura)
        {
            figura->imprimir();
        }
        else
        {
            cerr << "Error: Figura no es del tipo IFigura." << endl;
        }
        it->next();
    }
    delete it;
}

void Editor::imprimirFigurasPorNombre(const string nombre)
{
    IKey *key = new StringKey(nombre);
    List *lista = dynamic_cast<List *>(figurasPorNombre->find(key));
    delete key;

    if (!lista)
    {
        cout << "No hay figuras con nombre '" << nombre << "'." << endl;
        return;
    }

    IIterator *it = lista->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura)
        {
            figura->imprimir();
        }
        else
        {
            cerr << "Error: Figura no es del tipo IFigura." << endl;
        }
        it->next();
    }
    delete it;
}

Editor::~Editor()
{
    // Liberar memoria de las figuras (dueñas)
    IIterator *it = figuras->getIterator();
    while (it->hasCurrent())
    {
        IFigura *figura = dynamic_cast<IFigura *>(it->getCurrent());
        if (figura)
        {
            delete figura;
        }
        else
        {
            cerr << "Error: Figura no es del tipo IFigura o es nula." << endl;
        }
        it->next();
    }
    delete it;
    delete figuras;

    if (figurasPorNombre != nullptr)
    {
        figurasPorNombre->clearDictionary();
        delete figurasPorNombre;
        figurasPorNombre = nullptr;
        cout << "Limpiando diccionario de figuras por nombre." << endl;
    }
    if (figurasPorTipo != nullptr)
    {
        figurasPorTipo->clearDictionary();
        delete figurasPorTipo;
        figurasPorTipo = nullptr;
        cout << "Limpiando diccionario de figuras por Tipo." << endl;
    }
}