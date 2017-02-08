#include "jugador.h"
#include "listaedificios.h"
#include <iostream>
using namespace std;
#include <iomanip>

tJugador nuevoJugador() {
	tJugador jugador;
	char aux;

	cout << "Introduce el usuario: ";
	cin >> jugador.usuario;
	cout << "Introduce el password: ";
	cin >> jugador.password;
	cout << "Introduce el nombre de la empresa: ";
	cin.get(aux);
	cin.getline(jugador.universidad, MAX_CHAR);

	jugador.dinero = DINERO_INI;
	jugador.prestigio = 0;
	jugador.comprados.cont = 0;

	for(int i = 0; i < NUM_COMPRADOS; i++) {
		jugador.comprados.elem[i] = 0;
	}


	return jugador;
}

void mostrarJugador(tJugador jugador, tListaEdificios lista) {
	int ini = 0;
	int fin = lista.cont - 1;
	int pos;

	cout << endl << "==================================================" << endl;
	cout << setw(12) << right << "Usuario: " << jugador.usuario << " (" << jugador.universidad << ")" << endl;
	cout << setw(12) << right <<"Dinero: " << jugador.dinero << endl;
	cout << setw(12) << right << "Prestigio: " << jugador.prestigio << endl;
	cout << setw(12) << "Edificios: " << jugador.comprados.cont << endl;
	for(int i = 0; i < jugador.comprados.cont; i++) {
		cout << setw(15) << "Edificio #" << i + 1 << " - ";
		if(buscarEdificio(lista, jugador.comprados.elem[i], pos))
			cout << lista.edificios[pos].nombre << " - D: " << lista.edificios[pos].dinero << " - P: " << lista.edificios[pos].prestigio << endl;
	}

	cout << endl << "==================================================" << endl;

}

bool listaCompradosLlena(tJugador jugador) {
	bool completa;

	if(jugador.comprados.cont < NUM_COMPRADOS)
		completa = false;
	else
		completa = true;

	return completa;
}

void comprarEdificio(tJugador &jugador, tListaEdificios &lista) {

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

					jugador.comprados.elem[jugador.comprados.cont] = lista.edificios[i].codigo;
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