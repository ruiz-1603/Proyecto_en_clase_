//
// Created by castr on 6/6/2025.
//

#ifndef NODO_H
#define NODO_H

template<typename T>
class Nodo {
public:
    T* dato;
    Nodo<T>* siguiente;

    Nodo(T* d) : dato(d), siguiente(nullptr) {}
};

#endif //NODO_H
