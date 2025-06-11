//
// Created by RuizM on 6/5/2025.
//

#include "GestorArchivos.h"

template<class T>
void GestorArchivos<T>::guardarPeliculas(ListaPeliculas* listaPeliculas, ListaPersonal* listaPersonal, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }

        Nodo<Pelicula>* actual = listaPeliculas->getPeliculas()->getPrimero();

        while (actual != nullptr) {
            Pelicula* peli = actual->getDato();
            if (peli != nullptr) {
                // Guardar información de la película
                archivo << peli->getTitulo() << ","
                        << peli->getEstado() << ",";

                if (peli->getCronograma() != nullptr) {
                    archivo << fixed << setprecision(2) << peli->getCronograma()->getProgreso();
                } else {
                    archivo << "0.00";
                }

                archivo << "\n";

                // Extraer el personal de esta película y agregarlo a la lista general
                Lista<Personal>* equipoPelicula = peli->getEquipo();
                if (equipoPelicula != nullptr) {
                    Nodo<Personal>* actualPersonal = equipoPelicula->getPrimero();

                    while (actualPersonal != nullptr) {
                        Personal* miembro = actualPersonal->getDato();
                        if (miembro != nullptr) {
                            // Verificar si el personal ya existe en la lista general (evitar duplicados)
                            Personal* personalExistente = listaPersonal->getPersonalPorID(miembro->getId());
                            if (personalExistente == nullptr) {
                                // Crear una copia del personal para agregarlo a la lista general
                                Personal* copiaPersonal = nullptr;

                                // Dynamic cast para determinar el tipo y crear la copia apropiada
                                if (Productor* p = dynamic_cast<Productor*>(miembro)) {
                                    string aux = p->getId();
                                    string aux1 = p->getNombre();
                                    string aux2 = p->getEmail();
                                    int aux3 = p->getPresupuesto();

                                    copiaPersonal = new Productor(aux, aux1, aux2, aux3);
                                }
                                else if (IngenieroDeSonido* ing = dynamic_cast<IngenieroDeSonido*>(miembro)) {
                                    string tempId = ing->getId();
                                    string tempNombre = ing->getNombre();
                                    string tempEmail = ing->getEmail();
                                    copiaPersonal = new IngenieroDeSonido(tempId, tempNombre, tempEmail, ing->getAniosExperiencia());
                                }
                                else if (Artista* a = dynamic_cast<Artista*>(miembro)) {
                                    string tempId1 = a->getId();
                                    string tempNombre2 = a->getNombre();
                                    string tempEmail3 = a->getEmail();
                                    string temp4 = a->getHerramientasDibujo();
                                    copiaPersonal = new Artista(tempId1, tempNombre2, tempEmail3, temp4);
                                }

                                // Agregar la copia a la lista general si se pudo crear
                                if (copiaPersonal != nullptr) {
                                    if (!listaPersonal->agregarPersonal(copiaPersonal)) {
                                        delete copiaPersonal; // Limpiar memoria si no se pudo agregar
                                    }
                                }
                            }
                        }
                        actualPersonal = actualPersonal->getSiguiente();
                    }
                }
            }

            actual = actual->getSiguiente();
        }

        cout << "Películas guardadas correctamente en " << nombreArchivo << endl;
        cout << "Personal de las películas agregado a la lista general" << endl;

    } catch (const exception& e) {
        cerr << "Error al guardar películas: " << e.what() << endl;
    }

    archivo.close();
}

template<class T>
void GestorArchivos<T>::guardarPersonal(ListaPersonal* listaPersonal, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }

        Nodo<Personal>* actual = listaPersonal->getPersonal()->getPrimero();

        while (actual != nullptr) {
            Personal* persona = actual->getDato();
            if (persona == nullptr) {
                actual = actual->getSiguiente();
                continue;
            }

            // Dynamic cast a Productor
            if (Productor* p = dynamic_cast<Productor*>(persona)) {
                archivo << "Productor,"
                        << p->getId() << ","
                        << p->getNombre() << ","
                        << p->getEmail() << ","
                        << p->getPresupuesto() << ","
                        << "-,-\n";  // Espacios vacíos para los otros roles
            }
            // Dynamic cast a IngenieroDeSonido
            else if (IngenieroDeSonido* ing = dynamic_cast<IngenieroDeSonido*>(persona)) {
                archivo << "IngenieroDeSonido,"
                        << ing->getId() << ","
                        << ing->getNombre() << ","
                        << ing->getEmail() << ","
                        << "-" << ","  // No aplica presupuesto
                        << ing->getAniosExperiencia() << ","
                        << "-\n";     // No aplica herramientas
            }
            // Dynamic cast a Artista
            else if (Artista* a = dynamic_cast<Artista*>(persona)) {
                archivo << "Artista,"
                        << a->getId() << ","
                        << a->getNombre() << ","
                        << a->getEmail() << ","
                        << "-,-,"    // No aplica presupuesto ni años experiencia
                        << a->getHerramientasDibujo() << "\n";
            }

            actual = actual->getSiguiente();
        }

        cout << "Personal guardado correctamente en " << nombreArchivo << endl;

    } catch (const Excepcion& e) {
        cerr << "Error al guardar personal: " << e.what() << endl;
    }

    archivo.close();
}

#include "GestorArchivos.h"


template<class T>
ListaPeliculas* GestorArchivos<T>::cargarPeliculas(const string& nombreArchivo) {
    // Si no se proporciona una lista, crear una nueva
    ListaPeliculas* listaPeliculas = new ListaPeliculas();
    ListaPersonal* listaPersons = new ListaPersonal();

    ifstream archivo(nombreArchivo);

    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para lectura: " + nombreArchivo);
        }

        string linea;
        // Saltar encabezado si existe
        if (getline(archivo, linea) && linea.find("Titulo") != string::npos) {
            // Es un encabezado, continuar
        } else {
            // No es encabezado, procesar esta línea
            archivo.seekg(0); // Volver al inicio
        }

        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Saltar líneas vacías

            stringstream ss(linea);
            string titulo, estado, progresoStr, equipoStr;

            getline(ss, titulo, ',');
            getline(ss, estado, ',');
            getline(ss, progresoStr, ',');
            getline(ss, equipoStr); // IDs del equipo separados por ';'

            // Validar datos básicos
            if (titulo.empty()) {
                cerr << "Película sin título, saltando línea..." << endl;
                continue;
            }

            try {
                // Crear la película
                Pelicula* pelicula = new Pelicula(titulo);

                // Configurar el progreso si está disponible
                if (!progresoStr.empty() && progresoStr != "0.00") {
                    float progreso = stof(progresoStr);
                    if (pelicula->getCronograma() != nullptr) {
                        pelicula->getCronograma()->setProgreso(progreso);
                    }
                }

                // Asignar personal a la película
                if (!equipoStr.empty() && equipoStr != "-" && listaPersons != nullptr) {
                    // Dividir los IDs del equipo (formato: "id1;id2;id3")
                    stringstream ssEquipo(equipoStr);
                    string idPersonal;

                    while (getline(ssEquipo, idPersonal, ';')) {
                        if (idPersonal.empty() || idPersonal == "-") continue;

                        // Buscar el personal por ID en la lista
                        Nodo<Personal>* actualPersonal = listaPersons->getPersonal()->getPrimero();
                        Personal* miembro = nullptr;

                        while (actualPersonal != nullptr && miembro == nullptr) {
                            Personal* persona = actualPersonal->getDato();
                            if (persona != nullptr && persona->getId() == idPersonal) {
                                miembro = persona;
                            }
                            actualPersonal = actualPersonal->getSiguiente();
                        }

                        // Agregar miembro a la película si se encontró
                        if (miembro != nullptr) {
                            if (!pelicula->agregarMiembro(miembro)) {
                                cerr << "No se pudo agregar el miembro con ID " << idPersonal
                                     << " a la película " << pelicula->getTitulo() << endl;
                            }
                        } else {
                            cerr << "Personal con ID " << idPersonal << " no encontrado" << endl;
                        }
                    }
                }

                // Agregar película a la lista
                listaPeliculas->agregarPelicula(pelicula);

            } catch (const exception& e) {
                cerr << "Error al crear película '" << titulo << "': " << e.what() << endl;
                continue;
            }
        }

        cout << "Películas cargadas correctamente desde " << nombreArchivo << endl;

    } catch (const exception& e) {
        cerr << "Error al cargar películas: " << e.what() << endl;
    }

    archivo.close();
    return listaPeliculas;
}

template<class T>
ListaPersonal* GestorArchivos<T>::cargarPersonal(const string& nombreArchivo) {
    ListaPersonal* listaPersonal = new ListaPersonal();
    ifstream archivo(nombreArchivo);

    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para lectura: " + nombreArchivo);
        }

        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Saltar líneas vacías

            stringstream ss(linea);
            string tipo, id, nombre, email, presupuestoStr, experienciaStr, herramientas;

            getline(ss, tipo, ',');
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, email, ',');
            getline(ss, presupuestoStr, ',');
            getline(ss, experienciaStr, ',');
            getline(ss, herramientas);

            // Validar datos básicos
            if (tipo.empty() || id.empty() || nombre.empty() || email.empty()) {
                cerr << "Línea con datos incompletos, saltando..." << endl;
                continue;
            }

            Personal* persona = nullptr;

            try {
                if (tipo == "Productor" && !presupuestoStr.empty() && presupuestoStr != "-") {
                    float presupuesto = stof(presupuestoStr);
                    persona = new Productor(id, nombre, email, presupuesto);
                }
                else if (tipo == "IngenieroDeSonido" && !experienciaStr.empty() && experienciaStr != "-") {
                    int experiencia = stoi(experienciaStr);
                    persona = new IngenieroDeSonido(id, nombre, email, experiencia);
                }
                else if (tipo == "Artista" && !herramientas.empty() && herramientas != "-") {
                    persona = new Artista(id, nombre, email, herramientas);
                }

                if (persona != nullptr) {
                    listaPersonal->agregarPersonal(persona);
                }
            } catch (const exception& e) {
                cerr << "Error al crear persona de tipo " << tipo << ": " << e.what() << endl;
                continue;
            }
        }
    } catch (const exception& e) {
        cerr << "Error al cargar personal: " << e.what() << endl;
    }

    archivo.close();
    return listaPersonal;
}
