#ifndef JUGADOR_H
#define JUGADOR_H

#include "listaedificios.h"
#include "constants.h"

// Array de la lista de edificios comprados por el jugador.
typedef int tArray[MAX_EDIFICIOS];

// Lista de longitud variable de la lista de edificios comprados por el jugador.
typedef struct {
	tArray elem;
	int cont;
} tComprados;

// Estructura del jugador con sus correspondientes datos.
typedef struct{
	tCadena usuario;
	tCadena password;
	tCadena universidad;
	int dinero;
	int prestigio;
	tComprados comprados;
}tJugador;

/* La funcion nuevoJugador de tipo tJugador devuelve una estructura tJugador debidamente inicializada. Es la funcion encargada de crear un nuevo jugador.
No necesita par�metros.*/
tJugador nuevoJugador();
/*El procedimiento mostrarJugador muestra un jugador cualquiera, as� como sus caracter�sticas y su lista de edificios comprados. 
Consta de tres par�metros:
- El par�metro jugador no se modifica ya que el procedimiento no modifica la estructura tJugador.
- El par�metro lista no se modifica ya que el procedimiento no modifica la lista de edificios que ha comprado el jugador, solo los muestra. */
void mostrarJugador(tJugador jugador, tListaEdificios lista);
/* La funci�n booleana listaCompradosLlena indica si la lista de edificios comprados por el jugador est� llena. Al no modificar la estructura, el par�metro tJugador jugador no lleva ampersant.*/
bool listaCompradosLlena(tJugador jugador);
/* El procedimiento comprarEdificio permite al jugador realizar la comprar de un edificio, simplemente insertando su c�digo comprobando si el c�digo
que el usuario a introducido existe, es de un edificio disponible y si, y solo si, el jugador tiene el dinero suficiente para comprar el edificio.
Constra de dos par�metros:
- El par�metro jugador si se modifica ya que cuando compras un edificio a�ades el c�digo del edificio comprado a la lista de edificios comprados por
el jugador.
- El par�metro lista si se modifica ya que cuando compras un edificio, autom�ticamente cambias el estado del edificio a COMPRADO. Con lo cual est�s
modificando la lista. */
void comprarEdificio(tJugador &jugador, tListaEdificios &lista);

#endif