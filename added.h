//
// Created by yanet on 24/05/2023.
//

#ifndef BIBLIO_ADDED_H
#define BIBLIO_ADDED_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//agregacion
class Usuario {
    private:
        int id;
        int numCel;
        string nombreUsuario;
        string fechaInicial;
        string fechaFinal;

    public:
        //constructores
        Usuario(); //por default
        Usuario(int,int,string,string,string);
        //setters
        void setId(int);
        void setNumCel(int);
        void setNombreUsuario(string);
        void setFechaInicial(string);
        void setFechaFinal(string);
        //getters
        int getId();
        int getNumCel();
        string getNombreUsuario();
        string getFechaInicial();
        string getFechaFinal();
        //otros
        //void muestraUsuario();
        string muestraUsuario();
};

//METODOS USUARIO -----------------------------------------------------------------------------------------

//constructor por default
Usuario::Usuario(){
    id = 0;
    numCel = 0;
    nombreUsuario = "Desconocido";
    fechaInicial = "N/A";
    fechaFinal = "N/A";
}

//constructor
Usuario::Usuario(int _id, int _numCel, string _nombreUsuario, string _fechaInicial, string _fechaFinal){
    id = _id;
    numCel = _numCel;
    nombreUsuario = _nombreUsuario;
    fechaInicial = _fechaInicial;
    fechaFinal = _fechaFinal;
}

//setters
void Usuario::setId(int _id) {
    id = _id;
}

void Usuario::setNumCel(int _numCel) {
    numCel = _numCel;
}

void Usuario::setNombreUsuario(string _nombreUsuario) {
    nombreUsuario = _nombreUsuario;
}

void Usuario::setFechaInicial(string _fechaInicial) {
    fechaInicial = _fechaInicial;
}

void Usuario::setFechaFinal(string _fechaFinal) {
    fechaFinal = _fechaFinal;
}
//getters
int Usuario::getId() {
    return id;
}

int Usuario::getNumCel() {
    return numCel;
}

string Usuario::getNombreUsuario() {
    return nombreUsuario;
}

string Usuario::getFechaInicial() {
    return fechaInicial;
}

string Usuario::getFechaFinal() {
    return fechaFinal;
}

string Usuario::muestraUsuario() {
    stringstream aux;
    aux << "Nombre: " << nombreUsuario << " Id: " << id << " Telefono: " << numCel << " Fecha de inicio: " << fechaInicial << " Fecha de termino: " << fechaFinal << "\n";
    return aux.str();
}
#endif
