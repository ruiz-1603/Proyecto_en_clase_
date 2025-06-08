//
// Created by RuizM on 6/5/2025.
//

#include "Pelicula.h"

Pelicula::Pelicula(string titulo, string genero) : titulo(titulo), genero(genero) {
  this->cronograma = new Cronograma();
  this->equipo = new Lista<Personal>();
}

Pelicula::~Pelicula() {
  delete cronograma;
  delete equipo;
}

// getters
string Pelicula::getTitulo() { return this->titulo; }
string Pelicula::getGenero() { return this->genero; }
Cronograma* Pelicula::getCronograma() { return this->cronograma; }
string Pelicula::getEstado() {
  if (cronograma != nullptr && cronograma->getProgreso() == 100.00) {
     return "completa";
  } else {
    return "incompleta";
  }
}

// setters
void Pelicula::setTitulo(string titulo) { this->titulo = titulo; }
void Pelicula::setGenero(string genero) { this->genero = genero; }
void Pelicula::setCronograma(Cronograma* cronograma) {
  this->cronograma = cronograma;
}

string Pelicula::toString() {
  stringstream ss;
  ss << "Titulo: " << titulo << endl;
  ss << "Genero: " << genero << endl;
  return ss.str();
}

string Pelicula::mostrarEquipo() {
  return equipo->mostrar();
}

// implementación de los métodos para manejar el equipo
bool Pelicula::agregarMiembro(Personal* miembro) {
  return equipo->agregar(miembro);
}

bool Pelicula::eliminarMiembro(Personal* miembro) {
  return equipo->eliminar(miembro);
}

Personal* Pelicula::getMiembroPorID(string id) {
  Nodo<Personal>* actual = equipo->getPrimero();
  while (actual != nullptr) {
    if (actual->getDato()->getId() == id) {
      return actual->getDato();
    }
    actual = actual->getSiguiente();
  }
  return nullptr;
}

Lista<Personal>* Pelicula::getEquipo() {
  return equipo;
}