#ifndef ESTRATEGIATAREASONIDO_H
#define ESTRATEGIATAREASONIDO_H

#include "EstrategiaTarea.h"
#include "IngenieroDeSonido.h"

class EstrategiaTareaSonido : public EstrategiaTarea {
private:
    string tipoSonido;    // "Música", "Efectos", "Voces", "Mezcla"
    int duracionMinutos;  // Duración del segmento a trabajar

public:
    EstrategiaTareaSonido(string tipoSonido, int duracionMinutos) 
        : tipoSonido(tipoSonido), duracionMinutos(duracionMinutos) {}

    bool validarResponsable(Personal* responsable) override {
        // Verifica si el responsable es un Ingeniero de Sonido
        IngenieroDeSonido* ingeniero = dynamic_cast<IngenieroDeSonido*>(responsable);
        return ingeniero != nullptr && ingeniero->getAniosExperiencia() >= 2;
    }

    int calcularTiempoEstimado() override {
        // Base de tiempo en días según el tipo de sonido
        int tiempoBase;
        if (tipoSonido == "Música") tiempoBase = 3;
        else if (tipoSonido == "Efectos") tiempoBase = 2;
        else if (tipoSonido == "Voces") tiempoBase = 1;
        else if (tipoSonido == "Mezcla") tiempoBase = 4;
        else tiempoBase = 2;

        // Calcular tiempo basado en la duración (1 día por cada 10 minutos)
        return tiempoBase + (duracionMinutos / 10);
    }

    string obtenerRequisitos() override {
        stringstream ss;
        ss << "Tipo de Sonido: " << tipoSonido << endl;
        ss << "Duracion: " << duracionMinutos << " minutos" << endl;
        ss << "Requisitos:" << endl;
        ss << "- Equipo de grabacion profesional" << endl;
        ss << "- Software de edicion de audio" << endl;
        if (tipoSonido == "Voces") {
            ss << "- Estudio de grabacion con aislamiento acustico" << endl;
        }
        if (tipoSonido == "Mezcla") {
            ss << "- Experiencia en masterizacion" << endl;
        }
        return ss.str();
    }
    string getTipo() override {
        return "Estrategia de Sonido";
    }
    string getDuracion() const {
        return to_string(duracionMinutos);
    }
    //--------------------------------
    string getParam1() const override { return tipoSonido; }
    string getParam2() const override { return to_string(duracionMinutos); }
};

#endif //ESTRATEGIATAREASONIDO_H 