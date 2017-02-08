#include "jugador.h"
#include <iostream>
using namespace std;

tJugador nuevoJugador() {
	tJugador jugador;

	cout << "Introduce el usuario: ";
	cin >> jugador.usuario;
	cout << "Introduce el password: ";
	cin >> jugador.password;
	cout << "Introduce el nombre de la empresa: ";
	cin >> jugador.universidad;

	jugador.dinero = DINERO_INI;
	jugador.prestigio = 0;

	for(int i = 0; i < CHR; i++) {
		jugador.comprados.elem[i] = 0;
	}

	return jugador;
}

void mostrarJugador(const tJugador jugador) {
	cout << "Usuario: " << jugador.usuario << "(" << jugador.universidad << ")" << endl;
	cout << "Dinero: " << jugador.dinero << endl;
	cout << "Prestigio: " << jugador.prestigio << endl;
	cout << "Edificios: " << endl;
	for(int i = 0; i < jugador.comprados.cont; i++) {
		cout << jugador.comprados.elem[i] << endl;
	}
}

bool listaCompradosLlena(tJugador jugador) {
	bool completa;

	if(jugador.comprados.cont < MAX_EDIFICIOS)
		completa = false;
	else
		completa = true;

	return completa;
}

void comprarEdificio(tJugador &jugador, tListaEdificios lista) {

	int codigo;
	bool encontrado = false;
	int i = 0;

	cout << "Introduce el código del edificio: ";
	cin >> codigo;

	while(!encontrado && (i < lista.cont)) {
		if(codigo == lista.edificios[i].codigo) 
			encontrado = true;
		else
			i++;
	}
	if(encontrado) {
		if(listaCompradosLlena(jugador))
			cout << "ERROR: Tu lista de edificios comprados está llena." << endl << endl;
		else {
			if(lista.edificios[i].estado == DISPONIBLE) {
				if(jugador.dinero < lista.edificios[i].precio)
					cout << "ERROR: No tienes dinero suficiente, el edificio cuesta " << lista.edificios[i].precio << endl << endl;
				else {
					jugador.dinero = jugador.dinero - lista.edificios[i].precio;
					cout << "Has comprado el edificio y has pagado " << lista.edificios[i].precio << endl << endl;
					lista.edificios[i].estado = COMPRADO;

					jugador.comprados.elem[jugador.comprados.cont] == lista.edificios[i].codigo;
					jugador.comprados.cont++;
				}
			}
			else
				cout << "ERROR: El edificio no está disponible" << endl << endl;
		}
	}
	else
		cout << "ERROR: No es un edificio válido";

}