//
// Created by castr on 6/6/2025.
//

#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H

#include "Utilities.h"
#include "TareaProduccion.h"
#include <map>
#include <regex>

class Cronograma {
    private:
        map<string, TareaProduccion*> cronograma;

    public:
        Cronograma();
        ~Cronograma() = default;

        void agregarTarea(string fecha, TareaProduccion* tarea);
        string mostrarCronograma();

        bool esFechaValida(string fecha);
};

#endif //CRONOGRAMA_H
