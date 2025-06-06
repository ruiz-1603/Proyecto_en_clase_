#include "Personal.h"
#include "Personal.h"

Personal::Personal(string& id, string& nombre, string& email) {
    this->id = id;
    this->nombre = nombre;
    this->email = email;
    this->especialidad = especialidad;
}

Personal::~Personal() {

}

string Personal::getId() {
    return id;
}

string Personal::getNombre() {
    return nombre;
}

string Personal::getEmail() {
    return email;
}

void Personal::setId(string& id) {
    this->id = id;
}

void Personal::setNombre(string& nombre) {
    this->nombre = nombre;
}

void Personal::setEmail(string& email) {
    this->email = email;
}

void Personal::setEspecialidad(string& especialidad) {
    this->especialidad = especialidad;
}
