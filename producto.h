//
// Created by yanet on 23/05/2023.
//

#ifndef BIBLIO_PRODUCTO_H
#define BIBLIO_PRODUCTO_H

#include <iostream>
#include "added.h"

using namespace std;

class Producto {

    //Declarar atributos
    protected:
        string nombreProducto;
        string autor;
        string editorial;
        int year;
        bool disponibilidad;
        Usuario poseedor;

    public:
        //declarar constructores
        Producto();
        Producto(string, string, string, int); //sobrecarga
        Producto(string, string, string, int, bool, Usuario);

        //metodos adicionales
        virtual bool checaDisponibilidad(); //para revisar si esta disponible o no
        virtual void muestraProducto(); //para ver el objeto
};

//METODOS PRODUCTO --------------------------------------------------------------------------------------------------

//Constructor por default
Producto::Producto(){
    nombreProducto = "Desconocido";
    autor = "Desconocido";
    editorial = "Desconocido";
    year = 0;
    disponibilidad = false;
}

//Constructor
Producto::Producto(string _nombreProducto, string _autor, string _editorial, int _year) {
    nombreProducto = _nombreProducto;
    autor = _autor;
    editorial = _editorial;
    year = _year;
    disponibilidad = true;
}

//Constructor con usuario (sobrecarga)
Producto::Producto(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad, Usuario _poseedor) {
    nombreProducto = _nombreProducto;
    autor = _autor;
    editorial = _editorial;
    year = _year;
    disponibilidad = _disponibilidad;
    poseedor = _poseedor;
}

bool Producto::checaDisponibilidad() {
    cout << "Checar disponibilidad" << endl;
}

void Producto::muestraProducto() {
    cout << "El producto es: " << endl;
}

//clase hija de Producto
class PublicacionAcademica: public Producto {

    private:
        //tal vez citations deba de ser un arreglo
        string citations;

    public:
        //constructores
        PublicacionAcademica();
        PublicacionAcademica(string, string, string, int,string);
        PublicacionAcademica(string, string, string, int, bool,Usuario,string);
        //setter
        void setCitations(string);
        //getter
        string getCitations();
        //metodos adicionales
        bool checaDisponibilidad();
        void muestraProducto();
};

//METODOS DE PUBLICACION ACADEMICA ------------------------------------------------------------------------------------

//constructor por default
PublicacionAcademica::PublicacionAcademica():Producto() {
    citations = "None";
}

//constructor
PublicacionAcademica::PublicacionAcademica(string _nombreProducto, string _autor, string _editorial, int _year, string _citations) : Producto(_nombreProducto, _autor, _editorial, _year) {
    citations = _citations;
}

//constructor con usuario
PublicacionAcademica::PublicacionAcademica(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad, Usuario _poseedor, string _citations) : Producto(_nombreProducto, _autor, _editorial, _year, _disponibilidad, _poseedor) {
    citations = _citations;
}

//setter
void PublicacionAcademica::setCitations(string _citations) {
    citations = _citations;
}

//getter
string PublicacionAcademica::getCitations() {
    return citations;
}

//metodo para checar la disponibilidad de una publicacion
bool PublicacionAcademica::checaDisponibilidad() {
    if (disponibilidad == true)
        cout << "La publicacion academica " << nombreProducto << " esta disponible" << endl;
    else
        cout << "La publicacion academica " << nombreProducto << " no esta disponible" << endl;
}

//metodo para ver el objeto
void PublicacionAcademica::muestraProducto() {
    cout << "Nombre: " << nombreProducto << endl;
    cout << "Autor: " << autor << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Year: " << year << endl;
    cout << "Citations: " << citations << endl;
}

class Libro: public Producto {
private:
    int isbn;
    //Saga sagas[10]

public:
    Libro();
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn);
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad, Usuario _poseedor,int _isbn);
    //Libro(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad,int _isbn, Saga _sagas);
    //setter
    void setIsbn(int);
    //getter
    int getIsbn();
    //metodos adicionales
    bool checaDisponibilidad();
    void pedirSaga(string);
    void muestraProducto();

};

//METODOS DE LIBRO ----------------------------------------------------------------------------------------------------

//constructor por default
Libro::Libro(): Producto(){
    isbn = 0;
}

//constructor
Libro::Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn) : Producto(_nombreProducto, _autor, _editorial, _year) {
    isbn = _isbn;
    disponibilidad = true;
}

//constructor con user
Libro::Libro(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad, Usuario _poseedor, int _isbn) : Producto(_nombreProducto, _autor, _editorial, _year, _disponibilidad, _poseedor){
    isbn = _isbn;
}

//setter
void Libro::setIsbn(int _isbn) {
    isbn = _isbn;
}

//getter
int Libro::getIsbn() {
    return isbn;
}

//metodos adicionales
bool Libro::checaDisponibilidad() {
    if (disponibilidad == true)
        cout << "El libro " << nombreProducto << " esta disponible" << endl;
    else
        cout << "El libro " << nombreProducto << " no esta disponible" << endl;
}

void Libro::muestraProducto() {
    cout << "Nombre: " << nombreProducto << endl;
    cout << "Autor: " << autor << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Year: " << year << endl;
    cout << "ISBN: " << isbn << endl;
}

#endif //BIBLIO_PRODUCTO_H