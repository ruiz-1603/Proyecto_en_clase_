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
#include "Productor.h"
#include "Artista.h"
#include "IngenieroDeSonido.h"

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
    void agregarProductor();
    void agregarArtista();
    void agregarIngenieroSonido();

    void eliminarPersonal();
    string mostrarPersonal();

    ListaPeliculas* getPeliculas();
    ListaPersonal* getPersonal();
};

#endif //GESTORRECURSOS_H
