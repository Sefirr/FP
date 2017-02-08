#include <iostream>
#include <string>
using namespace std;

typedef enum {ESO, BACHILLERATO, GMEDIO, GSUPERIOR, GRADO, MASTER, DOCTORADO} tGradoEstudios;
typedef enum {FIJO, PRACTICAS, EVENTUAL, BECARIO} tContratacion;

const int N = 10;
typedef struct {
	string nombre;
	int edad;
	tGradoEstudios grado;
	tContratacion contratacion;
} tPersona;

typedef tPersona tEmpleados[N];

//Prototipos
void mostrarEmpleados(tEmpleados empleado);
void addemployult(tEmpleados empleado);
void addemployprimero(tEmpleados empleado);

int main() {
	tEmpleados empleado;

	system("chcp 1252");

}

int menu() {
	int opcion;
	tEmpleados empleado;

	do {
		cout << "1 - Añadir un empleado al final de la lista" << endl;
		cout << "2 - Añadir un empleado al principio de la lista" << endl;
		cout << "3 - Eliminar el último empleado de la lista" << endl;
		cout << "4 - Eliminar el primer empleado de la lista" << endl;
		cout << "5 - Eliminar todos los empleados de la plantilla" << endl;
		cout << "6 - Mostrar empleados" << endl;
		cout << "0 - Salir" << endl;
		cout << "Opción: ";
		cin >> opcion;

		switch(opcion) {
		case 0: break;
		case 1: 
			break; 
		case 2: 
			break;
		case 3: 
			break;
		case 4: 
			break;
		case 5: 
			break;
		case 6: 
			mostrarEmpleados(empleado);
			break;
		default: cout << "Opción no válida" << endl;
		}
	} while(opcion != 0);

	return opcion;
}

void mostrarEmpleados(tEmpleados empleado) {
	for(int i = 0; i < N; i++) {
		cout << "Empleado " << i + 1 << endl;
		cout << "Nombre: " << empleado[i].nombre << endl;
		cout << "Edad: " << empleado[i].edad;
		cout << "Grado: ";

		if(empleado[i].grado == ESO) 
			cout << "ESO";
		else if(empleado[i].grado == BACHILLERATO)
			cout << "BACHILLERATO";
		else if(empleado[i].grado == GMEDIO)
			cout << "GRADO MEDIO";
		else if(empleado[i].grado == GSUPERIOR)
			cout << "GRADO SUPERIOR";
		else if(empleado[i].grado == GRADO)
			cout << "GRADO";
		else if(empleado[i].grado == MASTER)
			cout << "MASTER";
		else if(empleado[i].grado == DOCTORADO)
			cout << "DOCTORADO";
		cout << endl;

		cout << "Tipo de contratación: ";
		if(empleado[i].contratacion == FIJO)
			cout << "FIJO";
		else if(empleado[i].contratacion == PRACTICAS)
			cout << "PRÁCTICAS";
		else if(empleado[i].contratacion == EVENTUAL)
			cout << "EVENTUAL";
		else if(empleado[i].contratacion == BECARIO)
			cout << "BECARIO";
		cout << endl << endl;
	}
}
