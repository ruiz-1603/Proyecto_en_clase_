//
// Created by RuizM on 6/5/2025.
//

#ifndef PRODUCTOR_H
#define PRODUCTOR_H
#include "Personal.h"

class Productor : public Personal {
private:
    float presupuesto;

public:
    Productor(string& id, string& nombre, string& email, float presupuesto);
    ~Productor() override = default;

    float getPresupuesto() const { return presupuesto; }
    void setPresupuesto(float nuevo_presupuesto) { presupuesto = nuevo_presupuesto; }

    string getEspecialidad() const override { return "Productor"; }
    string toString() const override;
};

#endif //PRODUCTOR_H
