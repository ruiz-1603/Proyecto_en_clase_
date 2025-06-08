//
// Created by castr on 6/6/2025.
//

#ifndef NODO_H
#define NODO_H

template<typename T> class Lista;  // Forward declaration

template<typename T>
class Nodo {
private:
    T* dato;
    Nodo<T>* siguiente;

public:
    Nodo(T* d) : dato(d), siguiente(nullptr) {}
    
    T* getDato() const { return dato; }
    void setDato(T* d) { dato = d; }
    
    Nodo<T>* getSiguiente() const { return siguiente; }
    void setSiguiente(Nodo<T>* sig) { siguiente = sig; }
    
    friend class Lista<T>;
};

#endif //NODO_H
