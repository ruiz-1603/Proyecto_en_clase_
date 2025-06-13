//
// Created by RuizM on 6/5/2025.
//

#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include "ListaPeliculas.h"
#include"ListaPersonal.h"
#include"ListaTareas.h"
#include"Excepcion.h"
#include"Productor.h"
#include"IngenieroDeSonido.h"
#include"Artista.h"

#include<iomanip>



    template<class T>
    class GestorArchivos {
    public:
        static void guardarPeliculas(ListaPeliculas*, ListaPersonal*, const string&);
        static void guardarPersonal(ListaPersonal*, const string&);
        static void guardarTareas(ListaTareas* ListaTareas, const string& nombreArchivo);

        static void cargarPeliculas(const string &nombreArchivo,ListaPeliculas* listaPeliculas, ListaPersonal* listaPersonal);
        static void cargarPersonal(const string &nombreArchivo,ListaPersonal* listaPersonal);
        static void cargarTareas(const string &nombreArchivo, ListaTareas* ListaTareas,ListaPersonal* listaPersonal);


    };



#endif //GESTORARCHIVOS_H
