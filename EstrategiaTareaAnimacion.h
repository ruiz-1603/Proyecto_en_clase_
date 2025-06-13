#ifndef ESTRATEGIATAREAANIMACION_H
#define ESTRATEGIATAREAANIMACION_H

#include "EstrategiaTarea.h"
#include "Artista.h"

class EstrategiaTareaAnimacion : public EstrategiaTarea {
private:
    string tipoAnimacion; // "2D", "3D", "Stop Motion"
    int complejidad;      // 1-5, donde 5 es más complejo

public:
    EstrategiaTareaAnimacion(string tipoAnimacion, int complejidad) 
        : tipoAnimacion(tipoAnimacion), complejidad(complejidad) {}

    bool validarResponsable(Personal* responsable) override {
        // Verifica si el responsable es un Artista
        Artista* artista = dynamic_cast<Artista*>(responsable);
        return artista != nullptr;
    }

    int calcularTiempoEstimado() override {
        // Base de tiempo en días según el tipo de animación
        int tiempoBase;
        if (tipoAnimacion == "2D") tiempoBase = 5;
        else if (tipoAnimacion == "3D") tiempoBase = 10;
        else if (tipoAnimacion == "Stop Motion") tiempoBase = 15;
        else tiempoBase = 7;

        // Multiplicar por la complejidad
        return tiempoBase * complejidad;
    }

    string obtenerRequisitos() override {
        stringstream ss;
        ss << "Tipo de Animación: " << tipoAnimacion << endl;
        ss << "Nivel de Complejidad: " << complejidad << "/5" << endl;
        ss << "Requisitos:" << endl;
        ss << "- Software de animación " << tipoAnimacion << endl;
        ss << "- Experiencia en animación " << tipoAnimacion << endl;
        if (tipoAnimacion == "3D") {
            ss << "- Conocimientos de modelado 3D" << endl;
        }
        return ss.str();
    }
    string getTipo() override {
        return "Estrate de Animacion";
    }
    string getComplejidad() const {
        return to_string(complejidad);
    }
    string getParam1() const override { return tipoAnimacion; }
    string getParam2() const override { return to_string(complejidad); }
};

#endif //ESTRATEGIATAREAANIMACION_H