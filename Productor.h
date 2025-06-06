//
// Created by RuizM on 6/5/2025.
//

#ifndef PRODUCTOR_H
#define PRODUCTOR_H
#include"Personal.h"

class Productor : public Personal {
private:
    float presupuesto;

public:
    Productor(string id, string nombre, string email, int presupuesto);

    int getPresupuesto();
    string getEspecialidad() override;
    string toString() override;
};


#endif //PRODUCTOR_H
