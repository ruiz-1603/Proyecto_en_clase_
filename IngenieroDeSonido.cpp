//
// Created by RuizM on 6/5/2025.
//

#include "IngenieroDeSonido.h"
IngenieroDeSonido::IngenieroDeSonido(string id, string nombre, string email,int xp):
  Personal(id,nombre,email){
  aniosExperiencia = xp;
}

int IngenieroDeSonido::getAniosExperiencia() {
  return aniosExperiencia;
}

string IngenieroDeSonido::getEspecialidad() {
  return "IngenieroDeSonido";
}

string IngenieroDeSonido::toString() {
  stringstream ss;
  ss << "Nombre del artista: " << getNombre()<<endl
     <<"Especialidad: " << getEspecialidad()<<endl
     <<"Id: " << getId()<<endl
     <<"Email: " << getEmail()<<endl
     <<"Anios de experiencia: " << getAniosExperiencia()<<"\n\n";
  return ss.str();
}