#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include <iostream>
using namespace std;
#include <fstream>
#include "edificios.h"
#include "constants.h"

typedef tEdificio tEdificios[MAX_EDIFICIOS];

typedef struct {
	tEdificios edificios;
	int cont;
} tListaEdificios;

bool listaEdificiosLlena(tListaEdificios lista);
bool buscarEdificio(tListaEdificios lista, int buscado, int &pos);
bool insertarEdificio(tListaEdificios &lista);
bool bajaEdificio(tListaEdificios &lista, int buscado);

#endif