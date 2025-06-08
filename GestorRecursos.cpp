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
    string titulo;
    cout << "Ingrese el titulo de la pelicula: ";
    getline(cin, titulo);

    // Verificar si ya existe una película con ese título
    if (peliculas->getPeliculaPorTitulo(titulo) != nullptr) {
        cout << "Ya existe una pelicula con ese titulo." << endl;
        return;
    }

    try {
        Pelicula* pelicula = new Pelicula(titulo);
        peliculas->agregarPelicula(pelicula);
        cout << "Pelicula agregada exitosamente!" << endl;
    } catch (const char* msg) {
        cout << "Error al agregar la pelicula: " << msg << endl;
    }
}

void GestorRecursos::eliminarPelicula() {
    string titulo;
    cout << "Peliculas disponibles:" << endl;
    cout << peliculas->mostrarPeliculas() << endl;
    cout << "Ingrese el titulo de la pelicula a eliminar: ";
    getline(cin, titulo);

    Pelicula* pelicula = peliculas->getPeliculaPorTitulo(titulo);
    if (pelicula) {
        peliculas->eliminarPelicula(pelicula);
        cout << "Pelicula eliminada exitosamente!" << endl;
    } else {
        cout << "No se encontro la pelicula." << endl;
    }
}

string GestorRecursos::mostrarPeliculas() {
    return peliculas->mostrarPeliculas();
}

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
    string id, nombre, email;
    float presupuesto;

    cout << "Ingrese el ID del productor: ";
    getline(cin, id);
    cout << "Ingrese el nombre del productor: ";
    getline(cin, nombre);
    cout << "Ingrese el email del productor: ";
    getline(cin, email);
    cout << "Ingrese el presupuesto del productor: ";
    cin >> presupuesto;
    cin.ignore();

    try {
        Personal* prod = new Productor(id, nombre, email, presupuesto);
        if (!personal->agregarPersonal(prod)) {
            delete prod;
            throw "Error al agregar el productor";
        }
    } catch (const char* msg) {
        throw;
    }
}

void GestorRecursos::agregarArtista() {
    string id, nombre, email, herramientasDibujo;

    cout << "Ingrese el ID del artista: ";
    getline(cin, id);
    cout << "Ingrese el nombre del artista: ";
    getline(cin, nombre);
    cout << "Ingrese el email del artista: ";
    getline(cin, email);
    cout << "Ingrese las herramientas de dibujo del artista: ";
    getline(cin, herramientasDibujo);

    try {
        Personal* artista = new Artista(id, nombre, email, herramientasDibujo);
        if (!personal->agregarPersonal(artista)) {
            delete artista;
            throw "Error al agregar el artista";
        }
    } catch (const char* msg) {
        throw;
    }
}

void GestorRecursos::agregarIngenieroSonido() {
    string id, nombre, email;
    int aniosExp;

    cout << "Ingrese el ID del ingeniero de sonido: ";
    getline(cin, id);
    cout << "Ingrese el nombre del ingeniero de sonido: ";
    getline(cin, nombre);
    cout << "Ingrese el email del ingeniero de sonido: ";
    getline(cin, email);
    cout << "Ingrese los anios de experiencia del ingeniero de sonido: ";
    cin >> aniosExp;
    cin.ignore();

    try {
        Personal* ingeniero = new IngenieroDeSonido(id, nombre, email, aniosExp);
        if (!personal->agregarPersonal(ingeniero)) {
            delete ingeniero;
            throw "Error al agregar el ingeniero de sonido";
        }
    } catch (const char* msg) {
        throw;
    }
}

void GestorRecursos::eliminarPersonal() {
    system("cls");
    cout << "Personal" << endl << endl;
    cout << mostrarPersonal() << endl;

    string id;
    cout << "Ingrese el ID del personal que desea eliminar: ";
    getline(cin, id);

    Personal* per = personal->getPersonalPorID(id);
    if (per) {
        personal->eliminarPersonal(per);
        cout << "Personal eliminado correctamente" << endl;
    } else {
        throw "Personal no encontrado";
    }
}

string GestorRecursos::mostrarPersonal() const {
    return personal->mostrarPersonal();
}

// getters de listas
ListaPeliculas* GestorRecursos::getPeliculas() {
    return peliculas;
}

ListaPersonal* GestorRecursos::getPersonal() {
    return personal;
}