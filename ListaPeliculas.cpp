//
// Created by castr on 6/6/2025.
//

#include "ListaPeliculas.h"

ListaPeliculas::ListaPeliculas() {
    peliculas = new Lista<Pelicula>;
}

ListaPeliculas::~ListaPeliculas() {
    delete peliculas;
}

void ListaPeliculas::agregarPelicula(Pelicula* pelicula) {
    peliculas->agregar(pelicula);
}

void ListaPeliculas::eliminarPelicula(Pelicula* pelicula) {
    peliculas->eliminar(pelicula);
}

string ListaPeliculas::mostrarPeliculas() {
    return peliculas->mostrar();
}

void ListaPeliculas::setPeliculas(Lista<Pelicula> * listaPelis) {
    delete peliculas;
    peliculas = listaPelis;
}

Pelicula* ListaPeliculas::getPeliculaPorTitulo(string titulo) {
    Nodo<Pelicula>* actual = peliculas->getPrimero();

    while (actual != nullptr) {
        if (actual->getDato()->getTitulo() == titulo) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}
