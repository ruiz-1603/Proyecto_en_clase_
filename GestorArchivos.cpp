//
// Created by RuizM on 6/5/2025.
//

#include "GestorArchivos.h"
#include "EstrategiaTareaAnimacion.h"
#include "EstrategiaTareaSonido.h"
#include <algorithm>

template<class T>
void GestorArchivos<T>::guardarPeliculas(ListaPeliculas* listaPeliculas, ListaPersonal* listaPersonal, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::trunc); // Usar ios::out para sobrescribir correctamente

    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }

        Nodo<Pelicula>* actual = listaPeliculas->getPeliculas()->getPrimero();

        while (actual != nullptr) {
            Pelicula* peli = actual->getDato();
            if (peli != nullptr) {
                archivo << peli->getTitulo() << ","
                        << peli->getEstado() << ",";

                if (peli->getCronograma() != nullptr) {
                    archivo << fixed << setprecision(2) << peli->getCronograma()->getProgreso();
                } else {
                    archivo << "0.00";
                }

                // Agregar IDs del equipo
                Lista<Personal>* equipoPelicula = peli->getEquipo();
                string idsEquipo;

                if (equipoPelicula != nullptr) {
                    Nodo<Personal>* actualPersonal = equipoPelicula->getPrimero();
                    while (actualPersonal != nullptr) {
                        Personal* miembro = actualPersonal->getDato();
                        if (miembro != nullptr) {
                            if (!idsEquipo.empty()) idsEquipo += ";";
                            idsEquipo += miembro->getId();
                        }
                        actualPersonal = actualPersonal->getSiguiente();
                    }
                }

                if (idsEquipo.empty()) {
                    archivo << ",-\n";
                } else {
                    archivo << "," << idsEquipo << "\n";
                }
                if (peli->getCronograma() != nullptr) {
                    ListaTareas *tareas = peli->getCronograma()->getTareas();
                    if (tareas != nullptr) {
                        Nodo<TareaProduccion>* nodoTarea = tareas->getPrimeroNodo();

                        while (nodoTarea != nullptr) {
                            TareaProduccion* tarea = nodoTarea->getDato();
                            if (tarea != nullptr) {
                                string tipoEstrategia = "Desconocido";
                                string param1 = "-", param2 = "-";

                                if (tarea->getEstrategia() != nullptr) {
                                    tipoEstrategia = tarea->getEstrategia()->getTipo();
                                    param1 = tarea->getEstrategia()->getParam1();
                                    param2 = tarea->getEstrategia()->getParam2();
                                }

                                archivo << tarea->getDescripcion() << ","
                                        << tarea->getEstado() << ","
                                        << tarea->getTiempoEstimado() << ","
                                        << (tarea->getResponsable() ? tarea->getResponsable()->getId() : "-") << ","
                                        << tipoEstrategia << ","
                                        << param1 << ","
                                        << param2 << "\n";
                            }

                            nodoTarea = nodoTarea->getSiguiente();
                        }
                    }
                }

                // Agregar personal a la lista global
                if (equipoPelicula != nullptr) {
                    Nodo<Personal>* actualPersonal = equipoPelicula->getPrimero();

                    while (actualPersonal != nullptr) {
                        Personal* miembro = actualPersonal->getDato();
                        if (miembro != nullptr) {
                            Personal* personalExistente = listaPersonal->getPersonalPorID(miembro->getId());
                            if (personalExistente == nullptr) {
                                Personal* copiaPersonal = nullptr;

                                if (Productor* p = dynamic_cast<Productor*>(miembro)) {
                                    string aux = p->getId();
                                    string aux1 = p->getNombre();
                                    string aux2 = p->getEmail();

                                    copiaPersonal = new Productor(aux,aux1,aux2, p->getPresupuesto());
                                } else if (IngenieroDeSonido* ing = dynamic_cast<IngenieroDeSonido*>(miembro)) {
                                    string tempId = ing->getId();
                                    string tempNombre = ing->getNombre();
                                    string tempEmail = ing->getEmail();
                                    copiaPersonal = new IngenieroDeSonido(tempId, tempNombre, tempEmail, ing->getAniosExperiencia());
                                } else if (Artista* a = dynamic_cast<Artista*>(miembro)) {
                                    string tempId1 = a->getId();
                                    string tempNombre2 = a->getNombre();
                                    string tempEmail3 = a->getEmail();
                                    string temp4 = a->getHerramientasDibujo();
                                    copiaPersonal = new Artista(tempId1, tempNombre2, tempEmail3, temp4);
                                }

                                if (copiaPersonal != nullptr) {
                                    if (!listaPersonal->agregarPersonal(copiaPersonal)) {
                                        delete copiaPersonal;
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

        cout << "Peliculas guardadas correctamente en " << nombreArchivo << endl;

    } catch (const exception& e) {
        cerr << "Error al guardar películas: " << e.what() << endl;
    }

    archivo.close();
}


template<class T>
void GestorArchivos<T>::guardarPersonal(ListaPersonal* listaPersonal, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
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

template<class T>
void GestorArchivos<T>::guardarTareas(ListaTareas* ListaTareas, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::trunc);
    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }

        Nodo<TareaProduccion>* actual = ListaTareas->getPrimeroNodo();
        int contador = 0;

        while (actual != nullptr) {
            TareaProduccion* tarea = actual->getDato();
            if (tarea != nullptr) {
                archivo << tarea->getDescripcion() << ","
                        << tarea->getEstado() << ","
                        << tarea->getTiempoEstimado() << ",";

                if (tarea->getResponsable() != nullptr) {
                    archivo << tarea->getResponsable()->getId();
                } else {
                    archivo << "-";
                }

                EstrategiaTarea* est = tarea->getEstrategia();
                archivo << "," << tarea->getTipoEstrategia();

                if (auto anim = dynamic_cast<EstrategiaTareaAnimacion*>(est)) {
                    archivo << "," << anim->getParam1() << "," << anim->getParam2();
                } else if (auto sonido = dynamic_cast<EstrategiaTareaSonido*>(est)) {
                    archivo << "," << sonido->getParam1() << "," << sonido->getParam2();
                } else {
                    archivo << ",-,-";
                }

                archivo << "\n";
            }
            else {
                cout << "  La tarea esta vacia" << endl;
            }
            actual = actual->getSiguiente();
        }

        cout << "Tareas guardadas correctamente en " << nombreArchivo << endl;
    } catch (const exception& e) {
        cerr << "Error al guardar tareas: " << e.what() << endl;
    }
    archivo.close();
}

template<class T>
void GestorArchivos<T>::cargarPeliculas(const string& nombreArchivo, ListaPeliculas* listaPeliculas, ListaPersonal* listaPersonal) {
    ifstream archivo(nombreArchivo);

    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para lectura: " + nombreArchivo);
        }

        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue;

            // --- Parsear datos básicos de la película ---
            stringstream ss(linea);
            string titulo, estado, progresoStr, equipoStr;

            getline(ss, titulo, ',');
            getline(ss, estado, ',');
            getline(ss, progresoStr, ',');
            getline(ss, equipoStr);

            if (titulo.empty()) continue;

            Pelicula* pelicula = new Pelicula(titulo);

            // Set progreso si es válido
            if (!progresoStr.empty() && progresoStr != "0.00") {
                float progreso = stof(progresoStr);
                if (pelicula->getCronograma() != nullptr) {
                    pelicula->getCronograma()->setProgreso(progreso);
                }
            }

            // --- Cargar equipo de personal manualmente ---
            if (!equipoStr.empty() && equipoStr != "-") {
                stringstream ssEquipo(equipoStr);
                string idPersonal;
                while (getline(ssEquipo, idPersonal, ';')) {
                    if (idPersonal.empty()) continue;

                    Nodo<Personal>* actualPersonal = listaPersonal->getPersonal()->getPrimero();
                    Personal* miembro = nullptr;

                    while (actualPersonal != nullptr) {
                        if (actualPersonal->getDato()->getId() == idPersonal) {
                            miembro = actualPersonal->getDato();
                            break;
                        }
                        actualPersonal = actualPersonal->getSiguiente();
                    }

                    if (miembro != nullptr) {
                        pelicula->agregarMiembro(miembro);
                    } else {
                        cerr << "No se encontro personal con ID: " << idPersonal << endl;
                    }
                }
            }

            // --- Ahora leer las tareas asociadas a esta película ---
            while (true) {
                // Guardar posición para posible retroceso
                std::streampos posAnterior = archivo.tellg();

                string lineaTarea;
                if (!getline(archivo, lineaTarea)) {
                    // No hay más líneas
                    break;
                }

                // Contar comas para validar formato de tarea (6 o más campos)
                int numComas = std::count(lineaTarea.begin(), lineaTarea.end(), ',');
                if (numComas < 6) {
                    // No es línea de tarea -> retrocedemos y salimos del loop
                    archivo.seekg(posAnterior);
                    break;
                }


                stringstream ssT(lineaTarea);
                string descripcion, estadoTarea, tiempoEstimadoStr, idResponsable, tipoEstrategia, param1, param2;

                getline(ssT, descripcion, ',');
                getline(ssT, estadoTarea, ',');
                getline(ssT, tiempoEstimadoStr, ',');
                getline(ssT, idResponsable, ',');
                getline(ssT, tipoEstrategia, ',');
                getline(ssT, param1, ',');
                getline(ssT, param2);

                // Buscar responsable manualmente
                Personal* responsable = nullptr;
                if (!idResponsable.empty() && idResponsable != "-") {
                    Nodo<Personal>* actualPersonal = listaPersonal->getPersonal()->getPrimero();
                    while (actualPersonal != nullptr) {
                        if (actualPersonal->getDato()->getId() == idResponsable) {
                            responsable = actualPersonal->getDato();
                            break;
                        }
                        actualPersonal = actualPersonal->getSiguiente();
                    }
                }

                if (responsable == nullptr && idResponsable != "-") {
                    cerr << "No se encontro personal con ID: " << idResponsable << endl;
                    continue;  // No se puede crear tarea sin responsable válido
                }

                // Crear la estrategia según tipo
                EstrategiaTarea* estrategia = nullptr;
                try {
                    if (tipoEstrategia == "EstrategiaAnimacion") {
                        int complejidad = param2.empty() ? 1 : stoi(param2);
                        estrategia = new EstrategiaTareaAnimacion(param1.empty() ? "2D" : param1, complejidad);
                    } else if (tipoEstrategia == "EstrategiaSonido") {
                        int duracion = param2.empty() ? 60 : stoi(param2);
                        estrategia = new EstrategiaTareaSonido(param1.empty() ? "Musica" : param1, duracion);
                    } else {
                        cerr << "Tipo de estrategia desconocido: " << tipoEstrategia << endl;
                        continue;
                    }
                } catch (const exception& e) {
                    cerr << "Error creando estrategia: " << e.what() << endl;
                    continue;
                }

                if (!estrategia->validarResponsable(responsable)) {
                    cerr << "Responsable invalido para estrategia " << tipoEstrategia << ": " << idResponsable << endl;
                    delete estrategia;
                    continue;
                }

                // Crear tarea y asignar estado
                TareaProduccion* tarea = new TareaProduccion(descripcion, responsable, estrategia);
                tarea->setEstado(estadoTarea);

                // Agregar tarea al cronograma
                if (pelicula->getCronograma() != nullptr) {
                    pelicula->getCronograma()->agregarTarea(tarea);
                } else {
                    cerr << "La película no tiene cronograma para agregar tarea." << endl;
                    delete tarea; // evitar fuga
                }
            }

            // Agregar película a la lista
            listaPeliculas->agregarPelicula(pelicula);
        }

        cout << "Peliculas con tareas cargadas correctamente desde " << nombreArchivo << endl;

    } catch (const exception& e) {
        cerr << "Error al cargar peliculas con tareas: " << e.what() << endl;
    }

    archivo.close();
}


template<class T>
void GestorArchivos<T>::cargarPersonal(const string& nombreArchivo,ListaPersonal* listaPersonal) {
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
                cerr << "Linea con datos incompletos, saltando..." << endl;
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
        cout << "Personal cargadas correctamente desde " << nombreArchivo << endl;
    } catch (const exception& e) {
        cerr << "Error al cargar personal: " << e.what() << endl;
    }

    archivo.close();
}
template<class T>
void GestorArchivos<T>::cargarTareas(const string &nombreArchivo, ListaTareas* ListaTareas,ListaPersonal* ListaPersonal) {
 ifstream archivo(nombreArchivo);

    try {
        if (!archivo.is_open()) {
            throw Excepcion("No se pudo abrir el archivo para lectura: " + nombreArchivo);
        }

         string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string descripcion, estado, tiempoEstimadoStr, idResponsable, tipoEstrategia, param1, param2;

            getline(ss, descripcion, ',');
            getline(ss, estado, ',');
            getline(ss, tiempoEstimadoStr, ',');
            getline(ss, idResponsable, ',');
            getline(ss, tipoEstrategia, ',');
            getline(ss, param1, ',');
            getline(ss, param2, ',');

            param2.erase(remove(param2.begin(), param2.end(), '\n'), param2.end());
            // Validar datos básicos
            if (descripcion.empty() || tipoEstrategia.empty()) {
                cerr << "Linea con datos incompletos, saltando..." << endl;
                continue;
            }

            try {
                // Buscar el responsable por ID
                Personal* responsable = nullptr;
                if (!idResponsable.empty() && idResponsable != "-") {
                    Nodo<Personal> *actualPersonal = ListaPersonal->getPrimeroNodo();
                    while (actualPersonal != nullptr) {
                        if (actualPersonal->getDato()->getId() == idResponsable) {
                            responsable = actualPersonal->getDato();
                            break;
                        }
                        actualPersonal = actualPersonal->getSiguiente();
                    }

                    if (responsable == nullptr) {
                        cerr << "No se encontro personal con ID: " << idResponsable << endl;
                        continue;
                    }
                }

                EstrategiaTarea* estrategia = nullptr;
                if (tipoEstrategia == "EstrategiaAnimacion") {
                    int complejidad = param2.empty() ? 1 : stoi(param2);
                    estrategia = new EstrategiaTareaAnimacion(param1.empty() ? "2D" : param1, complejidad);
                } else if (tipoEstrategia == "EstrategiaSonido") {
                    int duracion = param2.empty() ? 60 : stoi(param2);
                    estrategia = new EstrategiaTareaSonido(param1.empty() ? "Musica" : param1, duracion);
                }

                if (estrategia == nullptr) {
                    cerr << "Tipo de estrategia desconocido: " << tipoEstrategia << endl;
                    continue;
                }

                // Crear la tarea con el constructor original
                TareaProduccion* tarea = new TareaProduccion(descripcion, responsable, estrategia);

                if (estado == "completa") {
                    tarea->setEstado("completa");
                }

                ListaTareas->agregarTarea(tarea);

            } catch (const exception& e) {
                cerr << "Error al procesar linea de tarea: " << e.what() << endl;
                continue;
            }
        }

        cout << "Tareas cargadas correctamente desde " << nombreArchivo << endl;

    } catch (const exception& e) {
        cerr << "Error al cargar tareas: " << e.what() << endl;
    }
    archivo.close();
}
