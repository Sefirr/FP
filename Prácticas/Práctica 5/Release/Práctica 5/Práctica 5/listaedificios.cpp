#include "listaedificios.h"


bool listaEdificiosLlena(const tListaEdificios lista) {

	bool completa;

	if(lista.cont < lista.capacidad)
		completa = false;
	else
		completa = true;

	return completa;
}

bool buscarEdificio(tListaEdificios lista, int ini, int fin, int buscado, int &pos) {
	int mitad;
	bool encontrado = false;
	pos = -1;

	if (ini <= fin) {
		mitad = (ini + fin) / 2;
		if (buscado == lista.edificios[mitad].codigo) {
			encontrado = true;
			pos = mitad;
		}
		else if (buscado < lista.edificios[mitad].codigo)
			encontrado = buscarEdificio(lista, ini, mitad - 1, buscado, pos);
		else 
			encontrado = buscarEdificio(lista, mitad + 1, fin, buscado, pos);
	}

	return encontrado;
}

bool insertarEdificio(tListaEdificios &lista) {
	bool correcto = true;
	int pos;
	tEdificio edificio_new = nuevoEdificio();

	if (buscarEdificio(lista, 0, lista.cont - 1, edificio_new.codigo, pos))
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

	if(buscarEdificio(lista, 0, lista.cont - 1, buscado, pos) && (lista.edificios[pos].estado == DISPONIBLE))
		lista.edificios[pos].estado = BORRADO;
	else
		correcto = false;

	return correcto;
}
