#include <iostream>
#include "edificios.h"
#include "jugador.h"
#include "listaedificios.h"
#include "listajugadores.h"
using namespace std;
#include <fstream>

int menu();
bool cargarjugadores(tListaJugadores &lista);
bool cargaredificios(tListaEdificios &lista);

int main() {
	tListaJugadores jugadores;
	tListaEdificios edificios;


	if(cargarjugadores(jugadores) && cargaredificios(edificios)) {
		cout << "Listas cargadas" << endl << endl;


	}
	else
		cout << "ERROR - Listas no cargadas." << endl;


	return 0;
}

bool cargarjugadores(tListaJugadores &lista) {
	int dato;
	tJugador jugador_E;
	ifstream entrada;
	char c;
	bool ok = true;

	entrada.open("jugadores.txt");
	if(!entrada.is_open())
		ok = false;
	else {
		entrada >> jugador_E.usuario;
		lista.cont = 0;
		jugador_E.comprados.cont = 0;
		while((strcmp(jugador_E.usuario,"X") != -1) && (lista.cont < N)) {
			entrada >> jugador_E.password;
			entrada.get(c);
			entrada.getline(jugador_E.universidad, MAX);
			entrada >> jugador_E.dinero;
			entrada >> jugador_E.prestigio;
			entrada >> dato;
			while(dato != -1) {
				if(dato != -1)
					jugador_E.comprados.elem[jugador_E.comprados.cont] = dato;
				else
					entrada >> dato;
				jugador_E.comprados.cont++;
			}

			lista.jugador[lista.cont] = jugador_E;
			lista.cont++;

			entrada >> jugador_E.usuario;

		}
	}

	return ok;
}

bool cargaredificios(tListaEdificios &lista) {
	tEdificio edificio;
	ifstream entrada;
	int estado;
	char c;
	bool ok = true;

	entrada.open("edificios.txt");
	if(!entrada.is_open())
		ok = false; 
	else {
		entrada >> edificio.codigo;
		lista.cont = 0;
		while((edificio.codigo != -1) && (lista.cont < MAX))
		{
			entrada.get(c);
			// Hay que hacer una constante para leer edificio.nombre
			entrada.getline(edificio.nombre, MAX);
			entrada >> edificio.precio;
			entrada >> edificio.dinero;
			entrada >> edificio.prestigio;
			entrada >> estado;

			switch(estado) {
			case 0: 
				edificio.estado = DISPONIBLE;
					break;
			case 1: 
				edificio.estado = COMPRADO;
				break; 
			case 2: 
				edificio.estado = BORRADO;
				break;
			}

			lista.edificios[lista.cont] = edificio;
			lista.cont++;

			entrada >> edificio.codigo;

		}

	}

	return ok;
}

int menu() {
	int opcion;

	cout << "1 - Ver mis edificios" << endl;
	cout << "2 - Ver los edificios disponibles" << endl;
	cout << "3 - Comprar un edificio" << endl;
	cout << "4 - Ver la clasificación (ordenada por dinero)" << endl;
	cout << "5 - Ver la clasificación (ordenada por prestigio)" << endl;
	cout << "0 - Cerrar la sesión" << endl;
	cout << "Opción: ";
	cin >>opcion;

	switch(opcion) {
	case 0: break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	default: cout << "Opción no válida." << endl;
	}


	return opcion;
}

int menu_admin() {
	int opcion;

	cout << "1 - Ver el listado de edificios" << endl;
	cout << "2 - Nuevo edificio" << endl;
	cout << "3 - Borrar un edificio" << endl;
	cout << "4 - Ver el listado de jugadores" << endl;
	cout << "5 - Nuevo jugador" << endl;
	cout << "6 - Borrar un jugador" << endl;
	cout << "7 - Ejecutar un turno" << endl;
	cout << "8 - Ver la clasificación" << endl;
	cout << "0 - Cerrar la sesión" << endl;
	cout << "Opción: ";
	cin >> opcion;

	switch(opcion) {
	case 0: break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: break;
	case 8: break;
	default: cout << "Opción no válida." << endl;
	}

	return opcion;
}