//
// Created by yanet on 24/05/2023.
//

#ifndef BIBLIO_ADDED_H
#define BIBLIO_ADDED_H

#include <iostream>

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
        void muestraUsuario();
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

void Usuario::muestraUsuario() {
    cout << "*** Los datos del poseedor actual son: ***" << endl;
    cout << "Id: " << id << endl;
    cout << "Telefono: " << numCel << endl;
    cout << "Nombre: " << nombreUsuario << endl;
    cout << "Fecha de inicio: " << fechaInicial << endl;
    cout << "Fecha de termino: " << fechaFinal << endl;
}

class Saga {
private:
    string nombreSaga;
    int numLibros;

public:
    //constructores
    Saga();
    Saga(string); //sobrecarga
    Saga(string,int);
    //setters
    void setNombreSaga(string);
    void setNumLibros(int);
    //getters
    string getNombreSaga();
    int getNumLibros();
};

//METODOS SAGA --------------------------------------------------------------------------------------------------

//constructores
Saga::Saga() {
    nombreSaga = "Peter";
    numLibros = 3;
}

Saga::Saga(string _nombreSaga) {
    nombreSaga = _nombreSaga;
}

Saga::Saga(string _nombreSaga, int _numLibros) {
    nombreSaga = _nombreSaga;
    numLibros = _numLibros;
}

//setters
void Saga::setNombreSaga(string _nombreSaga) {
    nombreSaga = _nombreSaga;
}

void Saga::setNumLibros(int _numLibros) {
    numLibros = _numLibros;
}

//getters
string Saga::getNombreSaga() {
    return nombreSaga;
}

int Saga::getNumLibros() {
    return numLibros;
}

#endif //BIBLIO_ADDED_H
