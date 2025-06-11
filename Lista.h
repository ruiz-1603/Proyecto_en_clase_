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

    // Método privado para eliminar un dato
    void eliminarDato(T* dato) {
        if (dato != nullptr) {
            delete dato;
        }
    }

public:
    Lista() : cabeza(nullptr), tamaño(0) {}

    ~Lista() {
        while (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            eliminarDato(temp->getDato());
            delete temp;
        }
    }

    Nodo<T>* getPrimero() const { return cabeza; }
    int obtenerTamaño() const { return tamaño; }
    bool estaVacia() const { return cabeza == nullptr; }

    bool agregar(T* elemento) {
        if (elemento == nullptr) return false;
        
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

    string mostrar() const {
        stringstream ss;
        
        if (tamaño == 0) {
            ss << "No hay elementos en la lista." << endl;
            return ss.str();
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getDato() != nullptr) {
                ss << actual->getDato()->toString();
            }
            actual = actual->getSiguiente();
        }

        return ss.str();
    }
    string mostrar2() const {
        stringstream ss;

        if (tamaño == 0) {
            ss << "No hay elementos en la lista." << endl;
            return ss.str();
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            T* datoPtr = actual->getDato();  // datoPtr es T*
            if (datoPtr != nullptr && *datoPtr != nullptr) {
                ss << (*datoPtr)->mostrarTarea();
            }
            actual = actual->getSiguiente();
        }

        return ss.str();
    }
    bool eliminar(T* elemento) {
        if (cabeza == nullptr || elemento == nullptr) return false;

        // Si es el primer elemento
        if (cabeza->getDato() == elemento) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            eliminarDato(temp->getDato());
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
                eliminarDato(temp->getDato());
                delete temp;
                tamaño--;
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }
};

#endif //LISTA_H
