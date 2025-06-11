#ifndef ESTRATEGIATAREA_H
#define ESTRATEGIATAREA_H

#include "Personal.h"
#include "Utilities.h"

class EstrategiaTarea {
public:
    virtual ~EstrategiaTarea() = default;
    
    // Método para validar si el responsable puede realizar esta tarea
    virtual bool validarResponsable(Personal* responsable) = 0;
    
    // Método para calcular el tiempo estimado de la tarea
    virtual int calcularTiempoEstimado() = 0;
    
    // Método para obtener los requisitos específicos de la tarea
    virtual string obtenerRequisitos() = 0;
    //Virtual para ToString de Personal
    virtual string getTipo() = 0;
};

#endif //ESTRATEGIATAREA_H 