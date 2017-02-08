#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include <iostream>
using namespace std;
#include <fstream>
#include "edificios.h"
#include "constants.h"

// Array del número máximo de edificios
typedef tEdificio tEdificios[MAX_EDIFICIOS];

//Lista de longitud variable de la lista de edificios.
typedef struct {
	tEdificios edificios;
	int cont;
} tListaEdificios;

// SON FUNCIONES BOOLEANAS YA QUE EXISTIA LA CONDICIÓN DE QUE NO PODÍAN ESCRIBIR NADA EN CONSOLA. SOLO DEVOLVER VALORES.
/* La función booleana listsEdificiosLlena indica si la lista de edificios está llena.
Consta de un parámetro lista que no se modifica ya que solo mira el contador de edificios, no modifica nada.*/
bool listaEdificiosLlena(tListaEdificios lista);
/* La función booleana buscarEdificio busca un edificio en la lista gracias a un código proporcionado por el usuario. 
Si lo encuentra, lo indica devolviendo un booleano con el valor true. En caso contrario, false.
Consta de tres parámetros:
- El parámetro lista no se modifica ya que solo busca si el edificio está en la lista y devuelve el boleano con el valor correspondiente.
No modifica nada.
-El parámetro buscado es de entrada. Con lo cuál no modifica nada.
-El parametro pos si que se modifica ya que se necesita saber la posición en la que se encuentra el edificio en el caso en que se encuentre.*/
bool buscarEdificio(tListaEdificios lista, int buscado, int &pos);
/* La función booleana insertarEdificio, una vez ha recibido la estructura tEdificio del nuevo edificio, la inserta en la posición correspondiente
de la lista ordenada por códigos. Devuelve un booleano que indifica si se ha insertado el edificio o no.
Consta de un parametro lista que si se modifica ya que al insertar un nuevo edificio en la lista de edificios, estas modificando la lista de edificios. */
bool insertarEdificio(tListaEdificios &lista);
/* La función booleana bajaEdificio se sirve de la función buscarEdificio para saber si el edificio que queremos borrar existe. Si existe, borra el edificio.
En caso contrario, lo que no existe no se puede borrar. Es trivial. Devuelve un booleano para saber si se ha borrado el edificio o no.*/
bool bajaEdificio(tListaEdificios &lista, int buscado);

#endif