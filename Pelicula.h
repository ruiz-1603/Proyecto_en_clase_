//
// Created by RuizM on 6/5/2025.
//

#ifndef PELICULA_H
#define PELICULA_H
#include "Utilities.h"
#include "Lista.h"
#include "Personal.h"
#include "Cronograma.h"

class Pelicula {
    private:
      string titulo;
      Lista<Personal>* equipo;
      Cronograma* cronograma;

    public:
      Pelicula(string& titulo);
      ~Pelicula();

      // getters
      string getTitulo() const { return titulo; }
      Cronograma* getCronograma() const { return cronograma; }
      string getEstado();

      // setters
      void setTitulo(string titulo);
      void setCronograma(Cronograma* cronograma);

      string toString();
      string mostrarEquipo() const;
      
      // métodos para manejar el equipo
      bool agregarMiembro(Personal* miembro);
      bool eliminarMiembro(Personal* miembro);
      Personal* getMiembroPorID(string id);
      Lista<Personal>* getEquipo() const { return equipo; }
};

#endif //PELICULA_H