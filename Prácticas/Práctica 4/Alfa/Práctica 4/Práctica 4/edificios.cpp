#include "edificios.h"
#include <iostream>
using namespace std;

tEdificio nuevoEdificio() {

	tEdificio edificio;

	cout << "Identificador: ";
	cin >> edificio.codigo;
	cout << "Nombre del edificio: ";
	cin >> edificio.nombre;
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

	cout << "Identificador: " << edificio.codigo << endl;
	cout << "Nombre: " << edificio.nombre << endl;
	cout << "Precio de compra: " << edificio.precio << endl;
	cout << "Dinero por turno: " << edificio.dinero << endl;
	cout << "Prestigio por turno: " << edificio.prestigio;
	cout << "Estado: ";
	if(edificio.estado == 0)
		cout << "DISPONIBLE";
	else if(edificio.estado == 1)
		cout << "COMPRADO";
	else
		cout << "BORRADO";

}

