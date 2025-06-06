//
// Created by castr on 6/6/2025.
//

#ifndef TAREAPRODUCCION_H
#define TAREAPRODUCCION_H
#include "Utilities.h"
#include "Personal.h"

class TareaProduccion {
    private:
      string descripcion;
      string estado; // "completa", "incompleta"
      Personal* responsable;

    public:
      TareaProduccion(string descripcion, string estado, Personal* responsable);
      ~TareaProduccion() = default;

      // getters
      string getDescripcion();
      string getEstado();
      Personal* getResponsable();

      // setters
      void setDescripcion(string descripcion);
      void setEstado(string estado);
      void setResponsable(Personal* responsable);

      string mostrarTarea();

      bool validarEstado(string& estado);
};

#endif //TAREAPRODUCCION_H
