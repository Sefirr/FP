#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include "edificios.h"
#include <fstream>
using namespace std;

const int MAX = 50;

typedef tEdificio tEdificios[MAX];

typedef struct {
	tEdificios edificios;
	int cont;
} tListaEdificios;

bool listaEdificiosLlena(tListaEdificios lista);
int buscarEdificio(tListaEdificios lista, int buscado);
void insertarEdificio(tListaEdificios &lista);
void bajaEdificio(tListaEdificios &lista);

#endif