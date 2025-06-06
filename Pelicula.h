//
// Created by RuizM on 6/5/2025.
//

#ifndef PELICULA_H
#define PELICULA_H
#include "Personal.h"
#include "TareaProduccion.h"
#include "Lista.h"

class Pelicula {
    private:
      string titulo;
      string genero;
      string estado; // "incompleta", "completada"

      Lista<Personal*> miembros;
      Lista<TareaProduccion*> tareas;

    public:
      Pelicula(string titulo, string genero, string estado);
      ~Pelicula() = default;

      // getters
      string getTitulo();
      string getGenero();
      string getEstado();

      // setters
      void setTitulo(string titulo);
      void setGenero(string genero);
      void setEstado(string estado);
};

#endif //PELICULA_H
