//
// Created by RuizM on 6/5/2025.
//

#ifndef LISTA_H
#define LISTA_H
#include "Utilities.h"
#include "Nodo.h"

template <class T>
class Lista {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    Lista() : cabeza(nullptr), cola(nullptr) {}

    ~Lista() {
        Nodo<T>* temp;
        while (cabeza) {
            temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void agregar(const T& valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cola) {
            cola->siguiente = nuevoNodo;
        } else {
            cabeza = nuevoNodo;
        }
        cola = nuevoNodo;
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }
    void eliminar(const T& valor) {
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual) {
            if (actual->valor == valor) {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                if (actual == cola) {
                    cola = anterior;
                }
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
    }
    Nodo<T>* buscarPorNombre(const std::string& nombre) const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            if (actual->valor.getNombre() == nombre) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
};

#endif //LISTA_H
