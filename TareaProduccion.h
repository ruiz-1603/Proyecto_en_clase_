//
// Created by castr on 6/6/2025.
//

#ifndef TAREAPRODUCCION_H
#define TAREAPRODUCCION_H
#include "Utilities.h"
#include "Personal.h"

class TareaProduccion {
    private:
      string descricion;
      string estado; // "completa", "incompleta"
      Personal* responsable;

    public:
      TareaProduccion(string descricion, string estado, Personal* responsable);
      ~TareaProduccion() = default;

      // getters
      string getDescricion();
      string getEstado();
      Personal* getResponsable();

      // setters
      void setDescricion(string descricion);
      void setEstado(string estado);
      void setResponsable(Personal* responsable);
};



#endif //TAREAPRODUCCION_H
