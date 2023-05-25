//
// Created by yanet on 23/05/2023.
//

#ifndef BIBLIO_BIBLIOTECA_H
#define BIBLIO_BIBLIOTECA_H

#include <iostream>
#include "producto.h" //biblioteca con los objetos

using namespace std;

class Biblioteca {
    private:
        string nombreBiblio;
        string ubicacion;
        Libro libros[5]; //arreglos
        PublicacionAcademica publicaciones[5];

    public:
        //constructores
        Biblioteca();
        Biblioteca(string, string);

        //setters
        void setNombreBiblio(string);
        void setUbicacion(string);

        //getters
        string getNombreBiblio();
        string getUbicacion();

        //para llenar las listas
        void agregaLibro(Libro);
        void agregaPubAcademica(PublicacionAcademica);

};

//definir constructores
Biblioteca::Biblioteca() {
    nombreBiblio = "Biblioteca Tec";
    ubicacion = "Campus Qro";
}

Biblioteca::Biblioteca(string _nombreBiblio,string _ubicacion) {
    nombreBiblio = _nombreBiblio;
    ubicacion = _ubicacion;
}

//definir setters
void Biblioteca::setNombreBiblio(string _nombreBiblio) {
    nombreBiblio = _nombreBiblio;
}

void Biblioteca::setUbicacion(string _ubicacion) {
    ubicacion = _ubicacion;
}

//definir los getters
string Biblioteca::getNombreBiblio() {
    return nombreBiblio;
}

string Biblioteca::getUbicacion() {
    return ubicacion;
}

void Biblioteca::agregaLibro(Libro _libros) {
    int num_libros = 0;
    libros[num_libros] = _libros;
    num_libros++;
}

void Biblioteca::agregaPubAcademica(PublicacionAcademica _pubAcademic) {
    int num_pub = 0;
    publicaciones[num_pub] = _pubAcademic;
    num_pub++;
}

#endif //BIBLIO_BIBLIOTECA_H