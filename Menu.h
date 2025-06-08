//
// Created by castr on 6/6/2025.
//

#ifndef MENU_H
#define MENU_H
#include "GestorRecursos.h"
#include "Utilities.h"
#include "Productor.h"
#include "Artista.h"
#include "IngenieroDeSonido.h"

class Menu {
private:
  GestorRecursos* interfaz;

  // Funciones auxiliares para crear personal
  Personal* crearProductor();
  Personal* crearArtista();
  Personal* crearIngenieroSonido();
  void agregarPersonalAPelicula(Pelicula* pelicula);
  void eliminarPersonalDePelicula(Pelicula* pelicula);

public:
  Menu();
  ~Menu();

  void menuPrincipal();

  void seleccionarPelicula();
  void menuPelicula(Pelicula* pelicula);

  void menuCronograma(Pelicula* pelicula);
  void menuPersonal(Pelicula* pelicula);
};

#endif //MENU_H
