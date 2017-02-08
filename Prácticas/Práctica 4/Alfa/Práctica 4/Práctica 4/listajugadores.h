#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H
#include "jugador.h"

const int N = 20;
typedef tJugador tLista[N];
typedef struct{
	tLista jugador;
	int cont;
}tListaJugadores;

bool listaJugadoresLlena(tListaJugadores lista);
int buscarJugador(tListaJugadores lista, char buscado[N]);
void insertarJugador(tListaJugadores &lista);
void bajaJugador(tListaJugadores &lista);


#endif