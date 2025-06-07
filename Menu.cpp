//
// Created by castr on 6/6/2025.
//

#include "Menu.h"

Menu::Menu() {
  this->interfaz = new GestorRecursos();
}
Menu::~Menu() {
  delete interfaz;
}

void Menu::menuPrincipal() {
  int opcion = -1;

  while (opcion != 0) {
    cout << "=== GESTOR DE PRODUCCION PIXAR ===" << endl << endl;
    cout << "1. Agregar Pelicula" << endl;
    cout << "2. Seleccionar Pelicula" << endl;
    cout << "3. Ver Peliculas" << endl;
    cout << "4. Eliminar Pelicula" << endl;
    cout << "0. Salir" << endl << endl;
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->agregarPelicula();
        break;
      case 2:
        system("cls");
        interfaz->seleccionarPelicula();
        break;
      case 3:
        system("cls");
        cout << "Peliculas" << endl << endl;
        interfaz->mostrarPeliculas();
        cout << "Presione ENTER para continuar";
        cin.ignore();
        cin.get();
        break;
      case 4:
        system("cls");
        // eliminar peli
        break;
      default:
        system("cls");
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cin.ignore();
        cin.get();
        break;
    }
  }
}

void Menu::seleccionarPelicula() {
  string titulo;

  cout << "Seleccionar Pelicula" << endl << endl;
  cout << interfaz->mostrarPeliculas() << endl;
  cout << "Ingrese el titulo de la pelicula que desea seleccionar: ";
  getline(cin, titulo);

  // EXCEPTION AQUI: si devuelve nullptr la peli no se encontró
  Pelicula* pelicula = interfaz->getPeliculas()->getPeliculaPorTitulo(titulo);
  if (pelicula) {
    menuPelicula(pelicula);
  } else {
    throw "Pelicula no existe";
  }
}

void Menu::menuPelicula(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << pelicula->getTitulo() << endl << endl;
    cout << "1. Personal" << endl;
    cout << "2. Cronograma" << endl;
    cout << "0. Salir" << endl << endl;
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        menuPersonal();
        break;
      case 2:
        system("cls");
        menuCronograma();
        break;
      default:
        system("cls");
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cin.ignore();
        cin.get();
        break;
    }
  }
}

void Menu::menuPersonal() {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "Menu Personal" << endl << endl;
    cout << "1. Agregar miembro al equipo" << endl;
    cout << "2. Eliminar miembro del equipo" << endl;
    cout << "3. Mostrar personal" << endl;
    cout << "0. Salir" << endl << endl;
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->agregarPersonal();
        break;
      case 2:
        system("cls");
        interfaz->eliminarPersonal();
        break;
      case 3:
        system("cls");
        cout << interfaz->mostrarPersonal() << endl;
        break;
      default:
        system("cls");
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cin.ignore();
        cin.get();
        break;
    }
  }
}

void Menu::menuCronograma() {
  system("cls");
}