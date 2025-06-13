//
// Created by bryan on 12/06/2025.
//

#ifndef LISTATAREAS_H
#define LISTATAREAS_H

#include "Lista.h"
#include "TareaProduccion.h"

class ListaTareas {
private:
    Lista<TareaProduccion>* tareas;

public:
    ListaTareas();
    ~ListaTareas();

    bool agregarTarea(TareaProduccion* tarea);
    void eliminarTarea(TareaProduccion* tarea);
    string mostrarTareas();

    void setTareas(Lista<TareaProduccion>* nuevasTareas);
    TareaProduccion* getTareaPorDescripcion(string descripcion);
    Lista<TareaProduccion>* getTareas();

    Nodo<TareaProduccion>* getPrimeroNodo();
    int obtenerTamaño();
    bool estaVacia();
};



#endif //LISTATAREAS_H
