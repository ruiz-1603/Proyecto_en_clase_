//
// Created by RuizM on 6/5/2025.
//

#ifndef PELICULA_H
#define PELICULA_H
#include "Personal.h"
#include "TareaProduccion.h"
#include "Lista.h"
#include "Cronograma.h"

class Pelicula {
    private:
      string titulo;
      string genero;
      Cronograma* cronograma;

      Lista<Personal>* equipo;

    public:
      Pelicula(string titulo, string genero);
      ~Pelicula();

      // getters
      string getTitulo();
      string getGenero();
      Cronograma* getCronograma();
      string getEstado();

      // setters
      void setTitulo(string titulo);
      void setGenero(string genero);
      void setCronograma(Cronograma* cronograma);

      string toString();
      string mostrarEquipo();
};

#endif //PELICULA_H