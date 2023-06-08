//
// Created by yanet on 23/05/2023.
//

#ifndef BIBLIO_BIBLIOTECA_H
#define BIBLIO_BIBLIOTECA_H

#include <iostream>
#include <string>
#include <sstream>
#include "producto.h" //biblioteca con los objetos

using namespace std;

class Biblioteca {
    private:
        string nombreBiblio;
        string ubicacion;
        Producto *productos[100];
        int indice;

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
        void agregaProducto(Producto*);
        void checaDisponibilidad(string);
};

//definir constructores
Biblioteca::Biblioteca() {
    nombreBiblio = "Biblioteca Tec";
    ubicacion = "Campus Qro";
    indice = 0;
   ;
}

Biblioteca::Biblioteca(string _nombreBiblio,string _ubicacion) {
    nombreBiblio = _nombreBiblio;
    ubicacion = _ubicacion;
    indice = 0;
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

void Biblioteca::agregaProducto(Producto *prod)  {
    productos[indice] = prod;
    indice++;
}

void Biblioteca::checaDisponibilidad(string _nombre) {
    for(int i =0; i < indice; i++){
        if(productos[i]-> getNombreProducto() == _nombre){
            cout << productos[i] -> muestraProducto();
        }
    }
}
#endif //BIBLIO_BIBLIOTECA_H