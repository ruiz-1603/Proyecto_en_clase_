//
// Created by RuizM on 6/5/2025.
//

#include "Artista.h"
Artista::Artista(string id, string nombre, string email, string herramientasDibujo)
    :Personal(id, nombre, email) {
      this->herramientasDibujo = herramientasDibujo;

}

string Artista::getHerramientasDibujo() {
  return herramientasDibujo;
}

string getEspecialidad() {
  return "Artista";
}

string Artista::toString() {
  stringstream ss;
  ss << "Nombre del artista: " << getNombre()<<endl
     <<"Especialidad: " << getEspecialidad()<<endl
     <<"Id: " << getId()<<endl
     <<"Email: " << getEmail()<<endl
     <<"Herramientas de dibujo: " << getHerramientasDibujo()<<"\n\n";
    return ss.str();
}