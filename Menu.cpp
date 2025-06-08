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
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->agregarPelicula();
        break;
      case 2:
        system("cls");
        seleccionarPelicula();
        break;
      case 3:
        system("cls");
        cout << "Peliculas" << endl << endl;
        cout << interfaz->mostrarPeliculas();
        cout << "Presione ENTER para continuar";
        cin.ignore();
        cin.get();
        break;
      case 4:
        system("cls");
        interfaz->eliminarPelicula();
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
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        menuPersonal(pelicula);
        break;
      case 2:
        system("cls");
        menuCronograma(pelicula);
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

void Menu::menuPersonal(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "Menu Personal - Pelicula: " << pelicula->getTitulo() << endl << endl;
    cout << "1. Agregar miembro al equipo" << endl;
    cout << "2. Eliminar miembro del equipo" << endl;
    cout << "3. Mostrar personal" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        agregarPersonalAPelicula(pelicula);
        break;
      case 2:
        system("cls");
        eliminarPersonalDePelicula(pelicula);
        break;
      case 3:
        system("cls");
        cout << "Personal de la pelicula " << pelicula->getTitulo() << ":" << endl << endl;
        cout << pelicula->mostrarEquipo() << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
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

void Menu::agregarPersonalAPelicula(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "Agregar Personal a " << pelicula->getTitulo() << endl << endl;
    cout << "1. Productor" << endl;
    cout << "2. Artista" << endl;
    cout << "3. Ingeniero de Sonido" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    Personal* nuevoMiembro = nullptr;

    switch (opcion) {
      case 1:
        system("cls");
        nuevoMiembro = crearProductor();
        break;
      case 2:
        system("cls");
        nuevoMiembro = crearArtista();
        break;
      case 3:
        system("cls");
        nuevoMiembro = crearIngenieroSonido();
        break;
      case 0:
        return;
      default:
        system("cls");
        cout << "Opcion no valida. Intente de nuevo." << endl;
        break;
    }

    if (nuevoMiembro != nullptr) {
      if (pelicula->agregarMiembro(nuevoMiembro)) {
        cout << "Miembro agregado exitosamente!" << endl;
      } else {
        cout << "Error al agregar el miembro." << endl;
        delete nuevoMiembro;
      }
      cout << "Presione ENTER para continuar";
      cin.get();
    }
  }
}

void Menu::eliminarPersonalDePelicula(Pelicula* pelicula) {
  system("cls");
  string id;

  cout << "Personal de " << pelicula->getTitulo() << endl << endl;
  cout << pelicula->mostrarEquipo() << endl;
  cout << "Ingrese el ID del personal que desea eliminar: ";
  cin >> id;
  cin.ignore();

  Personal* miembro = pelicula->getMiembroPorID(id);
  if (miembro) {
    if (pelicula->eliminarMiembro(miembro)) {
      cout << "Personal eliminado correctamente" << endl;
    } else {
      cout << "Error al eliminar el personal" << endl;
    }
  } else {
    cout << "Personal no encontrado" << endl;
  }
  cout << "Presione ENTER para continuar";
  cin.get();
}

Personal* Menu::crearProductor() {
  float presupuesto;
  string id, nombre, email;

  cout << "Ingrese el ID del productor: ";
  cin >> id;
  cin.ignore();
  cout << "Ingrese el nombre del productor: ";
  getline(cin, nombre);
  cout << "Ingrese el email del productor: ";
  getline(cin, email);
  cout << "Ingrese el presupuesto del productor: ";
  cin >> presupuesto;
  cin.ignore();

  return new Productor(id, nombre, email, presupuesto);
}

Personal* Menu::crearArtista() {
  string id, nombre, email, herramientasDibujo;

  cout << "Ingrese el ID del artista: ";
  cin >> id;
  cin.ignore();
  cout << "Ingrese el nombre del artista: ";
  getline(cin, nombre);
  cout << "Ingrese el email del artista: ";
  getline(cin, email);
  cout << "Ingrese las herramientas de dibujo del artista: ";
  getline(cin, herramientasDibujo);

  return new Artista(id, nombre, email, herramientasDibujo);
}

Personal* Menu::crearIngenieroSonido() {
  string id, nombre, email;
  int aniosExp;

  cout << "Ingrese el ID del ingeniero de sonido: ";
  cin >> id;
  cin.ignore();
  cout << "Ingrese el nombre del ingeniero de sonido: ";
  getline(cin, nombre);
  cout << "Ingrese el email del ingeniero de sonido: ";
  getline(cin, email);
  cout << "Ingrese los anios de experiencia del ingeniero de sonido: ";
  cin >> aniosExp;

  return new IngenieroDeSonido(id, nombre, email, aniosExp);
}

void Menu::menuCronograma(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "Menu Cronograma" << endl << endl;
    cout << "1. Asignar tarea" << endl;
    cout << "2. Marcar tarea" << endl;
    cout << "3. Mostrar cronograma" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        // strategy
        break;
      case 2:
        system("cls");
        // marcar tarea
        break;
      case 3:
        system("cls");
        pelicula->getCronograma()->mostrarCronograma();
        break;
      default:
        system("cls");
        cout << "Opcion invalida. Intente de nuevo." << endl;
        break;
    }
  }
}