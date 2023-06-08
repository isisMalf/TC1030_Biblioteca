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
        //setter
        void setDisponibilidad(bool _disp) {
            disponibilidad = _disp;
        }

        //metodos adicionales
        virtual string muestraProducto(Usuario*) = 0; //para ver el objeto
        virtual string muestraProducto() = 0;
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
        string muestraProducto(Usuario*);
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

string PublicacionAcademica::muestraProducto(){
    stringstream aux;
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year << " Citations: " << citations << " Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}

//metodo para ver el objeto
string PublicacionAcademica::muestraProducto(Usuario *usu){
    stringstream aux;
    string usuarioss;
    usuarioss = usu -> muestraUsuario();
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year << " Citations: " << citations << " Disponibilidad: " << disponibilidad << usuarioss << endl;
    return aux.str();
}


class Libro: public Producto {
private:
    int isbn;

public:
    Libro();
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn);
    Libro(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor,int _isbn);

    //setter
    void setIsbn(int);
    //getter
    int getIsbn();
    //metodos adicionales
    string muestraProducto();
    string muestraProducto(Usuario*);

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

string Libro::muestraProducto() {
    stringstream aux;
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year << " ISBN: " << isbn << " Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}

string Libro::muestraProducto(Usuario *usu){
    stringstream aux;
    string usuarioss;
    usuarioss = usu -> muestraUsuario();
    aux << "Nombre: " << nombreProducto << " Autor: " << autor << " Editorial: " << editorial << " Year: " << year << " ISBN: " << isbn << " Disponibilidad: " << disponibilidad << usuarioss<< endl;
    return aux.str();
}

#endif //BIBLIO_PRODUCTO_H