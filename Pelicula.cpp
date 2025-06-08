//
// Created by RuizM on 6/5/2025.
//

#include "Pelicula.h"
#include <iomanip>

Pelicula::Pelicula(string& titulo) : titulo(titulo) {
  equipo = new Lista<Personal>();
  cronograma = new Cronograma();
}

Pelicula::~Pelicula() {
  delete equipo;
  delete cronograma;
}

// getters
string Pelicula::getEstado() {
  if (cronograma != nullptr && cronograma->getProgreso() == 100.00) {
     return "completa";
  } else {
    return "incompleta";
  }
}

// setters
void Pelicula::setTitulo(string titulo) { this->titulo = titulo; }
void Pelicula::setCronograma(Cronograma* cronograma) {
  this->cronograma = cronograma;
}

string Pelicula::toString() {
  stringstream ss;
  ss << "----------------------------------------" << endl;
  ss << "Titulo: " << titulo << endl;
  ss << "Estado: " << getEstado() << endl;
  if (cronograma != nullptr) {
    ss << "Progreso: " << fixed << setprecision(2) << cronograma->getProgreso() << "%" << endl;
  }
  ss << "Miembros del equipo: " << equipo->obtenerTamaño() << endl;
  ss << "----------------------------------------" << endl;
  return ss.str();
}

string Pelicula::mostrarEquipo() const {
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

