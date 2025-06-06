//
// Created by RuizM on 6/5/2025.
//

#include "Pelicula.h"

Pelicula::Pelicula(string titulo, string genero, string estado) {
  this->titulo = titulo;
  this->genero = genero;
  this->estado = estado;
}

// getters
string Pelicula::getTitulo() { return this->titulo; }
string Pelicula::getGenero() { return this->genero; }
string Pelicula::getEstado() { return this->estado; }

// setters
void Pelicula::setTitulo(string titulo) { this->titulo = titulo; }
void Pelicula::setGenero(string genero) { this->genero = genero; }
void Pelicula::setEstado(string estado) { this->estado = estado; }