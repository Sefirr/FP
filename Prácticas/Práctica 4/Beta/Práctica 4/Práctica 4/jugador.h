#ifndef JUGADOR_H
#define JUGADOR_H

#include "listaedificios.h"
#include "constants.h"

typedef int tArray[MAX_EDIFICIOS];

typedef struct {
	tArray elem;
	int cont;
} tComprados;

typedef struct{
	tCadena usuario;
	tCadena password;
	tCadena universidad;
	int dinero;
	int prestigio;
	tComprados comprados;
}tJugador;

tJugador nuevoJugador();
void mostrarJugador(const tJugador jugador);
bool listaCompradosLlena(const tJugador jugador);
void comprarEdificio(tJugador &jugador, tListaEdificios &lista);

#endif