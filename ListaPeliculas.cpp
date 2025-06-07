//
// Created by castr on 6/6/2025.
//

#include "ListaPeliculas.h"

ListaPeliculas::ListaPeliculas() {
  this->peliculas = new Lista<Pelicula>();
}

ListaPeliculas::~ListaPeliculas() {
  delete this->peliculas;
}

bool ListaPeliculas::agregarPelicula(Pelicula* pelicula) {
  peliculas->agregar(pelicula);
}

bool ListaPeliculas::eliminarPelicula(Pelicula* pelicula) {
  peliculas->eliminar(pelicula);
}

string ListaPeliculas::mostrarPeliculas() {
  return peliculas->mostrar();
}