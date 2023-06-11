/*
 * Proyecto Biblioteca
 * Isis Yaneth Malfavon Diaz
 * A01705838
 * 11/05/2023
 *
 * Este es un programa que simula de forma basica una biblioteca.
 * Se pueden realizar operaciones basicas como hacer una donacion
 * de material a la biblioteca, pedir un material prestado, devolver
 * el material y salir.
 */

#include <iostream> //Para imprimir
#include <string>

#include "biblioteca.h" //biblioteca con los objetos a usar

using namespace std;

int main() {
    //Variables
    bool seguir = true; //Para checar si se quieren seguir eligiendo opciones
    //Parametros para constructores
    int respuesta,id_usuario, tel_usuario, f_ini, f_fin, donacion;
    string nombreBiblio, nombre_usuario;

    cout << "***Bienvenid@ a la biblioteca digital*** " << '\n' << "Ingrese el nombre de la biblioteca a la que desea acceder: " << endl;
    cin >> nombreBiblio;

    Biblioteca biblio(nombreBiblio); //Crear un objeto Biblioteca

    //Ingresar parametros
    cout << "*Ingrese su usuario por favor* " << endl;
    cout << "Nombre de usuario: " << endl;
    cin >> nombre_usuario;
    cout << "ID: " << endl;
    cin >> id_usuario;
    cout << "Numero de telefono: " << endl;
    cin >> tel_usuario;

    Usuario persona(id_usuario, tel_usuario, nombre_usuario); //Crear un objeto Usuario

    //While para que siga permitiendo acciones hasta que se elija 4. Salir
    while (seguir == true) {

        //Mostrar las opciones
        cout << '\n' << " ---- Biblioteca " << biblio.getNombreBiblio() << " ----" << '\n';
        cout << "Elija una de las siguientes opciones: " << endl;
        cout << "1. Realizar una donacion " << endl;
        cout << "2. Realizar un prestamo " << endl;
        cout << "3. Realizar una devolucion " << endl;
        cout << "4. Salir " << endl;
        cout << "Favor de ingresar el numero de la opcion: " << '\n';
        cin >> respuesta;

        //Checar que elijan una opcion existente
        if (respuesta < 1 || respuesta > 4) {
            cout << "Esta opcion es invalida, por favor elija de nuevo: " << endl;
        }

        //Realizar una donacion
        else if (respuesta == 1){
            //Elegir tipo de objeto a crear
            cout <<'\n' << "Que tipo de material desea donar? " << endl;
            cout << "1. Libro " << endl;
            cout << "2. Publicacion Academica " << endl;
            cout << "Favor de ingresar el numero de la opcion " << endl;
            cin >> donacion;

            //Crear objeto Libro
            if (donacion == 1) {
                //Parametros
                string nombre_libro, autor_libro, editorial_libro;
                int year_libro, isbn_libro;

                //Pedir parametros
                cout << '\n' << "Ingrese los datos del libro: " << endl;
                cout << "Nombre: " << endl;
                cin >> nombre_libro;
                cout << "Autor: " << endl;
                cin >> autor_libro;
                cout << "Editorial: " << endl;
                cin >> editorial_libro;
                cout << "Año de publicacion: " << endl;
                cin >> year_libro;
                cout << "ISBN: " << endl;
                cin >> isbn_libro;

                Producto *a = new Libro(nombre_libro, autor_libro, editorial_libro, year_libro, isbn_libro); //Creacion del objeto
                biblio.agregaProducto(a); //Agregar el objeto a productos

                cout << "Agradecemos su donacion :) " << endl;
            }

            //Crear objeto PublicacionAcademica
            else if (donacion == 2) {
                //Parametros
                string nombre_pub, autor_pub, editorial_pub, citas_pub;
                int year_pub;

                //Ingresar parametros
                cout << '\n' << "Ingrese los datos de la publicacion academica: " << endl;
                cout << "Nombre: " << endl;
                cin >> nombre_pub;
                cout << "Autor: " << endl;
                cin >> autor_pub;
                cout << "Editorial: " << endl;
                cin >> editorial_pub;
                cout << "Año de publicacion: " << endl;
                cin >> year_pub;
                cout << "Citas (nombres de articulos donde ha sido citado): " << endl;
                cin >> citas_pub;

                Producto *b = new PublicacionAcademica(nombre_pub, autor_pub, editorial_pub, year_pub, citas_pub); //Crear objeto
                biblio.agregaProducto(b); //Agregarlo a productos

                cout << "Agradecemos su donacion :) " << endl;
            }

            else {
                cout << "Esta opcion es invalida" << endl; //Imprimir si eligen una opcion no existente
            }
        }

        //Prestamo
        else if (respuesta == 2) {
            string nombre_producto;

            cout << '\n' << "Ingrese el nombre del material que desea pedir prestado: " << endl;
            cin >> nombre_producto; //Pedir nombre del material
            cout << "Fecha de inicio (solo dia): " << endl; //Pedir el numero de dia actual
            cin >> f_ini;
            f_fin = f_ini + 5; //Se prestan los materiales por 5 dias
            /*
             * Como regresa el dia de devolucion, asume que todos los meses son de 31 dias
             * y si al sumarle los 5 dias se pasa de 31, regresa el dia de devolucion del siguiente mes.
             */
            if (f_fin > 31) {
                f_fin = f_fin - 31;
            }

            biblio.prestamo(nombre_producto, persona, f_ini, f_fin); //Realizar el prestamo
        }

        //Devolucion
        else if (respuesta == 3) {
            string nombre_producto;

            cout << '\n' << "Ingrese el nombre del material que desea devolver: " << endl; //Pedir el nombre del material
            cin >> nombre_producto;

            biblio.devolucion(nombre_producto, &persona); //Realizar la devolucion
        }

        //Salir
        else {
            seguir = false; //Cambiar el estatus de 'seguir' para detener el while
        }
    }

    return 0;
}
