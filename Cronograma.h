//
// Created by castr on 6/6/2025.
//

#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H

#include "Utilities.h"
#include "TareaProduccion.h"
#include <cmath>
#include <vector>
#include "ListaTareas.h"

class Cronograma {
    private:
        ListaTareas* tareas;
        bool esFechaValida(string fecha);

    public:
        Cronograma();
        ~Cronograma();

        void agregarTarea(TareaProduccion* tarea);
        void marcarTareaCompleta(int indice);
        string mostrarCronograma() const;
        double getProgreso() const;
        void setProgreso(double progreso);
        // Getters
        int getCantidadTareas() const { return tareas->obtenerTamaño(); }
        TareaProduccion* getTarea(int indice) const;
        ListaTareas* getTareas() const;
};

#endif //CRONOGRAMA_H
