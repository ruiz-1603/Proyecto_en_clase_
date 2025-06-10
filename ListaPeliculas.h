//
// Created by castr on 6/6/2025.
//

#ifndef LISTAPELICULAS_H
#define LISTAPELICULAS_H
#include "Utilities.h"
#include "Lista.h"
#include "Pelicula.h"

class ListaPeliculas {
private:
    Lista<Pelicula>* peliculas;

public:
    ListaPeliculas();
    ~ListaPeliculas();

    void agregarPelicula(Pelicula*);
    void eliminarPelicula(Pelicula*);
    string mostrarPeliculas();

    Lista<Pelicula>* getPeliculas() { return peliculas; }
    void setPeliculas(Lista<Pelicula>*);
    Pelicula* getPeliculaPorTitulo(string titulo);
};

#endif //LISTAPELICULAS_H
