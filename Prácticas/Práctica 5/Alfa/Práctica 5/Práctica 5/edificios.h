#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include "constants.h"

// Estados de los edificios.
typedef enum { DISPONIBLE, COMPRADO, BORRADO } tEstado;

// Estructura del edificio con sus correspondientes datos.
typedef struct {
	int codigo;
	tCadena nombre;
	int precio;
	int dinero;
	int prestigio;
	tEstado estado;
} tEdificio;

/*La funcion nuevoEdificio de tipo tEdificio genera un nuevo edificio. No necesita parámetros. Al ser de tipo tEdificio, devuelve una estructura 
tEdificio con sus correspondientes datos debidamente inicializados. */
tEdificio nuevoEdificio();
/*El procedimiento mostrarEdificio muestra un edificio cualquiera, así como sus características. Es por ello, que no modifica su parámetro ya que no modifica 
la estructura tEdificio. Por lo tanto, no lleva ampersant "&". */
void mostrarEdificio(tEdificio edificio);

#endif