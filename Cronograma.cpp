//
// Created by castr on 6/6/2025.
//

#include "Cronograma.h"
#include <regex>

Cronograma::Cronograma() {
    tareas = new Lista<TareaProduccion>();
}

Cronograma::~Cronograma() {
    delete tareas;
}

void Cronograma::agregarTarea(TareaProduccion* tarea) {
    tareas->agregar(tarea);
}

void Cronograma::marcarTareaCompleta(int indice) {
    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    int i = 0;
    
    while (actual != nullptr && i < indice) {
        actual = actual->getSiguiente();
        i++;
    }
    
    if (actual == nullptr) {
        throw "Índice de tarea inválido";
    }
    
    actual->getDato()->setEstado("completa");
}

string Cronograma::mostrarCronograma() const {
    stringstream ss;
    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    int i = 0;

    if (actual == nullptr) {
        ss << "No hay tareas en el cronograma." << endl;
        return ss.str();
    }

    while (actual != nullptr) {
        ss << "[" << i << "] " << actual->getDato()->mostrarTarea() << endl;
        actual = actual->getSiguiente();
        i++;
    }

    return ss.str();
}

double Cronograma::getProgreso() const {
    if (tareas->estaVacia()) return 0.0;
    
    int completadas = 0;
    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    while (actual != nullptr) {
        if (actual->getDato()->getEstado() == "completa") {
            completadas++;
        }
        actual = actual->getSiguiente();
    }
    
    return (double)completadas / tareas->obtenerTamaño() * 100.0;
}

TareaProduccion* Cronograma::getTarea(int indice) const {
    Nodo<TareaProduccion>* actual = tareas->getPrimero();
    int i = 0;
    
    while (actual != nullptr && i < indice) {
        actual = actual->getSiguiente();
        i++;
    }
    
    if (actual == nullptr) {
        return nullptr;
    }
    return actual->getDato();
}

bool Cronograma::esFechaValida(string fecha) {
    regex fechaValida("\\d{4}/\\d{2}/\\d{2}$");
    if (!regex_match(fecha, fechaValida)) return false;

    // Aquí podrías agregar más validaciones si lo deseas
    return true;
}