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

// SON FUNCIONES BOOLEANAS YA QUE EXISTIA LA CONDICI�N DE QUE NO POD�AN ESCRIBIR NADA EN CONSOLA. SOLO DEVOLVER VALORES.
/* La funci�n booleana listaJugadoresLlena indica si la lista de jugadores est� llena. Devuelve un booleano que marca true si esta llena y false si no lo est�.
Constra de un par�metro lista que no se modifica ya que solo comprueba que la lista est� llena. No modifica nada.*/
bool listaJugadoresLlena(tListaJugadores lista);
/* La funci�n booleana buscarJugador busca un jugador en la lista en base a los datos que ha introducido el usuario. Si lo encuentra, la funci�n devuelve
un booleano con valor true. En caso contrario, false.
Consta de tres par�metros:
- El par�metro lista no se modifica ya que solo busca el jugador en la lista, es decir, es un par�metro de entrada.
- El par�metro buscado no se modifica ya que es un par�metro de entrada. 
- El par�metro pos si se modifica ya que la posici�n en la que se encuentra el jugador se modifica conforme se va buscando binariamente en la lista.*/
bool buscarJugador(tListaJugadores lista, tCadena buscado, int &pos);
/* La funci�n booleana insertarJugador inserta al nuevo jugador en la �ltima posici�n de la lista. Devuelve un booleano si se ha insertado con �xito.
Consta de un par�metro lista que se modifica ya que al insertar un jugador en la ultima posici�n de la lista est�s modificando la lista.*/
bool insertarJugador(tListaJugadores &lista, bool &valido);
/* La funci�n booleana bajaJugador, elimina a un jugador, as� como vuelve a poner disponibles los edificios que hab�a comprado dicho jugador.
Consta de tres par�metros:
- El par�metro listajugadores se modifica ya que al eliminar un jugador, est�s modificando la lista.
- El par�metro buscado no se modifica ya que es un par�metro de entrada.
- El par�metro listaedificios si que se modifica ya que vuelves a poner disponibles los edificios que ten�a el jugador.*/
bool bajaJugador(tListaJugadores &listajugadores, tCadena buscado, tListaEdificios &listaedificios, int &pos);


#endif