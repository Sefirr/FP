#include "edificios.h"
#include <iostream>
using namespace std;
#include <iomanip>

tEdificio nuevoEdificio() {

	tEdificio edificio;
	char aux;

	cout << "Identificador: ";
	cin >> edificio.codigo;
	cout << "Nombre del edificio: ";
	cin.get(aux);
	cin.getline(edificio.nombre, MAX_CHAR);
	cout << "Precio de compra: ";
	cin >> edificio.precio;
	cout << "Prestigio por turno: ";
	cin >> edificio.prestigio;
	cout << "Dinero por turno: ";
	cin >> edificio.dinero;


	edificio.estado = DISPONIBLE;

	return edificio;
}


void mostrarEdificio(tEdificio edificio) {

	cout << endl << "==================================================" << endl;

	cout << setw(24) << "Identificador: " << edificio.codigo << endl;
	cout << setw(24) << "Nombre: " << edificio.nombre << endl;
	cout << setw(24) << "Precio de compra: " << edificio.precio << endl;
	cout << setw(24) << "Dinero por turno: " << edificio.dinero << endl;
	cout << setw(24) << "Prestigio por turno: " << edificio.prestigio << endl;
	cout << setw(24) << "Estado: ";

	if(edificio.estado == 0)
		cout << "DISPONIBLE";
	else if(edificio.estado == 1)
		cout << "COMPRADO";
	else
		cout << "BORRADO";

	cout << endl << "==================================================" << endl;

}