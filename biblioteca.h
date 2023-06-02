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
        Libro *libros[100]; //arreglos
        PublicacionAcademica *publicaciones[100];
        int libro_col;
        int pubAcad_col;

    public:
        //constructores
        Biblioteca();
        Biblioteca(string, string, int, int);

        //setters
        void setNombreBiblio(string);
        void setUbicacion(string);

        //getters
        string getNombreBiblio();
        string getUbicacion();

        //para llenar las listas
        void agregaLibro(Libro *a);
        void agregaPubAcademica(PublicacionAcademica *b);

};

//definir constructores
Biblioteca::Biblioteca() {
    nombreBiblio = "Biblioteca Tec";
    ubicacion = "Campus Qro";
    libro_col = 0;
    pubAcad_col = 0;
}

Biblioteca::Biblioteca(string _nombreBiblio,string _ubicacion, int _libroCol, int _pubAcadCol) {
    nombreBiblio = _nombreBiblio;
    ubicacion = _ubicacion;
    libro_col = _libroCol;
    pubAcad_col = _pubAcadCol;
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

void Biblioteca::agregaLibro(Libro *a) {
    libros[libro_col] = a;
    libro_col ++;
}

void Biblioteca::agregaPubAcademica(PublicacionAcademica *b) {
    publicaciones[pubAcad_col] = b;
    pubAcad_col ++;

}

#endif //BIBLIO_BIBLIOTECA_H