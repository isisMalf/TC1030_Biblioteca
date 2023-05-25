#include <iostream>
#include "biblioteca.h"

int main() {
    //crear objeto biblioteca
    Biblioteca BiblioTec("Biblioteca Tec", "Tec Campus Qro");

    //crear objeto de tipo libro
    Libro libro1("Harry Potter", "J.K. Rowling", "Fortuna", 2006, 4565132);
    libro1.muestraProducto(); //mostrar el objeto

    //crear objeto de tipo publicacion academica
    PublicacionAcademica pub1("Sciencias Basicas", "Green, H.", "Estrellas", 2020, "None");
    pub1.muestraProducto(); //mostrar el objeto

    return 0;
}
