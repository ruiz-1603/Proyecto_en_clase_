//
// Created by RuizM on 6/5/2025.
//

#ifndef PRODUCTOR_H
#define PRODUCTOR_H
#include"Personal.h"

class Productor : public Personal {

public:
    Productor(string id, string nombre, string email, int numeroProyectos);

    int getNumeroProyectos();
    string getEspecialidad() override;
    string toString() override;
};


#endif //PRODUCTOR_H
