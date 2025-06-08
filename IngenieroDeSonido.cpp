//
// Created by RuizM on 6/5/2025.
//

#include "IngenieroDeSonido.h"

IngenieroDeSonido::IngenieroDeSonido(string& id, string& nombre, string& email, int aniosExperiencia)
    : Personal(id, nombre, email), aniosExperiencia(aniosExperiencia) {}

string IngenieroDeSonido::toString() const {
    stringstream ss;
    ss << "ID: " << id << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "Email: " << email << endl;
    ss << "Años de experiencia: " << aniosExperiencia << endl;
    return ss.str();
}