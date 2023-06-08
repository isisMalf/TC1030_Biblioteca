//
// Created by yanet on 23/05/2023.
//

#ifndef BIBLIO_PRODUCTO_H
#define BIBLIO_PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>
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
        Producto(string, string, string, int, Usuario);

        //getters
        string getNombreProducto() {return nombreProducto;}
        string getAutor(){return autor;}
        string getEditorial() {return editorial;}
        int getYear() {return year;}
        bool getDisponibilidad() {return disponibilidad;}
        Usuario getPoseedor() { return poseedor;}

        //metodos adicionales
        //virtual void checaDisponibilidad(string) = 0; //para revisar si esta disponible o no
        virtual string muestraProducto() = 0; //para ver el objeto
};

//METODOS PRODUCTO --------------------------------------------------------------------------------------------------

//Constructor por default
Producto::Producto(){
    nombreProducto = "Desconocido";
    autor = "Desconocido";
    editorial = "Desconocido";
    year = 0;
    disponibilidad = true;
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
Producto::Producto(string _nombreProducto, string _autor, string _editorial, int _year,  Usuario _poseedor) {
    nombreProducto = _nombreProducto;
    autor = _autor;
    editorial = _editorial;
    year = _year;
    disponibilidad = true;
    poseedor = _poseedor;
}

/*bool Producto::checaDisponibilidad() {
    cout << "Checar disponibilidad" << endl;
}

void Producto::muestraProducto() {
    cout << "El producto es: " << endl;
}
*/

//clase hija de Producto
class PublicacionAcademica: public Producto {

    private:
        //tal vez citations deba de ser un arreglo
        string citations;

    public:
        //constructores
        PublicacionAcademica();
        PublicacionAcademica(string, string, string, int, string);
        PublicacionAcademica(string, string, string, int,  Usuario, string);
        //setter
        void setCitations(string);
        //getter
        string getCitations();
        //metodos adicionales
        //void checaDisponibilidad(string);
        string muestraProducto();
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
PublicacionAcademica::PublicacionAcademica(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor, string _citations) : Producto(_nombreProducto, _autor, _editorial, _year, _poseedor) {
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
/*
void PublicacionAcademica::checaDisponibilidad(string) {
    if (disponibilidad == true)
        cout << "La publicacion academica " << nombreProducto << " esta disponible" << endl;
    else
        cout << "La publicacion academica " << nombreProducto << " no esta disponible" << endl;
}
*/

//metodo para ver el objeto
string PublicacionAcademica::muestraProducto() {
    stringstream aux;
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year
        << " Citations: " << citations << " Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}


class Libro: public Producto {
private:
    int isbn;
    //Saga sagas[10]

public:
    Libro();
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn);
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor,int _isbn);
    //Libro(string _nombreProducto, string _autor, string _editorial, int _year, bool _disponibilidad,int _isbn, Saga _sagas);
    //setter
    void setIsbn(int);
    //getter
    int getIsbn();
    //metodos adicionales
    //void checaDisponibilidad();
    //void pedirSaga(string);
    string muestraProducto();

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
Libro::Libro(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor, int _isbn) : Producto(_nombreProducto, _autor, _editorial, _year, _poseedor){
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
/*
//metodos adicionales
bool Libro::checaDisponibilidad() {
    if (disponibilidad == true)
        cout << "El libro " << nombreProducto << " esta disponible" << endl;
    else
        cout << "El libro " << nombreProducto << " no esta disponible" << endl;
}
*/

string Libro::muestraProducto() {
    stringstream aux;
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year << " ISBN: " << isbn << " Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}

#endif //BIBLIO_PRODUCTO_H