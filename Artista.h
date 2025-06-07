//
// Created by RuizM on 6/5/2025.
//

#ifndef ARTISTA_H
#define ARTISTA_H
#include"Personal.h"

class Artista : public Personal {
private:
  string herramientasDibujo;
public:
  Artista(string id, string nombre, string email, string herramientasDibujo);
  string getHerramientasDibujo();
  string getEspecialidad() override;
  string toString() override;
};

#endif //ARTISTA_H
