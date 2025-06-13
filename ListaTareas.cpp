//
// Created by bryan on 12/06/2025.
//

#include "ListaTareas.h"
ListaTareas::ListaTareas() {
    tareas = new Lista<TareaProduccion>();
}

ListaTareas::~ListaTareas() {
    delete tareas;
}

bool ListaTareas::agregarTarea(TareaProduccion* tarea) {
    if (tarea == nullptr) return false;
    return tareas->agregar(tarea);
}

void ListaTareas::eliminarTarea(TareaProduccion* tarea) {
    if (tarea != nullptr) {
        tareas->eliminar(tarea);
    }
}

string ListaTareas::mostrarTareas() {
    if (tareas->estaVacia()) {
        return "No hay tareas registradas.\n";
    }

    stringstream ss;
    ss << "=== LISTA DE TAREAS ===" << endl;

    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    int contador = 1;

    while (actual != nullptr) {
        TareaProduccion* tarea = actual->getDato();
        if (tarea != nullptr) {
            ss << "Tarea " << contador << ":" << endl;
            ss << tarea->mostrarTarea();
            ss << "------------------------" << endl;
            contador++;
        }
        actual = actual->getSiguiente();
    }

    return ss.str();
}

void ListaTareas::setTareas(Lista<TareaProduccion>* nuevasTareas) {
    if (tareas != nullptr) {
        delete tareas;
    }
    tareas = nuevasTareas;
}

TareaProduccion* ListaTareas::getTareaPorDescripcion(string descripcion) {
    if (tareas == nullptr) return nullptr;

    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    while (actual != nullptr) {
        TareaProduccion* tarea = actual->getDato();
        if (tarea != nullptr && tarea->getDescripcion() == descripcion) {
            return tarea;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

Lista<TareaProduccion>* ListaTareas::getTareas() {
    return tareas;
}

Nodo<TareaProduccion>* ListaTareas::getPrimeroNodo() {
    return tareas->getPrimero();
}

int ListaTareas::obtenerTamaño() {
    return tareas->obtenerTamaño();
}

bool ListaTareas::estaVacia() {
    return tareas->estaVacia();
}