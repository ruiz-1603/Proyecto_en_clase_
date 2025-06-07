//
// Created by castr on 6/6/2025.
//

#include "GestorRecursos.h"

GestorRecursos::GestorRecursos() {
    peliculas = new ListaPeliculas();
    personal = new ListaPersonal();
}

GestorRecursos::~GestorRecursos() {
    peliculas = new ListaPeliculas();
    personal = new ListaPersonal();
}

// metodos de pelicula
void GestorRecursos::agregarPelicula() {
  string titulo, genero;

  cout << "Ingrese el titulo de la pelicula: ";
  getline(cin, titulo);
  cout << "Ingrese el genero de la pelicula: ";
  getline(cin, genero);

  Pelicula* pelicula = new Pelicula(titulo, genero);
  peliculas->agregarPelicula(pelicula);
}

void GestorRecursos::seleccionarPelicula() {}

string GestorRecursos::mostrarPeliculas() {
  return peliculas->mostrarPeliculas();
}
void GestorRecursos::eliminarPelicula() {}

// metodos de cronograma
void GestorRecursos::asignarTarea() {}
void GestorRecursos::marcarTarea() {}
void GestorRecursos::mostrarCronograma() {}

// metodos de personal
void GestorRecursos::agregarPersonal() {}
void GestorRecursos::eliminarPersonal() {}
void GestorRecursos::mostrarPersonal() {}