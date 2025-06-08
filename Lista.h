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
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
    }

    Nodo<T>* getPrimero() const { return cabeza; }

    bool agregar(T* elemento) {
        try {
            Nodo<T>* nuevo = new Nodo<T>(elemento);
            if (cabeza == nullptr) {
                cabeza = nuevo;
            } else {
                Nodo<T>* actual = cabeza;
                while (actual->getSiguiente() != nullptr) {
                    actual = actual->getSiguiente();
                }
                actual->setSiguiente(nuevo);
            }
            tamaño++;
            return true;
        } catch (...) {
            return false;
        }
    }

    string mostrar() {
        stringstream ss;
        Nodo<T>* actual = cabeza;
        int contador = 0;

        while (actual != nullptr) {
            ss << "[" << contador << "] " << actual->getDato()->toString() << "\n";
            actual = actual->getSiguiente();
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
        if (cabeza->getDato() == elemento) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
            tamaño--;
            return true;
        }

        // Buscar en el resto de la lista
        Nodo<T>* actual = cabeza;
        while (actual->getSiguiente() != nullptr) {
            if (actual->getSiguiente()->getDato() == elemento) {
                Nodo<T>* temp = actual->getSiguiente();
                actual->setSiguiente(temp->getSiguiente());
                delete temp;
                tamaño--;
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }

    int obtenerTamaño() const {
        return tamaño;
    }
};

#endif //LISTA_H
