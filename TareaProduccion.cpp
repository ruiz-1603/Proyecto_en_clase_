//
// Created by castr on 6/6/2025.
//

#include "TareaProduccion.h"

TareaProduccion::TareaProduccion(string descricion, string estado, Personal* responsable) {
  this->descricion = descricion;
  this->estado = estado;
  this->responsable = responsable;
}

// getters
string TareaProduccion::getDescricion() { return this->descricion; }
string TareaProduccion::getEstado() { return this->estado; }
Personal* TareaProduccion::getResponsable() { return this->responsable; }

// setters
void TareaProduccion::setDescricion(string descricion) { this->descricion = descricion; }
void TareaProduccion::setEstado(string estado) { this->estado = estado; }
void TareaProduccion::setResponsable(Personal* responsable) {this->responsable = responsable; }