//
// Created by castr on 6/6/2025.
//

#ifndef GESTORRECURSOS_H
#define GESTORRECURSOS_H
#include "Personal.h"
#include "Pelicula.h"
#include "Utilities.h"
#include "ListaPersonal.h"
#include "ListaPeliculas.h"

class GestorRecursos {
private:
    ListaPeliculas* peliculas;
    ListaPersonal* personal;

public:
    GestorRecursos();
    ~GestorRecursos();

    void agregarPelicula();
    void seleccionarPelicula();
    string mostrarPeliculas();
    void eliminarPelicula();

    void asignarTarea();
    void marcarTarea();
    void mostrarCronograma();

    void agregarPersonal();
    void eliminarPersonal();
    void mostrarPersonal();
};

#endif //GESTORRECURSOS_H
