#include "listaedificios.h"
#include <iostream>
using namespace std;

bool listaEdificiosLlena(tListaEdificios lista) {

	int estado;
	tEdificio edificio;
	bool ok = true;
	lista.cont = 0;
	ifstream entrada;

	entrada.open("edificios.txt");

	if(lista.cont >= MAX)
		ok = false;
	else {
		entrada >> edificio.codigo;
		while((edificio.codigo != -1) && (lista.cont < MAX)) {
			entrada >> edificio.nombre;
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

int buscarEdificio(tListaEdificios lista, int buscado) {
	int pos;
	int ini = 0, fin = lista.cont - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (buscado == lista.edificios[mitad].codigo) encontrado = true;
		else if (buscado < lista.edificios[mitad].codigo) fin = mitad - 1;
		else ini = mitad + 1;
	}
	pos = mitad + 1;
	if (encontrado)
		cout << "Encontrado en la posición " << pos << endl;
	else 
		pos = - 1;

	return pos;
}

