#include "listaedificios.h"


bool listaEdificiosLlena(const tListaEdificios lista) {

	bool completa;

	if(lista.cont < MAX_EDIFICIOS)
		completa = false;
	else
		completa = true;

	return completa;
}

bool buscarEdificio(tListaEdificios lista, int buscado, int &pos) {
	int ini = 0, fin = lista.cont - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (buscado == lista.edificios[mitad].codigo) encontrado = true;
		else if (buscado < lista.edificios[mitad].codigo) fin = mitad - 1;
		else ini = mitad + 1;
	}

	if (encontrado)
		pos = mitad;
	else 
		pos = - 1;

	return encontrado;
}

bool insertarEdificio(tListaEdificios &lista) {
	bool correcto = true;
	int pos;
	tEdificio edificio_new = nuevoEdificio();

	if (listaEdificiosLlena(lista) || buscarEdificio(lista, edificio_new.codigo, pos))
		correcto = false; 
	else {
		int i = 0;
		while ((i < lista.cont) && (lista.edificios[i].codigo < edificio_new.codigo))
			i++;

		for (int j = lista.cont; j > i; j--)
			lista.edificios[j] = lista.edificios[j - 1];
		lista.edificios[i] = edificio_new;
		lista.cont++;
	}

	return correcto;
}

bool bajaEdificio(tListaEdificios &lista, int buscado) {
	int pos;
	bool correcto = true;

	if(buscarEdificio(lista, buscado, pos) && (lista.edificios[pos].estado == DISPONIBLE))
		lista.edificios[pos].estado = BORRADO;
	else
		correcto = false;

	return correcto;
}
