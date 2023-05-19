# TC1030_Biblioteca

Este proyecto trata sobre una biblioteca a la cual le puedes agregar libros o publicaciones academicas. Ademas, se pueden hacer pedidos con lo cual se revisa con el nombre del libro si esta disponible o no, si esta disponible se cambia el estatus de disponibilidad y se agrega en poseedor la informacion del usuario que pidio el libro. Si no esta disponible se muestra que no esta disponible asi como la informacion del usuario que lo tiene en ese momento y la fecha de regreso del libro. Por otro lado, si se hace una devolucion se cambia el estatus de disponibilidad y se regresa el atributo poseedor al default. 
Ademas, si lo que se pide es un libro que pertenece a una saga, se muestra como recomendacion pedir los demas libros tambien, para este contexto se considera que una saga consta de dos a seis libros. 

## Funcionalidad 

El programa solo acepta libros o publicaciones academicas.

Tiene un menu y corre en consola.

## Consideraciones

El programa corre en consola y esta escrito en c++ standard, asi que corre en todos los sistemas operativos. 
compilar con: "g++ usuario.h producto.h biblioteca.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"
