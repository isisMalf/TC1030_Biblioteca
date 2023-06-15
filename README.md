Isis Malfavon A01705838

# TC1030_Biblioteca

Este proyecto trata sobre una biblioteca a la cual le puedes agregar libros o publicaciones academicas por medio de donaciones. Ademas, se pueden hacer prestamos con lo cual se revisa con el nombre del libro si esta disponible o no, si esta disponible se cambia el estatus de disponibilidad y se agrega en poseedor la informacion del usuario que pidio el libro. Si no esta disponible se muestra que no esta disponible. Por otro lado, si se hace una devolucion se cambia el estatus de disponibilidad. 

## Funcionalidad 

El programa solo acepta libros o publicaciones academicas.

Los prestamos y devoluciones solo se pueden hacer con el nombre de material como filtro. 

Si no utilizas la opcion de "realizar una donacion" antes de un pedido regresa que no se encuentra el material porque aun no hay ningun material en biblioteca, donar es la forma en la que se crean objetos. 

Tiene un menu y corre en consola.

## Consideraciones

El programa asume que el usuario ingresara el tipo de dato correcto. Ej. Si pide un numero de telefono que se ingresara un int. Si se ingresa el tipo de dato incorrecto hay un error. 

El programa corre en consola y esta escrito en c++ standard, asi que corre en todos los sistemas operativos. 
compilar con: "g++ added.h usuario.h producto.h biblioteca.h main.cpp"

Correr en linux: "/a.out"

Correr en windows: "a.exe"
