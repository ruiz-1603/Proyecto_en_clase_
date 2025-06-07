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

    bool agregarPelicula(Pelicula*);
    bool eliminarPelicula(Pelicula*);
    string mostrarPeliculas();
};

#endif //LISTAPELICULAS_H
