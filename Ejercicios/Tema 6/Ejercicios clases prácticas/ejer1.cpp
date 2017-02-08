#include <iostream>
using namespace std;

const int MAX_EMPLEADOS = 10;

typedef enum {
	ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctor
} tEstudios;

typedef enum {
	Fijo, Practicas, Eventual, Becario
} tTipoContrato;

typedef struct {
	string nombre;
	int edad;
	tEstudios estudios;
	tTipoContrato contrato;
} tEmpleado;

typedef struct {
	int numEmpleados;
	tEmpleado empleados[MAX_EMPLEADOS];
} tPlantilla;
bool insertar(tPlantilla &plantilla, tEmpleado nuevo, int pos);
bool eliminar(tPlantilla &plantilla, int pos);

int main() {
   tPlantilla plantilla;
   plantilla.numEmpleados = 0;
   // ...

   return 0;
}

bool insertar(tPlantilla &plantilla, tEmpleado nuevo, int pos) {
	bool insertado = false;
	if(plantilla.numEmpleados < MAX_EMPLEADOS) {
		if((pos >= 0) && (pos <= plantilla.numEmpleados))
		{
		for(int i = plantilla.numEmpleados; i > pos; i--) 
			plantilla.empleados[i] = plantilla.empleados[i - 1];

		plantilla.empleados[pos] = nuevo;
		plantilla.numEmpleados++;
		insertado = true;
		}
	}
	return insertado;
}

bool eliminar(tPlantilla &plantilla, int pos) {
	bool eliminado = false;
	if((pos < 0) && (pos >= plantilla.numEmpleados)){
		for(int i = pos; i < plantilla.numEmpleados - 1; i++) 
			plantilla.empleados[i] = plantilla.empleados[i + 1];
		plantilla.numEmpleados--;
		eliminado = true;
	}
	return eliminado;

}