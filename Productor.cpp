//
// Created by RuizM on 6/5/2025.
//

#include "Productor.h"

Productor::Productor(string& id, string& nombre, string& email, float presupuesto)
    : Personal(id, nombre, email), presupuesto(presupuesto) {}

string Productor::toString() const {
    stringstream ss;
    ss << "ID: " << id << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "Email: " << email << endl;
    ss << "Presupuesto: " << presupuesto << endl;
    return ss.str();
}