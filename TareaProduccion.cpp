//
// Created by castr on 6/6/2025.
//

#include "TareaProduccion.h"

TareaProduccion::TareaProduccion(string descripcion, string estado, Personal* responsable) {
  this->descripcion = descripcion;
  this->estado = estado;
  this->responsable = responsable;
}

// getters
string TareaProduccion::getDescripcion() { return this->descripcion; }
string TareaProduccion::getEstado() { return this->estado; }
Personal* TareaProduccion::getResponsable() { return this->responsable; }

// setters
void TareaProduccion::setDescripcion(string descricion) { this->descripcion = descricion; }
void TareaProduccion::setEstado(string estado) { this->estado = estado; }
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