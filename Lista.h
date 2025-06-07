//
// Created by RuizM on 6/5/2025.
//

#ifndef LISTA_H
#define LISTA_H
#include "Utilities.h"
#include "Nodo.h"

template<typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    int tamaño;

public:
    Lista() : cabeza(nullptr), tamaño(0) {}

    ~Lista() {
        while (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    Nodo<T>* getCabeza() const { return cabeza; }

    void agregar(T* elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamaño++;
    }

    string mostrar() {
        stringstream ss;
        Nodo<T>* actual = cabeza;
        int contador = 0;

        while (actual != nullptr) {
            ss << "[" << contador << "] " << actual->dato->toString() << "\n";
            actual = actual->siguiente;
            contador++;
        }

        if (tamaño == 0) {
            ss << "Lista vacía\n";
        }

        return ss.str();
    }

    bool eliminar(T* elemento) {
        if (cabeza == nullptr) return false;

        // Si es el primer elemento
        if (cabeza->dato == elemento) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamaño--;
            return true;
        }

        // Buscar en el resto de la lista
        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->siguiente->dato == elemento) {
                Nodo<T>* temp = actual->siguiente;
                actual->siguiente = temp->siguiente;
                delete temp;
                tamaño--;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    int obtenerTamaño() const {
        return tamaño;
    }
};

#endif //LISTA_H
