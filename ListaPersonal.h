//
// Created by castr on 6/6/2025.
//

#ifndef LISTAPERSONAL_H
#define LISTAPERSONAL_H
#include "Utilities.h"
#include "Lista.h"
#include "Personal.h"

class ListaPersonal {
private:
    Lista<Personal>* personal;

public:
    ListaPersonal();
    ~ListaPersonal();

    bool agregarPersonal(Personal*);
    void eliminarPersonal(Personal*);
    string mostrarPersonal();

    Personal* getPersonalPorID(string id);
};

#endif //LISTAPERSONAL_H
