//
// Created by castr on 6/6/2025.
//

#include "TareaProduccion.h"
#include "EstrategiaTareaAnimacion.h"
#include "EstrategiaTareaSonido.h"

TareaProduccion::TareaProduccion(string descripcion, Personal* responsable, EstrategiaTarea* estrategia)
    : descripcion(descripcion), estado("incompleta"), responsable(nullptr), estrategia(estrategia) {
    if (estrategia->validarResponsable(responsable)) {
        this->responsable = responsable;
        this->tiempoEstimado = estrategia->calcularTiempoEstimado();
    } else {
        throw "El responsable no es válido para esta tarea";
    }
}

TareaProduccion::~TareaProduccion() {
    delete estrategia;
}

// getters
string TareaProduccion::getDescripcion() const { return descripcion; }
string TareaProduccion::getEstado() const { return estado; }
Personal* TareaProduccion::getResponsable() const { return responsable; }
int TareaProduccion::getTiempoEstimado() const { return tiempoEstimado; }
string TareaProduccion::getRequisitos() const { return estrategia->obtenerRequisitos(); }

// setters
void TareaProduccion::setDescripcion(string descripcion) { this->descripcion = descripcion; }

void TareaProduccion::setEstado(string estado) {
    if (validarEstado(estado)) {
        this->estado = estado;
    } else {
        throw "Estado inválido";
    }
}

bool TareaProduccion::setResponsable(Personal* responsable) {
    if (estrategia->validarResponsable(responsable)) {
        this->responsable = responsable;
        return true;
    }
    return false;
}

void TareaProduccion::setEstrategia(EstrategiaTarea* nuevaEstrategia) {
    if (nuevaEstrategia->validarResponsable(this->responsable)) {
        delete this->estrategia;
        this->estrategia = nuevaEstrategia;
        this->tiempoEstimado = estrategia->calcularTiempoEstimado();
    } else {
        throw "El responsable actual no es válido para la nueva estrategia";
    }
}

string TareaProduccion::mostrarTarea() const {
    stringstream ss;
    ss << "Descripción: " << descripcion << endl;
    ss << "Estado: " << estado << endl;
    ss << "Tiempo Estimado: " << tiempoEstimado << " días" << endl;
    ss << "Responsable: " << responsable->toString() << endl;
    ss << "Requisitos:" << endl;
    ss << estrategia->obtenerRequisitos();
    return ss.str();
}

bool TareaProduccion::validarEstado(string& estado) const {
    return estado == "completa" || estado == "incompleta";
}

string TareaProduccion::getTipoEstrategia() const {
    if (dynamic_cast<EstrategiaTareaAnimacion*>(estrategia)) {
        return "EstrategiaAnimacion";
    } else if (dynamic_cast<EstrategiaTareaSonido*>(estrategia)) {
        return "EstrategiaSonido";
    }
    return "Productor (Sin Estrategia)";
}
EstrategiaTarea* TareaProduccion::getEstrategia() const {
    return estrategia;
}