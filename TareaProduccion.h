//
// Created by castr on 6/6/2025.
//

#ifndef TAREAPRODUCCION_H
#define TAREAPRODUCCION_H
#include "Utilities.h"
#include "Personal.h"
#include "EstrategiaTarea.h"

class TareaProduccion {
    private:
        string descripcion;
        string estado; // "completa", "incompleta"
        Personal* responsable;
        EstrategiaTarea* estrategia;
        int tiempoEstimado;

    public:
        TareaProduccion(string descripcion, Personal* responsable, EstrategiaTarea* estrategia);
        ~TareaProduccion();

        // getters
        string getDescripcion() const;
        string getEstado() const;
        Personal* getResponsable() const;
        int getTiempoEstimado() const;
        string getRequisitos() const;

        // setters
        void setDescripcion(string descripcion);
        void setEstado(string estado);
        bool setResponsable(Personal* responsable);
        void setEstrategia(EstrategiaTarea* nuevaEstrategia);

        string mostrarTarea() const;
        bool validarEstado(string& estado) const;
};

#endif //TAREAPRODUCCION_H
