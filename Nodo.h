//
// Created by castr on 6/6/2025.
//

#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T valor;
    Nodo* siguiente;

    Nodo(const T& valor) : valor(valor), siguiente(nullptr) {}
};



#endif //NODO_H
