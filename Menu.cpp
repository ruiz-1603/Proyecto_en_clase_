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
    system("cls");
    cout << "=== GESTOR DE PRODUCCION PIXAR ===" << endl << endl;
    cout << "1. Agregar Pelicula" << endl;
    cout << "2. Seleccionar Pelicula" << endl;
    cout << "3. Ver Peliculas" << endl;
    cout << "4. Eliminar Pelicula" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Intente de nuevo." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      continue;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "=== PELICULAS DISPONIBLES ===" << endl << endl;
        cout << "----------------------------------------" << endl;
        cout << interfaz->mostrarPeliculas();
        cout << "----------------------------------------" << endl;
        cout << endl << "Presione ENTER para continuar";
        cin.get();
        break;
      case 4:
        system("cls");
        interfaz->eliminarPelicula();
        break;
      case 0:
        break;
      default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
    }
  }
}

void Menu::seleccionarPelicula() {
  string titulo;
  string listaPeliculas = interfaz->mostrarPeliculas();

  system("cls");
  cout << "=== SELECCIONAR PELICULA ===" << endl << endl;
  cout << "----------------------------------------" << endl;
  cout << "Peliculas disponibles:" << endl;
  cout << listaPeliculas;
  cout << "----------------------------------------" << endl << endl;

  if (listaPeliculas == "No hay elementos en la lista.\n") {
    cout << "No hay peliculas disponibles para seleccionar." << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
    return;
  }

  cout << "Ingrese el titulo de la pelicula que desea seleccionar: ";
  getline(cin, titulo);

  try {
    Pelicula* pelicula = interfaz->getPeliculas()->getPeliculaPorTitulo(titulo);
    if (pelicula) {
      menuPelicula(pelicula);
    } else {
      cout << "La pelicula no existe." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
    }
  } catch (const exception& e) {
    cout << "Error al seleccionar la pelicula: " << e.what() << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
  }
}

void Menu::menuPelicula(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "=== MENU PELICULA ===" << endl;
    cout << "----------------------------------------" << endl;
    cout << pelicula->toString();
    cout << "----------------------------------------" << endl << endl;
    cout << "Opciones disponibles:" << endl;
    cout << "1. Personal" << endl;
    cout << "2. Cronograma" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    
    // Limpiar el buffer antes de leer
    cin.clear();
    cin >> opcion;
    
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Intente de nuevo." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      opcion = -1;
      continue;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (opcion) {
      case 1:
        system("cls");
        menuPersonal(pelicula);
        break;
      case 2:
        system("cls");
        menuCronograma(pelicula);
        break;
      case 0:
        break;
      default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
    }
  }
}

void Menu::menuPersonal(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "=== MENU PERSONAL ===" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Pelicula: " << pelicula->getTitulo() << endl;
    cout << "----------------------------------------" << endl << endl;
    cout << "Personal actual:" << endl;
    cout << pelicula->mostrarEquipo() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Opciones disponibles:" << endl;
    cout << "1. Agregar miembro al equipo" << endl;
    cout << "2. Eliminar miembro del equipo" << endl;
    cout << "3. Mostrar personal" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    
    // Limpiar el buffer antes de leer
    cin.clear();
    cin >> opcion;
    
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Intente de nuevo." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      opcion = -1;
      continue;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "=== PERSONAL DE LA PELICULA ===" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pelicula: " << pelicula->getTitulo() << endl << endl;
        cout << pelicula->mostrarEquipo() << endl;
        cout << "----------------------------------------" << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
      case 0:
        break;
      default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
    }
  }
}

void Menu::agregarPersonalAPelicula(Pelicula* pelicula) {
  int opcion = -1;

  while (opcion != 0) {
    system("cls");
    cout << "=== AGREGAR PERSONAL ===" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Pelicula: " << pelicula->getTitulo() << endl;
    cout << "----------------------------------------" << endl << endl;
    cout << "Tipos de personal disponibles:" << endl;
    cout << "1. Productor" << endl;
    cout << "2. Artista" << endl;
    cout << "3. Ingeniero de Sonido" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    
    // Limpiar el buffer antes de leer
    cin.clear();
    cin >> opcion;
    
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Intente de nuevo." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      opcion = -1;
      continue;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "Opcion no valida. Intente de nuevo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        continue;
    }

    if (nuevoMiembro != nullptr) {
      if (pelicula->agregarMiembro(nuevoMiembro)) {
        cout << "Miembro agregado exitosamente!" << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
      } else {
        delete nuevoMiembro;
        cout << "Error al agregar el miembro al equipo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
      }
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
    cout << "No se encontro el personal con ese ID." << endl;
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
    cout << "=== MENU CRONOGRAMA ===" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Pelicula: " << pelicula->getTitulo() << endl;
    cout << "Progreso: " << fixed << setprecision(2) << pelicula->getCronograma()->getProgreso() << "%" << endl;
    cout << "Cantidad de tareas: " << pelicula->getCronograma()->getCantidadTareas() << endl;
    cout << "----------------------------------------" << endl << endl;
    cout << "Tareas actuales:" << endl;
    cout << pelicula->getCronograma()->mostrarCronograma() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Opciones disponibles:" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Marcar tarea como completa" << endl;
    cout << "3. Ver cronograma detallado" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion: ";
    
    // Limpiar el buffer antes de leer
    cin.clear();
    cin >> opcion;
    
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opcion invalida. Intente de nuevo." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      opcion = -1;
      continue;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (opcion) {
      case 1:
        system("cls");
        asignarTareaAPelicula(pelicula);
        break;
      case 2:
        system("cls");
        marcarTareaCompleta(pelicula);
        break;
      case 3:
        system("cls");
        cout << "=== CRONOGRAMA DETALLADO ===" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pelicula: " << pelicula->getTitulo() << endl;
        cout << "Progreso total: " << fixed << setprecision(2) << pelicula->getCronograma()->getProgreso() << "%" << endl;
        cout << "----------------------------------------" << endl << endl;
        cout << pelicula->getCronograma()->mostrarCronograma() << endl;
        cout << "----------------------------------------" << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
      case 0:
        break;
      default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        break;
    }
  }
}

void Menu::asignarTareaAPelicula(Pelicula* pelicula) {
  string descripcion;
  string id;
  int tipoEstrategia;

  system("cls");
  cout << "=== AGREGAR TAREA ===" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Pelicula: " << pelicula->getTitulo() << endl;
  cout << "----------------------------------------" << endl << endl;

  cout << "Ingrese la descripcion de la tarea: ";
  getline(cin, descripcion);

  cout << endl << "Personal disponible:" << endl;
  cout << pelicula->mostrarEquipo() << endl;
  cout << "Ingrese el ID del responsable: ";
  getline(cin, id);

  Personal* responsable = pelicula->getMiembroPorID(id);
  if (!responsable) {
    cout << "No se encontró el personal con ese ID." << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
    return;
  }

  cout << endl << "Seleccione el tipo de tarea:" << endl;
  cout << "1. Tarea de Animacion" << endl;
  cout << "2. Tarea de Sonido" << endl;
  cout << "Ingrese una opcion: ";
  cin >> tipoEstrategia;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  EstrategiaTarea* estrategia = nullptr;
  try {
    if (tipoEstrategia == 1) {
      string tipoAnimacion;
      int complejidad;
      
      cout << endl << "Tipo de animacion (2D/3D/Stop Motion): ";
      getline(cin, tipoAnimacion);
      cout << "Complejidad (1-5): ";
      cin >> complejidad;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
      if (complejidad < 1 || complejidad > 5) {
        cout << "Complejidad invalida. Debe estar entre 1 y 5." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        return;
      }
      
      estrategia = new EstrategiaTareaAnimacion(tipoAnimacion, complejidad);
    } else if (tipoEstrategia == 2) {
      string tipoSonido;
      int duracionMinutos;
      
      cout << endl << "Tipo de sonido (Musica/Efectos/Voces/Mezcla): ";
      getline(cin, tipoSonido);
      cout << "Duracion en minutos: ";
      cin >> duracionMinutos;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
      if (duracionMinutos <= 0) {
        cout << "Duracion invalida. Debe ser mayor a 0." << endl;
        cout << "Presione ENTER para continuar";
        cin.get();
        return;
      }
      
      estrategia = new EstrategiaTareaSonido(tipoSonido, duracionMinutos);
    } else {
      cout << "Opcion invalida." << endl;
      cout << "Presione ENTER para continuar";
      cin.get();
      return;
    }

    if (!estrategia->validarResponsable(responsable)) {
      cout << "El responsable seleccionado no puede realizar este tipo de tarea." << endl;
      delete estrategia;
      cout << "Presione ENTER para continuar";
      cin.get();
      return;
    }

    TareaProduccion* tarea = new TareaProduccion(descripcion, responsable, estrategia);
    pelicula->getCronograma()->agregarTarea(tarea);
    cout << endl << "¡Tarea agregada exitosamente!" << endl;
    cout << endl << "Detalles de la tarea:" << endl;
    cout << tarea->mostrarTarea() << endl;
  } catch (const exception& e) {
    cout << "Error al agregar la tarea: " << e.what() << endl;
    if (estrategia) delete estrategia;
  }

  cout << "Presione ENTER para continuar";
  cin.get();
}

void Menu::marcarTareaCompleta(Pelicula* pelicula) {
  int indice;
  
  system("cls");
  cout << "=== MARCAR TAREA COMO COMPLETA ===" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Pelicula: " << pelicula->getTitulo() << endl;
  cout << "----------------------------------------" << endl << endl;
  
  cout << "Tareas actuales:" << endl;
  cout << pelicula->getCronograma()->mostrarCronograma() << endl;
  
  cout << "Ingrese el numero de la tarea a marcar como completa (1-" 
       << pelicula->getCronograma()->getCantidadTareas() << "): ";
  cin >> indice;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  if (cin.fail() || indice < 1 || indice > pelicula->getCronograma()->getCantidadTareas()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Numero de tarea invalido." << endl;
    cout << "Presione ENTER para continuar";
    cin.get();
    return;
  }
  
  try {
    pelicula->getCronograma()->marcarTareaCompleta(indice - 1);
    cout << "Tarea marcada como completa exitosamente!" << endl;
  } catch (const exception& e) {
    cout << "Error al marcar la tarea como completa: " << e.what() << endl;
  }
  
  cout << "Presione ENTER para continuar";
  cin.get();
}