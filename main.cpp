#include <iostream>

#include "biblioteca.h"
#include "producto.h"
#include "added.h"

int main() {
    //crear objeto biblioteca
    Biblioteca biblio1;

    //crear objeto de tipo libro
    Producto *a = new Libro("Corte de rosas","Sara J Maas", "Flor de loto", 2009, 334528);
    Producto *b = new PublicacionAcademica("Paper on physics", "Dr. Morales", "Tec de Monterrey", 2020, "none");

    //crear un usuario
    //Usuario persona1(789, 4423225905, "Maria", "04/03/2020", "04/04/2020");

    //Producto *c = new Libro("Diary of a kid","Sara J Maas", "Flor de loto", 2009, persona1 ,334528);

    biblio1.agregaProducto(a);
    biblio1.agregaProducto(b);
    //biblio1.agregaProducto(c);

    biblio1.checaDisponibilidad("Corte de rosas");
    biblio1.checaDisponibilidad("Paper on physics");
    biblio1.checaDisponibilidad("Diary of a kid");

    return 0;
}
