//
// Created by RuizM on 6/5/2025.
//

#include "Productor.h"

Productor::Productor(string id, string nombre, string email, int presupuesto) : Personal(id, nombre, email) {
  this->presupuesto = presupuesto;
}

int Productor::getPresupuesto() { return this->presupuesto; }

string Productor::getEspecialidad() { return "Productor"; }

string Productor::toString() {
    stringstream ss;
    ss << "Nombre: " << getNombre() << endl
       << "Especialidad: " << getEspecialidad() << endl
       << "ID: " << getId() << endl
       << "Email: " << getEmail() << endl
       << "Presupuesto: " << getPresupuesto() << endl;
    return ss.str();
}