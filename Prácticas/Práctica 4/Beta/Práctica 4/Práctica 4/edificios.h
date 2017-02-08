#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include "constants.h"

typedef enum { DISPONIBLE, COMPRADO, BORRADO } tEstado;

typedef struct {
	int codigo;
	tCadena nombre;
	int precio;
	int dinero;
	int prestigio;
	tEstado estado;
} tEdificio;

tEdificio nuevoEdificio();
void mostrarEdificio(const tEdificio edificio);

#endif