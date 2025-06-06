#ifndef PERSONAL_H
#define PERSONAL_H
#include"Utilities.h"

class Personal {
protected:
    string id;
    string nombre;
    string email;
    string especialidad;
public:
    Personal(string& id, string& nombre, string& email);
    virtual ~Personal();
    string getId();
    string getNombre();
    string getEmail();
    virtual string getEspecialidad() = 0;


    void setId(string& id);
    void setNombre(string& nombre);
    void setEmail(string& email);
    void setEspecialidad(string& especialidad);
    virtual string toString() = 0;
};


#endif //PERSONAL_H
