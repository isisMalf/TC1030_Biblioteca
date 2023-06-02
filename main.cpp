#include <iostream>
#include "biblioteca.h"

int main() {
    //crear objeto biblioteca
    Biblioteca BiblioTec("Biblioteca Tec", "Tec Campus Qro", 10,10);

    //crear objeto de tipo libro
    Producto a* = new Libro();
    Producto b* = new PublicacionAcademica();

    BiblioTec.agregaLibro(a);
    BiblioTec.agregaPubAcademica(b);

    return 0;
}
