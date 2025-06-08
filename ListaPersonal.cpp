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

bool ListaPersonal::agregarPersonal(Personal* per) {
  return personal->agregar(per);
}

void ListaPersonal::eliminarPersonal(Personal* per) {
  personal->eliminar(per);
}

string ListaPersonal::mostrarPersonal() {
  return personal->mostrar();
}

Personal* ListaPersonal::getPersonalPorID(string id) {
  Nodo<Personal>* actual = personal->getPrimero();

    while (actual != nullptr) {
        if (actual->getDato()->getId() == id) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    } return nullptr;
}