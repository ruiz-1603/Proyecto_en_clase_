//
// Created by castr on 6/6/2025.
//

#include "Cronograma.h"
#include <regex>

Cronograma::Cronograma() {
    tareas = new ListaTareas();
}

Cronograma::~Cronograma() {
    delete tareas;
}

void Cronograma::agregarTarea(TareaProduccion* tarea) {
    tareas->agregarTarea(tarea);
}

void Cronograma::marcarTareaCompleta(int indice) {
    Nodo<TareaProduccion>* actual = tareas->getPrimeroNodo();
    int i = 0;
    
    while (actual != nullptr && i < indice) {
        actual = actual->getSiguiente();
        i++;
    }
    
    if (actual == nullptr) {
        throw "Indice de tarea invalido";
    }
    
    actual->getDato()->setEstado("completa");
}

string Cronograma::mostrarCronograma() const {
    stringstream ss;
    Nodo<TareaProduccion>* actual = tareas->getPrimeroNodo();
    int i = 1;

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
    Nodo<TareaProduccion>* actual = tareas->getPrimeroNodo();
    while (actual != nullptr) {
        if (actual->getDato()->getEstado() == "completa") {
            completadas++;
        }
        actual = actual->getSiguiente();
    }
    
    return (double)completadas / tareas->obtenerTamaño() * 100.0;
}

void Cronograma::setProgreso(double progreso) {
    if (tareas->estaVacia()) return;

    // Validar rango del progreso (0-100)
    if (progreso < 0.0) progreso = 0.0;
    if (progreso > 100.0) progreso = 100.0;

    int totalTareas = tareas->obtenerTamaño();
    int tareasACompletar = (int)((progreso / 100.0) * totalTareas);

    // Si el progreso es muy alto, asegurar que se complete al menos una tarea
    if (progreso > 0.0 && tareasACompletar == 0) {
        tareasACompletar = 1;
    }

    int contador = 0;
    Nodo<TareaProduccion>* actual = tareas->getPrimeroNodo();

    // Marcar las primeras 'tareasACompletar' tareas como completas
    while (actual != nullptr && contador < tareasACompletar) {
        actual->getDato()->setEstado("completa");
        actual = actual->getSiguiente();
        contador++;
    }

    // Marcar el resto como incompletas
    while (actual != nullptr) {
        actual->getDato()->setEstado("incompleta");
        actual = actual->getSiguiente();
    }
}

TareaProduccion* Cronograma::getTarea(int indice) const {
    Nodo<TareaProduccion>* actual = tareas->getPrimeroNodo();
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