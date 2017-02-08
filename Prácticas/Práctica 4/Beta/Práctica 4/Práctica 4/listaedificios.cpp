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

	tEdificio Edificio_new = nuevoEdificio();
	bool inter = true;
	bool correcto = true;
	int i, pos;

	if(!listaEdificiosLlena(lista) && !buscarEdificio(lista, Edificio_new.codigo, pos) ) {
		lista.edificios[lista.cont] = Edificio_new;
		lista.cont++;

		i = 0;
		while((i < lista.cont - 1) && inter) {
			inter = false;
			for(int j = lista.cont - 1; j > i; j--)
				if(lista.edificios[j].codigo < lista.edificios[j - 1].codigo) {
					tEdificio tmp;
					tmp = lista.edificios[j];
					lista.edificios[j] = lista.edificios[j - 1];
					lista.edificios[j - 1] = tmp;
					inter = true;
				}
				if(inter) i++;
		}
	}
	else
		correcto = false;


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
