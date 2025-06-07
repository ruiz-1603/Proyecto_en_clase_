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
    // Verificar si ya existe una película con el mismo título
    if (getPeliculaPorTitulo(pelicula->getTitulo()) != nullptr) {
        return false;
    }
    peliculas->agregar(pelicula);
    return true;
}

bool ListaPeliculas::eliminarPelicula(Pelicula* pelicula) {
  return peliculas->eliminar(pelicula);
}

string ListaPeliculas::mostrarPeliculas() {
  return peliculas->mostrar();
}

Pelicula* ListaPeliculas::getPeliculaPorTitulo(string titulo) {
    Nodo<Pelicula>* actual = peliculas->getCabeza();

    while (actual != nullptr) {
        if (actual->dato->getTitulo() == titulo) {
            return actual->dato;
        }
        actual = actual->siguiente;
    } return nullptr;
}