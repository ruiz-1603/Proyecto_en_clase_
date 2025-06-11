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
    Lista<TareaProduccion *> tareas;

public:
    GestorRecursos();
    ~GestorRecursos();

    // métodos de película
    void agregarPelicula();
    void eliminarPelicula();
    string mostrarPeliculas();

    // Métodos de personal
    void agregarPersonal();
    void agregarProductor();
    void agregarArtista();
    void agregarIngenieroSonido();
    void eliminarPersonal();
    string mostrarPersonal() const;

    // getters de listas
    ListaPeliculas* getPeliculas();
    void setPeliculas(ListaPeliculas* peliculas);

    ListaPersonal *getPersonal();
    void setPersonal(ListaPersonal* personal);

    Lista<TareaProduccion*>& getTareas();
};

#endif //GESTORRECURSOS_H
