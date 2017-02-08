#include <iostream>
#include <cstring>
using namespace std;
#include "listaedificios.h"
#include "listajugadores.h"


bool listaJugadoresLlena(tListaJugadores lista) {
	bool completa;

	if(lista.cont < MAX_USUARIOS)
		completa = false;
	else
		completa = true;

	return completa;

}

bool buscarJugador(tListaJugadores lista, tCadena buscado, int &pos) {
	int ini = 0, fin = lista.cont, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (strcmp( buscado, lista.jugador[mitad].usuario) == 0) encontrado = true;
		else if (strcmp(buscado, lista.jugador[mitad].usuario) < 0) fin = mitad - 1;
		else ini = mitad + 1;
	}

	if (encontrado)
		pos = mitad;
	else 
		pos = - 1;

	return encontrado;
}

bool insertarJugador(tListaJugadores &lista, bool &valido) {
	bool correcto = true;
	valido = true;
	tJugador Jugador_new = nuevoJugador();
	int pos;

	if(listaJugadoresLlena(lista) || buscarJugador(lista, Jugador_new.usuario, pos)) {
		correcto = false;
		valido = true;
	}
	else if(strcmp(Jugador_new.usuario, "salir") == 0 || strcmp(Jugador_new.usuario, "admin") == 0)
		valido = false;
	else if(!listaJugadoresLlena(lista) && !buscarJugador(lista, Jugador_new.usuario, pos)) {
		lista.jugador[lista.cont] = Jugador_new;
		lista.cont++;
	}

	return correcto;
}

bool bajaJugador(tListaJugadores &listajugadores, tCadena buscado, tListaEdificios &listaedificios, int &pos) {
	bool correcto = true;

	if(!buscarJugador(listajugadores, buscado, pos)) 
		correcto = false;
	else {
		for(int i = 0; i < listajugadores.jugador[i].comprados.cont; i++) {
			if(buscarEdificio(listaedificios, listajugadores.jugador[pos].comprados.elem[i], pos))
				listaedificios.edificios[pos].estado = DISPONIBLE;
		}

		for(int i = pos; i < listajugadores.cont - 1; i++)
			listajugadores.jugador[i] = listajugadores.jugador[i + 1];
		listajugadores.cont--;
	}

	return correcto;
}