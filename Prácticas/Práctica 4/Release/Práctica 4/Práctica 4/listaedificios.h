#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include <iostream>
using namespace std;
#include <fstream>
#include "edificios.h"
#include "constants.h"

// Array del n�mero m�ximo de edificios
typedef tEdificio tEdificios[MAX_EDIFICIOS];

//Lista de longitud variable de la lista de edificios.
typedef struct {
	tEdificios edificios;
	int cont;
} tListaEdificios;

// SON FUNCIONES BOOLEANAS YA QUE EXISTIA LA CONDICI�N DE QUE NO POD�AN ESCRIBIR NADA EN CONSOLA. SOLO DEVOLVER VALORES.
/* La funci�n booleana listsEdificiosLlena indica si la lista de edificios est� llena.
Consta de un par�metro lista que no se modifica ya que solo mira el contador de edificios, no modifica nada.*/
bool listaEdificiosLlena(tListaEdificios lista);
/* La funci�n booleana buscarEdificio busca un edificio en la lista gracias a un c�digo proporcionado por el usuario. 
Si lo encuentra, lo indica devolviendo un booleano con el valor true. En caso contrario, false.
Consta de tres par�metros:
- El par�metro lista no se modifica ya que solo busca si el edificio est� en la lista y devuelve el boleano con el valor correspondiente.
No modifica nada.
-El par�metro buscado es de entrada. Con lo cu�l no modifica nada.
-El parametro pos si que se modifica ya que se necesita saber la posici�n en la que se encuentra el edificio en el caso en que se encuentre.*/
bool buscarEdificio(tListaEdificios lista, int buscado, int &pos);
/* La funci�n booleana insertarEdificio, una vez ha recibido la estructura tEdificio del nuevo edificio, la inserta en la posici�n correspondiente
de la lista ordenada por c�digos. Devuelve un booleano que indifica si se ha insertado el edificio o no.
Consta de un parametro lista que si se modifica ya que al insertar un nuevo edificio en la lista de edificios, estas modificando la lista de edificios. */
bool insertarEdificio(tListaEdificios &lista);
/* La funci�n booleana bajaEdificio se sirve de la funci�n buscarEdificio para saber si el edificio que queremos borrar existe. Si existe, borra el edificio.
En caso contrario, lo que no existe no se puede borrar. Es trivial. Devuelve un booleano para saber si se ha borrado el edificio o no.*/
bool bajaEdificio(tListaEdificios &lista, int buscado);

#endif