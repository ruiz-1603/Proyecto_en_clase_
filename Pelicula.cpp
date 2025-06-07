//
// Created by RuizM on 6/5/2025.
//

#include "Pelicula.h"

Pelicula::Pelicula(string titulo, string genero) : titulo(titulo), genero(genero) {
  this->cronograma = new Cronograma();
}

Pelicula::~Pelicula() {
  delete cronograma;
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