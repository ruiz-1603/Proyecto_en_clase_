//
// Created by castr on 6/6/2025.
//

#include "Cronograma.h"

Cronograma::Cronograma() {}

void Cronograma::agregarTarea(string fecha, TareaProduccion* tarea) {
    if (!esFechaValida(fecha)) {
        throw "Fecha invalida";
    }
    cronograma[fecha] = tarea;
}

string Cronograma::mostrarCronograma() {
    if (cronograma.empty()) {
        return "Cronograma vacio";
    }

    // recorrer cronograma
    string crono;
    for (const auto& par : cronograma) {
        crono += par.first + " : " + par.second->mostrarTarea() + "\n";
    }

    string progreso = to_string(getProgreso());
    crono += "Progreso: " + progreso.substr(0,5) + "%";
    return crono;
}

double Cronograma::getProgreso() {
    // contar las tareas completadas y totales
    int tareasCompletadas = 0;
    int tareasTotal = 0;
    for (const auto& par : cronograma) {
        tareasTotal++;
        if (par.second->getEstado() == "completa") tareasCompletadas++;
    }

    if (tareasTotal == 0) return 0.0;

    // agregar el porcentaje de cronograma completado
    // se usa static_cast<double> para convertir la division con decimales
    double progreso = static_cast<double>(tareasCompletadas) / tareasTotal * 100;
    return (round(progreso * 100) / 100.0); // retornar progreso con solo dos decimales
}

bool Cronograma::esFechaValida(string fecha) {
  // verificar si la fecha tiene el formato valido
  regex fechaValida("\\d{4}/\\d{2}/\\d{2}$");
  if (!regex_match(fecha, fechaValida)) return false;

  // obtener el anio, mes y dia
  int anio = stoi(fecha.substr(0,4));
  int mes = stoi(fecha.substr(5,2));
  int dia = stoi(fecha.substr(8,2));

  // comprobar si la fecha existe
  if (mes > 12 || mes < 1) return false;
  if (dia > 31 || dia < 1) return false;

  return true;
}