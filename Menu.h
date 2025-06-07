//
// Created by castr on 6/6/2025.
//

#ifndef MENU_H
#define MENU_H
#include "GestorRecursos.h"
#include "Utilities.h"

class Menu {
private:
  GestorRecursos* interfaz;

public:
  Menu();
  ~Menu();

  void menuPrincipal();

  void seleccionarPelicula();
  void menuPelicula(Pelicula* pelicula);

  void menuCronograma();
  void menuPersonal();
};



#endif //MENU_H
