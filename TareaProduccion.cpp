//
// Created by castr on 6/6/2025.
//

#include "TareaProduccion.h"

TareaProduccion::TareaProduccion(string descripcion, string estado, Personal* responsable) {
  this->descripcion = descripcion;
  this->responsable = responsable;

  if (validarEstado(estado)) {
    this->estado = estado;
  } else {
    throw "Estado invalido"; // poner exception
  }
}

// getters
string TareaProduccion::getDescripcion() { return this->descripcion; }
string TareaProduccion::getEstado() { return this->estado; }
Personal* TareaProduccion::getResponsable() { return this->responsable; }

// setters
void TareaProduccion::setDescripcion(string descricion) { this->descripcion = descricion; }

void TareaProduccion::setEstado(string estado) {
  if (validarEstado(estado)) {
    this->estado = estado;
  } else {
    throw "Estado invalido"; // poner exception
  }
}

void TareaProduccion::setResponsable(Personal* responsable) {this->responsable = responsable; }

string TareaProduccion::mostrarTarea() {
  stringstream ss;
  ss << "Tarea:" << endl;
  ss << this->descripcion << endl;
  ss << this->estado << endl;
  ss << "Responsable:" << endl;
  ss << this->responsable->toString() << endl;
  return ss.str();
}

bool TareaProduccion::validarEstado(string& estado) {
    // convertir estado a minusculas
    for (char& c : estado) {
      c = tolower(c);
    }

    if (estado == "completa" || estado == "incompleta") return true;
    return false;
}