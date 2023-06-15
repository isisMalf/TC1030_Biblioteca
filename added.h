/*
 * Proyecto Biblioteca
 * Isis Yaneth Malfavon Diaz
 * A01705838
 * 11/05/2023
 * Contiene la clase Usuario que compone a la clase Producto.
 */


#ifndef BIBLIO_ADDED_H
#define BIBLIO_ADDED_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Declaracion de la clase Usuario
class Usuario {

    //Declaracion de atributos
private:
    int id;
    int numCel;
    string nombreUsuario;
    int fechaInicial;
    int fechaFinal;

    //Declaracion de metodos
public:
    //Constructores
    Usuario(); //por default
    Usuario(int,int,string); //con parametros
    //Setters
    void setNombreUsuario(string);
    void setIdUsuario(int);
    void setNumCel(int);
    void setFechaInicial(int);
    void setFechaFinal(int);
    //Getters
    int getId(); //Se podria utilizar para filtrar por ID del usuario
    string getNombreUsuario(); //Se podria utilizar para filtrar por nombre del usuario
    int getFechaFinal();
    //Metodos adicionales
    string muestraUsuario(); //Visualizar el usuario
};

//Constructor por default
Usuario::Usuario(){
    id = 0;
    numCel = 0;
    nombreUsuario = "Desconocido";
    fechaInicial = 0;
    fechaFinal = 0;
}

//Constructor con parametros
Usuario::Usuario(int _id, int _numCel, string _nombreUsuario){
    id = _id;
    numCel = _numCel;
    nombreUsuario = _nombreUsuario;
    fechaInicial = 0;
    fechaFinal = 0;
}

//Setters
void Usuario::setNombreUsuario(string _nomUsuario) {
    nombreUsuario = _nomUsuario;
}

void Usuario::setIdUsuario(int _idUsuario) {
    id = _idUsuario;
}

void Usuario::setNumCel(int _numCel) {
    numCel = _numCel;
}

void Usuario::setFechaInicial(int _fechaInicial) {
    fechaInicial = _fechaInicial;
}

void Usuario::setFechaFinal(int _fechaFinal) {
    fechaFinal = _fechaFinal;
}

//Getters
int Usuario::getId() {
    return id;
}

string Usuario::getNombreUsuario() {
    return nombreUsuario;
}

int Usuario::getFechaFinal() {
    return fechaFinal;
}

/*
 * muestraUsuario convierte atributos a string y los concatena para ser impresos
 *
 * @param
 * @return string con valores de los atributos y texto concatenados
 */

string Usuario::muestraUsuario() {
    stringstream aux;
    aux << "Nombre: " << nombreUsuario << '\n' << "ID: " << id << '\n' << "Telefono: " << numCel << '\n' << "Fecha de inicio: " << fechaInicial << '\n' << "Fecha de termino: " << fechaFinal << "\n";
    return aux.str();
}

#endif
