//
// Created by castr on 6/6/2025.
//

#include "GestorRecursos.h"

GestorRecursos::GestorRecursos() {
    peliculas = new ListaPeliculas();
    personal = new ListaPersonal();
}

GestorRecursos::~GestorRecursos() {
    delete peliculas;
    delete personal;
}

// metodos de pelicula
void GestorRecursos::agregarPelicula() {
  string titulo, genero;

  cout << "Agregar Pelicula" << endl << endl;
  cout << "Ingrese el titulo de la pelicula: ";
  getline(cin, titulo);
  cout << "Ingrese el genero de la pelicula: ";
  getline(cin, genero);

  Pelicula* pelicula = new Pelicula(titulo, genero);

    // EXCEPTION: si se repite el titulo de una pelicula retorna false
  if (peliculas->agregarPelicula(pelicula)) {
    cout << "Pelicula agregada!" << endl;
  } else {
    throw "La pelicula ya existe";
  }
}

string GestorRecursos::mostrarPeliculas() {
  return peliculas->mostrarPeliculas();
}
void GestorRecursos::eliminarPelicula() {
  system("cls");
  cout << "Peliculas" << endl << endl;
  mostrarPeliculas();

  string titulo;
  cout << "Ingrese el titulo de la pelicula que desea eliminar: ";
  getline(cin, titulo);

  // EXCEPTION: si getPeliculaPorTitulo no la encuentra manda nullptr
  Pelicula* pelicula = peliculas->getPeliculaPorTitulo(titulo);
  if (pelicula) {
    peliculas->eliminarPelicula(pelicula);
  } else {
    throw "La pelicula no existe";
  }
}

// metodos de cronograma
void GestorRecursos::asignarTarea() {}
void GestorRecursos::marcarTarea() {}
void GestorRecursos::mostrarCronograma() {}

// metodos de personal
void GestorRecursos::agregarPersonal() {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "Agregar Personal" << endl << endl;
    cout << "1. Productor" << endl;
    cout << "2. Artista" << endl;
    cout << "3. Ingeniero de Sonido" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
      case 1:
        system("cls");
        agregarProductor();
        break;
      case 2:
        system("cls");
        agregarArtista();
        break;
      case 3:
        system("cls");
        agregarIngenieroSonido();
        break;
      default:
        system("cls");
        cout << "Opcion no valida. Intente de nuevo." << endl;
        break;
    }
  }
}

void GestorRecursos::agregarProductor() {
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

  Personal* prod = new Productor(id, nombre, email, presupuesto);
  personal->agregarPersonal(prod);
}

void GestorRecursos::agregarArtista() {
  string id, nombre, email, herramientasDibujo;

  cout << "Ingrese el ID del artista: ";
  cin >> id;
  cin.ignore();
  cout << "Ingrese el nombre del artista: ";
  getline(cin, nombre);
  cout << "Ingrese el email del artista: ";
  getline(cin, email);
  cout << "Ingrese las herramientos de dibujo del artista: ";
  getline(cin, herramientasDibujo);

  Personal* artista = new Artista(id, nombre, email, herramientasDibujo);
  personal->agregarPersonal(artista);
}

void GestorRecursos::agregarIngenieroSonido() {
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

  Personal* ingeniero = new IngenieroDeSonido(id, nombre, email, aniosExp);
  personal->agregarPersonal(ingeniero);
}

void GestorRecursos::eliminarPersonal() {
  system("cls");

  string id;

  cout << "Personal" << endl << endl;
  cout << mostrarPersonal() << endl;
  cout << "Ingrese el ID del personal que desea eliminar: ";
  cin >> id;
  cin.ignore();

  // EXCEPTION: getPersonalPorID retorna nullptr si no lo encuentra
  Personal* per = personal->getPersonalPorID(id);
  if (per) {
    personal->eliminarPersonal(per);
    cout << "Personal eliminado correctamente" << endl;
  } else {
    throw "Personal no encontrado";
  }
}

string GestorRecursos::mostrarPersonal() {
  return personal->mostrarPersonal();
}

// getters de listas
ListaPeliculas* GestorRecursos::getPeliculas() { return peliculas; }

ListaPersonal* GestorRecursos::getPersonal() { return personal; }