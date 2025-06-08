//
// Created by RuizM on 6/5/2025.
//

#include "Artista.h"

Artista::Artista(string& id, string& nombre, string& email, string& herramientasDibujo)
    : Personal(id, nombre, email), herramientasDibujo(herramientasDibujo) {}

string Artista::toString() const {
    stringstream ss;
    ss << "ID: " << id << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "Email: " << email << endl;
    ss << "Herramientas: " << herramientasDibujo << endl;
    return ss.str();
}