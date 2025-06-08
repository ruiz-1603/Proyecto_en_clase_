//
// Created by RuizM on 6/5/2025.
//

#ifndef ARTISTA_H
#define ARTISTA_H
#include "Personal.h"

class Artista : public Personal {
private:
    string herramientasDibujo;

public:
    Artista(string& id, string& nombre, string& email, string& herramientasDibujo);
    ~Artista() override = default;

    string getHerramientasDibujo() const { return herramientasDibujo; }
    void setHerramientasDibujo(const string& herramientas) { herramientasDibujo = herramientas; }

    string getEspecialidad() const override { return "Artista"; }
    string toString() const override;
};

#endif //ARTISTA_H
