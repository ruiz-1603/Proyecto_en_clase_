//
// Created by castr on 6/6/2025.
//

#include "Cronograma.h"

Cronograma::Cronograma() {}

void Cronograma::agregarTarea(string fecha, TareaProduccion* tarea) {
    if (!esFechaValida(fecha)) {
        cout << "Fecha invalida" << endl;
        return;
    }
    cronograma[fecha] = tarea;
}

string Cronograma::mostrarCronograma() {
    if (cronograma.empty()) {
        return "Cronograma vacio";
    }

    string crono;
    for (const auto& par : cronograma) {
        crono += par.first + " : " + par.second->mostrarTarea() + "\n";
    } return crono;
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