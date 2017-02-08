#include <iostream>
#include <cstring>
using namespace std;
#include "edificios.h"
#include "jugador.h"
#include "listaedificios.h"
#include "listajugadores.h"
#include "functions.h"
#include "constants.h"

int main() {
	tListaJugadores jugadores;
	tListaEdificios edificios;

	jugadores.jugador = new tJugador[MAX_USUARIOS];
	edificios.edificios = new tEdificio[MAX_EDIFICIOS];

	int fallos, pos;
	int opcion = -1;
	bool session, session_admin;

	system("chcp 1252");

	if(cargarjugadores(jugadores) && cargaredificios(edificios)) 
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
		listajugadores(jugadores);
		listaedificios(edificios);
		cout << "Listas guardadas." << endl;

		delete [] jugadores.jugador;
		delete [] edificios.edificios;

	return 0;
}