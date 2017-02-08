#include <iostream>
#include <cstring>
using namespace std;
#include "edificios.h"
#include "jugador.h"
#include "listaedificios.h"
#include "listajugadores.h"
#include "functions.h"
#include "constants.h"

const int SIZE_JUG = sizeof(tJugador);
const int SIZE_EDIF = sizeof(tEdificio);

void guardarJugadores(tListaJugadores lista);
void guardarEdificios(tListaEdificios lista);
bool leerJugadores(tListaJugadores &lista);
bool leerEdificios(tListaEdificios &lista);

int main() {
	tListaJugadores jugadores;
	tListaEdificios edificios;

	int fallos, pos;
	int opcion = -1;
	bool session, session_admin;

	system("chcp 1252");

	if(leerJugadores(jugadores) && leerEdificios(edificios)) 
		cout << "Listas cargadas";
	else
		cout << "Lista vacias";

		cout << endl << endl << endl << "Bienvenido a Campus Ville" << endl;
		cout << "=========================" << endl << endl;
		cout << "Escribe 'salir' o 's' para cerrar el programa..." << endl;

		session = login(jugadores, fallos, session_admin, pos);
		while((session || session_admin)) {		
			while(opcion != 0) {
				if(session)
					opcion = menu(edificios, jugadores, pos);
				else if(session_admin)
					opcion = menu_admin(jugadores,edificios);
				cout << endl << endl;
			}
			if(opcion == 0) {
				session = false;
				session_admin = false;
				session = login(jugadores, fallos, session_admin, pos);
				opcion = -1;
			}
		}
		guardarJugadores(jugadores);
		guardarEdificios(edificios);
		cout << "Listas guardadas." << endl;

		delete [] jugadores.jugador;
		delete [] edificios.edificios;

	return 0;
}

void guardarJugadores(tListaJugadores lista) {
	fstream archivo;

	archivo.open("jugadores.dat", ios::out | ios::binary | ios::trunc);
	for(int i = 0; i < lista.cont; i++) {
		archivo.write( (char *) &lista.jugador[i], SIZE_JUG);
	}
	archivo.close();
}

void guardarEdificios(tListaEdificios lista) {
	fstream archivo;

	archivo.open("edificios.dat", ios::out | ios::binary | ios::trunc);
	for(int i = 0; i < lista.cont; i++) {
		archivo.write( (char *) &lista.edificios[i], SIZE_EDIF);
	}
	archivo.close();
}

bool leerJugadores(tListaJugadores &lista) {
	fstream archivo;
	bool ok = false;

	archivo.open("jugadores.dat", ios::in | ios::binary);

	if(!archivo.is_open()) {
		lista.jugador = new tJugador[MAX_USUARIOS];
		ok = false; 
	}
	else {
		archivo.seekg(0, ios::end);
		int pos = archivo.tellg();
		int numReg = pos / SIZE_JUG;
		lista.cont = numReg;
		lista.capacidad = (numReg / 10 + 1) * 10; /* Como son enteros al dividir por 10, descarta decimales.
		Al sumarle uno y, posteriormente, multiplicar por 10. Pasamos a la siguiente decena. */
		lista.jugador = new tJugador[lista.capacidad];
		archivo.seekg(0 , ios::beg);
		for(int i = 0; i < numReg; i++) {
			archivo.read( (char *) &lista.jugador[i], SIZE_JUG);
		}
		archivo.close();
		ok = true;

	}

	return ok;
}

bool leerEdificios(tListaEdificios &lista) {
	fstream archivo;
	bool ok;

	archivo.open("edificios.dat", ios::in | ios::binary);

	if(!archivo.is_open()) {
		lista.edificios = new tEdificio[MAX_EDIFICIOS];
		ok = false; 
	}
	else {
		archivo.seekg(0, ios::end);
		int pos = archivo.tellg();
		int numReg = pos / SIZE_EDIF;
		lista.cont = numReg;
		lista.capacidad = (numReg / 10 + 1) * 10;
		lista.edificios = new tEdificio[lista.capacidad];
		archivo.seekg(0 , ios::beg);

		for(int i = 0; i < numReg; i++) {
			archivo.read( (char *) &lista.edificios[i], SIZE_EDIF);
		}
		archivo.close();
		ok = true;

	}

	return ok;
}