//
// Created by RuizM on 6/5/2025.
//

#ifndef INGENIERODESONIDO_H
#define INGENIERODESONIDO_H
#include "Personal.h"

class IngenieroDeSonido : public Personal {
private:
    int aniosExperiencia;

public:
    IngenieroDeSonido(string& id, string& nombre, string& email, int aniosExperiencia);
    ~IngenieroDeSonido() override = default;

    int getAniosExperiencia() const { return aniosExperiencia; }
    void setAniosExperiencia(int anios) { aniosExperiencia = anios; }

    string getEspecialidad() const override { return "Ingeniero de Sonido"; }
    string toString() const override;
};

#endif //INGENIERODESONIDO_H
