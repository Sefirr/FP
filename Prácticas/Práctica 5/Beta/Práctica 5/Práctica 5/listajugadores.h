#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H

#include <cstring>
using namespace std;
#include "jugador.h"
#include "listaedificios.h"
#include "constants.h"

//Array de la lista de jugadores.
typedef tJugador *tLista;

//Lista de longitud variable de la lista de jugadores.
typedef struct{
	tLista jugador;
	int capacidad;
	int cont;
}tListaJugadores;

// SON FUNCIONES BOOLEANAS YA QUE EXISTIA LA CONDICIÓN DE QUE NO PODÍAN ESCRIBIR NADA EN CONSOLA. SOLO DEVOLVER VALORES.
/* La función booleana listaJugadoresLlena indica si la lista de jugadores está llena. Devuelve un booleano que marca true si esta llena y false si no lo está.
Constra de un parámetro lista que no se modifica ya que solo comprueba que la lista esté llena. No modifica nada.*/
bool listaJugadoresLlena(tListaJugadores lista);
/* La función booleana buscarJugador busca un jugador en la lista en base a los datos que ha introducido el usuario. Si lo encuentra, la función devuelve
un booleano con valor true. En caso contrario, false.
Consta de tres parámetros:
- El parámetro lista no se modifica ya que solo busca el jugador en la lista, es decir, es un parámetro de entrada.
- El parámetro buscado no se modifica ya que es un parámetro de entrada. 
- El parámetro pos si se modifica ya que la posición en la que se encuentra el jugador se modifica conforme se va buscando binariamente en la lista.*/
bool buscarJugador(tListaJugadores lista, tCadena buscado, int &pos);
/* La función booleana insertarJugador inserta al nuevo jugador en la última posición de la lista. Devuelve un booleano si se ha insertado con éxito.
Consta de un parámetro lista que se modifica ya que al insertar un jugador en la ultima posición de la lista estás modificando la lista.*/
bool insertarJugador(tListaJugadores &lista, bool &valido);
/* La función booleana bajaJugador, elimina a un jugador, así como vuelve a poner disponibles los edificios que había comprado dicho jugador.
Consta de tres parámetros:
- El parámetro listajugadores se modifica ya que al eliminar un jugador, estás modificando la lista.
- El parámetro buscado no se modifica ya que es un parámetro de entrada.
- El parámetro listaedificios si que se modifica ya que vuelves a poner disponibles los edificios que tenía el jugador.*/
bool bajaJugador(tListaJugadores &listajugadores, tCadena buscado, tListaEdificios &listaedificios, int &pos);


#endif