#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H

#include <cstring>
using namespace std;
#include "jugador.h"
#include "listaedificios.h"
#include "constants.h"

typedef tJugador tLista[MAX_USUARIOS];

typedef struct{
	tLista jugador;
	int cont;
}tListaJugadores;

bool listaJugadoresLlena(tListaJugadores lista);
bool buscarJugador(tListaJugadores lista, tCadena buscado, int &pos);
bool insertarJugador(tListaJugadores &lista);
bool bajaJugador(tListaJugadores &listajugadores, tCadena buscado, tListaEdificios &listaedificios);


#endif