/*
 * Proyecto Biblioteca
 * Isis Yaneth Malfavon Diaz
 * A01705838
 * 11/05/2023
 * Contiene la clase Biblioteca que funciona como un catalogo pues es
 * donde se guardan los objetos Libro y PublicacionAcademica creados.
 * Ademas, es donde estan todas las operaciones realizables: donar, prestamo,
 * devolucion. Es la utilizada en el main.
 */

#ifndef BIBLIO_BIBLIOTECA_H
#define BIBLIO_BIBLIOTECA_H

#include <iostream>
#include <string>
#include <sstream>
#include "producto.h" //biblioteca con los objetos a usar

using namespace std;

//Declaracion de la clase Biblioteca
class Biblioteca {

    //Atributos
    private:
        string nombreBiblio;
        Producto *productos[100]; //Definido como apuntador para usar polimorfismo
        int indice; //Registra cuantos productos hay

    //Metodos
    public:
        //Constructores
        Biblioteca(); //Por default
        Biblioteca(string); //Sobrecarga
        //Setter
        void setNombreBiblio(string); //Por si hay un cambio de administracion de la biblioteca y tiene que cambiar de nombre
        //Getter
        string getNombreBiblio();
        //Metodos adicionales
        void agregaProducto(Producto*);
        void prestamo(string, Usuario, int, int);
        void devolucion(string, Usuario*);
};

//Constructor por default
Biblioteca::Biblioteca() {
    nombreBiblio = "Biblioteca Tec";
    indice = 0;
}

//Constructor con parametros
Biblioteca::Biblioteca(string _nombreBiblio) {
    nombreBiblio = _nombreBiblio;
    indice = 0;
}

//definir setters
void Biblioteca::setNombreBiblio(string _nombreBiblio) {
    nombreBiblio = _nombreBiblio;
}

//definir los getters
string Biblioteca::getNombreBiblio() {
    return nombreBiblio;
}

/*
 * agregaProducto agrega un objeto al arreglo de productos
 *
 * Recibe un objeto Producto que utilizando polimorfismo puede
 * ser Libro o PublicacionAcademica, y lo agrega al arreglo de productos
 * usando la variable indice, y le suma 1.
 *
 * @param objeto de tipo Producto
 * @return
 */

void Biblioteca::agregaProducto(Producto *prod)  {
    productos[indice] = prod;
    indice++;
}

/*
 * prestamo realiza un prestamo de libro si este esta disponible y
 * lo asigna al usuario, asi como establece fecha de regreso.
 *
 * Checa si el libro pedido se encuentra en la biblioteca revisando el
 * arreglo de productos, si lo encuentra y esta disponible cambia su estatus
 * a 'no disponible', utiliza setPoseedor para que el usuario forme
 * parte del libro (composicion) como poseedor, y cambia la fecha inicial y final
 * por las que recibe. Finalmente, muestra el libro y el poseedor con la
 * informacion actualizada. Si no esta disponible imprime 'No esta disponible'
 * y si no existe el libro en la biblioteca imprime 'No se encontraron resultados'.
 *
 * @param string nombre del libro, Usuario usu, int fecha inicial, int fecha final
 * @return
 */

void Biblioteca::prestamo(string _nombre, Usuario usu, int f_ini, int f_fin) {

    bool found = false;

    for(int i = 0; i < indice; i++){

        if(productos[i]-> getNombreProducto() == _nombre){

            if (productos[i] -> getDisponibilidad() == true){

                productos[i] -> setDisponibilidad(false);
                productos[i] -> setPoseedor(usu);
                usu.setFechaInicial(f_ini);
                usu.setFechaFinal(f_fin);
                cout << productos[i] -> muestraProducto();
                cout << "La fecha de devolucion es: " << usu.getFechaFinal();
            }

            else {
                cout << "No esta disponible" << endl;
            }

            found = true;
        }
    }

    if (found == false) {
        cout << "No se encontraron resultados" << endl;
    }
}

/*
 * devolucion realiza una devolucion de libro al volverlo disponible y
 * mostrar la informacion actualizada.
 *
 * Checa si el libro pedido se encuentra en la biblioteca revisando el
 * arreglo de productos, si lo encuentra y no esta disponible (eso significa
 * que si fue prestado), cambia el estatus a 'disponible' e imprime la
 * informacion actualizada. Si el libro no fue prestado (disponibilidad = true)
 * imprime que el libro ya se encuentra disponible asi que no se puede
 * hacer una devolucion.
 *
 * @param string nombre del libro, Usuario usu
 * @return
 */

void Biblioteca::devolucion(string _nombre, Usuario *usu) {

    bool found = false;

    for(int i =0; i < indice; i++){

        if(productos[i]-> getNombreProducto() == _nombre){

            if (productos[i] -> getDisponibilidad() == false){
                productos[i] -> setDisponibilidad(true);
                cout << productos[i] -> muestraProducto(usu);
            }

            else {
                cout << "Este libro esta disponible, por lo que no se puede realizar una devolucion" << endl;
            }

            found = true;
        }
    }

    if (found == false) {
        cout << "No se encontraron resultados" << endl;
    }
}

#endif //BIBLIO_BIBLIOTECA_H