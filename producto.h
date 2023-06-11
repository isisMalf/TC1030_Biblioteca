/*
 * Proyecto Biblioteca
 * Isis Yaneth Malfavon Diaz
 * A01705838
 * 11/05/2023
 * Contiene la clase base Producto, asi como las clases derivadas:
 * Libro y PublicacionAcademica
 */

#ifndef BIBLIO_PRODUCTO_H
#define BIBLIO_PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>
#include "added.h" //biblioteca con los objetos a usar

using namespace std;

//Declaracion de la clase abstracta Producto
class Producto {

    //Declarar atributos
    protected:
        string nombreProducto;
        string autor;
        string editorial;
        int year;
        bool disponibilidad;
        Usuario poseedor; //Composicion con la clase Usuario

    //Declarar metodos
    public:
        //Declarar constructores
        Producto(); //por default
        Producto(string, string, string, int);
        Producto(string, string, string, int, Usuario); //Sobrecarga
        //Getters
        string getNombreProducto() {return nombreProducto;}
        string getAutor(){return autor;}
        string getEditorial() {return editorial;}
        int getYear() {return year;}
        bool getDisponibilidad() {return disponibilidad;}
        Usuario getPoseedor() { return poseedor;}
        //Setter
        void setDisponibilidad(bool _disp) {disponibilidad = _disp;}
        void setPoseedor(Usuario usu) {poseedor = usu;}
        //Metodos abtractos que seran sobreestrictos
        virtual string muestraProducto(Usuario*) = 0;
        virtual string muestraProducto() = 0; //Sobrecarga
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

//Constructor con parametros
Producto::Producto(string _nombreProducto, string _autor, string _editorial, int _year) {
    nombreProducto = _nombreProducto;
    autor = _autor;
    editorial = _editorial;
    year = _year;
    disponibilidad = true;
}

//Constructor con parametros y Usuario
Producto::Producto(string _nombreProducto, string _autor, string _editorial, int _year,  Usuario _poseedor) {
    nombreProducto = _nombreProducto;
    autor = _autor;
    editorial = _editorial;
    year = _year;
    disponibilidad = true;
    poseedor = _poseedor;
}

//Declaracion de PublicacionAcademica que hereda de Producto
class PublicacionAcademica: public Producto {

    //Atributos
    private:
        string citations; //Se refiere a en que otras publicaciones fue citado

    //Metodos
    public:
        //Constructores
        PublicacionAcademica(); //Por default
        PublicacionAcademica(string, string, string, int, string);
        PublicacionAcademica(string, string, string, int,  Usuario, string); //sobrecarga
        //Setter
        void setCitations(string); //Con el tiempo puede ser citado en otros lugares
        //Getter
        string getCitations(); //Se podria utilizar para buscar publicaciones relacionadas
        //Metodos adicionales
        string muestraProducto(Usuario*);
        string muestraProducto();
};

//METODOS DE PUBLICACION ACADEMICA ------------------------------------------------------------------------------------

//Constructor por default
PublicacionAcademica::PublicacionAcademica():Producto() {
    citations = "None";
}

//Constructor con parametros
PublicacionAcademica::PublicacionAcademica(string _nombreProducto, string _autor, string _editorial, int _year, string _citations) : Producto(_nombreProducto, _autor, _editorial, _year) {
    citations = _citations;
}

//Constructor con parametros y Usuario
PublicacionAcademica::PublicacionAcademica(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor, string _citations) : Producto(_nombreProducto, _autor, _editorial, _year, _poseedor) {
    citations = _citations;
}

//Setter
void PublicacionAcademica::setCitations(string _citations) {
    citations = _citations;
}

//Getter
string PublicacionAcademica::getCitations() {
    return citations;
}

/*
 * muestraProducto convierte atributos a string y los concatena para ser impresos
 *
 * @param
 * @return string con valores de los atributos y texto concatenados
 */

string PublicacionAcademica::muestraProducto(){
    stringstream aux;
    aux << "Nombre: " << nombreProducto << '\n' << "Autor: " << autor << '\n' << "Editorial: " << editorial << '\n' << "Year: " << year << '\n' << "Citations: " << citations << '\n' << "Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}

/*
 * muestraUsuario(Usuario) convierte atributos a string y los concatena para ser impresos
 *
 * Llama al metodo de Usuario muestraUsuario
 *
 * @param Usuario *usu, es un objeto creado de tipo Usuario
 * @return string con valores de los atributos y texto concatenados
 */

string PublicacionAcademica::muestraProducto(Usuario *usu){
    stringstream aux;
    string usuarioss;
    usuarioss = usu -> muestraUsuario();
    aux << "Nombre: " << nombreProducto << '\n' << "Autor: " << autor << '\n' << "Editorial: " << editorial << '\n' << "Year: " << year << '\n' << "Citations: " << citations << '\n' << "Disponibilidad: " << disponibilidad << '\n' << usuarioss << '\n';
    return aux.str();
}

//Declaracion de Libro que hereda de Producto
class Libro: public Producto {

    //Atributos
    private:
        int isbn;

    //Metodos
    public:
        //Constructores
        Libro(); //Por default
        Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn);
        Libro(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor,int _isbn); //Sobrecarga
        //Getter
        int getIsbn(); //Podria usarse para filtrar por isbn
        //Metodos adicionales
        string muestraProducto();
        string muestraProducto(Usuario*);

};

//METODOS DE LIBRO ----------------------------------------------------------------------------------------------------

//Constructor por default
Libro::Libro():Producto(){
    isbn = 0;
}

//Constructor con parametros
Libro::Libro(string _nombreProducto, string _autor, string _editorial, int _year, int _isbn) : Producto(_nombreProducto, _autor, _editorial, _year) {
    isbn = _isbn;
    disponibilidad = true;
}

//Constructor con parametros y Usuario
Libro::Libro(string _nombreProducto, string _autor, string _editorial, int _year, Usuario _poseedor, int _isbn) : Producto(_nombreProducto, _autor, _editorial, _year, _poseedor){
    isbn = _isbn;
}

//Getter
int Libro::getIsbn() {
    return isbn;
}

/*
 * muestraUsuario(Usuario) convierte atributos a string y los concatena para ser impresos
 *
 * @param
 * @return string con valores de los atributos y texto concatenados
 */

string Libro::muestraProducto() {
    stringstream aux;
    aux << "Nombre: " << nombreProducto << '\n' << "Autor: " << autor << '\n' << "Editorial: " << editorial << '\n' << "Year: " << year << '\n' << "ISBN: " << isbn << '\n' << "Disponibilidad: " << disponibilidad << "\n";
    return aux.str();
}

/*
 * muestraUsuario(Usuario) convierte atributos a string y los concatena para ser impresos
 *
 * Llama al metodo de Usuario muestraUsuario
 *
 * @param Usuario *usu, es un objeto creado de tipo Usuario
 * @return string con valores de los atributos y texto concatenados
 */

string Libro::muestraProducto(Usuario *usu){
    stringstream aux;
    string usuarioss;
    usuarioss = usu -> muestraUsuario();
    aux << "Nombre: " << nombreProducto << '\n' << "Autor: " << autor << '\n' << "Editorial: " << editorial << '\n' << "Year: " << year << '\n' << "ISBN: " << isbn << '\n' << "Disponibilidad: " << disponibilidad << '\n' << usuarioss << '\n';
    return aux.str();
}

#endif //BIBLIO_PRODUCTO_H