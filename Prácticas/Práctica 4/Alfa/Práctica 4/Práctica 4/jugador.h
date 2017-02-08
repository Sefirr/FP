#ifndef JUGADOR_H
#define JUGADOR_H

#include "listaedificios.h"

const int CHR = 50;
const int DINERO_INI = 3000;
const int MAX_EDIFICIOS = 20;
typedef int tArray[MAX_EDIFICIOS];

typedef struct {
	tArray elem;
	int cont;
} tComprados;

typedef struct{
	char usuario[CHR];
	char password[CHR];
	char universidad[CHR];
	int dinero;
	int prestigio;
	tComprados comprados;
}tJugador;

tJugador nuevoJugador();
void mostrarJugador(const tJugador jugador);
bool listaCompradosLlena(tJugador jugador);
void comprarEdificio(tJugador &jugador, tListaEdificios &lista);
#endif