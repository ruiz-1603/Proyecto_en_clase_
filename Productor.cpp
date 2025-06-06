//
// Created by RuizM on 6/5/2025.
//

#include "Productor.h"

Productor::Productor(string id, string nombre, string email, int numeroProyectos)
    : Personal(id, nombre, email){

    }

int Productor::getNumeroProyectos() {
    return numeroProyectos;
}

string Productor::getEspecialidad() {
    return "Productor";
}

string Productor::toString() {
    stringstream ss;
    ss << "Nombre: " << getNombre() << endl
       << "Especialidad: " << getEspecialidad() << endl
       << "ID: " << getId() << endl
       << "Email: " << getEmail() << endl
       << "Número de proyectos: " << numeroProyectos << "\n\n";
    return ss.str();
}