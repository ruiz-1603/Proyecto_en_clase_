//
// Created by castr on 6/6/2025.
//

#include "ListaPersonal.h"

ListaPersonal::ListaPersonal() {
  personal = new Lista<Personal>;
}

ListaPersonal::~ListaPersonal() {
  delete this->personal;
}

void ListaPersonal::agregarPersonal(Personal* per) {
  personal->agregar(per);
}

void ListaPersonal::eliminarPersonal(Personal* per) {
  personal->eliminar(per);
}

string ListaPersonal::mostrarPersonal() {
  return personal->mostrar();
}

Personal* ListaPersonal::getPersonalPorID(string id) {
  Nodo<Personal>* actual = personal->getCabeza();

    while (actual != nullptr) {
        if (actual->dato->getId() == id) {
            return actual->dato;
        }
        actual = actual->siguiente;
    } return nullptr;
}