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
#include "EstrategiaTareaAnimacion.h"
#include "EstrategiaTareaSonido.h"
#include <iomanip>

class Menu {
private:
  GestorRecursos* interfaz;

  // Métodos auxiliares
  void seleccionarPelicula();
  void menuPelicula(Pelicula* pelicula);
  void menuPersonal(Pelicula* pelicula);
  void menuCronograma(Pelicula* pelicula);
  void agregarPersonalAPelicula(Pelicula* pelicula);
  void eliminarPersonalDePelicula(Pelicula* pelicula);
  void asignarTareaAPelicula(Pelicula* pelicula);
  void marcarTareaCompleta(Pelicula* pelicula);
  Personal* crearProductor();
  Personal* crearArtista();
  Personal* crearIngenieroSonido();

public:
  Menu();
  ~Menu();

  void menuPrincipal();
};

#endif //MENU_H
