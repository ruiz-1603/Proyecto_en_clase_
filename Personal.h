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
    virtual ~Personal() = 0;  // Destructor virtual puro

    // Getters
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    string getEmail() const { return email; }
    virtual string getEspecialidad() const = 0;

    // Setters
    void setId(string& id) { this->id = id; }
    void setNombre(string& nombre) { this->nombre = nombre; }
    void setEmail(string& email) { this->email = email; }
    void setEspecialidad(string& especialidad) { this->especialidad = especialidad; }

    // Método virtual puro
    virtual string toString() const = 0;
};

inline Personal::~Personal() = default;

#endif //PERSONAL_H
