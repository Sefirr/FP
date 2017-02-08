#include <iostream>
using namespace std;

const int MAX_EMPLEADOS = 10;

typedef enum {ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctor} tEstudios;

typedef enum {Fijo, Practicas, Eventual, Becario} tTipoContrato;

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

void insertarUltimo(tPlantilla &plantilla, tEmpleado empleado);
void insertarPrimero(tPlantilla &plantilla, tEmpleado empleado);
void eliminarUltimo(tPlantilla &plantilla);
void eliminarPrimero(tPlantilla &plantilla);
void eliminarTodos(tPlantilla &plantilla);

int main() {
   tPlantilla plantilla;
   plantilla.numEmpleados = 0;
   // ...

   return 0;
}

void insertarUltimo(tPlantilla &plantilla, tEmpleado empleado) {
	if (plantilla.numEmpleados < MAX_EMPLEADOS) {
		plantilla.empleados[plantilla.numEmpleados] = empleado;
		plantilla.numEmpleados++;
	} else
		cout << "Plantilla llena";
}

void insertarPrimero(tPlantilla &plantilla, tEmpleado empleado) {
	if (plantilla.numEmpleados < MAX_EMPLEADOS) {
		desplazarDcha(plantilla);
		plantilla.empleados[0] = empleado;
		plantilla.numEmpleados++;
	} else
		cout << "Plantilla llena";
}

void eliminarUltimo(tPlantilla &plantilla) {
	if (plantilla.numEmpleados > 0)
		plantilla.numEmpleados--;
	else
		cout << "La plantilla esta vacia";
}

void eliminarPrimero(tPlantilla &plantilla) {
	if (plantilla.numEmpleados > 0) {
		desplazarIzda(plantilla);
		plantilla.numEmpleados--;
	} else
		cout << "La plantilla esta vacia";
}

void eliminarTodos(tPlantilla &plantilla) {
	plantilla.numEmpleados = 0;
}
