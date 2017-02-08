#ifndef EDIFICIOS_H
#define EDIFICIOS_H

typedef enum { DISPONIBLE, COMPRADO, BORRADO } tEstado;

typedef struct {
	int codigo;
	char nombre[20];
	int precio;
	int dinero;
	int prestigio;
	tEstado estado;
} tEdificio;

tEdificio nuevoEdificio();
void mostrarEdificio(tEdificio edificio);

#endif